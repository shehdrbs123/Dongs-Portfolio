using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class LobbyPlayer : NetworkLobbyPlayer {

	public Text nameText;
	public Text readyText;
	public Button readyButton;
	[HideInInspector]
	[SyncVar(hook="SyncOnName")]
	public string names=null;
	[HideInInspector]
	[SyncVar(hook="SyncOnReady")]
	public string ready=null;

	public override void OnClientEnterLobby(){
		base.OnClientEnterLobby ();
		if(SceneManager.GetActiveScene().name.Equals("Connect")){
			StartCoroutine (AddPlayerAndSetupCourutine());
		}
	}

	public IEnumerator AddPlayerAndSetupCourutine(){
		LobbyPlayerList list = null;
		while (true) {
			while (list == null) {
				list = LobbyPlayerList.singleton;
				yield return new WaitForSeconds (0.1f);
			}
			if (list.gameObject.activeSelf) {
				list.AddPlayer (this);
				if (isLocalPlayer) {
					SetupLocalPlayer ();
				} else {
					SetupOtherPlayer ();
				}
				yield break;
			} else {
				yield return new WaitForSeconds (0.1f);
			}
		}
	}
    public override void OnStartAuthority()
    {
        base.OnStartAuthority();
        StartCoroutine(AddPlayerAndSetupCourutine());
    }

    public override void OnClientExitLobby ()
	{
		base.OnClientExitLobby ();
	}
	public void SetupLocalPlayer(){
		CmdChangeName (NetworkLobbyManagerExtend._singleton.localplayerName);
		CmdChangeReady ("Not Ready");
		readyButton = GameObject.Find ("ReadyButton").GetComponent<Button>();
		readyButton.onClick.RemoveAllListeners ();
		readyButton.onClick.AddListener (OnReadyClicked);
		if (nameText.text.Equals("")) {
			SyncOnName (names);
		}
		if (readyText.text.Equals ("")) {
			SyncOnReady (ready);
		}
	}

	public void SetupOtherPlayer(){
		SyncOnName (names);
		OnClientReady (false);	
	}

	public override void OnClientReady(bool readyState){
		if (readyState) {
			SyncOnReady ("Ready");
			//readyButton.colors = Color.gray;
		} else {
			SyncOnReady ("Not Ready");
			//readyButton.colors = Color.white;
		}
	}
	//hook, when all player change their's name, it is activated with syncVar in all networked player
	public void SyncOnReady(string ready){
		this.ready = ready;
		StartCoroutine (InputSyncData (readyText, ready));
	}
	public void SyncOnName(string name){
		this.names = name;
		StartCoroutine (InputSyncData (nameText, name));
	}
	public IEnumerator InputSyncData(Text text, string value){
		while (text == null) {
			//Text[] texts = LobbyPlayerList.singleton.userList[slot].GetComponentsInChildren<Text>();
			//nameText = texts[0];
			//readyText = texts[1];
			yield return new WaitForSeconds (0.1f);
		}
		text.text = value;
	}
		
	public void OnReadyClicked(){
		string innerready;
		if (readyText.text.Equals ("Not Ready")) {
			SendReadyToBeginMessage ();
			innerready = "Ready";
		} else {
			SendNotReadyToBeginMessage ();
			innerready = "Not Ready";
		}
		CmdChangeReady(innerready);
	}

	[Command]
	public void CmdChangeName(string name){
		if (!isServer)
			return;
		this.names = name;
	}
	[Command]
	public void CmdChangeReady(string ready){
		if (!isServer)
			return;
		this.ready = ready;
	}
	public void OnDestroy(){
		LobbyPlayerList.singleton.RemovePlayer (this);
	}
}
