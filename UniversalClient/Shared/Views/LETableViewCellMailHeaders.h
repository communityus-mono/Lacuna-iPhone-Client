//
//  LETableViewCellMailHeaders.h
//  UniversalClient
//
//  Created by Kevin Runde on 7/17/10.
//  Copyright 2010 n/a. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface LETableViewCellMailHeaders : UITableViewCell {
	UILabel *subjectText;
	UILabel *fromLabel;
	UILabel *fromText;
	UILabel *dateLabel;
	UILabel *dateText;
}


@property(nonatomic, retain) UILabel *subjectText;
@property(nonatomic, retain) UILabel *toLabel;
@property(nonatomic, retain) UILabel *toText;
@property(nonatomic, retain) UILabel *fromLabel;
@property(nonatomic, retain) UILabel *fromText;
@property(nonatomic, retain) UILabel *dateLabel;
@property(nonatomic, retain) UILabel *dateText;


- (void)setMessage:(NSDictionary *)message;


+ (LETableViewCellMailHeaders *)getCellForTableView:(UITableView *)tableView;
+ (CGFloat)getHeightForTableView:(UITableView *)tableView;


@end
