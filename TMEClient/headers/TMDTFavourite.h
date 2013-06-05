//
//  TMDTFavourite.h
//  TMAPIClient
//
//  Created by Simon Cook on 30/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TMDTFavouriteType) {
    TMDTFavouriteTypeNone = 0,
    TMDTFavouriteTypeCategory = 1,
    TMDTFavouriteTypeSearch = 3,
    TMDTFavouriteTypeAttributeSearch = 4,
    TMDTFavouriteTypeSeller = 6
};

typedef NS_ENUM(NSInteger, TMDTFavouriteEmailOption) {
    TMDTFavouriteEmailOptionNoEmail = 0,
    TMDTFavouriteEmailOptionDaily = 1,
    TMDTFavouriteEmailOptionEveryThreeDays = 3,
    TMDTFavouriteEmailOptionWeekly = 7
};

typedef NS_ENUM(NSInteger, TMDTFavouriteSearchApi) {
    TMDTFavouriteSearchApiGeneral = 0,
    TMDTFavouriteSearchApiUsedMotors = 1,
    TMDTFavouriteSearchApiMotorBoat = 2,
    TMDTFavouriteSearchApiMotorBike = 3,
    TMDTFavouriteSearchApiResidential = 4,
    TMDTFavouriteSearchApiRental = 5,
    TMDTFavouriteSearchApiCommmercialSale = 6,
    TMDTFavouriteSearchApiCommmercialLease = 7,
    TMDTFavouriteSearchApiRural = 8,
    TMDTFavouriteSearchApiLifestyle = 9,
    TMDTFavouriteSearchApiFlatmate = 10,
    TMDTFavouriteSearchApiOpenHomes = 11,
    TMDTFavouriteSearchApiRetirement = 12,
    TMDTFavouriteSearchApiJob = 13
};

@interface TMDTFavourite : NSObject <NSCoding>

@property (strong, nonatomic) NSNumber *favouriteId;
@property (strong, nonatomic) NSString *searchQueryString;
@property (nonatomic) TMDTFavouriteEmailOption emailOption;
@property (nonatomic) TMDTFavouriteType favouriteType;//-- used when deleting or updating
@property (nonatomic) TMDTFavouriteSearchApi searchApi;

- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

@end
