//
//  TMDTSaveFavouriteResponse.h
//  TMAPIClient
//
//  Created by Simon Cook on 15/08/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMDTFavourite.h"

@interface TMDTSaveFavouriteResponse : NSObject

@property (strong, nonatomic) NSNumber *favouriteId;
@property (nonatomic) TMDTFavouriteType favouriteType;
@property (strong, nonatomic) NSString *response;
@property (nonatomic) BOOL saved;

- (id)initWithDictionary:(NSDictionary *)dictionaryOfFavouriteResponse;

@end
