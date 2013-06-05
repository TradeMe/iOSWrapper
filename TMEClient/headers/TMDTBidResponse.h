//
//  TMDTBidResponse.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTBidStatus.h"

/**
 Represents the response you get back from the api when attempting to place a bid.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/bidding-methods/place-a-bid/
 */
@interface TMDTBidResponse : NSObject

/**
 Indicates whether the bid was successfully placed.
 */
@property (assign, nonatomic) BOOL success;

/**
 The description of the bid result.
 */
@property (strong, nonatomic) NSString *description;

/**
  Indicates whether the bid is too high.
 */
@property (assign, nonatomic) BOOL isTooHigh;

/**
 Indicates whether the bid is too low.
 */
@property (assign, nonatomic) BOOL isTooLow;

/**
 Indicates whether the reserve has been met.
 */
@property (assign, nonatomic) BOOL isReserveMet;

/**
 The minimum next bid price.
 */
@property (strong, nonatomic) NSNumber *minimumNextBid;

/**
 The state of the bid.
 */
@property (assign, nonatomic) TMDTBidStatus statusCode;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryBid_;

@end
