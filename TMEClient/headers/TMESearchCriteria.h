//
//  TMDTSearchCriteria.h
//  TMAPIClient
//
//  Created by Nick Parfene on 16/01/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTFavouriteSearch.h"

@class TMESearchAttributeGroup;
@class TMDTCategory;
@class TMDTRegion;
@class TMDTDistrict;

typedef NS_ENUM(NSInteger, TMESearchCriteriaRegionType) {
    TMESearchCriteriaRegionTypeOneTier = 0,
    TMESearchCriteriaRegionTypeTwoTier = 1, // these are three tier regions without the third tier, i.e, suburbs.
    TMESearchCriteriaRegionTypeThreeTier = 2,
    TMESearchCriteriaRegionTypeThreeTierMultiSelect = 3,
    TMESearchCriteriaRegionTypeNone = 4 //-- e.g. Flights, Accommodation International, Holiday Packages
};

typedef NS_ENUM(NSInteger, TMESearchCriteriaType) {
    TMESearchCriteriaTypeGeneral = 0,
    TMESearchCriteriaTypeMotorsUsed = 1,
    TMESearchCriteriaTypeMotorBoat = 2,
    TMESearchCriteriaTypeMotorBike = 3,
    TMESearchCriteriaTypeResidential = 4,
    TMESearchCriteriaTypeRental = 5,
    TMESearchCriteriaTypeCommmercialSale = 6,
    TMESearchCriteriaTypeCommmercialLease = 7,
    TMESearchCriteriaTypeRural = 8,
    TMESearchCriteriaTypeLifestlye = 9,
    TMESearchCriteriaTypeFlatmate = 10,
    TMESearchCriteriaTypeOpenHomes = 11,
    TMESearchCriteriaTypeRetirement = 12,
    TMESearchCriteriaTypeJob = 13,
    TMESearchCriteriaTypeResidentialCarpark = 14,
    TMESearchCriteriaTypeSectionForSale = 15,
    TMESearchCriteriaTypeWomenswear = 16,
    TMESearchCriteriaTypeMenswear = 17,
    TMESearchCriteriaTypeBabyClothing = 18,
    TMESearchCriteriaTypeDigitalCameras = 19,
    TMESearchCriteriaTypeTravelAccommodation = 20,
    TMESearchCriteriaTypeFlights = 21,
    TMESearchCriteriaTypeHolidayPackages = 22,
    TMESearchCriteriaTypePhoneAccessories = 23,
    TMESearchCriteriaTypeDesktops = 24,
    TMESearchCriteriaTypeLaptops = 25,
    TMESearchCriteriaTypeBusinessesForSale = 26,
    TMESearchCriteriaTypeServices = 27,
    TMESearchCriteriaTypeMoviesTV = 28,
    TMESearchCriteriaTypeWatchlist = -14,
    TMESearchCriteriaTypeItemsIWon = -15,
    TMESearchCriteriaTypeItemsILost = -16,
    TMESearchCriteriaTypeUndetermined = -19
};

/**
 Responsible for managing sort orders, regions and filters for all the non-my trade me search endpoints.

 For more information, see http://developer.trademe.co.nz/api-reference/search-methods/
 */
@interface TMESearchCriteria : NSObject {
    NSDictionary *_dictionaryOfSearchAttributeGroups;
}

@property (strong, nonatomic) TMDTCategory *category;

- (id)initWithCategory:(TMDTCategory *)category;

/**
 * Holds all the available filters. A TMSearchAttributeGroup wraps a TMSearchAttribute.
 */
@property (strong, nonatomic) NSDictionary *dictionaryOfSearchAttributeGroups;

/**
 Storage for region, district and suburbs that have been selected by the user.
 Districts apply to services and businesses for sale listings. See http://developer.trademe.co.nz/api-reference/search-methods/general-search/
 */
@property (strong, nonatomic) TMDTRegion *regionSelected;
@property (strong, nonatomic) TMDTDistrict *districtSelected;
@property (strong, nonatomic) NSArray *arrayOfSelectedSuburbs;
@property (nonatomic) TMESearchCriteriaRegionType regionType;

/**
 Returns the search api number required when saving a favourite.
 */
- (TMDTFavouriteSearchApi)favouriteSearchApi;

/**
 * Returns the search type for the current search criteria. Each subclass will return the "appropriate" search type
 */
- (TMESearchCriteriaType)searchType;

/**
 Returns the name of the search term parameter name used by this criteria.  This is typically 'search_string' for most criteria,
 but for the motors used api this is the 'model parameter name.
 */
- (NSString *)searchTermParameterName;

/**
 * Returns the URL query string. Does not include the '?' character.
 */
- (NSString *)queryString;

/**
 Configures the search criteria based on the query string.
 */
- (void)setQueryString:(NSString *)queryString;

/**
 Returns the correct parameter name for region parameter
 */
- (NSString *)regionQueryParameterName;

@end

