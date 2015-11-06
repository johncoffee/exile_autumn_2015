//
//  PlaylistData.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-03-15.
//
//  This class is the model for the Veemix playlist which associates iPod songs with the event ID within the Unity scene.

#import <Foundation/Foundation.h>
#import "vmxSelector.h"

@interface PlaylistData : NSObject {
    NSNumber *gameID;
    NSMutableDictionary *sharedPlaylistDictionary;
    NSMutableArray *vmxArray;
    MPMediaItemCollection *vmxCollection;
    NSMutableDictionary *vmxDictionary;
    MPMediaItemCollection *playlist;
    NSMutableArray *playlistEvents;
    NSMutableArray *sceneTitle;
    NSMutableString *selectedEvent;
    MPMediaItem *currentItem;
    NSURL *currentURL;
    NSMutableArray *eventURLArray;
    NSMutableDictionary *buildDict;
    
    NSNumber *yCoord;
    
    NSMutableString *suggestion;
    
    NSMutableString *currentStream;
    NSMutableDictionary *streamDictionary;
    
    NSMutableArray *streamArray;
    
    NSMutableString *nowPlayingArtist;
    NSMutableString *nowPlayingTitle;
    UIImage *nowPlayingArtwork;
    
    NSMutableString *showStreamPanel;
}

@property(nonatomic, retain)NSNumber *yCoord;

@property(nonatomic, retain)NSNumber *gameID;
@property(nonatomic, retain)NSMutableDictionary *sharedPlaylistDictionary;
@property(nonatomic, retain)NSMutableArray *vmxArray;
@property(nonatomic, retain)MPMediaItemCollection *vmxCollection;
@property(nonatomic, retain)NSMutableDictionary *vmxDictionary;
@property(nonatomic, retain)MPMediaItemCollection *playlist;
@property(nonatomic, retain)NSMutableArray *playlistEvents;
@property(nonatomic, retain)NSMutableArray *sceneTitle;
@property(nonatomic, retain)NSMutableString *selectedEvent;
@property(nonatomic, retain)MPMediaItem *currentItem;
@property(nonatomic, retain)NSMutableArray *eventURLArray;
@property(nonatomic, retain)NSMutableDictionary *buildDict;
@property(nonatomic, retain)NSURL *currentURL;

@property(nonatomic, retain)NSMutableString *suggestion;
@property(nonatomic, retain)NSMutableString *currentStream;
@property(nonatomic, retain)NSMutableDictionary *streamDictionary;
@property(nonatomic,retain)NSMutableArray *streamArray;

@property(nonatomic,retain)NSMutableString *nowPlayingArtist;
@property(nonatomic,retain)NSMutableString *nowPlayingTitle;
@property(nonatomic,retain)UIImage *nowPlayingArtwork;
@property(nonatomic, retain)NSMutableString *showStreamPanel;

+(PlaylistData*)getInstance;

@end
