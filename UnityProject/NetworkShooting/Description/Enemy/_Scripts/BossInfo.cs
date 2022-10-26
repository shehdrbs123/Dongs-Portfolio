using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class BossInfo : NetworkBehaviour {
	public int maxHealth = 10000;
	[HideInInspector]
	[SyncVar(hook="SyncBossHealthBar")]
	public int health;
	[HideInInspector]
	public int healthBarMax = 300;
	// Use this for initialization
	public GameObject boss;
	[HideInInspector]
	public float playerDistance = 15.0f;
	public delegate void BossHealthBar(int health);
	public BossHealthBar delegateSyncBossHealthBar;
	void OnEnable(){
		StartCoroutine (StartBossSpawn ());
	}
	private void SyncBossHealthBar(int health){
		delegateSyncBossHealthBar (health);
	}
	public IEnumerator StartBossSpawn(){
		yield return new WaitForSeconds (1);
		GameObject bossIns;
		for (int i = 0; i < NetworkServer.connections.Count; i++) {
			bossIns = Instantiate (boss, new Vector3 (transform.position.x + playerDistance * i, transform.position.y, 0), transform.rotation);
			NetworkServer.Spawn (bossIns);
		}
		yield break;
	}
	public void OnDeath(){
		StopAllCoroutines ();
		StartCoroutine (TableSetter.singleton.WinOperation());
	}
}