using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class NetworkLobbyManagerExtend : NetworkLobbyManager
{


	public static NetworkLobbyManagerExtend _singleton = null;
	public ConnectSceneButtonScript ui { set; get; }
	public string localplayerName { private set; get; }
	void Start()
	{
		_singleton = this;
	}

	//server	

	public override bool OnLobbyServerSceneLoadedForPlayer(GameObject lobbyPlayer, GameObject gamePlayer)
	{
		base.OnLobbyServerSceneLoadedForPlayer(lobbyPlayer, gamePlayer);
		GamePlayer gamePlayerIns = gamePlayer.GetComponent<GamePlayer>();
		gamePlayerIns.nickname = lobbyPlayer.GetComponent<LobbyPlayer>().names;
		Vector3 playerDefaultPos = new Vector3(lobbyPlayer.GetComponent<LobbyPlayer>().slot * 15, -3.0f, 0);
		gamePlayerIns.playerDefaultPos = playerDefaultPos;
		gamePlayer.transform.position = playerDefaultPos;
		return true;
	}

	public override void OnLobbyServerSceneChanged(string sceneName)
	{
		base.OnLobbyServerSceneChanged(sceneName);
		if (SceneManager.GetActiveScene().name == lobbyScene)
		{
			if (NetworkServer.connections.Count != 0)
			{
				ui.UIChangeTo('m');
				ui.setupWaitroom();
			}
		}
		else
		{
			DefaultSetting();
		}
	}
	//Client

	public override void OnLobbyClientSceneChanged(NetworkConnection conn)
	{
		base.OnLobbyClientSceneChanged(conn);
		if (SceneManager.GetActiveScene().name == lobbyScene)
		{
			if (IsClientConnected())
			{
				ui.UIChangeTo('w');
				ui.setupWaitroom();
			}
			else
			{
				ui.UIChangeTo('m');
			}
		}
		else
		{
			DefaultSetting();
		}
	}

	public void DefaultSetting()
	{
		GameObject[] players = GameObject.FindGameObjectsWithTag("Player");
		GameObject[] buttons = GameObject.FindGameObjectsWithTag("Button");
		GamePlayer gamePlayer;
		foreach (GameObject i in players)
		{
			gamePlayer = i.GetComponent<GamePlayer>();
			if (gamePlayer.isLocalPlayer)
			{
				foreach (GameObject j in buttons)
				{
					if (j.GetComponent<ParentButton>() != null)
					{
						j.GetComponent<ParentButton>().player = gamePlayer;
					}
				}
				gamePlayer.HPBar = GameObject.Find("remainHp").GetComponent<RectTransform>();
				break;
			}
		}
	}

	public NetworkClient StartHost(string name, int port)
    {
		localplayerName = name;
		networkPort = port;
		return StartHost();
    }

	public NetworkClient StartClient(string name, string ip, int port)
    {
		localplayerName = name;
		networkAddress = ip;
		networkPort = port;
		return StartClient();
    }

	public override void OnLobbyClientDisconnect(NetworkConnection conn)
	{
		base.OnLobbyClientDisconnect(conn);
		ui.UIChangeTo('m');
	}

	public override void OnClientError(NetworkConnection conn, int errorCode)
	{
		base.OnClientError(conn, errorCode);
		ui.UIChangeTo('m');
	}
}
