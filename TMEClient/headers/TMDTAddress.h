//
//  TMDTBaseAddress.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 13/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTAddress : NSObject

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *address1;
@property (strong, nonatomic) NSString *address2;
@property (strong, nonatomic) NSString *suburb;
@property (strong, nonatomic) NSString *city;
@property (strong, nonatomic) NSString *postcode;
@property (strong, nonatomic) NSString *country;
@property (strong, nonatomic) NSString *phoneNumber;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
