//
//  ViewAvailableTradesController.h
//  UniversalClient
//
//  Created by Kevin Runde on 8/15/10.
//  Copyright 2010 n/a. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LETableViewControllerGrouped.h"


@class BaseTradeBuilding;


@interface ViewAvailableTradesController : LETableViewControllerGrouped {
	BaseTradeBuilding *baseTradeBuilding;
	NSDate *tradesLastUpdated;
}


@property (nonatomic, retain) BaseTradeBuilding *baseTradeBuilding;
@property (nonatomic, retain) NSDate *tradesLastUpdated;


+ (ViewAvailableTradesController *) create;


@end
