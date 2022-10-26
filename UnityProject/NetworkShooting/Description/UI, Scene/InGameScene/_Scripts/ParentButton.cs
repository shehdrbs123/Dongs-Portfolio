using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
public abstract class ParentButton : MonoBehaviour, IPointerDownHandler,IPointerUpHandler {

	[HideInInspector]
	public GamePlayer player;
	public virtual void OnPointerDown (PointerEventData pEvent){}
	public virtual void OnPointerUp (PointerEventData pEvent){}
}
