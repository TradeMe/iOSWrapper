//
//  NSDate+TMAdditions.h
//  TMAPIClient
//
//  Created by Simon Cook on 18/06/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, kTMDateFormat) {
    kTMDateFormatTime,
    kTMDateFormatShortDate,
    kTMDateFormatLongDate,
    kTMDateFormatLongDateTime
};

@interface NSDate (TMAdditions)

+ (NSDate *)dateFromAPIDateString:(NSString *)date;
- (NSString *)formatWithFormat:(kTMDateFormat)dateFormat;
- (BOOL)dateIsToday;

@end
