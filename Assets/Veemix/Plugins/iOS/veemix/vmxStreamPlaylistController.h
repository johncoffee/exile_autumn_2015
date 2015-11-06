//
//  vmxStreamPlaylistController.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-08-22.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "vmxSelector.h"
#import "vmxSharedStreamPlaylists.h"
#import "PlaylistData.h"
#import "Reachability.h"

typedef enum {
    vmxStreamPlaylistController_MyVeemixPlaylist,
    vmxStreamPlaylistController_SharedPlaylists
} vmxStreamPlaylistControllerIndex;

@interface vmxStreamPlaylistController : NSObject <UITableViewDataSource, UITableViewDelegate> {
    NSMutableData *_responseData;
    NSMutableDictionary *sharedPlaylistDictionary;
}

@property (nonatomic, retain) id delegate;

@property (nonatomic, assign) vmxStreamPlaylistControllerIndex selectedTabIndex;

@property (nonatomic, retain, readonly) UIViewController *viewController;

@property (nonatomic, retain) NSMutableDictionary *sharedPlaylistDictionary;

@end

@protocol vmxStreamPlaylistControllerDelegate <NSObject, UITableViewDelegate, UITableViewDataSource>
@optional

-(void)vmxStreamPlaylistControllerDidDone:(vmxStreamPlaylistController *)playlistController;
@end
