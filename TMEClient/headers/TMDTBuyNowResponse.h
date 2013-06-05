//
//  TMDTBuyNowResponse.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTBuyNowStatus.h"

/**
 The response object after attempting to buy an item using Buy Now. See the Buy Now API documentation at:
 
 http://developer.trademe.co.nz/api-reference/bidding-methods/buy-an-auction-using-buy-now/
 */
@interface TMDTBuyNowResponse : NSObject

/**
 Either an error message if the Buy Now request failed, or a success message providing useful information to the buyer.
 */
@property (strong, nonatomic) NSString *description;

/**
 The ID of the purchase that was just made.
 */
@property (strong, nonatomic) NSNumber *purchaseId;

/**
 The status of the Buy Now request.
 */
@property (assign, nonatomic) TMDTBuyNowStatus statusCode;

/**
 Indicates whether the bid was successfully placed.
 */
@property (assign, nonatomic) BOOL success;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryBid_;

@end
