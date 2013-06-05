//
//  TMDTSearchAttribute.h
//  TMAPIClient
//
//  Created by Nick Parfene on 17/01/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -
@interface TMESearchAttribute : NSObject

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *value;
@property (strong, nonatomic) NSString *displayValue;

- (id)initWithName:(NSString *)name_ value:(NSString *)value_ displayValue:(NSString *)displayValue_;

@end
