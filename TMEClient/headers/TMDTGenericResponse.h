//
//  TMDTGenericResponse.h
//  TMAPIClient
//
//  Created by Nick Parfene on 12/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTGenericResponse : NSObject

@property (nonatomic) BOOL success;
@property (strong , nonatomic) NSString *responseMessage;

@end
