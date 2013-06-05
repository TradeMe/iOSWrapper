//
//  TMDTFPOResponse.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

/**
 This class represents the base response from the server after you have requested to accept or reject a fixed price offer from the seller.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/respond-to-a-fixed-price-offer/
 */
@interface TMDTFPOResponse : NSObject

/**
 Indicates whether the operation was successful.
 */
@property (assign, nonatomic) BOOL success;

/**
 The description of the error, if the operation failed.
 */
@property (strong, nonatomic) NSString *description;

/**
 The result code of the offer response.
 */
@property (assign, nonatomic) NSInteger statusCode;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
