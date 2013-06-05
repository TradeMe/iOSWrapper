//
//  TMDTFavouriteCategory.h
//  TMAPIClient
//
//  Created by Simon Cook on 30/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTFavourite.h"

@interface TMDTFavouriteCategory : TMDTFavourite <NSCoding>

@property (strong, nonatomic) NSString *categoryPath;//-- e.g. “Books > Children & babies > Picture books > Beatrix Potter”.
@property (strong, nonatomic) NSString *categoryName;
@property (strong, nonatomic) NSString *category;//-- full mcat path e.g. “0193-0462-0255-6659-”
@property (strong, nonatomic) NSNumber *categoryId;

@end
