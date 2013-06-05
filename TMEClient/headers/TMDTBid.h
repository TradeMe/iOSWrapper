//
//  TMDTBid.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

@class TMDTMember;

/**
 Represents a single bid in the list of bids for a single listing.
 
 See the 'Bids' collection in the ListingItemDetail at: http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTBid : NSObject

/**
 The account the bid came from.
 */
@property (strong, nonatomic) NSString *account;

/**
 The amount of money the bid represents, in NZD.
 */
@property (strong, nonatomic) NSNumber *amount;

/**
 Indicates whether the bid came from a mobile phone.
 */
@property (assign, nonatomic) BOOL isByMobile;

/**
 Indicates whether the bid was by proxy.
 */
@property (assign, nonatomic) BOOL isByProxy;

/**
 The date and time the bid was placed.
 */
@property (strong, nonatomic) NSDate *bidDate;

/**
 Indicates whether the bid was a Buy Now bid.
 */
@property (assign, nonatomic) BOOL isBuyNow;

/**
 The member who placed the bid.
 */
@property (strong, nonatomic) TMDTMember *bidder;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryBid_;

@end
