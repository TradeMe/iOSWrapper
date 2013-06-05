//
//  TMDTDistrict.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TMDTRegion;

/**
 Locations are split into three categories; regions, districts and suburbs.  A region has many districts and a district has many suburbs.
 
 This class represents the mid level district.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/catalogue-methods/retrieve-property-jobs-and-services-localities/
 */
@interface TMDTDistrict : NSObject

/**
 The ID of the district
 */
@property (strong, nonatomic) NSNumber *districtId;

/**
 The name of the district
 */
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSMutableArray *suburbs;
@property (weak, nonatomic) TMDTRegion *parentRegion;

- (id)initWithDictionary:(NSDictionary *)dictionaryDistrict_;

@end
