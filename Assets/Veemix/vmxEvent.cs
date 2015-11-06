using System;
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Threading;
using System.ComponentModel;

public class vmxEvent : MonoBehaviour {
	
	public const int vmxGameID = 09560971; //This is the game's unique ID which is required for playlist sharing. Developers will receive an email from Veemix containing their unique game ID.
	public const int vmxYCoord = 0; //This integer determines where on the Y axis the Veemix audio toolbar and tagging interface appear.
	public int eventID;
	public vmxEventManager eventManager;
	public String sceneTitle;
	public bool areaTrigger;
	public List<string> tagList;
	public GameObject playerObject;
	public static int sizeOfTagList;
	private Vector2[] startPoint;
	private Vector2[] endPoint;
	private Vector2 midPoint;
	private bool strokeUp;
	private bool possibleV;
	private bool vRecognized;
	private int activeTouch = -1;
	private Vector2[] fingerTrackArray;
	
	void Start () {

		eventManager.setIfSearch(true);
		eventManager.setIfGesture(false);
		eventManager.setUseVeemix(true); //Developer can make their own button/toggle to enable or disable Veemix from their in-game menu.
		vmxManager.sendGameID(vmxGameID);
		vmxManager.sendYCoord(vmxYCoord);
		vmxManager.showStreamPanel (true); //Shows or hides the streaming information panel when a Veemix event is encountered while in streaming mode.
		fingerTrackArray = new Vector2[1];
		vRecognized = false;
		DontDestroyOnLoad(this);

	}
	
	void Update () {

		
	}
	
	void LateUpdate() {
		/*
		if(Input.touchCount == 1 && eventManager.checkIfGesture()) {
			print("vgesture called");
			vmxGesture();
		}
		*/
	}
	
	
	void vmxGesture() {



		foreach(Touch touch in Input.touches) {

			if(touch.phase == TouchPhase.Began) {

				activeTouch = -1;
				fingerTrackArray[touch.fingerId] = touch.position;
			}
			
			if(touch.phase == TouchPhase.Moved && (touch.position.x > fingerTrackArray[touch.fingerId].x) && (touch.position.y < fingerTrackArray[touch.fingerId].y) &&  activeTouch == -1) {

				activeTouch = touch.fingerId;	
				strokeUp = false;
				midPoint = fingerTrackArray[touch.fingerId];
				possibleV = true;
				
			} 
			
			else if (activeTouch == touch.fingerId && touch.phase == TouchPhase.Moved && (touch.position.x > midPoint.x) && (touch.position.y > midPoint.y) && possibleV == true) {

				strokeUp = true;
				vRecognized = true;
			} 
			
			else if (activeTouch == touch.fingerId && touch.phase == TouchPhase.Moved && (touch.position.x < midPoint.x )) {

				activeTouch = -1;
				strokeUp = false;
				possibleV = false;
				vRecognized = false;
				foreach(Touch touchReset in Input.touches) {
					fingerTrackArray[touchReset.fingerId] = touchReset.position;	
				}
			}
			
			if(activeTouch == touch.fingerId && touch.phase == TouchPhase.Ended && strokeUp == true && possibleV == true) {

				if(vRecognized == true && eventManager.checkIfUseVeemix()) {
					
					vGestureSuccess();
				}
				
				foreach(Touch touchReset in Input.touches) {
					fingerTrackArray[touchReset.fingerId] = touchReset.position;
				}
				activeTouch = -1;
				strokeUp = false;
				possibleV = false;
				vRecognized = false;
				
			}
		}
		
	}
	
	void vGestureSuccess(){
		vmxManager.showToolbar(); 
		
	}

	void eventOccurance(){
		
		if (eventManager.checkIfSearch() && eventManager.checkIfUseVeemix()){
			sizeOfTagList = tagList.Count;
			string moodsString = string.Join(",", tagList.ToArray());
			vmxManager.passMoodTags( moodsString , sizeOfTagList , sceneTitle);
			vmxManager.showVeemixTags();
		}
		else { 
			StartCoroutine(FileIOCoroutine());
			
		}
	}
	
	void OnGUI()
	{
		if (GUI.Button (new Rect (Screen.width/2-50, Screen.height-150, 250, 100), "Veemix toolbar"))
						vmxManager.showToolbar ();

	}
	
	bool checkIfUseVeemix(){
		return eventManager.checkIfUseVeemix();
	}
	bool checkIfSearch(){
		return eventManager.checkIfSearch();
		
	}
	
	bool checkIfGesture(){
		return eventManager.checkIfGesture();	
	}
	
	void OnTriggerEnter(Collider other) {
		
		print(other.name);
		if (( other.gameObject == playerObject) && areaTrigger && eventManager.checkIfUseVeemix()) {
			vmxManager.sendEventID( eventID );
			eventOccurance();
		}
	}
	
	void OnTriggerExit(Collider other) {
		
		if (( other.gameObject == playerObject) && areaTrigger && eventManager.checkIfUseVeemix()) {
			vmxManager.hideVeemixTags();
		}
	}
	
	void findSongToPlay(){
		vmxManager.findSong( sceneTitle );
	}

	IEnumerator FileIOCoroutine() {
		var extractSong = new ThreadedAction(findSongToPlay);
		yield return StartCoroutine(extractSong.WaitForComplete());
		
	}
	
}
