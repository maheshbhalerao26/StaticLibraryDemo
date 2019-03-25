//
//  ProfileConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Luis Marmolejo on 9/28/11.
//  Copyright 2011 iPass. All rights reserved.
//
//  Revision History: 
//  3/12/12 - Ronak Shah: Added logic to parse the XML file once and store it in a respective .plist file
//

#import <Foundation/Foundation.h>

@class iPassXMLDocument;

// Public field identifiers for keying into private metadata for leaf nodes.
// This enum identifies each leaf node of interest to this app version because
// it contains a data element value
typedef NS_ENUM(NSInteger, ProfileConfigField)
{
    kProfileConfigField_ProfileId,
    kProfileConfigField_AccountId,
    kProfileConfigField_Name,
    kProfileConfigField_Version,
    kProfileConfigField_Status,
    kProfileConfigField_TargetBundle_Name,
    kProfileConfigField_TargetBundle_Description,
    kProfileConfigField_TargetBundle_Version,
    kProfileConfigField_TargetBundle_Platform,
    kProfileConfigField_TargetBundle_Locale,
    kProfileConfigField_ReplaceProfile,
    kProfileConfigField_Count
} ;

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSInteger, ProfileConfigNodeContext)
{
    kProfileConfigNodeContext_TargetBundle_LocaleSupport,
    kProfileConfigNodeContext_TargetBundle_Locale,
    kProfileConfigNodeContext_Count
} ;

@interface ProfileConfigWrapper : NSObject 
{
@private
    iPassXMLDocument *mDocument;
    NSError         *mErr;
    int             mLocaleCount;
    BOOL            mStatusOk;
}

- (id)initWithPath:(NSString *)filePath;
- (instancetype) initWithCompletePath: (NSString *) completeFilePath;
- (BOOL)isOk;
- (BOOL)isParsedOk;
- (void)print;
- (BOOL)validateCorrectness;

#pragma mark - Getters
- (nullable NSString *)getProfileId;
- (nullable NSString *)getAccountId;
- (nullable NSString *)getProfileName;
- (nullable NSString *)getProfileVersion;
- (nullable NSString *)getProfileStatus;
- (nullable NSString *)getProfileBundle_Name;
- (nullable NSString *)getProfileBundle_Description;
- (nullable NSString *)getProfileBundle_Version;
- (nullable NSString *)getProfileBundle_Platform;
- (BOOL)      shouldReplaceProfile;

#pragma mark - Locale Level getters
- (int)getLocaleCount;
- (NSString *)getLocale:(int)index;
@end
