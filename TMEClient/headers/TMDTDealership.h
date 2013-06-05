//
//  TMDTDealership.h
//  TMAPIClient
//
//  Created by Simon Cook on 12/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTDealership : NSObject

@property (strong, nonatomic) NSString *address;
@property (strong, nonatomic) NSString *city;
@property (strong, nonatomic) NSString *faxNumber;
@property (strong, nonatomic) NSNumber *dealershipId;
@property (strong, nonatomic) NSString *logoUrl;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *phoneNumber;
@property (strong, nonatomic) NSString *suburb;
@property (strong, nonatomic) NSString *website;

@property (strong, nonatomic) NSArray *arrayOfDealers; //-- TMDTDealer objects

- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

@end
