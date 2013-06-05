//
//  TMDTEmailSellerRequest.h
//  TMAPIClient
//
//  Created by Nick Parfene on 12/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMDTEmailSellerRequest : NSObject

@property (strong, nonatomic, readonly) NSNumber *listingId;
@property (strong, nonatomic, readonly) NSString *messageBody;
@property (nonatomic) BOOL copyToSelf;

- (id)initWithListingId:(NSNumber *)listingId_ messageBody:(NSString *)messageBody_;

@end
