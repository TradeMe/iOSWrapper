//
//  TMDTAuction.h
//  TMAPIClient
//
//  Created by Simon Cook on 22/05/12.
//  Copyright (c)2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NSDate+TMAdditions.h"

@class TMDTMember;
@class TMDTGeographicLocation;
@class TMDTSellerContactDetails;
@class TMDTAttribute;

/**
 This represents a listing on the Trade Me website.  
 
 For more information, start here; http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTListing : NSObject

/**
 The attributes for the item.
 */
@property (strong, nonatomic) NSArray *arrayOfAttributes;

/**
 A list of the last 10 bids for the listing.
 */
@property (strong, nonatomic) NSArray *arrayOfBids;

/**
 A collection of open home times for this listing. Only applies to open home listings.
 */
@property (strong, nonatomic) NSArray *arrayOfOpenHomes;

/**
 A comma-separated list of the available payment options e.g. “NZ Bank Deposit, Cash, Pay Now”.
 */
@property (strong, nonatomic) NSArray *arrayOfPaymentOptions;

/**
 A collection of photos for the listing.
 */
@property (strong, nonatomic) NSArray *arrayOfPhotos;

/**
 A list of questions and answers for the listing.
 */
@property (strong, nonatomic) NSArray *arrayOfQuestionAnswers;

/**
 Contains sales information for the listing. A “sale” in this context can via Buy Now, a fixed price offer or a winning bid. If you are the seller of this listing, this field contains information on all sales. If you are the buyer, then it contains information about your purchases only.
 */
@property (strong, nonatomic) NSArray *arrayOfSales;

/**
 A list of shipping options.
 */
@property (strong, nonatomic) NSArray *arrayOfShippingOptions;

/**
 The date the MaxBidAmount was placed.
 */
@property (strong, nonatomic) NSDate *asAt;

/**
 The number of bids on the item.
 */
@property (nonatomic) NSInteger bidCount;

/**
 The number of bidders and watcher for this listing.
 */
@property (nonatomic) NSInteger biddersAndWatchers;

/**
 The text used as the body of the item.
 */
@property (strong, nonatomic) NSString *body;

/**
 The Buy Now price.
 */
@property (strong, nonatomic) NSNumber *buyNowPrice;

/**
 The listing category.
 */
@property (strong, nonatomic) NSString *category;

/**
 The display name of the category.
 */
@property (strong, nonatomic) NSString *categoryName;

/**
 The category path, representing a top down string of category names from the root category to the leaf.
 */
@property (strong, nonatomic) NSString *categoryPath;

/**
 The ID of the delivery information (address, phone number, etc).
 */
@property (strong, nonatomic) NSNumber *deliveryId;

/**
 The date the listing will end.
 */
@property (strong, nonatomic) NSDate *endDate;

/**
 Indicates whether the item has Buy Now.
 */
@property (nonatomic) BOOL hasBuyNow;

/**
 Is this a listing with extra photos?
 */
@property (nonatomic) BOOL hasExtraPhotos;

/**
 Is this a gallery listing?
 */
@property (nonatomic) BOOL hasGallery;

/**
 Is this a homepage feature listing?
 */
@property (nonatomic) BOOL hasHomepageFeature;

/**
 Indicates whether there is more than one item available. Only applicable for Buy Now Only listings.
 */
@property (nonatomic) BOOL hasMultiple;

/**
 Indicates whether the payment was made with a credit card using Pay Now.
 */
@property (nonatomic) BOOL hasPaidByCreditCard;

/**
 Indicates whether the item has Pay Now.
 */
@property (nonatomic) BOOL hasPayNow;

/**
 Indicates whether the item has a reserve.
 */
@property (nonatomic) BOOL hasReserve;

/**
 Is this a listing with a scheduled end date?
 */
@property (nonatomic) BOOL hasScheduledEndDate;

/**
 Is this a bold listing?
 */
@property (nonatomic) BOOL isBold;

/**
 Indicates whether or not this is a Buy Now Only listing.
 */
@property (nonatomic) BOOL isBuyNowOnly;

/**
 Indicates whether the item is a classified.
 */
@property (nonatomic) BOOL isClassified;

/**
 Is this a featured listing?
 */
@property (nonatomic) BOOL isFeatured;

/**
 Indicates whether one flat shipping fee will be charged if more than one of this item is purchased. Only applicable for Buy Now Only listings.
 */
@property (nonatomic) BOOL isFlatShippingCharge;

/**
 Is this a highlighted listing?
 */
@property (nonatomic) BOOL isHighlighted;

/**
 Indicates whether the authenticated user is leading the bidding.
 */
@property (nonatomic) BOOL isLeading;

/**
 Indicates whether the item is marked as new.
 */
@property (nonatomic) BOOL isNew;

/**
 Indicates whether the item is on the authenticated member’s watchlist.
 */
@property (nonatomic) BOOL isOnWatchlist;

/**
 Indicates whether the item’s reserve has been met.
 */
@property (nonatomic) BOOL isReserveMet;

/**
 The ID of the listing.
 */
@property (strong, nonatomic) NSNumber *listingId;

/**
 The listing length.
 */
@property (strong, nonatomic) NSString *listingLength;

/**
 The current leading bid amount.
 */
@property (strong, nonatomic) NSNumber *maxBidAmount;

/**
 The note on an item.
 */
@property (strong, nonatomic) NSString *note;

/**
 The date of the note on an item.
 */
@property (strong, nonatomic) NSDate *noteDate;

/**
 The note id on an item.
 */
@property (strong, nonatomic) NSNumber *noteId;

/**
 The ID of the fixed price offer, if any.
 */
@property (strong, nonatomic) NSNumber *offerId;

/**
 Comma separated list of Payment options e.g. Credit Card, NZ Bank Account, etc". Also consult arrayOfPaymentOptions
 */
@property (strong, nonatomic) NSString *paymentInfo;

/**
 Descriptive message from the seller regarding account details or other payment decription
 */
@property (strong, nonatomic) NSString *paymentInstructions;

/**
 The ID of the primary photo for the listing (if the listing has a photo).
 */
@property (strong, nonatomic) NSNumber *photoId;

/**
 The URL of the primary photo for the listing (if the listing has a photo). By default you’ll get a thumbnail-sized photo, but you can control the size of the photo using the photo_size parameter.
 */
@property (strong, nonatomic) NSString *pictureHref;

/**
 The price the item was sold for, excluding shipping. If the purchase was for multiple items, this is the price of a single item.
 */
@property (strong, nonatomic) NSNumber *price;

/**
 The way the price is displayed.
 */
@property (strong, nonatomic) NSString *priceDisplay;

/**
 The purchase-specific id (or auction sold id).
 */
@property (strong, nonatomic) NSNumber *purchaseId;

/**
 The total quantity available of the item. Only applicable for Buy Now Only listings. When retrieving won items this value represents the number sold, not the total quantity. When retrieving sold items, this value is not present (use QuantitySold instead). When retrieving listing details, this value is only present if you are the seller.
 */
@property (nonatomic) NSInteger quantity;

/**
 The reference number that the buyer can use when making a deposit into the seller’s bank account.
 */
@property (strong, nonatomic) NSString *referenceNumber;

/**
 The restictions associated with the listing.
 */
@property (strong, nonatomic) NSString *restrictions;

/**
 The region ID for the item.
 */
@property (strong, nonatomic) NSNumber *regionId;

/**
 The region name for the item.
 */
@property (strong, nonatomic) NSString *region;

/**
 The listing ID of the new auction if this item did not sell and the auction was relisted.
 */
@property (strong, nonatomic) NSNumber *relistedItemId;

/**
 The reserve price for the auction. This is available in the sold/unsold items APIs and, if you are the seller, the listing details API.
 */
@property (strong, nonatomic) NSNumber *reservePrice;

/**
 This is the shipping price per item. Refer to totalShippingPrice when quantity is involved (solves the flat shipping charge problem as well)
 */
@property (strong, nonatomic) NSNumber *shippingPrice;

/**
 The date and time the item was sold.
 */
@property (strong, nonatomic) NSDate *soldDate;

/**
 Returned as a string. Can be one of: “offer”, “buynow” or “auction”. Casing is not guaranteed.
 */
@property (strong, nonatomic) NSString *soldType;

/**
 The date the listing was created.
 */
@property (strong, nonatomic) NSDate *startDate;

/**
 The start price.
 */
@property (strong, nonatomic) NSNumber *startPrice;

/**
 The subtitle, if present.
 */
@property (strong, nonatomic) NSString *subtitle;

/**
 The price for all items, excluding shipping (i.e. equal to SalePrice * QuantitySold).
 */
@property (strong, nonatomic) NSNumber *subtotalPrice;

/**
 The suburb name for the item.
 */
@property (strong, nonatomic) NSString *suburb;

/**
 The suburb id for the item.
 */
@property (strong, nonatomic) NSNumber *suburbId;

/**
 The listing title.
 */
@property (strong, nonatomic) NSString *title;

/**
 The total number of questions in the collection. Can be larger than the number of returned results.
 */
@property (strong, nonatomic) NSNumber *totalCountOfQuestionAnswers;

/**
 The total price for the entire sale, including shipping. If the purchase was for multiple items, all items are included in this price.
 */
@property (strong, nonatomic) NSNumber *totalSalePrice;

/**
 The total price for shipping. If flat shipping is not enabled, equal to ShippingPrice * QuantitySold.
 */
@property (strong, nonatomic) NSNumber *totalShippingPrice;

/**
 The number of times the listing has been viewed.
 */
@property (nonatomic) NSInteger viewCount;

/**
 A type that represents the state of the reserve price on this listing.
 */
typedef NS_ENUM(NSInteger, ReserveState) {
    ReserveStateNone = 0,           //-- There is no reserve on the item (i.e. the reserve price is the same as the starting price).
    ReserveStateMet = 1,            //-- The value of the highest bid has exceeded the reserve price.
    ReserveStateNotMet = 2,         //-- The value of the highest bid has not reached the reserve price.
    ReserveStateNotApplicable = 3   //-- The listing cannot have a reserve because bidding is not allowed. This may be because it is a classified or because it is a Buy Now Only auction.
};

/**
 The flag to display on an item.
 */
@property (nonatomic) ReserveState reserveState;

/**
 The buyer of this listing, if it has been sold.
 */
@property (strong, nonatomic) TMDTMember *buyer;

/**
 The latitude and longitude of the listing (e.g. for properties).
 */
@property (strong, nonatomic) TMDTGeographicLocation *geographicLocation;

/**
 The seller of this listing.
 */
@property (strong, nonatomic) TMDTMember *seller;

/**
 The contact details for a personal listing.
 */
@property (strong, nonatomic) TMDTSellerContactDetails *sellerContactDetails;

@property (weak, nonatomic) UIImage *imageMain;

#pragma mark -
/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

//--- utility methods

/**
 Returns a nicely formatted string that represents the time that this item was listed.
 
 For example, 'Listing 23 Mar'.
 */
- (NSString *)listed;

/**
 Returns a nicely formatted string that represents the date to display on the classified card.
 */
- (NSString *)listedDateForClassifiedCard;

/**
 Returns a nicely formatted string that displays the closed date.
 
 For example, 'Closed 12 Feb'.
 */
- (NSString *)closed;

/**
 Returns a nicely formatted string that displays the closed date using the date time use give it.
 */
- (NSString *)closedWithFormat:(kTMDateFormat)format;

/**
 Returns whether this listing has either closed or is in the process of closing
 */
- (BOOL)isClosingOrClosed;

/**
 Returns either the max bid amount or the start price, whichever one is larger.
 */
- (float)highestPrice;

/**
 Returns a nicely formatted currency string that represents either the max bid amount or the start price, whichever one is larger.
 */
- (NSString *)highestPriceAsCurrency:(BOOL)mustHaveDecimals;

/**
 Returns whether the highest price is the same as the starting price.
 */
- (BOOL)isAtStartingPrice;

/**
 Returns the next bid price.
 */
- (CGFloat)nextBidPrice;

/**
 Returns the start price as a nicely formatted currency string.
 */
- (NSString *)startPriceAsCurrency;

/**
 Returns the sub total price as a nicely formatted currency string.
 */
- (NSString *)subtotalPriceAsCurrency;

/**
 Returns the next bid price as a nicely formatted number string.
 */
- (NSString *)nextBidPriceAsValue;

/**
 Returns the next bid price as a nicely formatted currency string.
 */
- (NSString *)nextBidPriceAsCurrency;

/**
 Returns the buy now price as a nicely formatted currency string.
 */
- (NSString *)buyNowPriceAsCurrency;

/**
 Returns how much time is left (in seconds) before the listing closes.
 */
- (NSTimeInterval)timeLeftInSeconds;

/**
 Returns a nicely formatted string that represents how much time is left before the listing closes.
 
 For example, this method could return 'Closed', '20 secs', '1 min'.
 */
- (NSString *)timeLeftWithShortDateFormat:(BOOL)shortDateFormat;

/**
 Returns a nicely formatted string that represents how much time is left before the listing end date and the specified date that you pass in.
 
 For example, this method could return 'Closed', '20 secs', '1 min'.
 */
- (NSString *)timeLeftWithShortDateFormat:(BOOL)shortDateFormat sinceDate:(NSDate *)theDate;

/**
 Returns whether this listing is about to expire soon.
 */
- (BOOL)timeLeftExpiringSoon;

/**
 Returns a nicely formatted string that represents the bid count.
 
 For example, this method could return '1 bid', '20 bids', 'No Bids' or 'Classified'.
 */
- (NSString *)bids;

#pragma mark - Utility methods

/**
 Returns the attribute whose name is the passed in value or nil if not found
 */
- (TMDTAttribute *)attributeForName:(NSString *)attributeName;

@end
