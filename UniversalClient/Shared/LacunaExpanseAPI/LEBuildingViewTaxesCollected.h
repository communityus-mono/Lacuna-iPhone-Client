//
//  LEBuildingViewTaxesCollected.h
//  UniversalClient
//
//  Created by Kevin Runde on 4/9/11.
//  Copyright 2011 n/a. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LERequest.h"


@interface LEBuildingViewTaxesCollected : LERequest {
}


@property (nonatomic, retain) NSString *buildingId;
@property (nonatomic, retain) NSString *buildingUrl;
@property (nonatomic, retain) NSMutableDictionary *results;
@property (nonatomic, retain) NSMutableArray *taxesCollected;


- (LERequest *)initWithCallback:(SEL)callback target:(NSObject *)target buildingId:(NSString *)buildingId buildingUrl:(NSString *)buildingUrl;


@end
