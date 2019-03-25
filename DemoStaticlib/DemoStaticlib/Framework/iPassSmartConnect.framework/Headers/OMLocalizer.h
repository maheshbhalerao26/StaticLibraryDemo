////
////  OMLocalizer.h
////  iPassOpenMobile
////
////  Created by Puru Shukla on 18/03/13.
////
////
//
//#import <Foundation/Foundation.h>
//
//@interface OMLocalizer : NSObject
//
///**
// * @description: Method returns the string after replacing all the format specifiers
// * with their corresponing values. The caller is responsible for passing the localized string.
// * This method just replaces the format specifier with values.
// *
// * @param: Localized string with format specifiers in form: $<param>$
// * @return: String after replacing params with values
// *
// */
//+ (NSString*) localizedStringWithFormat:(NSString*)format, ...;
//
///**
// * @description: Method returns the localized string after replacing all the format specifiers
// * with their corresponing values. The values are read from the table. The caller is responsible 
// * for passing tablename and the key for initial string feed. This method just replaces the format
// * specifier by reading the their values from the string table.
// *
// * @param: Localized string with format specifiers in form: $<param>$
// * @return: String after replacing params with values
// *
// * Exp: feed string: This is feed for $STRING2$
// * STRING2 is defined as: the second string2 
// * then the final string after expansion would be: This is feed for the second string2
// */
//+(NSString*)localizedStringFromTable:(NSString*)table
//                              forKey:(NSString*)key;
//
//@end
