//
//  vmxGamePlaylist.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-06-12.
//
//  The view controller that displays the Veemix events and game screenshots in a UITableView. Cell selection pushes the vmxGamePlaylistSongs ViewController, which shows the songs associated with a Veemix event.

#import <UIKit/UIKit.h>
#import "PlaylistData.h"
#import "vmxGamePlaylistSongs.h"
@interface vmxGamePlaylist : UITableViewController
@property (nonatomic,retain) NSArray *vmxSongs;
@property (nonatomic,retain) NSMutableArray *eventArray;
@property (nonatomic,retain) NSMutableArray *playlistSongs;
@property (nonatomic,retain) NSMutableDictionary *eventDictionary;
@property (nonatomic, retain) NSMutableArray *validArray;
@property (nonatomic, retain) id delegate;

@end
