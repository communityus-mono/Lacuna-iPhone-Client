//
//  ViewMailMessageController.h
//  UniversalClient
//
//  Created by Kevin Runde on 4/17/10.
//  Copyright 2010 n/a. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LETableViewControllerGrouped.h"


@class Mailbox;


@interface ViewMailMessageController : LETableViewControllerGrouped <UIActionSheetDelegate> {
	UISegmentedControl *messageSegmentedControl;
	Mailbox *mailbox;
	NSInteger messageIndex;
	BOOL isObserving;
	NSDictionary *attachements;
	BOOL hasAttachements;
	BOOL isArchiving;
	BOOL isResending;
}


@property(nonatomic, retain) UISegmentedControl *messageSegmentedControl;
@property(nonatomic, retain) Mailbox *mailbox;
@property(nonatomic) NSInteger messageIndex;


- (IBAction)archiveMessage;
- (IBAction)resendMessage;
- (IBAction)replyToMessage;
- (IBAction)forwardMessage;
- (IBAction)newMessage;


+ (ViewMailMessageController *)create;


@end
