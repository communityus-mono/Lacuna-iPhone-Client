//
//  BaseTradeBuilding.h
//  UniversalClient
//
//  Created by Kevin Runde on 8/15/10.
//  Copyright 2010 n/a. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Building.h"


@class ItemPush;
@class OneForOneTrade;
@class Trade;
@class MarketTrade;


@interface BaseTradeBuilding : Building {
	id itemPushTarget;
	SEL itemPushCallback;
	id oneForOneTradeTarget;
	SEL oneForOneTradeCallback;
	id postTradeTarget;
	SEL postTradeCallback;
	id acceptTradeTarget;
	SEL acceptTradeCallback;
	id postToMarketTarget;
	SEL postToMarketCallback;
	id acceptFromMarketTarget;
	SEL acceptFromMarketCallback;
}


@property (nonatomic, assign) NSInteger availableTradePageNumber;
@property (nonatomic, retain) NSDecimalNumber *availableTradeCount;
@property (nonatomic, retain) NSDate *availableTradesUpdated;
@property (nonatomic, retain) NSMutableArray *availableTrades;
@property (nonatomic, retain) NSString *captchaGuid;
@property (nonatomic, retain) NSString *captchaUrl;
@property (nonatomic, assign) NSInteger myTradePageNumber;
@property (nonatomic, retain) NSDecimalNumber *myTradeCount;
@property (nonatomic, retain) NSDate *myTradesUpdated;
@property (nonatomic, retain) NSMutableArray *myTrades;

@property (nonatomic, assign) NSInteger marketPageNumber;
@property (nonatomic, assign) NSString *marketFilter;
@property (nonatomic, retain) NSDecimalNumber *marketTradeCount;
@property (nonatomic, retain) NSDate *marketUpdated;
@property (nonatomic, retain) NSMutableArray *marketTrades;
@property (nonatomic, assign) NSInteger myMarketPageNumber;
@property (nonatomic, retain) NSDecimalNumber *myMarketTradeCount;
@property (nonatomic, retain) NSDate *myMarketUpdated;
@property (nonatomic, retain) NSMutableArray *myMarketTrades;

@property (nonatomic, retain) NSMutableArray *glyphs;
@property (nonatomic, retain) NSMutableDictionary *glyphsById;
@property (nonatomic, retain) NSDecimalNumber *cargoUsedPerGlyph;
@property (nonatomic, retain) NSMutableArray *plans;
@property (nonatomic, retain) NSMutableDictionary *plansById;
@property (nonatomic, retain) NSDecimalNumber *cargoUsedPerPlan;
@property (nonatomic, retain) NSMutableArray *prisoners;
@property (nonatomic, retain) NSMutableDictionary *prisonersById;
@property (nonatomic, retain) NSDecimalNumber *cargoUsedPerPrisoner;
@property (nonatomic, retain) NSMutableArray *ships;
@property (nonatomic, retain) NSMutableDictionary *shipsById;
@property (nonatomic, retain) NSDecimalNumber *cargoUsedPerShip;
@property (nonatomic, retain) NSMutableArray *resourceTypes;
@property (nonatomic, retain) NSMutableArray *storedResources;
@property (nonatomic, retain) NSDecimalNumber *cargoUsedPerStoredResource;
@property (nonatomic, readonly) BOOL usesEssentia;
@property (nonatomic, readonly) BOOL selectTradeShip;
@property (nonatomic, readonly) BOOL hasMarket;
@property (nonatomic, readonly) BOOL hasTrade;
@property (nonatomic, retain) NSDecimalNumber *maxCargoSize;
@property (nonatomic, retain) NSMutableArray *tradeShips;
@property (nonatomic, retain) NSMutableDictionary *tradeShipsById;
@property (nonatomic, retain) NSMutableDictionary *tradeShipsTravelTime;


- (void)clearLoadables;
- (void)loadTradeableGlyphs;
- (void)loadTradeablePlans;
- (void)loadTradeablePrisoners;
- (void)loadTradeableResourceTypes;
- (void)loadTradeableShips;
- (void)loadTradeableStoredResources;
- (void)loadTradeShipsToBody:(NSString *)targetBodyId;
- (void)removeTradeableStoredResource:(NSDictionary *)storedResource;
- (void)addTradeableStoredResource:(NSDictionary *)storedResource;
- (NSDecimalNumber *)calculateStorageForGlyphs:(NSInteger)numGlyphs plans:(NSInteger)numPlans prisoners:(NSInteger)numPrisoners storedResources:(NSDecimalNumber *)numStoredResources ships:(NSInteger)numShips;
- (void)loadAvailableTradesForPage:(NSInteger)pageNumber;
- (bool)hasPreviousAvailableTradePage;
- (bool)hasNextAvailableTradePage;
- (void)loadMyTradesForPage:(NSInteger)pageNumber;
- (bool)hasPreviousMyTradePage;
- (bool)hasNextMyTradePage;
- (void)pushItems:(ItemPush *)itemPush target:(id)target callback:(SEL)callback;
- (void)tradeOneForOne:(OneForOneTrade *)oneForOneTrade target:(id)target callback:(SEL)callback;
- (void)postTrade:(Trade *)trade target:(id)target callback:(SEL)callback;
- (void)acceptTrade:(Trade *)trade solution:(NSString *)solution target:(id)target callback:(SEL)callback;
- (void)withdrawTrade:(Trade *)trade;

- (void)loadMarketPage:(NSInteger)pageNumber filter:(NSString *)filter;
- (bool)hasPreviousMarketPage;
- (bool)hasNextMarketPage;
- (void)loadMyMarketPage:(NSInteger)pageNumber;
- (bool)hasPreviousMyMarketPage;
- (bool)hasNextMyMarketPage;
- (void)postMarketTrade:(MarketTrade *)trade target:(id)target callback:(SEL)callback;
- (void)acceptMarketTrade:(MarketTrade *)trade solution:(NSString *)solution target:(id)target callback:(SEL)callback;
- (void)withdrawMarketTrade:(MarketTrade *)trade;



@end
