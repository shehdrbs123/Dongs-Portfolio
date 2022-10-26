using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UserUIButtonMon : MonoBehaviour {

	private static UserInfoButton[] button;

	void Start(){
		button = new UserInfoButton[3];
		button [0] = transform.GetChild (0).GetComponent<UserInfoButton> ();
		button [1] = transform.GetChild (0).GetComponent<UserInfoButton> ();
		button [2] = transform.GetChild (0).GetComponent<UserInfoButton> ();
	}
}
