using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class BossPrefab : EnemyObject {
	[HideInInspector]
	public BossInfo bossInfo;
	[HideInInspector]
	public RectTransform HPGauge;
	[HideInInspector]
	public float defaultX;
	[HideInInspector]
	public Transform userPos;//outboundary로 부터 입력됨.
	void OnEnable(){
		HPGauge = transform.GetChild (3).GetChild (0).GetChild (0).gameObject.GetComponent<RectTransform> ();
		BossInfo bossInfo = GameObject.FindGameObjectWithTag ("BossInfo").GetComponent<BossInfo>();
		this.bossInfo = bossInfo;
		defaultX = transform.position.x - bossInfo.transform.position.x;

		bossInfo.delegateSyncBossHealthBar += SyncBossHealthInfo;
		bossInfo.health = bossInfo.maxHealth;
	}

	public override void OnStartServer ()
	{
		base.OnStartServer ();
		GetComponent<Rigidbody2D> ().velocity = new Vector2 (-1, 0);
		StartCoroutine (stopAccelation ());
		StartCoroutine (bossBulletPattern());
	}
	private IEnumerator bossBulletPattern(){
		yield return new WaitForSeconds (3.5f);
		Vector3 bulletRotation;
		Vector2 bulletDirection;
		float angle = 0;
		while (true) {
			int rand = Random.Range (1, 5);
			switch(rand){
			case 1:// 부채꼴
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 9; j++) {
						angle = -45 +(10.0f * j);
						bulletRotation = new Vector3 (0, 0, angle);
						bulletDirection = new Vector2 (Mathf.Cos ((angle-90)/180 * Mathf.PI),Mathf.Sin ((angle-90) / 180 * Mathf.PI));
						CmdFire (0, i % 3, bulletRotation, bulletDirection);
					} 
					yield return new WaitForSeconds (0.5f);
				}
				break;
			case 2: // 난사
				for (int i = 0; i < 100; i++) {
					angle = -45 + Random.Range (0, 90);
					bulletRotation = new Vector3 (0, 0, angle);
					bulletDirection = new Vector2 (Mathf.Cos ((angle - 90) / 180 * Mathf.PI), Mathf.Sin ((angle - 90) / 180 * Mathf.PI));
					CmdFire (0, Random.Range (0, 3), bulletRotation, bulletDirection);
					yield return new WaitForSeconds (0.02f);
				}
				break;
			case 3: //폭탄
				for (int i = 0; i < 8; i++) {
					angle = -15 + Random.Range (0, 30);
					bulletRotation = new Vector3 (0, 0, angle);
					bulletDirection = new Vector2 (Mathf.Cos ((angle - 90) / 180 * Mathf.PI), Mathf.Sin ((angle - 90) / 180 * Mathf.PI));
					CmdFire (1, Random.Range (0, 3), bulletRotation, bulletDirection);
					yield return new WaitForSeconds (0.5f);
				}
				break;
			case 4: // 모아쏘기
				for (int i = 0; i < 10; i++) {
					bulletRotation = FollowBullet (userPos, bulletSpawn[0].transform,out bulletDirection);
					CmdFire (2, 0, bulletRotation, bulletDirection);
					bulletRotation = FollowBullet (userPos, bulletSpawn [1].transform, out bulletDirection);
					CmdFire (2, 1, bulletRotation, bulletDirection);
					yield return new WaitForSeconds (0.1f);
				}
				break;
			}
			yield return new WaitForSeconds (1.5f);
		}
	}
	private IEnumerator stopAccelation(){
		while (transform.position.x > defaultX) {
			yield return new WaitForSeconds (0.5f);
		}
		GetComponent<Rigidbody2D> ().velocity = new Vector2 (0, 0);
		transform.position = new Vector3(defaultX,transform.position.y);

		yield break;
	}


	public void SyncBossHealthInfo(int bossHealth){
		if (HPGauge != null && bossHealth > 0) {
			HPGauge.sizeDelta = new Vector2 (bossInfo.healthBarMax * bossHealth / bossInfo.maxHealth, HPGauge.rect.height);
		} else {
			bossInfo.OnDeath ();
			if (this != null) {
				Destroy (gameObject);
			}
		}
	}


	public override void hitDamage(int damage){
		if (!isServer)
			return;
		if (bossInfo.health - damage <= 0) {
			bossInfo.health = 0;
		} else {
			bossInfo.health -= damage;
		}
	}
	void Update(){}
}
