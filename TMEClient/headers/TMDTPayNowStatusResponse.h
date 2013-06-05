//
//  TMDTPayNowStatusResponse.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 13/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTPayNowStatus.h"
#import "TMDTAddress.h"

@interface TMDTPayNowStatusResponse : NSObject

@property (strong, nonatomic) NSArray *arrayOfDeliveryAddresses;
@property (nonatomic) BOOL askUserForDeliveryAddress;
@property (nonatomic) BOOL canSaveCard;
@property (strong, nonatomic) NSString *statusDescription;
@property (strong, nonatomic) NSString *existingCardLastFourDigits;
@property (strong, nonatomic) NSString *existingCardType;
@property (strong, nonatomic) TMDTAddress *savedAddress;
@property (strong, nonatomic) NSString *shippingMethod;
@property (strong, nonatomic) NSNumber *shippingPrice;
@property (nonatomic) TMDTPayNowStatus statusResponse;
@property (strong, nonatomic) NSNumber *totalPrice;
@property (nonatomic) NSInteger quantitySold;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
