//
//  TMDTLocality.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Locations are split into three categories; regions, districts and suburbs.  A region has many districts and a district has many suburbs.

 This class represents the top level region.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/catalogue-methods/retrieve-property-jobs-and-services-localities/
 */
@interface TMDTRegion : NSObject

/**
 The ID of the region.
 */
@property (strong, nonatomic) NSNumber *regionId;

/**
 The name of the region.
 */
@property (strong, nonatomic) NSString *name;

/**
 The array of districts associated with this region.
 */
@property (strong, nonatomic) NSArray *districts;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryRegion_;

@end
