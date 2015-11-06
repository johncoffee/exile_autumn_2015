//
//  playlistTitleDesc.h
//  Unity-iPhone
//
//  Created by Alexander Hodge on 2013-05-27.
//
//  The view presented to the user which handles Veemix playlist naming and description input, and uploading to www.veemix.com

#import <UIKit/UIKit.h>
#import "vmxSelector.h"
#import "PlaylistData.h"

@interface playlistTitleDesc : UIViewController <UITextViewDelegate> {
    
    NSMutableData *_responseData;

}

@property (strong,nonatomic) IBOutlet UITextView *playlistTitle;
@property (strong,nonatomic) IBOutlet UITextView *playlistDescription;
@property (strong,nonatomic) IBOutlet UIButton *uploadButton;
@property (strong, nonatomic) IBOutlet UIButton *closeButton;
-(IBAction)tappedUpload:(id)sender;
-(IBAction)tappedClose:(id)sender;

@end
