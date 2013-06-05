//
//  TMDTGeographicLocation.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TMDTGeographicLocationMapAccuracy) {
    TMDTGeographicLocationAccuracyNone = 0,
    TMDTGeographicLocationAccuracyAddress,  //-- highest accuracy
    TMDTGeographicLocationAccuracySuburb,   //-- rough accuracy
    TMDTGeographicLocationAccuracyStreet    //-- street level accuracy
};

/**
 Represents the latitude and longitude of a TMDTListing object (e.g. for properties).
*/
@interface TMDTGeographicLocation : NSObject

/**
 The accuracy of the geographic location (address, street or suburb).
 */
@property (nonatomic) TMDTGeographicLocationMapAccuracy mapAccuracy;

/**
 The latitude of the location, in degrees (WGS84).
 */
@property (strong, nonatomic) NSNumber *latitude;

/**
 The longitude of the location, in degrees (WGS84).
 */
@property (strong, nonatomic) NSNumber *longitude;

/**
 The northing of the location, in metres (NZTM).
 */
@property (nonatomic) NSInteger northing;

/**
 The easting of the location, in metres (NZTM).
 */
@property (nonatomic) NSInteger easting;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryGeographicLocation;

@end
