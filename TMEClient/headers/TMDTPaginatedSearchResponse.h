//
//  TMDTPaginatedSearchResponse.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Base class that contains pagination properties used by every api call.
 */
@interface TMDTPaginatedSearchResponse : NSObject

/**
 The total number of results in the collection. Can be larger than the number of returned results.
 */
@property (nonatomic) NSInteger totalCount;

/**
 The index of the current page of results (starts at 1).
 */
@property (nonatomic) NSInteger page;

/**
 The number of results in the current page.
 */
@property (nonatomic) NSInteger pageSize;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionarySearchResponse;

@end
