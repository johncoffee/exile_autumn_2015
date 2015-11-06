//
//  vPanel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-16.
//
//  This class is the container for the Veemix toolbar which handles user interaction for dragging and tapping to show and hide the toolbar. Has a delegate method to check on state (open/closed).

#import <UIKit/UIKit.h>
@class vPanel;

@protocol vPanelDelegate <NSObject>

/**
 @param vPanel state changed
 @param opened the new state
 
 */

-(void)vView:(vPanel *)vPanelView didChangeState:(BOOL)opened;

@end

@interface vPanel : UIView {
    CGPoint closedCenter;
    CGPoint openedCenter;
    
    UIView *handleView;
    UIPanGestureRecognizer *dragRecognizer;
    UITapGestureRecognizer *tapRecognizer;
    
    CGPoint startPos;
    CGPoint minPos;
    CGPoint maxPos;
    
    BOOL opened;
    BOOL verticalAxis;
    BOOL toggleOnTap;
    BOOL animate;
    float animationDuration;
    
    id<vPanelDelegate> delegate;
}

@property (nonatomic, readonly) UIView *handleView;
@property (readwrite, assign) CGPoint closedCenter;
@property (readwrite, assign) CGPoint openedCenter;
@property (nonatomic, readonly) UIPanGestureRecognizer *dragRecognizer;
@property (nonatomic, readonly) UITapGestureRecognizer *tapRecognizer;
@property (readwrite, assign) BOOL toggleOnTap;
@property (readwrite, assign) BOOL animate;
@property (readwrite, assign) float animationDuration;
@property (readwrite, assign) id<vPanelDelegate> delegate;
@property (readonly, assign) BOOL opened;
-(void)setOpened:(BOOL)op animated:(BOOL)anim;

@end
