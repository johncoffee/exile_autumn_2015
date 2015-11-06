//
//  RegisterPanel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-24.
//
//  This class handles Veemix user registration.

#import <UIKit/UIKit.h>
#import "vmxSelector.h"
#import "vmxNowPlayingInfo.h"


@interface RegisterPanel : UIViewController <UITextFieldDelegate, UIImagePickerControllerDelegate, UIActionSheetDelegate, UINavigationControllerDelegate,NSURLSessionDelegate, NSURLSessionTaskDelegate> {
    NSMutableData *_responseData;
    
    NSURLSession *_urlSession;
    
    NSTimer *_statusTimer;
    NSMutableArray *_tasks;


}

@property (strong, nonatomic) IBOutlet UITextField *nameField;
@property (strong, nonatomic) IBOutlet UITextField *usernameField;
@property (strong, nonatomic) IBOutlet UITextField *passwordField;
@property (strong, nonatomic) IBOutlet UITextField *passwordField2;
@property (strong, nonatomic) IBOutlet UITextField *emailField;
@property (strong, nonatomic) IBOutlet UIButton *registerButton;
-(IBAction)tappedRegister:(id)sender;
-(IBAction)tappedClose:(id)sender;
-(IBAction)getPhotoNowPlease:(id)sender;
@end
