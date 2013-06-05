//
//  TMDTDeliveryAddressResponse.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTDeliveryAddressResponse : NSObject

/**
 Indicates whether the operation was successful.
 */
@property (nonatomic) BOOL success;

/**
 The description of the error, if the operation failed.
 */
@property (strong, nonatomic) NSString *descriptionText;

/**
 The delivery address ID.
 */
@property (strong, nonatomic) NSNumber *deliveryAddressId;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
