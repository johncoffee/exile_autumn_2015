//
//  vmxNowPlayingInfo.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-04-20.
//
//  An extension of UIView that displays the song info and album art on a song change event. Fades in and out based on duration.

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "EventClass.h"
@interface UIView (vmxNowPlayingInfo)


-(void)vmxNowPlayingInfo:(NSString *)title duration:(CGFloat)interval position:(id)position vmxSongArtist:(NSString *)artist vmxSongArtwork:(UIImage *)image;

-(void)showMoodInfo;
-(void)showMoodInfo:(id)position;
-(void)hideMoodInfo;


-(void)vmxShowView:(UIView *)vmxView;
-(void)vmxShowView:(UIView *)vmxView duration:(CGFloat)interval position:(id)point;
-(void)vmxShowView:(UIView *)vmxView position:(id)point;
@end
