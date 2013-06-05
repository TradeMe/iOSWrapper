//
//  TMDTCategory.h
//  TMAPIClient
//
//  Created by Simon Cook on 15/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a single category as returned by the 'Retrieve general categories' API at:
 
 http://developer.trademe.co.nz/api-reference/catalogue-methods/retrieve-general-categories/
 */
@interface TMDTCategory : NSObject

/**
 The name of the category.
 */
@property (nonatomic, strong) NSString *name;

/**
 The id of this category
 */
@property (nonatomic, strong) NSNumber *categoryId;

/**
 A unique identifier for the category e.g. “0004-0369-6076-”. We plan to change this to a numeric identifier (e.g. “6076″) so you should ensure you can cope with both formats.
 */
@property (nonatomic, strong) NSString *number;

/**
 The full URL path of this category e.g. “/Home-living/Beds-bedroom-furniture/Bedside-tables”.
 */
@property (nonatomic, strong) NSString *path;

/**
 Indicates whether the category is restricted to adults only (i.e. the category is R18).
 */
@property (nonatomic, strong) NSNumber *isRestricted;

/**
 Indicates whether the category has legal requirements. You should ask the user to accept the legal notice before listing in this category. There is an API to get the text of the legal notice.
 */
@property (nonatomic, strong) NSNumber *hasLegalNotice;

/**
 Indicates whether classifieds are allowed in this category.
 */
@property (nonatomic, strong) NSNumber *hasClassifieds;

/**
 The number of items for sale in this category.
 */
@property (nonatomic, strong) NSNumber *count;

/**
 The list of subcategories belonging to this category.
 */
@property (nonatomic, strong) NSArray *arrayOfSubcategories;

/**
 The id of the parent category.
 */
@property (nonatomic) NSNumber *parentId;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryCategory;

/**
 A nicely formatted string that represents the category path from the root category to this category.
 */
- (NSString *)nicePath;

/**
 Returns whether the current category is a child of the specified category id.
 */
- (BOOL)isChildOfCategoryId:(NSNumber *)categoryId;

/**
 Returns the parent category object of this category.
 */
- (TMDTCategory *)parent;

@end
