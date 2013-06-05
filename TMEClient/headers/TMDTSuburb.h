//
//  TMDTSuburb.h
//  TMAPIClient
//
//  Created by Karol Tarka on 24/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TMDTDistrict;

@interface TMDTSuburb : NSObject

@property (strong, nonatomic) NSNumber *suburbId;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSArray *adjacentSuburbs;
@property (weak, nonatomic) TMDTDistrict *parentDistrict;

- (id)initWithDictionary:(NSDictionary *)dictionarySuburb_;

@end
