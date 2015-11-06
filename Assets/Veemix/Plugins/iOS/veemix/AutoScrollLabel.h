//
//  AutoScrollLabel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-30.
//
//  This class puts a set of mood tags in a UIScrollView and auto scrolls them as part of the Veemix toolbar. Based on the excellent scrolling UILabel at Stormy Productions blog http://blog.stormyprods.com/2009/10/simple-scrolling-uilabel-for-iphone.html

#import <UIKit/UIKit.h>

#define NUM_LABELS 2

enum AutoScrollDirection {
	AUTOSCROLL_SCROLL_RIGHT,
	AUTOSCROLL_SCROLL_LEFT,
};

@interface AutoScrollLabel : UIScrollView <UIScrollViewDelegate>{
	UILabel *label[NUM_LABELS];
	enum AutoScrollDirection scrollDirection;
	float scrollSpeed;
	NSTimeInterval pauseInterval;
	int bufferSpaceBetweenLabels;
	bool isScrolling;
}
@property(nonatomic) enum AutoScrollDirection scrollDirection;
@property(nonatomic) float scrollSpeed;
@property(nonatomic) NSTimeInterval pauseInterval;
@property(nonatomic) int bufferSpaceBetweenLabels;
// normal UILabel properties
@property(nonatomic,retain) UIColor *textColor;
@property(nonatomic, retain) UIFont *font;

- (void) readjustLabels;
- (void) setText: (NSString *) text;
- (NSString *) text;
- (void) scroll;


@end
