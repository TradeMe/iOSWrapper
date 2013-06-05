//
//  TMDTFavouriteSeller.h
//  TMAPIClient
//
//  Created by Simon Cook on 30/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTFavourite.h"

@interface TMDTFavouriteSeller : TMDTFavourite <NSCoding>

@property (nonatomic) NSInteger currentListingCount;
@property (nonatomic) NSInteger feedbackCount;
@property (strong, nonatomic) NSNumber *memberId;
@property (strong, nonatomic) NSString *nickname;

@end
