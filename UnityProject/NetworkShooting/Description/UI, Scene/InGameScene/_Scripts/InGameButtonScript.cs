using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class InGameButtonScript : NetworkBehaviour {
	[HideInInspector]
	private NetworkLobbyManagerExtend lobbyManager;
	public GameObject[] UI = new GameObject[3];
	public enum UINAME{
		MAIN_UI,DIALOG_UI,PAUSE_UI
	};
	public delegate void exitdelegate();
	private exitdelegate exit;
	void Start(){
		lobbyManager = NetworkLobbyManagerExtend._singleton;
	}

	public void SetPausePanel(InGameButtonScript.UINAME uiName,bool active)
    {
		UI[(int)uiName].SetActive(active);
	}

	public void OnPressPauseButton()
	{
		SetPausePanel(UINAME.PAUSE_UI, true);
	}

	public void OnPressContinue()
    {
		SetPausePanel(UINAME.PAUSE_UI, false);
	}

	public void OnPressExitButton()
    {
		if (!isServer)
			lobbyManager.StopClient();
		else
			lobbyManager.StopHost();
	}
}
