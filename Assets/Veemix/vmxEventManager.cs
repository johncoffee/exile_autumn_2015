using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Xml;
using System.Threading;
using System.ComponentModel;
public class vmxEventManager : MonoBehaviour {

	public bool useVeemix;
	public bool tagSearching;
	public bool gestureToggle;
	private string myEvent;
	
	public vmxEventManager ()
	{
	}
	
	public bool checkIfUseVeemix(){
		return useVeemix;
	}
	public bool checkIfSearch(){
		return tagSearching;
	}
	
	public bool checkIfGesture(){
		return gestureToggle;	
	}
	
	public void setUseVeemix (bool useBool){
		useVeemix = useBool;
	}

	public void setIfSearch (bool searchBool){
		tagSearching = searchBool;
	}
	
	public void setIfGesture (bool gestureBool){
		gestureToggle = gestureBool;
	}
	
	public void goScreenshot(string eventID)
	{
		myEvent = eventID;
		StartCoroutine(ScreenshotCoroutine());
	}
	
	void TakeScreenshot() {
		string filename = (myEvent +"screenshot" + ".png");
		Application.CaptureScreenshot(filename);
	}
	
	IEnumerator ScreenshotCoroutine() {
		var screengrab = new ThreadedAction(TakeScreenshot);
		yield return StartCoroutine(screengrab.WaitForComplete());
		
	}
}
