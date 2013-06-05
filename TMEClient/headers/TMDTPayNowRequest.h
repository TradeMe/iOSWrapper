//
//  TMDTPayNowRequest.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TMDTCreditCardDetails;

/**
 Contains the required information in order to execute a pay now request.
 */
@interface TMDTPayNowRequest : NSObject

/**
 The purchase ID corresponding to the purchased item to purchase. This can be obtained from the Won Items API or from the Buy Now API.
 */
@property (strong, nonatomic) NSNumber *purchaseId;

/**
 The ID of the delivery address (returned by the add address API or via the delivery addresses returned from GetPayNowStatus). Optional if the auction is pick-up only or if the user has already saved an address.
 */
@property (strong, nonatomic) NSNumber *deliveryAddressId;

/**
 The details of the credit card that should be used to purchase the item. Optional. If this is not supplied then the buyer's existing card is used.
 */
@property (strong, nonatomic) TMDTCreditCardDetails *creditCardDetails;

/**
 The buyer's phone number. This is optional but if supplied, it will be included in the email that is sent to the seller. If the delivery instructions email has already been sent, then this information is ignored.
 */
@property (strong, nonatomic) NSString *contactPhoneNumber;

/**
 A message to the seller. This is optional but if supplied, it will be included in the email that is sent to the seller. If the delivery instructions email has already been sent, then this information is ignored.
 */
@property (strong, nonatomic) NSString *messageToSeller;

/**
 The password is used to ensure that the user of the device is allowed to pay for goods using their saved credit card details.
 */
@property (strong, nonatomic) NSString *password;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

@end
