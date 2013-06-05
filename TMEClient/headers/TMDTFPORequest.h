//
//  TMDTFPORequest.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

/**
 This class represents a base request to accept or reject a fixed price offer that a seller has given.
 
 For more information see; http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/respond-to-a-fixed-price-offer/
 
 The associated response class is TMDTFPOResponse
 */
@interface TMDTFPORequest : NSObject

/**
 The ID of a listing which has a current fixed price offer associated with it.
 */
@property (strong, nonatomic) NSNumber *listingId;

/**
 Indicates whether or not to accept or reject the fixed price offer.
 */
@property (assign, nonatomic) BOOL accept;

/**
 The preferred shipping option which will be used when this request happens to be the winning bid. The value is an numeric ID that is returned from the listing detail request (in the ShippingId field).
 */
@property (assign, nonatomic) NSInteger shippingOption;

/**
 Indicates the number of items to buy. Only applicable to Buy Now only auctions. Defaults to 1.
 */
@property (assign, nonatomic) NSInteger quantity;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary_;

@end
