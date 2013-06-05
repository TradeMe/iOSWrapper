//
//  TMDTDealer.h
//  TMAPIClient
//
//  Created by Simon Cook on 12/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTDealer : NSObject

@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *fullName;
@property (strong, nonatomic) NSString *mobilePhoneNumber;
@property (strong, nonatomic) NSString *officePhoneNumber;
@property (strong, nonatomic) NSString *position;

- (id)initWithDictionary:(NSDictionary *)dictionaryListing;

@end
