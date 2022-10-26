using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class UserInfoButton: ParentButton{
	//[HideInInspector]
	public Transform target;//GamePlayer에서 초기화
	//[HideInInspector]
	public bool isPressed;
	private RectTransform HealthBar;
	private float maxHealth;
	public void init(Transform target){
		this.target = target;
		HealthBar = transform.GetChild(0).GetComponent<RectTransform>();
		HealthBar.sizeDelta = new Vector2 (160, HealthBar.rect.height);
		maxHealth = HealthBar.rect.width;
		transform.GetChild (1).GetComponent<Text> ().text = target.gameObject.GetComponent<GamePlayer> ().nickname;
	}
	public override void OnPointerDown (PointerEventData pEvent){ }

	public void SyncHealthBar(int Health){
		HealthBar.sizeDelta = new Vector2 (maxHealth * Health / 1000, HealthBar.rect.height);
	}

}
