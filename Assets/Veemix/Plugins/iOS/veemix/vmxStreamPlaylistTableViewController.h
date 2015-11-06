//
//  vmxStreamPlaylistTableViewController.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-07-15.
//
//

#import <UIKit/UIKit.h>
#import "PlaylistData.h"
#import "vmxGamePlaylistSongs.h"
@interface vmxStreamPlaylistTableViewController : UITableViewController
@property (nonatomic,retain) NSArray *vmxSongs;
@property (nonatomic,retain) NSMutableArray *eventArray;
@property (nonatomic,retain) NSMutableArray *playlistSongs;
@property (nonatomic,retain) NSMutableDictionary *eventDictionary;
@property (nonatomic, retain) NSMutableArray *validArray;
@property (nonatomic, retain) id delegate;

@end
