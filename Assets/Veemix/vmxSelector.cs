using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;

public class vmxSelector : MonoBehaviour {
	
	public static event Action<string> vmxTagToggleEvent;
	public static event Action<string> vmxGestureToggleEvent;
	public static event Action<string> takeScreenshotEvent;
	
	void Awake()
	{
		gameObject.name = this.GetType().ToString();
		DontDestroyOnLoad( this );
	}
	
	public void vmxTagToggle( string tag )
	{
		if ( vmxTagToggleEvent != null )
			vmxTagToggleEvent( tag );
		
	}
	
	public void vmxGestureToggle (string gesture)
	{
		if (vmxGestureToggleEvent != null )
			vmxGestureToggleEvent( gesture );
		
	}
	
	public void takeScreenshot (string eventID) 
	{
		if ( takeScreenshotEvent != null )
			takeScreenshotEvent(eventID);
	}
	
	public void orientationChange ()
	{
		Debug.Log( "Orientation has changed");	
	}
	
}
