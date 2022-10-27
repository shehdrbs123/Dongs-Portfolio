using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
public class outboundary :  NetworkBehaviour{
	public GameObject player;
	// Use this for initialization
	void OnTriggerExit2D(Collider2D other)
	{
		NetworkServer.UnSpawn (other.gameObject);
		NetworkServer.Destroy (other.gameObject);
	}
	void OnTriggerEnter2D(Collider2D other){
		if (other.gameObject.GetComponent<GamePlayer> () != null) {
			player = other.gameObject;
			return;
		} else if (other.gameObject.GetComponent<Slayer> () != null) {
			if (player != null) {
				other.gameObject.GetComponent<Slayer> ().target = player.transform;
			}
		} else if (other.gameObject.GetComponent<BossPrefab> () != null) {
			if (player != null) {
				other.gameObject.GetComponent<BossPrefab> ().userPos = player.transform;
			}
		}
	}
}
