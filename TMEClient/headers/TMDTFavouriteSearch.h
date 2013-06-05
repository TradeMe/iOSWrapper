//
//  TMDTFavouriteSearch.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTFavouriteCategory.h"

@class TMDTAttribute;

typedef NS_ENUM(NSInteger, TMDTFavouriteSearchType) {
    TMDTFavouriteSearchTypeAll = 0,
    TMDTFavouriteSearchTypeGeneral = 1,
    TMDTFavouriteSearchTypeJob = 2,
    TMDTFavouriteSearchTypeMotor = 3,
    TMDTFavouriteSearchTypeProperty = 4
};

@interface TMDTFavouriteSearch : TMDTFavouriteCategory <NSCoding>

@property (strong, nonatomic) NSArray *arrayOfAttributes;//-- contains TMDTAttribute
@property (strong, nonatomic) NSString *keywords;
@property (nonatomic) TMDTFavouriteSearchType searchType;
@property (strong, nonatomic) NSNumber *regionId;

#pragma mark - UI Helper functions
- (TMDTAttribute *)attributeForName:(NSString *)attributeName;
- (NSString *)regionDisplay;
- (NSString *)districtDisplay;
- (NSString *)suburbDisplay;

/*
 Returns a user friendly search type ready to be displayed: e.g. 11 becomes "Open Homes"
 */
- (NSString *)searchTypeDisplay;

/*
 if we have 2 prices then return "$123,456 to $654,321"
 if we have just min price then return "$123,456 or more"
 if we have just max price then return "$654,321 or less"
 otherwise return nil
 */

- (NSString *)expectedSalePriceDisplay;
- (NSString *)cpuRangeDisplay;
- (NSString *)memoryRangeDisplay;
- (NSString *)diskRangeDisplay;
- (NSString *)bedrooms;
- (NSString *)bathrooms;
- (NSString *)landAreaRangeDisplay;
- (NSString *)yearRangeDisplay;
- (NSString *)salaryRangeDisplay;
- (NSString *)doorsRangeDisplay;
- (NSString *)engineRangeDisplay;
- (NSString *)odometerRangeDisplay;
- (NSString *)lengthRangeDisplay;

@end
