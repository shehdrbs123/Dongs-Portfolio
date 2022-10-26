using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
public class weapon : NetworkBehaviour {
	public int damage;
	void Awake(){
		if (transform.position.y <= -5) {
			NetworkServer.UnSpawn (this.gameObject);
			NetworkServer.Destroy (this.gameObject);
		}
	}
	protected virtual void OnTriggerEnter2D(Collider2D other){
		//Debug.Log (other.gameObject.name);
		if (other.gameObject.CompareTag ("Enemy")) {
			other.gameObject.GetComponent<MoveObject> ().hitDamage (damage);
			//NetworkServer.UnSpawn (this.gameObject);
			NetworkServer.Destroy (this.gameObject);
		}
	}
}
