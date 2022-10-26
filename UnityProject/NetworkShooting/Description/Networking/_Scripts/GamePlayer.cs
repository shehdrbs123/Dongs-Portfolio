using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
public class GamePlayer : MoveObject {

	// Use this for initialization
	[HideInInspector]
	[SyncVar]
	public string nickname;
	//movement

	[HideInInspector]
	public int xInput;
	private float boundary=2.5f;

	//defaultPos
	[SyncVar]
	public Vector3 playerDefaultPos;

	public RectTransform HPBar;

	private delegate void otherHealthUI(int health);
	private otherHealthUI otherHealth;

	public UserInfoButton userInfoButton;
	void Start(){
		if(!isLocalPlayer)
			SetupOtherPlayer();
	}
	public override void OnStartAuthority ()
	{
		base.OnStartAuthority ();
		if (isLocalPlayer) {
			SetupLocalPlayer ();
		}
	}

	private void SetupLocalPlayer (){
		Camera camera = Camera.main;
		camera.transform.position = new Vector3 (playerDefaultPos.x, camera.transform.position.y, camera.transform.position.z);
		GameObject[] buttons = GameObject.FindGameObjectsWithTag ("Button");
		foreach (GameObject j in buttons) {
			if (j.GetComponent<ParentButton> () != null) {
				j.GetComponent<ParentButton> ().player = this;
			}
		}
		HPBar = GameObject.Find("remainHp").GetComponent<RectTransform>();
	}
	private void SetupOtherPlayer(){//다른 유저의 정보는 UI 정보버튼에 등록.
		GameObject[] buttons = GameObject.FindGameObjectsWithTag ("Button");
		foreach (GameObject i in buttons) {
			UserInfoButton userui = i.GetComponent<UserInfoButton> ();//UI 정보 버튼
			if (userui != null && userui.target == null) {// UI 정보버튼을 불러왔고, target이 정해져있지 않을때(타 유저 정보가 등록됨);
				userui.init (this.GetComponent<Transform>());
				otherHealth = userui.SyncHealthBar;//유저정보에 표기되는 HPGauge 변경 함수를 otherhealth 델리게이트에 등록
													// 이제 유저가 피해를 입었을 때 로컬유저가 아니면 자동으로 UI의 hp게이지를 조절함. 
				return;
			}
		}
	}


	protected override void OnDeath ()
	{ 
		CmdGameOverSet ();
	}
	[Command]
	public void CmdGameOverSet(){
		if (!isServer)
			return;
		NetworkServer.UnSpawn (gameObject);
		TableSetter.singleton.userDeath +=1;
		Destroy(gameObject);
	}
	protected override void SetHealthBar (int health){
		if (isLocalPlayer) {
			HPBar.sizeDelta = new Vector2 (health, HPBar.rect.height);
		} else {
			otherHealth (health);
		}

	}

	// Update is called once per frame
	void Update () {
		if (!isLocalPlayer) {
			return;
		}
		var x = xInput * movespeed *Time.deltaTime;
		transform.Translate (x, 0, 0);
		transform.position = new Vector3(Mathf.Clamp (transform.position.x, -boundary+playerDefaultPos.x, boundary+playerDefaultPos.x), playerDefaultPos.y, 0);
		if (Time.time > nextFire) {
			nextFire = Time.time + delayFire;
			CmdFire (0,0,bulletSpawn[0].eulerAngles,bulletSpawn[0].up);
		}
	}
}
