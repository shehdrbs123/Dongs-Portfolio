using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class MoveButton : ParentButton{

	void Awake(){}
	public int direction;
	public override void OnPointerDown(PointerEventData pEvent){
		if (player == null) return;
		player.xInput = direction;
	}

	public override void OnPointerUp(PointerEventData pEvent){
		if (player == null)
			return;
		player.xInput = 0;
	}
}