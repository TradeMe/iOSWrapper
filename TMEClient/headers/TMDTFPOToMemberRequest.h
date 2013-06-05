//
//  TMDTFPOToMemberRequest.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTFPORequest.h"

typedef NS_ENUM(NSInteger, TMDTFPODuration) {
    TMDTFPODurationNone = 0,   //-- Not valid.
    TMDTFPODuration1 = 1,      //-- One day.
    TMDTFPODuration3 = 3,      //-- Three days (default).
    TMDTFPODuration7 = 7       //-- Seven days
};

/**
 This class represents a request to accept or reject a fixed price offer that a seller has given.
 
 For more information see; http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/respond-to-a-fixed-price-offer/
 
 The associated response class is TMDTFPOMemberResponse
 */
@interface TMDTFPOToMemberRequest : TMDTFPORequest

/**
 The price of the offer. Truncated to two decimal places.
 */
@property (strong, nonatomic) NSNumber *price;

/**
 The duration the offer is valid for (one, three or seven days).
 */
@property (assign, nonatomic) TMDTFPODuration duration;

/**
 The list of member IDs corresponding to the members to send the offer to.
 */
@property (strong, nonatomic) NSArray *arrayOfMemberIds;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
