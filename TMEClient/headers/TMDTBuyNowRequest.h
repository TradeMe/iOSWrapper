//
//  TMDTBuyNowRequest.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

/**
 Represents the class that contains the required information in order to use the Trade Me Buy Now process to buy an item.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/bidding-methods/buy-an-auction-using-buy-now/
 */
@interface TMDTBuyNowRequest : NSObject

/**
 The ID of the listing the Buy Now request is for.
 */
@property (strong, nonatomic) NSNumber *listingId;

/**
 The ID of the preferred shipping option which will be used if the Buy Now request succeeds. This ID can be retrieved from the ShippingId field in the listing detail.
 */
@property (assign, nonatomic) NSInteger shippingOption;

/**
 The quantity to buy. Defaults to 1. Only applicable to Buy Now Only auctions.
 */
@property (assign, nonatomic) NSInteger quantity;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryBid_;

@end
