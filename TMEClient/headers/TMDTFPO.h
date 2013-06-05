//
//  TMDTListingJob.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

@class TMDTAgency;
@class TMDTJobApplicationDetails;

/**
 Represents a single Fixed Price Offer as returned by the 'Retrieve your unreviewed fixed price offers' API method at:
 
 http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/retrieve-your-unreviewed-fixed-price-offers/
 */
@interface TMDTFPO : NSObject

/**
 The listing ID of the item on offer.
 */
@property (strong, nonatomic) NSNumber *listingId;

/**
 The title of the item on offer.
 */
@property (strong, nonatomic) NSString *title;

/**
 The offer price of the item on offer.
 */
@property (strong, nonatomic) NSNumber *offerPrice;

/**
 The date and time the fixed price offer expires.
 */
@property (strong, nonatomic) NSDate *offerExpiryDate;

/**
 The identifier of the category the item is listing in.
 */
@property (strong, nonatomic) NSString *mcat;

/**
 The URL of the thumbnail photo.
 */
@property (strong, nonatomic) NSString *pictureHref;

/**
 A list of shipping options for this fixed price offer.
 */
@property (strong, nonatomic) NSArray *arrayOfShippingOptions;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryFPO_;

@end
