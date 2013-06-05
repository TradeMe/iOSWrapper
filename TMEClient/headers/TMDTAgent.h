//
//  TMDTAgent.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Contains contact information for an agent, for example, a real estate agent.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTAgent : NSObject

/**
 The agent's email address
 */
@property (strong, nonatomic) NSString *email;

/**
 The agent's fax number
 */
@property (strong, nonatomic) NSString *faxNumber;

/**
 The agent's first name
 */
@property (strong, nonatomic) NSString *firstName;

/**
 The agent's full name
 */
@property (strong, nonatomic) NSString *fullName;

/**
 The agent's home phone number
 */
@property (strong, nonatomic) NSString *homePhoneNumber;

/**
 The agent's mobile phone number
 */
@property (strong, nonatomic) NSString *mobilePhoneNumber;

/**
 The agent's office phone number
 */
@property (strong, nonatomic) NSString *officePhoneNumber;

/**
 The agent's position title
 */
@property (strong, nonatomic) NSString *position;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryAgent;

@end
