//
//  NSString+IVGUtils.h
//  IVGUtils
//
//  Created by Douglas Sjoquist on 3/18/11.
//  Copyright 2011 Ivy Gulch, LLC. All rights reserved.
//
//  Updated by Ronak to add:
//  1. (BOOL)haveValue
//  2. (BOOL)containsString:(NSString *)substring
//

#import <Foundation/Foundation.h>

@interface NSString(IVGUtils)

+ (NSString *)GUID;

/*! @brief Checks whether the self object of NSString contains a value.
 *  @return YES if it contains a value & NO if it is an empty string. */
- (BOOL)haveValue;

/*! @brief Checks whether the self object of NSString contains a substring
 *  @return YES if found & NO if did not find the occurence of substring */
- (BOOL)containsString:(NSString *)substring isCaseSensitive:(BOOL)caseSensitive;

@end

@interface NSString (ZipUtils)

- (NSString *)compressStringWithEncoding:(NSStringEncoding)encoding;
- (NSString *)decompressStringWithEncoding:(NSStringEncoding)encoding;

@end
