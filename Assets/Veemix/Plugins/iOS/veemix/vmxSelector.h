//
//  vmxSelector.h
//
//
//  Created by Alexander Hodge on 2013-08-01.
//  Copyright (c) 2013 Alexander Hodge. All rights reserved.
//
//
//  vmxSelector is the control center for all of the Veemix functions. It is also responsible for drawing all content on top of the Unity game scene. See methods below for a more detailed description.

#import <Foundation/Foundation.h>
#import "EventClass.h"
#import "PersistentIDClass.h"
#import "PlaylistData.h"
#import "UserData.h"
#import "slidePanel.h"
#import "vPanel.h"
#import "playlistTitleDesc.h"
#include <AVFoundation/AVFoundation.h>
#import <dispatch/dispatch.h>
#import "vmxAudioPlayer.h"
#import "AVAudioPlayer+vmxExtension.h"
#import "vmxGamePlaylist.h"
#import "AutoScrollLabel.h"
#import "LoginPanel.h"
#import "vmxPlaylistController.h"

#import "Reachability.h"

#import "streamPanel.h"

    
@interface vmxSelector : NSObject <UITextViewDelegate, UIPopoverControllerDelegate, NSURLConnectionDelegate, slidePanelDelegate, AVAudioPlayerDelegate, vPanelDelegate , streamPanelDelegate, MPMediaPickerControllerDelegate> {
    NSTimer *timer;
	UIViewController *_viewControllerWrapper;
    NSMutableArray *tempArray, *songURLArray, *tempStreamArray;
    NSMutableDictionary *buildDict, *query, *tempDict;
    NSMutableData *_responseData;
    slidePanel *flipView;
    vPanel *vPanelView;
    NSString *encounteredTag;
    NSString *encounteredStream;
    UIImage *audioControl;
    UIImageView *imageHolder;
    dispatch_queue_t backgroundQueue;
    BOOL isAudioToolBarShowing;
    BOOL isVeemixTagInterfaceShowing;
    
    Reachability *isReachable;
    
    streamPanel *myStreamPanel;
    BOOL isStreamPanelShowing;
    
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, retain) NSMutableArray *tempArray;
@property (nonatomic, retain) NSMutableDictionary *tempDict;
@property (nonatomic,retain) NSMutableArray *songURLArray;
@property (nonatomic, retain) NSMutableDictionary *buildDict;
@property(nonatomic, retain) NSMutableDictionary *query;
@property(nonatomic, retain) slidePanel *flipView;
@property(nonatomic, retain) vPanel *vPanelView;
@property(nonatomic, retain) NSString *encounteredTag;
@property(nonatomic, retain) NSString *encounteredStream;
@property (nonatomic, retain) UIImage *audioControl;
@property (nonatomic, retain) UIImageView *imageHolder;

@property (nonatomic, retain) UIView *suggestionView;

@property (nonatomic, retain) streamPanel *myStreamPanel;

@property(nonatomic,retain)NSMutableArray *tempStreamArray;

@property(nonatomic, retain)AVPlayer *streamPlayer;



+ (vmxSelector*)Veemix;

- (void)hideTitleDesc; //dismiss the modal popover for playlist Name/Description/Upload.
- (void)showRegisterPanel; //shows the Register view.
- (void)showMusicLibrary; //shows the iPod media picker.
- (void)play; //Plays the current song.
- (void)pause; //Pauses the current song.
- (void)stop; //Stops the current song, sets current track time to start of track.
- (void)skipToNextSong; //Skip to next song for the current event within the Veemix playlist.
- (void)skipToPreviousSong; // Skips to the previous song for the current event within the Veemix playlist.
- (void)savePlaylist:(MPMediaItemCollection*) mediaItemCollection; //Saves a playlist based on a collection of MPMediaItems.
- (void)saveEvents:(NSMutableArray*) newSongs; //Saves to the Veemix playlist an iPod song's Persistent ID and the current event ID.
- (void)saveVeemix:(NSMutableArray*) veemixSongs; //Saves the XML playlist file that gets uploaded.
- (void)showToolbar; //Displays the Veemix toolbar.
- (void)showVeemixTags; //Shows the tag icon when a tagged area is encountered.
- (void)hideVeemixTags; //Hides the tag icon when the player leaves the tagged area.
- (void)uploadPlaylist; //Uploads playlist to veemix.com
- (void)sendEventID:(int) eventID; //Receives the event ID from Unity when a player encounters an event.
- (void)receiveMoodTagString:(NSString *)vmxMoodString receiveMoodSize:(int)vmxMoodSize receiveSceneTitle:(NSString *)vmxSceneTitle; //Receives the mood tag information from Unity.
-(void)findSong:(NSString *)pID; //Finds a song in the iPod libray with the persistent ID.

-(void)buildPlayer;

-(void)showLoginPanel;

-(void)playStream;

-(void)updateNowPlayingArtist:(NSString *)getNowPlayingArtist updateNowPlayingTitle:(NSString *)getNowPlayingTitle updateNowPlayingArtwork:(UIImage *)getNowPlayingArtwork;

@end
