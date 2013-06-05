//
//  TMDTAttribute.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 An attribute contains metadata about a listing.
 
 For more information see; http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTAttribute : NSObject <NSCoding>

/**
 The name of the attribute.
 */
@property (strong, nonatomic) NSString *name;

/**
 The display name of the attribute.
 */
@property (strong, nonatomic) NSString *displayName;

/**
 The string value of the attribute. When listing, the valid values for the attribute can be determined using the “Retrieve attributes for a category” API. Use “0″ (false) or “1″ (true) for boolean attributes.
 */
@property (strong, nonatomic) NSString *value;

/**
 The display value of the attribute.
 */
@property (strong, nonatomic) NSString *displayValue;

typedef NS_ENUM(NSInteger, TMDTAttributeType) {
    TMDTAttributeTypeNone = 0,          //-- Not used.
    TMDTAttributeTypeBoolean = 1,       //-- The attribute value is a boolean (true/false).
    TMDTAttributeTypeInteger = 2,       //-- The attribute value is an integer.
    TMDTAttributeTypeDecimal = 3,       //-- The attribute value is a floating point number.
    TMDTAttributeTypeString = 4,        //-- The attribute value can be arbitrary text.
    TMDTAttributeTypeDateTime = 5,      //-- The attribute value is a date & time (in UTC).
    TMDTAttributeTypeStayPeriod = 6     //-- The attribute value is a StayPeriod – date values (in UTC).
};

/**
 The type of the attribute.
 */
@property (nonatomic) TMDTAttributeType type;

/**
 The min value if the attribute is a range.
 */
@property (strong, nonatomic) NSString *lowerRange;

/**
 The max value if the attribute is a range.
 */
@property (strong, nonatomic) NSString *upperRange;

/**
 A list of options, if the attribute is restricted to a fixed set of values.
 */
@property (strong, nonatomic) NSDictionary *dictionaryOfOptions;

/**
 Indicates whether the attribute must be present when selling an item.
 */
@property (nonatomic) BOOL isRequiredForSell;

/**
 The name of the attribute when used in a search string.
 */
@property (strong, nonatomic) NSString *searchParameterName;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryAttribute;

@end
