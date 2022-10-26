using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class EnemyWeapon : weapon {

	protected override void OnTriggerEnter2D (Collider2D other)
	{
		if(other.gameObject.CompareTag("Player")){
			other.gameObject.GetComponent<MoveObject> ().hitDamage (damage);
			//NetworkServer.UnSpawn(this.gameObject);
			NetworkServer.Destroy(this.gameObject);
		}
	}
}
