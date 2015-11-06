//
//  PersistentIDClass.h
//  
//
//  Created by Alexander Hodge on 2013-03-16.
//
//  This class is a model for a song's persistent ID within the iPod library and a query to fetch it.

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@interface PersistentIDClass : NSObject
{
    NSString *pID;
    MPMediaQuery *vmxSongQuery;
}
@property(nonatomic, retain)NSString *pID;
@property(nonatomic, retain)MPMediaQuery *vmxSongQuery;
+(PersistentIDClass*)getInstance;
@end
