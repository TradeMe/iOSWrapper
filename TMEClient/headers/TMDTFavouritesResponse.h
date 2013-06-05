//
//  TMDTSearchFavouritesResponse.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMDTPaginatedSearchResponse.h"

/**
 A paginated search response specific to the downloading of favourites from the api.
 */
@interface TMDTFavouritesResponse : TMDTPaginatedSearchResponse

/**
 The list of favourites returned from the api.
 */
@property (strong, nonatomic) NSArray *arrayOfFavourites;

/**
 Create an instance of this class passing through data from a dictionary as well as the type of favourite to create.
 */
- (id)initWithDictionary:(NSDictionary *)dictionarySearchResponse forFavouriteType:(Class)favouriteClass;

@end
