//
//  LoginPanel.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-07-23.
//
//  This is the Login panel for logging in to Veemix as a player.

#import <UIKit/UIKit.h>
#import "UserData.h"
#import "RegisterPanel.h"
#import "vmxSelector.h"
#import "vmxNowPlayingInfo.h"

#import "DeveloperLoginPanel.h"

@interface LoginPanel : UIViewController <UITextFieldDelegate> {
    NSMutableData *_responseData;
    UIActivityIndicatorView *activityIndicator;
    
    
}

@property (strong, nonatomic) IBOutlet UITextField *usernameField;
@property (strong, nonatomic) IBOutlet UITextField *passwordField;
@property (strong, nonatomic) IBOutlet UIButton *loginButton;
@property (strong, nonatomic) IBOutlet UIButton *registerButton;
@property(strong, nonatomic) IBOutlet UILabel *registerLabel;
@property (strong, nonatomic) IBOutlet UINavigationController *navController;
@property (nonatomic, retain) UIActivityIndicatorView *activityIndicator;

@property(nonatomic, strong) IBOutlet UILabel *usernameLabel;
@property(nonatomic, strong) IBOutlet UILabel *usernameStatus;
@property(nonatomic, strong) IBOutlet UIImageView *profileImage;

@property(nonatomic,strong)IBOutlet UIButton *devLogin;

@property(nonatomic, strong)IBOutlet UIButton *signOut;


-(IBAction)tappedLogin:(id)sender;
-(IBAction)tappedRegister:(id)sender;
-(IBAction)tappedClose:(id)sender;

-(IBAction)devLogin:(id)sender;

-(IBAction)signOut:(id)sender;

@end
