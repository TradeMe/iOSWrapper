//
//  TMDTSale.h
//  TMAPIClient
//
//  Created by Stefan Church on 2/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

@class TMDTDeliveryAddress;
@class TMDTMember;

#import "TMESearchCriteria.h"

typedef NS_ENUM(NSInteger, TMDTSaleMethod) {
    TMDTSaleMethodAuction = 0,
    TMDTSaleMethodBuyNow = 1,
    TMDTSaleMethodOffer = 2,
};

@interface TMDTSale : NSObject

@property (strong, nonatomic) TMDTMember *buyer;
@property (strong, nonatomic) TMDTDeliveryAddress *deliverAddress;
@property (nonatomic) BOOL hasBuyerPlacedFeedback;
@property (nonatomic) BOOL hasPaidByCreditCard;
@property (nonatomic) BOOL hasSellerPlacedFeedback;
@property (strong, nonatomic) NSString *messageFromBuyer;
@property (nonatomic) TMDTSaleMethod method;
@property (strong, nonatomic) NSString *paymentInstructions;
@property (strong, nonatomic) NSNumber *price;
@property (strong, nonatomic) NSNumber *purchaseId;
@property (nonatomic) NSInteger quantitySold;
@property (strong, nonatomic) NSString *referenceNumber;
@property (strong, nonatomic) NSString *selectedShipping;
@property (strong, nonatomic) NSNumber *shippingPrice;
@property (strong, nonatomic) NSDate *soldDate;
@property (strong, nonatomic) NSNumber *subtotalPrice;
@property (strong, nonatomic) NSNumber *totalSalePrice;
@property (strong, nonatomic) NSNumber *totalShippingPrice;

- (id)initWithDictionary:(NSDictionary *)dictionarySale;

@end
