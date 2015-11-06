using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class vmxReceiver : MonoBehaviour {
	
	public vmxEventManager eventManager;

	void OnEnable()
	{
		vmxSelector.vmxTagToggleEvent += vmxTagToggleEvent;
		vmxSelector.vmxGestureToggleEvent += vmxGestureToggleEvent;;
		vmxSelector.takeScreenshotEvent += takeScreenshotEvent;
	}
	
	
	void OnDisable()
	{
		vmxSelector.vmxTagToggleEvent -= vmxTagToggleEvent;
		vmxSelector.vmxGestureToggleEvent -= vmxGestureToggleEvent;
		vmxSelector.takeScreenshotEvent -= takeScreenshotEvent;
	}
	
	
	
	void vmxTagToggleEvent ( string tag )
	{
		string toggle = tag.ToString();
		string a ="1";
		string b ="0";
		if(toggle.Equals(a)) {	
			eventManager.setIfSearch(true);
			Debug.Log( "Veemix tagging is ON. " );
			
		}
		if(toggle.Equals(b)) {
			eventManager.setIfSearch(false);
			Debug.Log( "Veemix tagging is OFF. " );
		}
		
	}
	
	void vmxGestureToggleEvent (string gesture )
	{
		string toggle = gesture.ToString();
		string a = "1";
		string b = "0";
		if(toggle.Equals(a)) {
			eventManager.setIfGesture(true);
			Debug.Log("V Gesture turned ON");
		}
		
		if(toggle.Equals(b)) {
			eventManager.setIfGesture(false);
			Debug.Log("V Gesture turned OFF");
		}
	}
	
	void takeScreenshotEvent( string eventID)
	{
		eventManager.goScreenshot(eventID);
	}
	
	
}
