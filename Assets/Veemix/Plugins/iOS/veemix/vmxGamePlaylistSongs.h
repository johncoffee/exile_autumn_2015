//
//  vmxGamePlaylistSongs.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-06-14.
//
//  Detail view for the Veemix playlist, showing songs associated with a given event ID.

#import <UIKit/UIKit.h>
#import "PlaylistData.h"
#import "BuyButton.h"

@interface vmxGamePlaylistSongs : UITableViewController

@property (nonatomic,retain) NSMutableDictionary *eventDictionary;
@property (nonatomic, retain) NSMutableArray *songArray;
@property (nonatomic, retain) MPMediaItemCollection *detailCollection;
@property (nonatomic, retain) NSMutableArray *detailArray;
@property (nonatomic, retain) UILabel *noSongsLabel;
@end
