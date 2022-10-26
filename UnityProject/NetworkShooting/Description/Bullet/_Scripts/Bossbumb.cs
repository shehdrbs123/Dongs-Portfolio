using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class Bossbumb : EnemyWeapon {
	public GameObject shrapnel;
	public override void OnStartServer ()
	{
		base.OnStartServer ();
		StartCoroutine (burst ());
	}
	void spreadShrapnel(){
		Vector3 bulletRotation = new Vector3();
		Vector2 bulletDirection = new Vector2();
		float angle = 0;
		for (int i = 0; i < 9; i++) {
			angle = 40 * i;
			bulletRotation = new Vector3 (0, 0, angle);
			bulletDirection = new Vector2 (Mathf.Cos ((angle-90)/180 * Mathf.PI),Mathf.Sin ((angle-90) / 180 * Mathf.PI));
			CmdFire (bulletRotation, bulletDirection);
		}
	}
	public IEnumerator burst(){
		yield return new WaitForSeconds (1.3f);
		spreadShrapnel ();
		Destroy (gameObject);
		yield break;
	}
	[Command]
	public void CmdFire(Vector3 bulletRotation, Vector2 bulletDirection){
		var bullet = (GameObject)Instantiate (shrapnel, transform.position, Quaternion.Euler(bulletRotation));
		bullet.GetComponent<Rigidbody2D> ().velocity = bulletDirection;
		NetworkServer.Spawn(bullet);
		Destroy (bullet, 5.0f);
	}
}
