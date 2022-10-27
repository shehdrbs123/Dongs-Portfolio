using System.Collections;    
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using System.Net;
public class ConnectSceneButtonScript : MonoBehaviour {
	[HideInInspector]
	public NetworkLobbyManagerExtend lobbyManager;
	public RectTransform[] UI = new RectTransform[5];
	[HideInInspector]
	public RectTransform presentUI;

	private const int UI_MAIN = 0;
	private const int UI_HOST = 1;
	private const int UI_CLI = 2;
	private const int UI_WAIT = 3;
	private const int UI_POP = 4;
	void Start(){
		lobbyManager = (NetworkLobbyManagerExtend)NetworkLobbyManagerExtend.singleton;
		lobbyManager.ui = this;
		presentUI = UI [UI_MAIN];
	}
	private delegate void exitButtonDelegate();
	private exitButtonDelegate exitDelegate;

	public void UIChangeTo(char name){
		if (presentUI != null) {
			presentUI.gameObject.SetActive (false);
		}
		int num = 0;
		switch (name)
		{
			case 'm' : num = 0;
				break;
			case 'h':  num = 1;
				break;
			case 'c':  num = 2;
				break;
			case 'w':  num = 3;
				break;
			case 'p':  num = 4;
				break;
		}
		presentUI = UI[num];
		if (presentUI != null) {
			presentUI.gameObject.SetActive (true);
		}
	}

	//button method

	public void OnClickToConnectionPanel(){
		UIChangeTo ('c');
	}
	public void OnClickToHostPanel(){
		UIChangeTo('h');
	}

	public void OnClickCreateHost(){
		InputField[] inputField = UI [UI_HOST].GetComponentsInChildren<InputField> ();
		try{
			string playerName = inputField[0].GetComponentsInChildren<Text>()[1].text;
			int port = int.Parse(inputField[1].GetComponentsInChildren<Text>()[1].text);
			lobbyManager.StartHost(playerName, port);
			if(NetworkServer.active){
				UIChangeTo ('w');
				setupWaitroom();
			}
		}catch(System.Exception e){
			Debug.Log (e.GetBaseException ());
		}
	
	}
	public void OnClickClientConnect(){
		InputField[] inputField = UI [UI_CLI].GetComponentsInChildren<InputField> ();
		try{
			string playerName = inputField [0].GetComponentsInChildren<Text>()[1].text;
			string ip = inputField [1].GetComponentsInChildren<Text> ()[1].text;
			int port = int.Parse (inputField [2].GetComponentsInChildren<Text> ()[1].text);
			lobbyManager.StartClient(playerName, ip,port);
			if(NetworkClient.active){
				UIChangeTo ('w');
				setupWaitroom();
			}
		}catch(System.Exception e){
			Debug.Log (e.StackTrace);
		}
	}
	public void setupWaitroom(){
		Text[] serverInfo = UI [UI_WAIT].Find("RoomInfo").GetComponentsInChildren<Text>();
		serverInfo[0].text = "Server : " + GetNetworkAddress() + ":" + lobbyManager.networkPort;
		if (NetworkServer.active) 
			exitDelegate = lobbyManager.StopHost;
		else
			exitDelegate = lobbyManager.StopClient;
	}

	public string GetNetworkAddress()
	{
		if (NetworkServer.active)
		{
			var host = Dns.GetHostEntry(Dns.GetHostName());
			foreach (var ip in host.AddressList)
			{
				if (ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork)
				{
					return ip.ToString();
				}
			}
			//https://www.delftstack.com/ko/howto/csharp/get-local-ip-address-in-csharp/
		}
		return lobbyManager.networkAddress;
		
	}
	//출처: https://blog.edit.kr/entry/C-사설-공인-IP-구하기-Internal-External-IP-Address [소금인형 - SW개발자?:티스토리]
	public void OnClickExitToMain(){
		if (presentUI == UI [UI_WAIT]) {
			if (lobbyManager.isNetworkActive) {
				exitDelegate ();
			}
		}
		UIChangeTo('m');
	}

}
