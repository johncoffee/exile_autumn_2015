//
//  vmxAudioPlayer.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-06-09.
//
//  Contains one instance of AVAudioPlayer for iPod playback and one instance of AVPlayer for streaming playback.

#import <Foundation/Foundation.h>
#import "AVAudioPlayer+vmxExtension.h"

@interface vmxAudioPlayer : NSObject {
    AVAudioPlayer *player1;
    AVPlayer *player2;
}
@property(nonatomic,retain)AVAudioPlayer *player1;
@property(nonatomic,retain)AVPlayer *player2;
+(vmxAudioPlayer*)getInstance;
@end
