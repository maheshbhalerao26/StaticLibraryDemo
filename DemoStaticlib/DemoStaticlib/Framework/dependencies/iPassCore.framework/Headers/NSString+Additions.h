//
//  NSString+Additions.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 01/10/13.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Additions)

-(BOOL)isNotEqualToString:(NSString*)string;

-(NSString*)stringByTrimmingLeadingAndTrailingCharactersInSet:(NSCharacterSet*)characterSet;
-(NSString*)stringByTrimmingLeadingCharactersInSet:(NSCharacterSet*)characterSet;
-(NSString*)stringByTrimmingTrailingCharactersInSet:(NSCharacterSet*)characterSet;

-(NSUInteger)countOfSubstring:(NSString*)substring;

+ (NSString*)stringFromHex:(NSString *)str;
+ (NSString*)stringToHex:(NSString *)str;

//URL Encoding
-(NSString*)urlEncodedString;
-(NSString*)urlDecodedString;

-(NSData*)hexStringToData;

@end

NS_ASSUME_NONNULL_END
