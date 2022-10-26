using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyObject : MoveObject {
	protected int gaugeValue=50;
	protected override void OnDeath ()
	{
		if (!TableSetter.singleton.isGaugeFull) {
			TableSetter.singleton.CrisisGauge += gaugeValue;
		}
		Destroy (this.gameObject);
	}
	protected Vector3 FollowBullet(Transform target ,Transform currentPos,out Vector2 Directionvelocity){
		float deltaX = currentPos.position.x - target.position.x;
		float deltaY = currentPos.position.y - target.position.y;
		Directionvelocity = -(new Vector2 (deltaX, deltaY).normalized);
		return new Vector3 (0, 0, Mathf.Atan2 (deltaY, deltaX) * 180 / Mathf.PI + 90);
	}
}
