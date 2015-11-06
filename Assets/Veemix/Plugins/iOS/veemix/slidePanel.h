//
//  slidePanel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-05-26.
//
//  This class is the container for the Veemix toolbar which handles user interaction for dragging and tapping to show and hide the toolbar. Has a delegate method to check on state (open/closed).

#import <UIKit/UIKit.h>
@class slidePanel;

@protocol slidePanelDelegate <NSObject>

/**
@param pView slidePanel state changed
@param opened the new state
*/

-(void)slideView:(slidePanel *)flipView didChangeState:(BOOL)opened;

@end

@interface slidePanel : UIView {
    
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
    
    id<slidePanelDelegate> delegate;
    
}

@property (nonatomic, readonly) UIView *handleView;
@property (readwrite, assign) CGPoint closedCenter;
@property (readwrite, assign) CGPoint openedCenter;
@property (nonatomic, readonly) UIPanGestureRecognizer *dragRecognizer;
@property (nonatomic, readonly) UITapGestureRecognizer *tapRecognizer;
@property (readwrite, assign) BOOL toggleOnTap;
@property (readwrite, assign) BOOL animate;
@property (readwrite, assign) float animationDuration;
@property (readwrite, assign) id<slidePanelDelegate> delegate;
@property (readonly, assign) BOOL opened;
-(void)setOpened:(BOOL)op animated:(BOOL)anim;

@end
