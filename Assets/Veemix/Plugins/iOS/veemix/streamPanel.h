//
//  streamPanel.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-07-14.
//
//

#import <UIKit/UIKit.h>

@class streamPanel;

@protocol streamPanelDelegate <NSObject>

-(void)streamView:(streamPanel *)myStreamPanel didChangeState:(BOOL)opened;

@end

@interface streamPanel : UIView
{
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
    
    id<streamPanelDelegate> delegate;
}


@property (nonatomic, readonly) UIView *handleView;
@property (readwrite, assign) CGPoint closedCenter;
@property (readwrite, assign) CGPoint openedCenter;
@property (nonatomic, readonly) UIPanGestureRecognizer *dragRecognizer;
@property (nonatomic, readonly) UITapGestureRecognizer *tapRecognizer;
@property (readwrite, assign) BOOL toggleOnTap;
@property (readwrite, assign) BOOL animate;
@property (readwrite, assign) float animationDuration;
@property (readwrite, assign) id<streamPanelDelegate> delegate;
@property (readonly, assign) BOOL opened;
-(void)setOpened:(BOOL)op animated:(BOOL)anim;

@end
