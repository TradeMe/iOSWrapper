//
//  TMDTSearchCriteriaManager.h
//  TMAPIClient
//
//  Created by Nick Parfene & Stefan Church on 16/01/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMESearchCriteria.h"

extern NSString * const TMESearchCriteriaSearchTermKey;
extern NSString * const TMESearchCriteriaBuyNowKey;
extern NSString * const TMESearchCriteriaPayNowKey;
extern NSString * const TMESearchCriteriaConditionKey;
extern NSString * const TMESearchCriteriaSortKey;
extern NSString * const TMESearchCriteriaSalaryMinKey;
extern NSString * const TMESearchCriteriaSalaryMaxKey;
extern NSString * const TMESearchCriteriaCategoryKey;

/**
 * My Trade Me filters
 */
extern NSString * const TMESearchCriteriaMyTradeMeFilterKey;

/**
 * Member Search
 */
extern NSString * const TMESearchCriteriaMemberIdKey;

/**
 * Category specific keys (filters that only apply in those categories)
 */
extern NSString * const TMESearchCriteriaBabyClothingGenderKey;
extern NSString * const TMESearchCriteriaDigitalCamerasBrandKey;
extern NSString * const TMESearchCriteriaPhoneAccessoriesPhoneBrandKey;
extern NSString * const TMESearchCriteriaMotorsUsedBodyKey;
extern NSString * const TMESearchCriteriaMotorsUsedTransmissionKey;
extern NSString * const TMESearchCriteriaMotorsUsedListingTypeKey;
extern NSString * const TMESearchCriteriaMotorsUsedDoorsMinKey;
extern NSString * const TMESearchCriteriaMotorsUsedDoorsMaxKey;
extern NSString * const TMESearchCriteriaMotorsUsedEngineSizeMinKey;
extern NSString * const TMESearchCriteriaMotorsUsedEngineSizeMaxKey;
extern NSString * const TMESearchCriteriaMotorsUsedOdometerMinKey;
extern NSString * const TMESearchCriteriaMotorsUsedOdometerMaxKey;
extern NSString * const TMESearchCriteriaMotorsUsedYearMinKey;
extern NSString * const TMESearchCriteriaMotorsUsedYearMaxKey;
extern NSString * const TMESearchCriteriaMotorsUsedModelKey;
extern NSString * const TMESearchCriteriaPriceMinKey;
extern NSString * const TMESearchCriteriaPriceMaxKey;
extern NSString * const TMESearchCriteriaMotorBoatsTypeKey;
extern NSString * const TMESearchCriteriaMotorBoatsLengthMinKey;
extern NSString * const TMESearchCriteriaMotorBoatsLengthMaxKey;
extern NSString * const TMESearchCriteriaMotorBikesYearMinKey;
extern NSString * const TMESearchCriteriaMotorBikesYearMaxKey;
extern NSString * const TMESearchCriteriaMotorBikesEngineSizeMinKey;
extern NSString * const TMESearchCriteriaMotorBikesEngineSizeMaxKey;
extern NSString * const TMESearchCriteriaMotorBikesTypeKey;
extern NSString * const TMESearchCriteriaMotorsMakeKey;
extern NSString * const TMESearchCriteriaJobsTypeKey;
extern NSString * const TMESearchCriteriaPropertyCommercialLeaseAreaMinKey;
extern NSString * const TMESearchCriteriaPropertyCommercialLeaseAreaMaxKey;
extern NSString * const TMESearchCriteriaPropertyUsageKeyey;
extern NSString * const TMESearchCriteriaPropertyTypeKey;
extern NSString * const TMESearchCriteriaPropertyResidentialOpenHomesKey;
extern NSString * const TMESearchCriteriaPropertyBedroomsMinKey;
extern NSString * const TMESearchCriteriaPropertyBedroomsMaxKey;
extern NSString * const TMESearchCriteriaPropertyLandAreaMinKey;
extern NSString * const TMESearchCriteriaPropertyLandAreaMaxKey;
extern NSString * const TMESearchCriteriaPropertyBathroomsMinKey;
extern NSString * const TMESearchCriteriaPropertyBathroomsMaxKey;
extern NSString * const TMESearchCriteriaCpuSpeedMinKey;
extern NSString * const TMESearchCriteriaCpuSpeedMaxKey;
extern NSString * const TMESearchCriteriaMemoryMinKey;
extern NSString * const TMESearchCriteriaMemoryMaxKey;
extern NSString * const TMESearchCriteriaHardDriveSizeMinKey;
extern NSString * const TMESearchCriteriaHardDriveSizeMaxKey;
extern NSString * const TMESearchCriteriaScreenSizeMinKey;
extern NSString * const TMESearchCriteriaScreenSizeMaxKey;
extern NSString * const TMESearchCriteriaPropertyAdjacentSuburbsKey;

@class TMDTCategory;
@class TMESearchCriteria;
@class TMESearchAttributeGroup;
@class TMESearchAttribute;
@class TMDTSearchResponse;

@protocol TMDTSearchCriteriaDelegate;

/**
 Manages the different Trade Me api end points so that they are exposed to you as a single TMDTSearchCriteria object.
 */
@interface TMESearchCriteriaManager : NSObject

/**
 * Changes of the category may trigger delegate callbacks. These changes may mean that sort orders, regions or filters have
 * been updaded or ever cleared altogether
 */
@property (strong, nonatomic) TMDTCategory *category;

/**
 * When searching across MyTradeMe endpoints this is the property that needs to be set e.g. TMESearchCriteriaTypeWatchlist
 */
@property (nonatomic) TMESearchCriteriaType searchType;

/*
 * Sets the keyword in the TMDTSearchCriteriaSearchTermKey attribute group
 */
@property (strong, nonatomic) NSString *keyword;

/*
 * Immutable TMDTSearchCriteria object. Please use the business functions below to update its contents
 */
@property (strong, nonatomic, readonly) TMESearchCriteria *searchCriteria;

/**
 * The last/curent search response (if a search has run) and the error it has/has not produced
 */
@property (strong, nonatomic) TMDTSearchResponse *searchResponse;
@property (strong, nonatomic) NSError *error;

#pragma mark - Business functions
/**
 * Returns a singleton, shared instance of a search criteria manager.
 */
+ (TMESearchCriteriaManager *)sharedInstance;

/**
 * Clears the user selection in the TMDTSearchAttributeGroup with the corresponding TMDTSearchCriteria<Name>Key
 */
- (void)clearAttributeGroup:(NSString *)attributeGroupKey;

/**
 * Saves the user's selection (attribute) in the corresponding attributeGroup. If the group type is TMESearchAttributeTypeMultipleValues
 * this will just add the attribute to the arrayOfUserSelectedAttributes. If the group type is TMESearchAttributeTypeSingleValue
 * the array will be emptied first
 */
- (void)setSelectedAttribute:(TMESearchAttribute *)attribute inAttributeGroup:(TMESearchAttributeGroup *)attributeGroup;

/**
 Does what it says on the tin. Pass nil to remove the user selection.
 */
- (void)setSelectedRegion:(TMDTRegion *)region district:(TMDTDistrict *)district suburbs:(NSArray *)arrayOfSelectedSuburbs;

/**
 * Returns the corresponding attribute group that has the TMDTSearchCriteria<Name>Key key
 */
- (TMESearchAttributeGroup *)attributeGroupWithKey:(NSString *)attributeGroupKey;


-(void)setCategory:(TMDTCategory *)category andQueryString:(NSString *)queryString;

/**
 * Downloads the list of regions relevant to the current search criteria. If there are no regions then success will call back with an empty array.
 */
- (void)getRegions:(void (^)(NSArray *arrayOfRegions, NSError *error))completion;

#pragma mark - Utility methods (derived off the above)
/**
 * Returns the attribute group with key TMDTSearchCriteriaSortKey
 */
- (TMESearchAttributeGroup *)attributeGroupSortOrder;

/**
 * Returns the search type that would normally be used for a category
 */
- (TMESearchCriteriaType)searchTypeForCategory:(TMDTCategory *)category;

#pragma mark - Listeners
- (void)addSearchCriteriaChangeListner:(id<TMDTSearchCriteriaDelegate>)listener;
- (void)removeSearchCriteriaChangeListner:(id<TMDTSearchCriteriaDelegate>)listener;
- (void)removeAllCriteriaChangeListners:(id<TMDTSearchCriteriaDelegate>)listener;

#pragma mark - Search
/**
 * Starts a new search. Call getNextSearchResults: to get the next page.
 */
- (void)searchWithCompletion:(void (^)(TMDTSearchResponse *, NSError *))completion;

/**
 * Gets the next set of search results. Check searchResponse's totalCount and arrayOfListings to know when there are no more search results.
 */
- (void)getNextSearchResults:(void (^)(TMDTSearchResponse *searchResponse, NSError *error))completion;

/**
 * Does what it says on the tin
 */
- (BOOL)hasMoreSearchResults;

/**
 * Does what it says on the tin. Also resets the page count.
 */
- (void)resetSearchCriteria;

/**
 * Resets the page (but keeps the existing search criteria). To reset the criteria then call -setCategory:nil
 * and then re-apply your search settings
 */
- (void)resetPageCount;

@end

#pragma mark - Delegate

/**
 The purpose of this delegate is to provide feedback to consumers about changes in the search criteria manager, for example,
 you can be informed when the search criteria manager is about to start a new search.
 */
@protocol TMDTSearchCriteriaDelegate <NSObject>

@optional

/**
 * Notify listeners that a searchCriteria replacement has occurred (due to a change of categories in the previous search criteria)
 */
- (void)searchCriteriaHasBeenReplacedBySearchCriteria:(TMESearchCriteria *)searchCriteria;

/*
 * Notifies the listeners that something has changed inside the search criteria
 */
- (void)searchCriteriaAttributeGroupsHaveChanged;

/**
 * Called when the search criteria gets reset as a result of - resetSearchCriteria
 */
- (void)searchCriteriaDidReset;

/**
 * Does what it says on the tin
 */
- (void)searchCriteriaManagerWillBeginNewSearch;

/**
 * Does what it says on the tin
 */
- (void)searchCriteriaManagerDidFinishSearchWithSearchResponse:(TMDTSearchResponse *)searchResonse error:(NSError *)error;

@end
