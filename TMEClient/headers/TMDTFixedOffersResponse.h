//
//  TMDTFixedOffersResponse.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTPaginatedSearchResponse.h"

/**
 A paginated search response specific to retrieving a list of fixed price offers. See the API endpoint at:
 
 http://developer.trademe.co.nz/api-reference/fixed-price-offer-methods/retrieve-your-unreviewed-fixed-price-offers/
 */
@interface TMDTFixedOffersResponse : TMDTPaginatedSearchResponse

/**
 Contains a list of fixed price offers.
 */
@property (strong, nonatomic) NSArray *arrayOfFixedOffers;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionarySearchResponse;

@end
