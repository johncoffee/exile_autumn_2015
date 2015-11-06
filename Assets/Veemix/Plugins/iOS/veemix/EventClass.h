//
//  EventClass.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-03-15.
//
//  This is the model of the Veemix event and contains the event's ID as a string, sceneTitle, moodTagWord, moodLabels.

#import <Foundation/Foundation.h>

@interface EventClass : NSObject {
    NSString *str;
    NSString *sceneTitle;
    NSMutableArray *moodTagWords;
    
    NSMutableString *currentEvent;
}
@property(nonatomic, retain)NSString *str;
@property(nonatomic, retain)NSMutableArray *moodTagWords;
@property(nonatomic,retain)NSString *sceneTitle;
@property(nonatomic,retain)NSMutableString *currentEvent;
+(EventClass*)getInstance;

@end
