//
//  StreamData.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-07-15.
//
//

#import <Foundation/Foundation.h>

@interface StreamData : NSObject {
    NSMutableArray *streamArray;
    NSMutableDictionary *streamDictionary;
    
    NSMutableString *artistString;
    NSMutableString *titleString;
    
    
}

@property(nonatomic,retain)NSMutableArray *streamArray;
@property(nonatomic,retain)NSMutableDictionary *streamDictionary;

@property(nonatomic,retain)NSMutableString *artistString;
@property(nonatomic,retain)NSMutableString *titleString;

+(StreamData *)getInstance;

@end
