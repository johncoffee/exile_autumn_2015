//
//  DeveloperLoginPanel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2014-11-07.
//
//

#import <UIKit/UIKit.h>

@interface DeveloperLoginPanel : UIViewController <UITextFieldDelegate, NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLConnectionDelegate>
{
    NSMutableData * _responseData;
    NSURLSession *_urlSession;
    NSTimer *_statusTimer;
    NSMutableArray *_tasks;
    
    UIActivityIndicatorView *activityIndicator;
}

@property (strong, nonatomic) IBOutlet UITextField *devEmail;
@property (strong, nonatomic) IBOutlet UITextField *gameID;

@property(nonatomic,strong)IBOutlet UIButton *loginButton;

@property (nonatomic, retain) UIActivityIndicatorView *activityIndicator;


-(IBAction)doDevLogin:(id)sender;


@end
