//
//  TMDTCategoryManager.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 11/03/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTCategory.h"

/**
 The category manager provides utility methods for looking up and searching for categories.
 */
@interface TMECategoryManager : NSObject

/**
 Flat reference to the list of categories, that is, the entire category tree in a single list
 */
@property (nonatomic, strong) NSMutableDictionary *dictionaryOfCategories;

/**
 Returns the singleton instance. This assumes that the categories have already been downloaded
 */
+ (TMECategoryManager *)sharedInstance;


/**
 Returns a category object for specified Category ID. Returns nil if category doesn't exist or Category ID is root ID.
 */
- (TMDTCategory *)categoryWithId:(NSNumber *)categoryId;

/**
 Expects a fully specified mcat (of the format "xxxx-xxxx-" for example).  Its length must be multiple of 5 or this will crash.
 Trade Me is moving away from mcats, you should use categoryWithId:categoryId where possible
 */
- (TMDTCategory *)categoryWithMcat:(NSString *)mcat;


/**
 Returns an array of subcategories with the specified parent category ID.
 If the parentId is nil, then the array will contain all the top level categories.
 */
- (NSArray *)categoriesWithParentId:(NSNumber *)parentId;

/**
 Searches the subcategories of category with the parent ID and the name specified.
 Returns nil if the category can't be found.
 */
- (TMDTCategory *)categoryWithParentId:(NSNumber *)parentId andSubCategoryName:(NSString *)categoryName;

@end
