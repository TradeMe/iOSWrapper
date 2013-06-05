//
//  TMDTShippingOption.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

typedef NS_ENUM(NSInteger, TMDTDeliveryType) {
    TMDTDeliveryTypeNone = 0,
    TMDTDeliveryTypeUndecided = 1,
    TMDTDeliveryTypePickup = 2,
    TMDTDeliveryTypeFree = 3,
    TMDTDeliveryTypeCustom = 4
};

/**
 This class represents a single shipping option the a seller has made available for a listing.
 
 For more information see; http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTShippingOption : NSObject

/**
 The type of delivery.
 */
@property (assign, nonatomic) TMDTDeliveryType deliveryType;

/**
 The price of the delivery option. Only applicable if ShippingType is Custom.
 */
@property (strong, nonatomic) NSNumber *price;

/**
 The name of the delivery method (e.g. “NZ Courier”, “Rural Delivery”). Only applicable if ShippingType is Custom.
 */
@property (strong, nonatomic) NSString *method;

/**
 The ID of the shipping option (used when bidding or for Buy Now). Not required when listing an item.
 */
@property (assign, nonatomic) NSInteger shippingId;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
