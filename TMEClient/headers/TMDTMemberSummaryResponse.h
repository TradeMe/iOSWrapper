//
//  TMDTMemberSummaryResponse.h
//  TMAPIClient
//
//  Created by Stefan Church on 17/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a class that contains information returned when retrieving your user profile.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-profile-information/
 */
@interface TMDTMemberSummaryResponse : NSObject

/**
 The number of items on the watchlist.
 */
@property (nonatomic) NSInteger watchListCount;

/**
 The number of items won.
 */
@property (nonatomic) NSInteger wonCount;

/**
 The number of items lost.
 */
@property (nonatomic) NSInteger lostCount;

/**
 The number of items being sold.
 */
@property (nonatomic) NSInteger sellingCount;

/**
 The number of items sold.
 */
@property (nonatomic) NSInteger soldCount;

/**
 The number of items unsold.
 */
@property (nonatomic) NSInteger unsoldCount;

/**
 The total positive feedback.
 */
@property (nonatomic) NSInteger positiveFeedback;

/**
 The total negative feedback.
 */
@property (nonatomic) NSInteger negativeFeedback;

/**
 The total feedback (positive – negative).
*/
@property (nonatomic) NSInteger totalFeedback;

/**
 The ID of the member.
 */
@property (strong, nonatomic) NSNumber *memberId;

/**
 The member’s nickname.
 */
@property (strong, nonatomic) NSString *nickname;

/**
 The date the member joined.
 */
@property (strong, nonatomic) NSDate *dateJoined;

/**
 The date the member’s address was verified.
 */
@property (strong, nonatomic) NSDate *dateAddressVerified;

/**
 Indicates whether the address has been verified.
 */
@property (nonatomic) BOOL isAddressVerified;

/**
 The member’s Trade Me account balance.
 */
@property (strong, nonatomic) NSNumber *balance;

/**
 The member’s Pay Now account balance.
 */
@property (strong, nonatomic) NSNumber *payNowBalance;

/**
 The member’s first name.
 */
@property (strong, nonatomic) NSString *firstName;

/**
 The member’s last name.
 */
@property (strong, nonatomic) NSString *lastName;

/**
 The number of fixed price offers for the member.
 */
@property (nonatomic) NSInteger fixedPriceOffers;

/**
 The email address for the member.
 */
@property (strong, nonatomic) NSString *email;

/**
 Indicates whether the member is authenticated.
 */
@property (nonatomic) BOOL isAuthenticated;

/**
 Indicates whether the member can accept Pay Now payments.
 */
@property (nonatomic) BOOL isPayNowAccepted;

/**
 The number of saved searches in the member’s favourites.
 */
@property (nonatomic) NSInteger favouriteSearchCount;

/**
 The number of saved categories in the member’s favourites.
 */
@property (nonatomic) NSInteger favouriteCategoryCount;

/**
 The number of saved sellers in the member’s favourites.
 */
@property (nonatomic) NSInteger favouriteSellerCount;

/**
 Indicates whether the member has set up auto-billing.
*/
@property (nonatomic) BOOL autoBillingEnabled;

/**
 Indicates whether the member can list clearance items using the IsClearance flag. This is currently only for certain elite sellers.
**/
@property (nonatomic) BOOL canListClearanceItems;

/**
 Indicates whether the member is currently a registered top seller.
 */
@property (nonatomic) BOOL isTopSeller;

/**
 Indicates whether the member is registered as a property agent.
 */
@property (nonatomic) BOOL isPropertyAgent;

/**
 Indicates whether the member is registered as a rental agent.
 */
@property (nonatomic) BOOL isRentalAgent;

/**
 Indicates whether the member is registered as a job agent.
 */
@property (nonatomic) BOOL isJobAgent;

/**
 If the user has a saved credit card that they can use, contains the card type (“Visa”, “Mastercard”, etc). Will be omitted if the user does not have a saved card.
 */
@property (strong, nonatomic) NSString *creditCardType;

/**
 If the user has a saved credit card, contains the last four digits of the card number (e.g. “1234″). Will be omitted if the user does not have a saved card.
 */
@property (strong, nonatomic) NSString *creditCardLastFourDigits;

/**
 If the user has a saved credit card, contains the month when it expires (1 = January, 12 = December).
 */
@property (nonatomic) NSInteger creditCardExpiryMonth;

/**
 If the user has a saved credit card, contains the year when it expires.
 */
@property (nonatomic) NSInteger creditCardExpiryYear;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryMember;

@end
