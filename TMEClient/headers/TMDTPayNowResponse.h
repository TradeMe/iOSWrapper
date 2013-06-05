//
//  TMDTPayNowResponse.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTPayNowStatus.h"

/**
 The response object returned after attempting to pay for an item.
 */
@interface TMDTPayNowResponse : NSObject

/**
 Indicates whether the operation was successful.
 */
@property (nonatomic) BOOL success;

/**
 The description of the error, if the operation failed.
 */
@property (strong, nonatomic) NSString *descriptionText;

/**
 If something went wrong with the Pay Now request, contains a status code that indicates exactly what went wrong. When there are multiple errors, this is the status code for the first error.
 */
@property (nonatomic) TMDTPayNowStatus statusCode;

/**
 A list of validation errors. Only populated for certain types of validation errors. When present, this list can be used to report multiple failures to the user at once.
 */
@property (strong, nonatomic) NSArray *arrayOfValidationErrors;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
