//
//  UserData.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-18.
//
//  Model for user data.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface UserData : NSObject {
    NSMutableDictionary *query;
    BOOL isOnline;
    UIButton *sender;
}
@property (nonatomic, retain) NSMutableDictionary *query;
@property BOOL isOnline;
@property (nonatomic,retain)UIButton *sender;
+(UserData*)getInstance;
@end
