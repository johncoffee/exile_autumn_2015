//
//  vmxSharedPlaylists.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-25.
//
//  Fetches and displays the shared playlists for the current game from veemix.com.

#import <UIKit/UIKit.h>
#import "PlaylistData.h"

@interface vmxSharedPlaylists : UITableViewController <UITableViewDataSource, UITableViewDelegate> {
    NSMutableData *_responseData;
    NSMutableDictionary *sharedPlaylistDictionary;
    NSMutableDictionary *theNewPlaylist;
}

@property (nonatomic, retain) NSMutableDictionary *sharedPlaylistDictionary;
@property (nonatomic, retain) NSMutableDictionary *theNewPlaylist;

@end
