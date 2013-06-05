//
//  TMAPIClient.h
//  TMAPIClient
//
//  Created by Nick Parfene on 11/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMDTFavourite.h"

@class TMDTBidRequest;
@class TMDTBidResponse;
@class TMDTBuyNowRequest;
@class TMDTBuyNowResponse;
@class TMDTCategory;
@class TMDTDeliveryAddress;
@class TMDTDeliveryAddressResponse;
@class TMDTEmailSellerRequest;
@class TMDTFixedOffersResponse;
@class TMDTFPO;
@class TMDTFPORequest;
@class TMDTFPOToMemberRequest;
@class TMDTFPOResponse;
@class TMDTFPOMemberResponse;
@class TMDTFavouritesResponse;
@class TMDTFavouriteSearch;
@class TMDTGenericResponse;
@class TMDTListing;
@class TMDTMemberProfile;
@class TMDTMemberSummaryResponse;
@class TMDTPaginatedSearchResponse;
@class TMDTPayNowRequest;
@class TMDTPayNowResponse;
@class TMDTPayNowStatusResponse;
@class TMDTQuestionAnswer;
@class TMDTSaveFavouriteResponse;
@class TMDTSearchResponse;
@class TMEOAuthHTTPClient;

//-- TODO enable this URL to support TEST, STAGE and PROD deployment modes
#define TMEClientBaseURL    @"https://api.trademe.co.nz"

/**
 These constants represent major categories used within Trade Me.  They are category codes.
 */
extern NSString * const TMECategoryPrefixFlatmates;
extern NSString * const TMECategoryPrefixJobs;
extern NSString * const TMECategoryPrefixMotors;
extern NSString * const TMECategoryPrefixProperty;
extern NSString * const TMECategoryPrefixServices;

/**
 Represents the set of options available if you wish to filter the list of sold items that will be returned by the api.
 
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-sold-items/
 */
typedef NS_ENUM(NSInteger, TMDTSoldItemsFilter) {
    TMDTSoldItemsFilterLast45Days,
    TMDTSoldItemsFilterLast30Days,
    TMDTSoldItemsFilterLast7Days,
    TMDTSoldItemsFilterLast3Days,
    TMDTSoldItemsFilterLast24Hours,
    TMDTSoldItemsFilterPaymentInstructionsToSend,
    TMDTSoldItemsFilterFeedbackToPlace,
    TMDTSoldItemsFilterEmailSent,
    TMDTSoldItemsFilterPaymentReceived,
    TMDTSoldItemsFilterGoodsShipped,
    TMDTSoldItemsFilterSaleCompleted
};

/**
 Represents the set of options available if you wish to filter the list of un-sold items that will be returned by the api.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-unsold-items/
 */
typedef NS_ENUM(NSInteger, TMDTUnsoldItemsFilter) {
    TMDTUnsoldItemsFilterLast45Days,
    TMDTUnsoldItemsFilterLast7Days,
    TMDTUnsoldItemsFilterLast24Hours,
    TMDTUnsoldItemsFilterItemsIHaveOffered,
    TMDTUnsoldItemsFilterItemsICanRelist
};

/**
 Represents the set of options available if you wish to filter the list of won items that will be returned by the api.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-won-items/
 */
typedef NS_ENUM(NSInteger, TMDTWonFilter) {
    TMDTWonFilterAll,
    TMDTWonFilterLast30Days,
    TMDTWonFilterLast7Days,
    TMDTWonFilterLast24Hours
};

/**
 Represents the set of options available if you wish to filter the list of lost items that will be returned by the api.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-lost-items/
 */
typedef NS_ENUM(NSInteger, TMDTLostFilter) {
    TMDTLostFilterAll,
    TMDTLostFilterLast7Days,
    TMDTLostFilterLast24Hours
};

/**
 Represents the set of options available if you wish to filter the list of watchlist items that will be returned by the api.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-watchlist/
 */
typedef NS_ENUM(NSInteger, TMDTWatchlistFilter) {
    TMDTWatchlistFilterAll,
    TMDTWatchlistFilterClosingToday,
    TMDTWatchlistFilterLeadingBids,
    TMDTWatchlistFilterReserveMet,
    TMDTWatchlistFilterReserveNotMet
};

/**
 Represents the set of options available if you wish to filter the list of members you can make a fixed price offer to for a particular auction.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/retrieve-a-list-of-members-for-a-fixed-price-offer/
 */
typedef NS_ENUM(NSInteger, TMDTFixPriceOfferMembersFilter) {
    TMDTFixPriceOfferMembersFilterAll,
    TMDTFixPriceOfferMembersFilterBidders,
    TMDTFixPriceOfferMembersFilterWatchers
};


/** This class allows developers to retrieve data from the Trade Me api and consume it.
 
 Trade Me requires the use of OAuth to authenticate and authorize the user.  This class will not work without a generated OAuth token and secret.
 
 You need to look at the Trade Me Api Client Sample application in order to see how to generate your session token and secret.
 
 For an overview of the OAuth process used by Trade Me go to;
 http://developer.trademe.co.nz/api-overview/authentication-authorisation/oauth/example-oauth-flow/
 */
@interface TMEClient : NSObject

@property (strong, nonatomic) TMEOAuthHTTPClient *client;

/**
 Returns the shared, singleton instance of the api client.
 */
+ (TMEClient *)sharedInstance;

/**
 Set the HTTPClient class to use.  If not called the default is AFHTTPClient
 */
- (BOOL)registerHTTPClientClass:(Class)clientClass;

/**
 Set the consumer key and secret for xauth/oauth authentication. You get the consumerKey and consumerSecret when you register an app on 
 http://www.trademe.co.nz/MyTradeMe/Api/MyApplications.aspx
 */
- (void)setConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret;

/**
 The client exposes a number of configuration options that can be queries and set/overriden via the preferences dictionary. 
 
 The defaults are (in minutes):
 kTMDTCheckIntervalCategories = 60
 kTMDTCheckIntervalRegions = 60
 
 Setting these to 0 will cause the TMAPIClient to always check the remote API for updates. Any positive value will cause the catalogue methods to return cached values for the duration of the "interval". 
 You can query the last check dates using the keys:
 kTMDTDateLastCheckCategories and kTMDTDateLastCheckRegions
 
 */
- (NSDictionary *)preferences;
- (void)setPreferences:(NSDictionary *)dictionaryOfPreferences;
- (void)setPreference:(NSString *)key value:(NSObject *) value_;

/**
 Call this before getCategories:failure:
 */
- (void)getCategoriesLastUpdated:(void (^)(NSDate *dateLastUpdated, NSError *error))completion;

/**
 Only call this after getCategoriesLastUpdatedSuccess:failure:
 */
- (void)getCategories:(void (^)(NSArray *categories, NSError *error))completion;

/**
 Returns the list of localities that are cached on the device, or nil.
 */
- (NSArray *)getCachedLocalities;

/**
 Get Localities
*/
- (void)getLocalities:(void (^)(NSArray *localities, NSError *error))completion;

/**
 Get Regions (used E-Tag as per http://developer.trademe.co.nz/api-overview/caching/)
 */
- (void)getRegions:(void (^)(NSArray *arrayOfRegions, NSError *error))completion;

/**
 Returns the list of delivery addresses for the current user.
 */
- (void)getDeliveryAddresses:(void (^)(NSArray *arrayOfDeliveryAddresses, NSError *error))completion;

/**
 Returns the list of motor bike makes.
 */
- (NSArray *)getCachedMotorbikeMakes;

/**
 Returns the list of motor bike makes.
 */
- (void)getMotorbikeMakes:(void (^)(NSArray *arrayOfMotorbikeMakes, NSError *error))completion;
/**
 Adds the specified delivery address to the current user's list of delivery addresses.
 */
- (void)addDeliveryAddress:(TMDTDeliveryAddress *)deliveryAddress completion:(void (^)(TMDTDeliveryAddressResponse *response, NSError *error))completion;

/**
 Removes the specified delivery address to the current user's list of delivery addresses.
 */
- (void)removeDeliveryAddress:(TMDTDeliveryAddress *)deliveryAddress completion:(void (^)(TMDTDeliveryAddressResponse *response, NSError *error))completion;

#pragma mark - Listing details / Bidding / Buying -
/**
 * Returns the listing details object.
 * Try casting via isKindOf: to TMDTListingProperty for example if the expected result should be a Property Listing
 */
- (void)getListingDetails:(NSString *)listingId 
               completion:(void (^)(TMDTListing *listing, NSError *error))completion;

/**
 Sends a message to the seller of a classified via email. If possible, the listing will be added to the authenticated member’s watchlist.
 */
- (void)emailSeller:(TMDTEmailSellerRequest *)emailSellerRequest
         completion:(void (^)(TMDTGenericResponse *apiResponse, NSError *error))completion;

/**
 Place a bid (normal or auto-bid) on a listing.
 */
- (void)placeBid:(TMDTBidRequest *)listingBidRequest
      completion:(void (^)(TMDTBidResponse *bidResponse, NSError *error))completion;

/**
 Buys an item using Buy Now.
 */
- (void)placeBuyNow:(TMDTBuyNowRequest *)buyNowRequest
         completion:(void (^)(TMDTBuyNowResponse *buyNowResponse, NSError *error))completion;

/**
 * Ask a question for the specified listing.
 * The error's code is the response code from the web server.
 * The error's localized desciption contains a human friendly error returned from the server if the error code is 400.
 */
- (void)askQuestion:(NSString *)question listingId:(NSNumber *)listingId
         completion:(void (^)(TMDTQuestionAnswer *questionAnswer, NSError *error))completion;

/**
 * Answer a question for the specified question in a listing.
 * The error's code is the response code from the web server.
 * The error's localized desciption contains a human friendly error returned from the server if the error code is 400.
 */
- (void)answerQuestionId:(NSNumber *)questionId listingId:(NSNumber *)listingId answer:(NSString *)answer
              completion:(void (^)(TMDTQuestionAnswer *questionAnswer, NSError *error))completion;

#pragma mark - Authentication -
/**
 * Clears authorization header and removes token data from the Keychain.  Does not actually make an API call to Trade Me
 */
- (void)logout;

/**
 * Returns nil when a user has not yet been authenticated
 */
- (NSNumber *)memberIdOfAuthenticatedUser;

#pragma mark - Search -
/**
 * Does a search across the whole website. The objects in the TMDTSearchResponse will all be of type TMDTListing.
 */
- (void)searchGeneral:(NSDictionary *)dictionaryOfSearchParamaters completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Used Motor listings. The objects in the TMDTSearchResponse will all be TMDTListingMotors.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/used-motors-search/
 */
- (void)searchMotorsUsed:(NSDictionary *)dictionaryOfSearchParamaters
              completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Boats listings. The objects in the TMDTSearchResponse will all be TMDTListingMotors.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/motorboat-search/
 */
- (void)searchMotorsBoats:(NSDictionary *)dictionaryOfSearchParamaters
               completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Motorbike listings. The objects in the TMDTSearchResponse will all be TMDTListingMotors.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/motorbike-search/
 */
- (void)searchMotorsBikes:(NSDictionary *)dictionaryOfSearchParamaters
               completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Residential for Sale listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/residential-search/
 */
- (void)searchResidentialForSale:(NSDictionary *)dictionaryOfSearchParamaters
                      completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Residential for Rent listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/rental-search/
 */
- (void)searchResidentialForRent:(NSDictionary *)dictionaryOfSearchParamaters
                      completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Commercial For Sale listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/commercial-sale-search/
 */
- (void)searchCommercialSale:(NSDictionary *)dictionaryOfSearchParamaters
                  completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Commerical For Lease listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/commerical-lease-search/
 */
- (void)searchCommercialLease:(NSDictionary *)dictionaryOfSearchParamaters
                   completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Rural property listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/rural-property-search/
 */
- (void)searchRural:(NSDictionary *)dictionaryOfSearchParamaters
         completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Lifestyle property listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/lifestyle-property-search/
 */
- (void)searchLifestyle:(NSDictionary *)dictionaryOfSearchParamaters
             completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Retirement property listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/retirement-village-search/
 */
- (void)searchRetirement:(NSDictionary *)dictionaryOfSearchParamaters
              completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Flatmates listings. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/retirement-village-search/
 */
- (void)searchFlatmates:(NSDictionary *)dictionaryOfSearchParamaters
             completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Open Homes listings that have Open Home times. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation: http://developer.trademe.co.nz/api-reference/search-methods/flatmate-search/
 */
- (void)searchResidentialOpenHomes:(NSDictionary *)dictionaryOfSearchParamaters
                        completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Restricts the search to just Jobs listings that have Open Home times. The objects in the TMDTSearchResponse will all be TMDTListingProperty.
 * Official documentation:http://developer.trademe.co.nz/api-reference/search-methods/jobs-search/
 */
- (void)searchJobs:(NSDictionary *)dictionaryOfSearchParamaters
        completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

#pragma mark - My Trade Me
/**
 Retrieves a list of items on the authenticated user’s watchlist.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-watchlist/
 */
- (void)getWatchlist:(NSDictionary *)dictionaryOfParameters watchlistFilterType:(TMDTWatchlistFilter)watchlistFilterType
          completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Retrieves a list of purchases for the authenticated user. Multiple-quantity auctions can be purchased multiple times.
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-won-items/
 */
- (void)getWonItems:(NSDictionary *)dictionaryOfParameters wonFilterType:(TMDTWonFilter)wonFilterType
            completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Retrieves listings the authenticated user lost. A listing counts as “lost” if it is on the user’s watchlist when it closes.    
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-lost-items/
 */
- (void)getLostItems:(NSDictionary *)dictionaryOfParameters lostFilterType:(TMDTLostFilter)lostFilterType 
          completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-sold-items/
 */
- (void)getSoldItems:(NSDictionary *)dictionaryOfParameters soldFilterType:(TMDTSoldItemsFilter)soldFilterType
             completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-unsold-items/
 */
- (void)getUnsoldItems:(NSDictionary *)dictionaryOfParameters unsoldFilterType:(TMDTUnsoldItemsFilter)unsoldFilterType
            completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Official documentation: http://developer.trademe.co.nz/api-reference/my-trade-me-methods/retrieve-your-profile-information/
 */
- (void)getMemberSummaryWithCompletion:(void (^)(TMDTMemberSummaryResponse *memberSummary, NSError *error))completion;


#pragma mark - FPO
/**
 Retrieves a list of the outstanding fixed price offers that have been offered to the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/retrieve-your-unreviewed-fixed-price-offers/
 */
- (void)getFPOItems:(NSDictionary *)dictionaryOfParameters
         completion:(void (^)(TMDTFixedOffersResponse *fixedOffersResponse, NSError *error))completion;

/**
 Accepts or rejects a fixed price offer.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/respond-to-a-fixed-price-offer/
 */
- (void)respondToFPO:(TMDTFPORequest *)fpoRequest
          completion:(void (^)(TMDTFPOResponse *fpoResponse, NSError *error))completion;

/**
 Makes a fixed price offer for an auction to the specified members.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/make-a-fixed-price-offer/
 */
- (void)makeFPO:(TMDTFPOToMemberRequest *)fpoToMemberRequest
     completion:(void (^)(TMDTFPOResponse *fpoResponse, NSError *error))completion;

/**
 Withdraws an offer that is current and not expired, accepted or rejected by all users.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/withdraw-a-fixed-price-offer/
 */
- (void)withdrawFPOForListingId:(NSInteger)listingId
                     completion:(void (^)(TMDTFPOResponse *fpoResponse, NSError *error))completion;

/**
 Returns a list of members you can make a fixed price offer to for a particular auction.
 Official documentation: http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/retrieve-a-list-of-members-for-a-fixed-price-offer/
 */
- (void)getMembersForFPOWithListingId:(NSInteger)listingId
                               filter:(TMDTFixPriceOfferMembersFilter)memberType
                           completion:(void (^)(TMDTFPOMemberResponse *fpoMemberResponse, NSError *error))completion;

#pragma mark - Favourite Searches
- (void)saveSearchAsFavourite:(NSDictionary *)dictionaryOfSearchParameters
favouriteSearchEmailFrequency:(TMDTFavouriteEmailOption)favouriteEmailFrequency
       favouriteSearchApiType:(TMDTFavouriteSearchApi)favouriteApiType
                   completion:(void (^)(TMDTSaveFavouriteResponse *apiResponse, NSError *error))completion;

/**
 Removes the specified favourite from the currently authenticated user's list of favourites.
 Offical documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/remove-a-saved-favourite/
 */
- (void)removeFavourite:(TMDTFavourite *)favourite
             completion:(void (^)(TMDTGenericResponse *apiResponse, NSError *error))completion;

/**
 Removes the specified favourite from the currently authenticated user's list of favourites.
 Offical documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/remove-a-saved-favourite/
 */
- (void)removeFavourite:(NSNumber *)favouriteId
           favouriteType:(TMDTFavouriteType)favouriteType
             completion:(void (^)(TMDTGenericResponse *apiResponse, NSError *error))completion;

- (void)updateFavourite:(TMDTFavourite *)favouriteSearch
         emailFrequency:(TMDTFavouriteEmailOption)emailfrequency
             completion:(void (^)(TMDTSaveFavouriteResponse *apiResponse, NSError *error))completion;

/**
 Retrieves the list of all favourite searches for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-searches/
 */
- (void)getFavouriteSearchesAll:(NSDictionary *)dictionaryOfParameters
                     completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

/**
 A utility method that invokes all the neccessary api calls in order to retrieve the entire set of favourites for the currently authenticated user.
 These are executed as a single http batch operation.  Once all the user's favourites have been downloaded, the completion blocks are invoked in the
 following order; favourite searches, favourite categories and favourite sellers.
 */
- (void)getFavouritesAllWithCategoryCompletion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))categoriesCompletion
                              searchCompletion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))searchCompletion
                              sellerCompletion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))sellerCompletion
                             overallCompletion:(void (^)())overallCompletion;

/**
 Retrieves the list of favourite general searches for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-searches/
 */
- (void)getFavouriteSearchesGeneral:(NSDictionary *)dictionaryOfParameters
                         completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

/**
 Retrieves the list of favourite property searches for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-searches/
 */
- (void)getFavouriteSearchesProperty:(NSDictionary *)dictionaryOfParameters
                          completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

/**
 Retrieves the list of favourite job searches for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-searches/
 */
- (void)getFavouriteSearchesJobs:(NSDictionary *)dictionaryOfParameters
                      completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

/**
 Retrieves the list of favourite motor searches for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-searches/
 */
- (void)getFavouriteSearchesMotors:(NSDictionary *)dictionaryOfParameters
                        completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

/**
 Executes a listing search for a specified favourite object.
 */
- (void)searchFavourite:(TMDTFavourite *)favouriteSearch
             parameters:(NSDictionary *)dictionaryOfParameters
             completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

#pragma mark - Favourite Categories
/**
 Retrieves the list of favourite categories for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-categories/
 */
- (void)getFavouriteCategories:(NSDictionary *)dictionaryOfParameters
                    completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

#pragma mark - Favourite Sellers
/**
 Retrieves the list of favourite sellers for the currently authenticated user.
 Official documentation: http://developer.trademe.co.nz/api-reference/favourite-methods/retrieve-your-favourite-sellers/
 */
- (void)getFavouriteSellers:(NSDictionary *)dictionaryOfParameters
                 completion:(void (^)(TMDTFavouritesResponse *searchResponse, NSError *error))completion;

#pragma mark - Watchlist methods
/**
 Adds listing to watchlist
 */
- (void)addToWatchlist:(NSString *)listingId
          completion:(void (^)(TMDTGenericResponse *apiResponse, NSError *error))completion;

/**
 Remove listing from watchlist
 */
- (void)removeFromWatchlist:(NSString *)listingId
                 completion:(void (^)(TMDTGenericResponse *apiResponse, NSError *error))completion;

#pragma mark - Membership Methods
/**
 Returns the member's profile (it's a wrapper around the TMDTMember object with extra personal information)
 */
- (void)getMemberProfile:(NSNumber *)memberId
              completion:(void (^)(TMDTMemberProfile *memberProfile, NSError *error))completion;

/**
 Gets the listings for the specified member
 */
- (void)searchMemberListings:(NSNumber *)memberId 
            searchParameters:(NSDictionary *)dictionaryOfSearchParamaters 
                  completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 Gets the property listings for the specified member
 */
- (void)searchMemberPropertyListings:(NSNumber *)memberId
                    searchParameters:(NSDictionary *)dictionaryOfSearchParamaters 
                          completion:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

#pragma mark - pay now Methods
/**
 Attempts to pay for an item.
 */
- (void)payNow:(TMDTPayNowRequest *)payNowDetails completion:(void (^)(TMDTPayNowResponse *response, NSError *error))completion;

/**
 Fetch the pay now status for an item. If the status code is not successful, no data is returned.
 */
- (void)getPayNowStatus:(NSNumber *)purchaseId
             completion:(void (^)(TMDTPayNowStatusResponse *payNowStatus, NSError *error))completion;

@end
