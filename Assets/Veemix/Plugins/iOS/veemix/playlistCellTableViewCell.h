//
//  playlistCellTableViewCell.h
//  Unity-iPhone
//
//  Created by Karen Collins on 2014-07-22.
//
//

#import <UIKit/UIKit.h>

static NSString * const kCellIDTitle = @"CellWithTitle";

@interface playlistCellTableViewCell : UITableViewCell
{
    NSString *reuseID;
}

@property(nonatomic,strong) UILabel *playlistTitle;
@property(nonatomic,strong) UITextView *playlistSubtitle;
@property(nonatomic,strong) UIButton *downloadButton;
@property(nonatomic,strong) UIImageView *recommendedStar;
@property(nonatomic,strong)UIColor *cellColor;

@end
