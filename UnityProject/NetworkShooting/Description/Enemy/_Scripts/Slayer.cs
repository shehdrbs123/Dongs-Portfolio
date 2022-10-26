using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class Slayer : EnemyObject {
	int repeat = 0;
	public Transform target;
	// Use this for initializatio
	Vector3 lookAtTarget;
	Vector2 DirectionVelocity;
	void Awake(){
		lookAtTarget = transform.up;
		DirectionVelocity = new Vector2 (0, -1);
	}
	[Command]
	protected void CmdFire2(int bulletIndex){ 
		if (target != null) {
			if (transform.position.y >= 0) {
				if(repeat == 0)
					lookAtTarget = FollowBullet (target, gameObject.GetComponent<Transform> (), out DirectionVelocity);
			} else {
				lookAtTarget = new Vector3 (0, 0, 180);
				DirectionVelocity = new Vector2(0,-1);
			}
		}

		CmdFire (0, 0, lookAtTarget, DirectionVelocity);
	}

	void Update(){
		if (!isServer)
			return;
		// 고칠 필요가 다분, 왜 이렇게 해놧엇지, 추가 변수 쓰기 싫어서 그랫던거 같음
		if (Time.time > nextFire) {
			CmdFire2 (0);
			if (repeat < 2) {
				nextFire = Time.time + delayFire;
				repeat +=1;
			} else {
				nextFire = Time.time + 2.5f;
				repeat = 0;
			}
		}
	}
}
