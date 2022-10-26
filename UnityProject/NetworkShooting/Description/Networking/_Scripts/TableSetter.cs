using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;

public class TableSetter : NetworkBehaviour {
	public static TableSetter singleton;
	public GameObject outBoundary;
	public GameObject spawner;
	public GameObject bossInfo;
	public Transform bossInsPos;

	public GameObject warningPan;
	public GameObject winPan;
	private float playerDistanceX=15.0f;

	[SyncVar(hook="SyncCrisisGaugeBar")]
	public int CrisisGauge=0;
	public const int CrisisGaugeMax = 930;
	public RectTransform GaugeBar;
	public bool isGaugeFull;

	[SyncVar]
    int numOfPlayer;
	public bool isGameWin;
	[SyncVar(hook="isGameOver")]
	public int userDeath = 0;

	void OnEnable(){
		singleton = this;
	}
	public override void OnStartServer(){
		base.OnStartServer ();
		numOfPlayer = NetworkServer.connections.Count;
		for (int i = 0; i < numOfPlayer; i++) {
			GameObject InsOutBoundary = Instantiate (outBoundary, new Vector2 (i * playerDistanceX, 0), Quaternion.identity);
			GameObject InsSpawner = Instantiate (spawner, new Vector2 (i * playerDistanceX, 6.5f), Quaternion.Euler (new Vector3 (0, 0, 180)));
			NetworkServer.Spawn (InsSpawner);
			NetworkServer.Spawn (InsOutBoundary);
		}
	}
		

	// Use this for initialization
	public delegate void DestroyEvent();
	public event DestroyEvent DestroyWhenGaugeFull;
	public void SyncCrisisGaugeBar(int CrisisGauge){
		if (CrisisGaugeMax >= CrisisGauge)
			GaugeBar.sizeDelta = new Vector2 (CrisisGauge, GaugeBar.rect.height);
		else {
			if (isServer) {
				DestroyWhenGaugeFull ();
				isGaugeFull = true;
				CrisisGauge = 0;
			}
			StartCoroutine (BossInstantiateCoroutine ());
		}
	}
	private IEnumerator BossInstantiateCoroutine(){
		for (int i = 0; i < 4; i++) {
			warningPan.SetActive (true);
			yield return new WaitForSeconds (1);
			warningPan.SetActive (false);
			yield return new WaitForSeconds (1);
		}
		if (!isServer)
			yield break;
		GameObject bossInfoIns = (GameObject)Instantiate (bossInfo, bossInfo.transform.position, bossInfo.transform.rotation);
		NetworkServer.Spawn (bossInfoIns);
		yield break;
	}

	public IEnumerator WinOperation(){
		winPan.SetActive (true);
		Text text=winPan.GetComponent<Text> ();
		for(int i=1;i<=256;i+=3){
			text.color = new Color (text.color.r, text.color.g, text.color.b,(float)i/256);
			yield return new WaitForSeconds (0.01f);
		}
		text = null;
		yield return new WaitForSeconds (3);
		NetworkLobbyManagerExtend._singleton.ServerReturnToLobby ();
		yield break;
	}

	private void isGameOver(int userDeath){
		if (!isServer)
			return;
		if (userDeath >= numOfPlayer) {
			NetworkLobbyManagerExtend._singleton.ServerReturnToLobby ();		
		}
		
	}
}
