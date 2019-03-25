//
//  OMCUtil.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 9/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

//! OMCutil Constents
//! @def Format for last update time
#define OMC_DEFAULT_LASTUPDATE_DATE_FORMAT @"MM/dd/yyyy HH:mm:ss"

#define URL_PARAM_SEP @"&"
#define KEY_VALUE_SEP @"="

//@interface NSArray (CaseInsensitiveIndexing)
//- (NSUInteger)indexOfCaseInsensitiveString:(NSString *)aString;
//@end

@interface OMCUtil : NSObject

//! Time zone specific
+ (NSTimeZone*)omcDefaultTimeZone;
+ (NSTimeZone*)omcGMTTimeZone;
+ (NSTimeZone*)omcUTCTimeZone;

//! Date realted
+ (NSDate*)dateInLocalTimeZone;
+ (NSDate*)dateByAddingLocalOffsetToDate:(NSDate*)date;
+ (NSDate*)currentDateInTimeZone:(NSTimeZone*)timezone;
+ (NSDate*)convertDate:(NSDate*)date inTimeZone:(NSTimeZone*)timezone;
+ (NSString*)timeFromNSDate:(NSDate*)date;

/**
 * Converts NSDate into a localized string using the template.
 * E.g. "EEEMMMd" results in:
 * US: Mon, Jan 28
 * UK: Mon 28 Jan
 * FR: lun. 28 janv.
 */
+ (NSString *)localizedDateFromDate:(NSDate *)date formatTemplate:(NSString *)formatTemplate;

//! Last update time
+ (NSDate*)lastUpdateTime;
+ (void)updateLastUpdateTime:(NSDate*)lastUpdate;
+ (NSString*)lastUpdateStringInDisplayFormat;
+ (NSString*)lastUpdateStringInSQMFormat;
+ (NSString*)lastUpdateStringInFormat:(NSString*)format withLocale:(NSLocale*)locale;

+ (NSDate*) lastUpdateAttemptTime;
//Call this method directly instead of "updateLastUpdateTime" for cases where
//UI update of last update time is not needed.
+ (void)updateLastUpdateAttemptTime:(NSDate*)lastUpdateAttempt;
+(void)clearLastUpdateKeys;

//CFC device reg check related
+(NSDate*)lastCfcDeviceRegCheckTime;
+(void)updateLastCfcDeviceRegCheckTime:(NSDate*)lastCheck;

//! System uptime
+ (NSTimeInterval)omcSystemUpTime;

/*! @brief excepts the string in hh:mm:ss format
    @return NSTimeInterval in seconds*/
+(NSTimeInterval) timeInSeconds:(NSString*) time;

+(NSString*) timeIntervalSince1970InMilliSeconds;
+(NSInteger)timeIntervalSince1970;
+(NSString*) dateWithtimeIntervalSince1970InMilliSeconds:(NSDate*)date;

+ (BOOL)validateEmail:(NSString *)email;

+ (BOOL)usidEnabledForDirectoryID:(NSString*)directoryId;
+(BOOL)autoConnectEnabledForDirectoryID:(NSString*)directoryId;
//! Create a new UUID
+ (NSString *)createUUID;

//encode string
+ (NSString*)xmlEncodeString:(NSString *)string;
+ (NSString*)xmlDecodeString:(NSString*)string;

//Method url encodes the string passed
+ (NSString*)urlEncodedString:(NSString*)stringToEncode;
+ (NSString*)urlDecodedString:(NSString*)stringToEncode;

//encode string to base64
+(NSString*)encodeStringBase64:(NSString*)inputString;

/*! @brief Apply ssid filter
 *  @param NSArray of ssid 
 *  @return NSArray of filtered ssid */
+ (NSArray*)newFilteredSsidListFromList:(NSArray*)ssidList;

/*! @brief clear cookies for a url */
+ (void)clearCookiesForURL:(NSURL*)url;

/*! @brief Returns the MAC Address of the Wi-Fi chip on the device, without the ':'
 *  @return NSString of MAC Address */
+ (NSString *) wifiMacAddress;

/*! @brief Formats standard mac address format for storage / comparison (uppercase @return NSString of Mac w/ format XXXXXXXXXXXX */
+ (NSString*) formatMacAddress: (NSString*) mac;

/*! @brief Function to perform nested unzipping of a compressed file till required */
+ (BOOL)unzipAtDirectory:(NSString *)directory withRecursion:(BOOL)recursive;

//Unzip the .zip files and place the contents in a directory whose name is same as the the zip file.
+ (BOOL)unzipFilesAtLocation:(NSString *)directory;


// Current language in device settings
+ (NSString *)userPreferredLocale;
+ (NSString *)currentLocaleInJavaServerFormat;


// Methods to update last success ful login time
+(NSDate*)lastSuccessfulLoginDate;
+(void)clearLastSuccessfulLoginDate;
+(void)updateLastSuccessfulLoginDate:(NSDate*)lastSuccessfulLoginDate;
+(NSInteger) noOfDaysAfterSuccessfulLogin;

+(NSString*) CDATAFormat:(NSString*) input;

+ (BOOL)isInternetIsReachableAndOMLoggedIn;
+ (BOOL)shouldUseInAppHotspotFinder;

// Method to verify dialer id
+ (BOOL)isDialerIdValid:(NSString*)dialerId;

+(NSString*) replaceOccuranceOfVariableWithKeyWithValueInURLString:(NSString*)sourceString variableName:(NSString*)key replaceWithValue:(NSString*)value;

+(NSString*) normalize:(NSString*) string;

//Used for the log Service Analysis purpose
+(NSString*) formattedCurrentTime;

+(nonnull NSString*)stripUnwantedCharactersFromResponse:(nonnull NSString *)aString;
+(NSString *_Nullable)createSHA512:(NSString *_Nonnull)string;
@end
