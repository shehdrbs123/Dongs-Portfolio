using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class Spawner : NetworkBehaviour{

	public float[] nextSpawn;
	public GameObject[] spawnPrefabs;
	public float within;
	// Update is called once per frame\
	void OnEnable(){
		TableSetter.singleton.DestroyWhenGaugeFull += CmdDestroySpawner;
	}
	public override void OnStartServer(){
		base.OnStartServer ();
		for (int i = 0; i < spawnPrefabs.Length; i++) {
			StartCoroutine (SpawnCourutine (i));
		}
	}

	public IEnumerator SpawnCourutine(int i){
		
		Random.InitState (Random.Range(0,11000));
		while (true) {
			CmdSpawn (i);
			yield return new WaitForSeconds (nextSpawn [i]);
		}
	}
	[Command]
	void CmdSpawn(int i){
		Vector3 pos = new Vector3 (transform.position.x + Random.Range (-within, within), transform.position.y, 0.0f);
		var enemy = (GameObject)Instantiate (spawnPrefabs[i], pos, transform.rotation);
		enemy.GetComponent<Rigidbody2D> ().velocity = enemy.transform.up * enemy.GetComponent<MoveObject> ().movespeed;
		NetworkServer.Spawn (enemy);
	}
	[Command]
	void CmdDestroySpawner (){
		Destroy (this.gameObject);
	}
}
