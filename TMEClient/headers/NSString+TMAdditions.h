//
//  NSString+TMAdditions.h
//  TMAPIClient
//
//  Created by Nick Parfene on 10/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TMAdditions)

- (NSInteger)integerValueFromSubstring;

- (float)floatValueFromSubstring;

- (NSInteger)integerValueFromDollarAmountSubstring;

/*
 * The string must be URL encoded before this method is called
 */
- (NSDictionary *)dictionaryFromSearchQueryString;

- (NSString *)urlDecode;

- (NSString *)urlEncode;

- (NSString *)xmlEscape;

- (BOOL) containsString:(NSString *) string;

- (BOOL) containsString:(NSString *) string options:(NSStringCompareOptions) options;

- (BOOL)isValidCurrencyStringWithPrefix:(NSString *)prefix;

@end
