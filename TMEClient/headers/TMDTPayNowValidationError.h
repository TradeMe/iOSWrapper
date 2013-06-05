//
//  TMDTPayNowValidationError.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTPayNowStatus.h"

/**
 Represents a validation error that has occurred on the server when attempting to process your pay now request.
 */
@interface TMDTPayNowValidationError : NSObject

/**
 The description of the validation error, suitable for display to the user.
 */
@property (strong, nonatomic) NSString *descriptionText;

/**
 A status code that indicates exactly what went wrong.
 */
@property (nonatomic) TMDTPayNowStatus statusCode;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

@end
