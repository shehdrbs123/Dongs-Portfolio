using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class MoveObject : NetworkBehaviour {

	public float movespeed;
	[SyncVar(hook="SyncHealthInfo")]
	public int health;
	public float delayFire;
	protected float nextFire=2; 
	public GameObject[] bulletPrefab;
	public Transform[] bulletSpawn;
	public float[] bulletSpeed;
	[Command]
	protected void CmdFire(int bulletIndex,int bulletSpawnIndex,Vector3 direction, Vector2 directionVelocity){
		var bullet = (GameObject)Instantiate (bulletPrefab[bulletIndex], bulletSpawn[bulletSpawnIndex].position, Quaternion.Euler(direction));
		bullet.GetComponent<Rigidbody2D> ().velocity = directionVelocity * bulletSpeed[bulletIndex];
		NetworkServer.Spawn(bullet);
		Destroy (bullet, 5.0f);
	}
    protected void SyncHealthInfo(int health){
		SetHealthBar (health);
	}
		

	public virtual void hitDamage(int damage){
		if (!isServer)
			return;
		if (health - damage <= 0) {
			health = 0;
			OnDeath ();
		} else {
			health -= damage;
		}
	}
	protected virtual void SetHealthBar (int health){}
	protected virtual void OnDeath (){}
	void Update(){
		if (!isServer)
			return;
		if (Time.time > nextFire) {
			nextFire = Time.time + delayFire;
			CmdFire (0,0,bulletSpawn[0].eulerAngles,bulletSpawn[0].up.normalized);
		}
	}
}
