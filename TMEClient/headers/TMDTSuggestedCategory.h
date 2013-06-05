//
//  TMDTSuggestedCategory.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a single suggested category that the api has returned.
 */
@interface TMDTSuggestedCategory : NSObject

/**
 Returns the count of listings that are available from the search that was executed.
 */
@property (nonatomic) NSInteger count;

/**
 Returns the category code.
 */
@property (strong, nonatomic) NSString *category;

/**
 Returns the category name
 */
@property (strong, nonatomic) NSString *name;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryCategory;

@end
