using System;
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Threading;
using System.ComponentModel;

public class VeemixPlayer : MonoBehaviour {
    public const int vmxGameID = 09560971; //This is the game's unique ID which is required for playlist sharing. Developers will receive an email from Veemix containing their unique game ID.
    public int eventID;
    public vmxEventManager eventManager;
    public String sceneTitle;
    public List<string> tagList;

    // Use this for initialization
    void Start () {
        eventManager.setIfSearch(true);
        eventManager.setIfGesture(false);
        eventManager.setUseVeemix(true); //Developer can make their own button/toggle to enable or disable Veemix from their in-game menu.
        vmxManager.sendGameID(vmxGameID);
        vmxManager.showStreamPanel(true);


        vmxManager.sendEventID(eventID);

        if (eventManager.checkIfSearch() && eventManager.checkIfUseVeemix())
        {
            var sizeOfTagList = tagList.Count;
            string moodsString = string.Join(",", tagList.ToArray());
            vmxManager.passMoodTags(moodsString, sizeOfTagList, sceneTitle);
            vmxManager.showVeemixTags();
        }
        else
        {
            StartCoroutine(FileIOCoroutine());

        }

    }

    IEnumerator FileIOCoroutine()
    {
        var extractSong = new ThreadedAction(findSongToPlay);
        yield return StartCoroutine(extractSong.WaitForComplete());
    }

    void findSongToPlay()
    {
        vmxManager.findSong(sceneTitle);
    }

}
