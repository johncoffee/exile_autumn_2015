//
//  ExtendedAudioPlayer.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-06-09.
//
//  An extension of AVAudioPlayer that enables fading volume changes. Veemix uses a fade down on the outgoing track and a fade in on the new track to create the crossfade effect that occurs when a song change is made.

#import <AVFoundation/AVFoundation.h>

typedef void (^AVAudioPlayerFadeCompleteBlock)();


@interface AVAudioPlayer (vmxExtension)

@property (nonatomic,readonly) BOOL  fading;
@property (nonatomic,readonly) float fadeTargetVolume;

- (void) fadeToVolume:(float)volume duration:(NSTimeInterval)duration;
- (void) fadeToVolume:(float)volume duration:(NSTimeInterval)duration completion:(AVAudioPlayerFadeCompleteBlock)completion;

- (void) stopWithFadeDuration:(NSTimeInterval)duration;
- (void) playWithFadeDuration:(NSTimeInterval)duration;
 
@end





