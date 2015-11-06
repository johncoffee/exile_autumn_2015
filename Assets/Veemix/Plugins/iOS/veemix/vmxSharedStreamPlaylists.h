//
//  vmxSharedStreamPlaylists.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-08-23.
//
//

#import <UIKit/UIKit.h>
#import "PlaylistData.h"

@interface vmxSharedStreamPlaylists : UITableViewController <UITableViewDataSource, UITableViewDelegate> {
    NSMutableData *_responseData;
    NSMutableDictionary *sharedPlaylistDictionary;
    NSMutableDictionary *theNewPlaylist;
}

@property (nonatomic, retain) NSMutableDictionary *sharedPlaylistDictionary;
@property (nonatomic, retain) NSMutableDictionary *theNewPlaylist;

@end