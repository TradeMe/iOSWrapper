//
//  TMDTSearchResponse.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTPaginatedSearchResponse.h"
#import "TMDTFavourite.h"

/**
 A base paginated search class that contains the array of listings, suggested categories, a favourite id and other
 properties for a general search response.
 */
@interface TMDTSearchResponse : TMDTPaginatedSearchResponse

/**
 A list of the results in the current page.
 */
@property (strong, nonatomic) NSArray *arrayOfListings;

/**
 The suggestion string, if the search produced no results and there is a popular search term that is lexigraphically close to the search string.
 */
@property (strong, nonatomic) NSString *didYouMean;

/**
 A collection of category counts for the search.
 */
@property (strong, nonatomic) NSArray *arrayOfSuggestedCategories;

/**
 The ID of a favourite search that corresponds to the current search, if the call is authenticated and the authenticated member has a favourite search that matches.
 */
@property (strong, nonatomic) NSNumber *favouriteId;

/**
 The type of favourite (e.g. “Category”, “Search”, “Seller”) that the FavouriteId property refers to. Only applicable for searches that match one of the authenticated user’s favourites.
 */
@property (nonatomic) TMDTFavouriteType favouriteType;

/**
 * The query string that was used to produce the search response
 */
@property (strong, nonatomic) NSString *queryString;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionarySearchResponse;

@end
