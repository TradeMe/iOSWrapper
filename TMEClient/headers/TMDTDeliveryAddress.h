//
//  TMDTDeliveryAddress.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTAddress.h"

@interface TMDTDeliveryAddress : TMDTAddress

@property (nonatomic) BOOL isMembershipAddress;
@property (strong, nonatomic) NSNumber *deliveryAddressId;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
