//
//  TMDTSellerContactDetails.h
//  TMAPIClient
//
//  Created by Karol Tarka on 6/08/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTSellerContactDetails : NSObject

@property (strong, nonatomic) NSString *contactName;
@property (strong, nonatomic) NSString *bestContactTime;
@property (strong, nonatomic) NSString *mobilePhoneNumber;
@property (strong, nonatomic) NSString *phoneNumber;

/*
 Designated initialiser.
 */
- (id)initWithDictionary:(NSDictionary *)dictionarySellerContactDetails;

@end
