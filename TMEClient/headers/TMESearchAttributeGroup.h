//
//  TMDTSearchAttributeGroup.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/01/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMESearchCriteria.h"

#pragma mark - Search Attributes -
typedef NS_ENUM(NSInteger, TMESearchAttributeGroupType) {
    TMESearchAttributeTypeSingleValue = 1,
    TMESearchAttributeTypeMultipleValues = 2,
    TMESearchAttributeTypeRange = 3
};

/**
 * A group wrapes one search criteria. e.g. max bedrooms
 */
@interface TMESearchAttributeGroup : NSObject

@property (nonatomic) TMESearchAttributeGroupType attributeGroupType;
/**
 * Unique identifier for the search attribute group.
 */
@property (strong, nonatomic) NSString *key;
/**
 * If the attributeGroupType is `TMESearchAttributeTypeRange` then this property will contain the name of the counterpart attribute group
 * Trade Me's API will swap arround min and max if the values are not passed in the correct order (e.g. min is larger than max).
 */
@property (strong, nonatomic) NSString *nameOfRangeAttributeCounterpart;
/**
 * Recommended way of displaying the search attribute name / key. e.g. "Rental price"
 */
@property (strong, nonatomic) NSString *displayValue;
/**
 * The request parameter submitted to the API when posting the requestParameterValue
 */
@property (strong, nonatomic) NSString *requestParameterName;
/**
 * All the search attributes that apply for the current [TMDTSearchCriteria searchType]
 */
@property (strong, nonatomic) NSMutableArray *arrayOfFilterOptions;

/**
 * Holds the default TMDSearchAttributes for the current group
 */
@property (strong, nonatomic) NSMutableArray *arrayOfDefaultFilterOptions;

/**
 * This is where the user's selection is captured. Usually the array only contains one element
 * but in the case of suburbs there can be mulitple items.
 */
@property (strong, nonatomic) NSMutableArray *arrayOfUserSelectedAttributes;

- (id)initWithType:(TMESearchAttributeGroupType)type_
              key:(NSString *)key_
      displayValue:(NSString *)displayValue_
requestParameterName:(NSString *)requestParameterName_;

- (id)initWithType:(TMESearchAttributeGroupType)attributeGroupType_
               key:(NSString *)key_
      displayValue:(NSString *)displayValue_
requestParameterName:(NSString *)requestParameterName_
nameOfRangeAttributeCounterpart:(NSString *)nameOfRangeAttributeCounterpart_;

@end
