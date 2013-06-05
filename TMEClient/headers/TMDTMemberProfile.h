//
//  TMDTMemberProfile.h
//  TMAPIClient
//
//  Created by Nick Parfene on 1/08/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TMDTMember;

/**
 This class represents a member profile returned from the server after being requested.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/membership-methods/retrieve-member-profile/
 */
@interface TMDTMemberProfile : NSObject

/**
 The first name of the member.
 */
@property (strong, nonatomic) NSString *firstName;

/**
 The occupation of the member.
*/
@property (strong, nonatomic) NSString *occupation;

/**
 The member’s bio.
 */
@property (strong, nonatomic) NSString *biography;

/**
 The member’s favourite quote.
*/
@property (strong, nonatomic) NSString *quote;

/**
 A URL representing the member’s photo.
*/
@property (strong, nonatomic) NSString *photoUrl;

/**
 Indicates whether the member account is enabled.
*/
@property (nonatomic, getter = isEnabled) BOOL enabled;

/**
 The date the member was disabled (assuming it has been disabled).
*/
@property (strong, nonatomic) NSDate *dateRemoved;

/**
 Basic information about the member.
*/
@property (strong, nonatomic) TMDTMember *member;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryMemberProfile;

@end
