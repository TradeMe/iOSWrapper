//
//  TMDTCreditCardDetails.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Contains details about a credit card.
 */
@interface TMDTCreditCardDetails : NSObject

/** 
 The full credit card number. 
 */
@property (strong, nonatomic) NSString *cardNumber;

/** 
 The name of the cardholder (this is usually stamped on the front of the card). 
 */
@property (strong, nonatomic) NSString *cardHolderName;

/** 
 The month when the credit card expires. 1 = January. 
 */
@property (strong, nonatomic) NSNumber *expiryMonth;

/** 
 The year when the credit card expires. 
 */
@property (strong, nonatomic) NSNumber *expiryYear;

/** 
 The three or four digit security code on the back of the card (often called CVV, CVC or CVC2). 
 */
@property (strong, nonatomic) NSString *securityCode;

/** 
 Indicates whether or not to suggest the card the next time the buyer needs to enter credit card details on Trade Me. 
 */
@property (nonatomic) BOOL saveCard;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 Returns a dictionary that represents the data that this object contains
 */
- (NSDictionary *)dictionaryRepresentation;

@end
