//
//  TMDTBidRequest.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

/**
 Contains information about a bid that the user wishes to place on a listing.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/bidding-methods/place-a-bid/
 */
@interface TMDTBidRequest : NSObject

/**
 The listing ID of the item the bid is for.
 */
@property (strong, nonatomic) NSNumber *listingId;

/**
 The bid amount, in New Zealand dollars.
 */
@property (strong, nonatomic) NSNumber *amount;

/**
 Indicates whether the bid is an auto-bid.
 */
@property (assign, nonatomic) BOOL autoBid;

/**
 The ID of the preferred shipping option which will be used when this request happens to be the winning bid. This ID can be retrieved from the ShippingId field in the listing detail.
 */
@property (assign, nonatomic) NSInteger shippingOption;

/**
 Indicates whether the bidder should be emailed if they are outbid.
 */
@property (assign, nonatomic) BOOL emailOutBid;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryBid;

@end
