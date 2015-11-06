using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;


public class vmxManager {
	
	[DllImport("__Internal")]
	private static extern void _vmxShowMusicLibrary();
	
	public static void showMusicLibrary()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxShowMusicLibrary();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxPlay();
	
	public static void play()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxPlay();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxPause();
	
	public static void pause()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxPause();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxStop();
	
	public static void stop()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxStop();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxSkipToNextSong();
	
	public static void skipToNextSong()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxSkipToNextSong();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxSkipToPreviousSong();
	
	public static void skipToPreviousSong()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxSkipToPreviousSong();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxShowAudioToolbar();
	public static void showToolbar()
	{
		if(Application.platform == RuntimePlatform.IPhonePlayer)
			_vmxShowAudioToolbar();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxShowVeemixTagsInterface();
	public static void showVeemixTags() 
	{
		if ( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxShowVeemixTagsInterface();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxHideVeemixTagsInterface();
	public static void hideVeemixTags() 
	{
		if ( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxHideVeemixTagsInterface();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxUploadPlaylistToVeemix();
	public static void uploadPlaylist()
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxUploadPlaylistToVeemix();
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxSendEventID( int eventID );
	
	public static void sendEventID( int eventID )
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxSendEventID( (int)eventID );
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxSendGameID( int vmxGameID );
	
	public static void sendGameID( int vmxGameID )
	{
		if(Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxSendGameID( (int)vmxGameID );
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxSendYCoord( int vmxYCoord );
	public static void sendYCoord( int vmxYCoord )
	{
		if(Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxSendYCoord( (int)vmxYCoord );
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxFindSong (string sceneTitle);
	public static void findSong(string sceneTitle)
	{
		if( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxFindSong(sceneTitle);
		
	}
	
	[DllImport("__Internal")]
	private static extern void _vmxPassMoodTags (string moodsString, int sizeOfTagList, string sceneTitle);
	
	public static void passMoodTags(string moodsString, int sizeOfTagList, string sceneTitle)
	{
		if ( Application.platform == RuntimePlatform.IPhonePlayer )
			_vmxPassMoodTags(moodsString,sizeOfTagList,sceneTitle);
	}

	[DllImport("__Internal")]
	private static extern void _vmxShowStreamPanel (bool showStreamPanel);
	public static void showStreamPanel (bool showStreamPanel)
	{
		if (Application.platform == RuntimePlatform.IPhonePlayer)
			_vmxShowStreamPanel (showStreamPanel);
	}
	
}
