//
//  vmxPlaylistController.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-25.
//
//  A container for vmxGamePlaylist.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "vmxSelector.h"
#import "vmxSharedPlaylists.h"
#import "PlaylistData.h"
#import "Reachability.h"

typedef enum {
    vmxPlaylistController_MyVeemixPlaylist,
    vmxPlaylistController_SharedPlaylists
} vmxPlaylistControllerIndex;

@interface vmxPlaylistController : NSObject <UITableViewDataSource, UITableViewDelegate> {
    NSMutableData *_responseData;
    NSMutableDictionary *sharedPlaylistDictionary;
}

@property (nonatomic, retain) id delegate;

@property (nonatomic, assign) vmxPlaylistControllerIndex selectedTabIndex;

@property (nonatomic, retain, readonly) UIViewController *viewController;

@property (nonatomic, retain) NSMutableDictionary *sharedPlaylistDictionary;

@end

@protocol vmxPlaylistControllerDelegate <NSObject, UITableViewDelegate, UITableViewDataSource>
@optional

-(void)vmxPlaylistControllerDidDone:(vmxPlaylistController *)playlistController;
@end
