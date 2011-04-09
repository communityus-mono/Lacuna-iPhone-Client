//
//  LEBuildingProposeFireBfg.h
//  UniversalClient
//
//  Created by Kevin Runde on 4/9/11.
//  Copyright 2011 n/a. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LERequest.h"


@interface LEBuildingProposeFireBfg : LERequest {
}


@property (nonatomic, retain) NSString *buildingId;
@property (nonatomic, retain) NSString *buildingUrl;
@property (nonatomic, retain) NSString *bodyId;
@property (nonatomic, retain) NSString *reason;
@property (nonatomic, retain) NSMutableDictionary *results;
@property (nonatomic, retain) NSMutableDictionary *proposition;


- (LERequest *)initWithCallback:(SEL)callback target:(NSObject *)target buildingId:(NSString *)buildingId buildingUrl:(NSString *)buildingUrl bodyId:(NSString *)bodyId reason:(NSString *)reason;


@end
