//
//  TMDTListingMotor.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTListing.h"

@class TMDTDealership;
@class TMDTSellerContactDetails;

typedef NS_ENUM(NSInteger, TMDTBoatEngineType) {
    TMDTBoatEngineAny = 0,
    TMDTBoatEngineOutboard = 1,
    TMDTBoatEngineInboard = 2,
    TMDTBoatEngineTwinOutboard = 3,
    TMDTBoatEngineTwinInboard = 4,
    TMDTBoatEngineJet = 5,
    TMDTBoatEngineNone = 6,
    TMDTBoatEngineOther = 7
};

typedef NS_ENUM(NSInteger, TMDTBoatType) {
    TMDTBoatTypeAll = 0,
    TMDTBoatTypeFibreglass = 1,
    TMDTBoatTypeAluminium = 2,
    TMDTBoatTypeWooden = 3,
    TMDTBoatTypeInflatable = 4,
    TMDTBoatTypeSteel = 5
};

/**
 Represents a Trade Me listing under the motors category.  The motors category includes the following api end points;
 
 Used motors - http://developer.trademe.co.nz/api-reference/search-methods/used-motors-search/
 
 Motorboats - http://developer.trademe.co.nz/api-reference/search-methods/motorboat-search/
 
 Motorbikes - http://developer.trademe.co.nz/api-reference/search-methods/motorbike-search/
 */
@interface TMDTListingMotor : TMDTListing

/**
 The car body style.
 */
@property (strong, nonatomic) NSString *bodyStyle;

/**
 The number of doors the car has.
 */
@property (assign, nonatomic) NSInteger doors;

/**
 Engine size in CC
 */
@property (assign, nonatomic) NSInteger engineSize;

/**
 The vehicle make.
 */
@property (strong, nonatomic) NSString *make;

/**
 The vehicle model.
 */
@property (strong, nonatomic) NSString *model;

/**
 The recorded distance.
 */
@property (assign, nonatomic) NSInteger odometer;

/**
 The year the vehicle was manufactured.
 */
@property (assign, nonatomic) NSInteger year;

/**
 The transmission type
 */
@property (strong, nonatomic) NSString *transmission;

/**
 Fuel for the engine.
 */
@property (strong, nonatomic) NSString *fuel;

/**
 The vehicle number plate
 */
@property (strong, nonatomic) NSString *numberPlate;

/**
 Best time to contact the seller
 */
@property (strong, nonatomic) NSString *bestContactTime;

/**
 Engine cylinder count
 */
@property (assign, nonatomic) NSInteger cylinders;

/**
 Number of Previous owners
 */
@property (assign, nonatomic) NSInteger owners;

/**
 Warrant of Fitness expiration date
 */
@property (strong, nonatomic) NSDate *wofExpires;

/**
 Vehicle registration expiration date
 */
@property (strong, nonatomic) NSDate *registrationExpires;

/**
 What stereo does it have?
 */
@property (strong, nonatomic) NSString *stereoDescription;

/**
 The exterior color of the vehicle.
 */
@property (strong, nonatomic) NSString *exteriorColour;

/**
 The import history of the vehicle.
 */
@property (strong, nonatomic) NSString *importHistory;

/**
 Indicates whether the listing is from a car dealer.
 */
@property (assign, nonatomic) BOOL isDealer;
@property (assign, nonatomic) BOOL isOrNearOffer;

/**
 The approximate value of the motorbike (used in the motorbikes and motorboats api).
 */
@property (assign, nonatomic) NSInteger approximateValue;

/**
 The year the boat was made (used in the motorboats api).
*/
@property (assign, nonatomic) NSInteger boatDate;

/**
 The year the engine was made (used in the motorboats api).
 */
@property (assign, nonatomic) NSInteger engineDate;

/**
 The number of hours the engine has been running (used in the motorboats api).
 */
@property (assign, nonatomic) NSInteger engineHours;

/**
 The type of engine (used in the motorboats api).
 */
@property (assign, nonatomic) TMDTBoatEngineType engineType;

/**
 The asking price, in NZD (used in the motorboats api).
 */
@property (assign, nonatomic) NSInteger expectedPrice;

/**
 The length of the boat, in millimetres (used in the motorboats api).
 */
@property (assign, nonatomic) NSInteger length;

/**
 The material of the boat’s hull (used in the motorboats api).
 */
@property (assign, nonatomic) TMDTBoatType type;

/**
 The dealership details if this is a car dealer listing.
 */
@property (strong, nonatomic) TMDTDealership *dealership;

/**
 The type of motorbike (used in the motorbikes api).
 */
@property (strong, nonatomic) NSString *bikeType;

/*
 Returns the vehicles odometer reading in the format xxx,xxxkm
 */
- (NSString *)odometerDisplay;

/*
 Returns the hull type as a string eg "fibreglass"
 */
- (NSString *)typeDisplay;

/*
 Returns the boat engine type as a string eg "twin outboard"
 */
- (NSString *)engineTypeDisplay;

/*
 Returns the length of a boat as a float in metres
 */
- (float)lengthDisplay;

@end
