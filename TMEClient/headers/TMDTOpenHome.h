//
//  TMDTOpenHome.h
//  TMAPIClient
//
//  Created by Simon Cook on 23/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents open home information used in the class TMDTListing.
 */
@interface TMDTOpenHome : NSObject

/**
 The open home start date.
 */
@property (strong, nonatomic) NSDate *start;

/**
 The open home end date.
 */
@property (strong, nonatomic) NSDate *end;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryOpenHome;

@end
