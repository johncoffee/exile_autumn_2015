//
//  BuyButton.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-30.
//
//  This class is the Buy button on the playlist view. It has one property, an iTunes style itms:// link as urlString.

#import <UIKit/UIKit.h>

@interface BuyButton : UIButton {
    NSString *urlString;
}

@property (nonatomic, retain) NSString *urlString;

@end
