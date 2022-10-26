using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LobbyPlayerList : MonoBehaviour {
	public static LobbyPlayerList singleton = null;

	public RectTransform [] userList = new RectTransform[4];
	// Use this for initialization
	void Start(){
		singleton = this;
	}
		
	private bool ContainInLobbyPlayer(LobbyPlayer player,out int emptyNum){
		int empty = 3;
		for (int i = 0; i < 4; i++) {
			if (userList [i] != null) {
				if (userList [i].GetComponentInChildren<LobbyPlayer> () == null) {
					if (empty > i)
						empty = i;
					continue;
				}
				if (userList [i].GetComponentInChildren<LobbyPlayer> () == player) {
					emptyNum = i;
					return true;
				}
			}
		}
		emptyNum = empty;
		return false;
	}
	public void AddPlayer(LobbyPlayer player){
		int emptyNum=3;
		if (ContainInLobbyPlayer (player,out emptyNum))
			return;
		if (player.slot < 0)
			player.slot = (byte)emptyNum;
		DontDestroyOnLoad (player.transform.gameObject);
		Text[] userInfoText = userList [player.slot].GetComponentsInChildren<Text> ();
		player.nameText = userInfoText [0];
		player.readyText = userInfoText [1];
	
	}
	public void RemovePlayer(LobbyPlayer player){
		if (player.nameText != null) {
			player.nameText.text = "";
		}
		if (player.readyText != null) {
			player.readyText.text = "";		
		}
	}

	public void RpcResetUserUI(LobbyPlayer player){
		
	}
}