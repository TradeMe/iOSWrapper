//
//  TMDTMember.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a Trade Me member.  A Trade Me member could be either a seller or a buyer depending on the context, for example, if a user is viewing
 an item that he/she has won, then the listing would have two member objects; one buyer and one seller.
 
 For more information, see TMDTListing.
 */
@interface TMDTMember : NSObject

/**
 The ID of the member. This may be 0, if we determine it is necessary to protect the member’s privacy.
 */
@property (strong, nonatomic) NSNumber *memberId;

/**
 The nickname of the member. Some characters may be changed, if we determine it is necessary to protect the member’s privacy.
 */
@property (strong, nonatomic) NSString *nickname;

/**
 The date the member was address verified.
 */
@property (strong, nonatomic) NSDate *dateAddressVerified;

/**
 The date the member joined.
 */
@property (strong, nonatomic) NSDate *dateJoined;

/**
 The email address of the member
 */
@property (strong, nonatomic) NSString *email;

/**
 The number of distinct members who have placed negative feedback against this member.
 */
@property (nonatomic) NSInteger uniqueNegative;

/**
 The number of distinct members who have placed positive feedback against this member.
 */
@property (nonatomic) NSInteger uniquePositive;

/**
 The member’s total feedback (UniquePositive minus UniqueNegative).
 */
@property (nonatomic) NSInteger feedbackCount;

/**
 Indicates whether the member has been address verified.
 */
@property (nonatomic) BOOL isAddressVerified;

/**
 The suburb name for the item.
 */
@property (strong, nonatomic) NSString *suburb;

/**
 The suburb ID for the item.
 */
@property (strong, nonatomic) NSNumber *suburbId;

/**
 The region name for the item.
 */
@property (strong, nonatomic) NSString *region;

/**
 The region ID for the item.
 */
@property (strong, nonatomic) NSNumber *regionId;

/**
 Indicates whether the member is a car dealer.
 */
@property (nonatomic) BOOL isDealer;

/**
 Indicates whether the member is authenticated.
 */
@property (nonatomic) BOOL isAuthenticated;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryMember;

@end
