//
//  AccountConfigWrapper.h
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
typedef NS_ENUM(NSInteger, AccountConfigField)
{
    kAccountConfigField_ProfileId,
    kAccountConfigField_PreAuthValidation,
    kAccountConfigField_ACAEnabled,
    kAccountConfigField_ACAReactivationRequired,
    kAccountConfigField_MasterAccountName,
    kAccountConfigField_AccountName,
    kAccountConfigField_AccountDescription,
    kAccountConfigField_AccountDescriptionResourceFile,
    kAccountConfigField_AccountDescriptionResourceID,
    kAccountConfigField_AccountDisplayText,
    kAccountConfigField_AccountUser_Type,
    kAccountConfigField_AccountUser_Show,
    kAccountConfigField_AccountUser_AllowModify,
    kAccountConfigField_AccountUser_DisplayText,
    kAccountConfigField_AccountUser_DisplayTextUseDefault,
    kAccountConfigField_AccountUser_DisplayTextResourceFile,
    kAccountConfigField_AccountUser_DisplayTextResourceID,
    kAccountConfigField_AccountUser_DefaultValue,
    kAccountConfigField_AccountPrefix_Show,
    kAccountConfigField_AccountPrefix_AllowModify,
    kAccountConfigField_AccountPrefix_DisplayText,
    kAccountConfigField_AccountPrefix_DisplayTextUseDefault,
    kAccountConfigField_AccountPrefix_DisplayTextResourceFile,
    kAccountConfigField_AccountPrefix_DisplayTextResourceID,
    kAccountConfigField_AccountPrefix_DefaultValue,
    kAccountConfigField_AccountDomain,
    kAccountConfigField_AccountDomain_ListValue,
    kAccountConfigField_AccountDomain_Show,
    kAccountConfigField_AccountDomain_AllowModify,
    kAccountConfigField_AccountDomain_DisplayText,
    kAccountConfigField_AccountDomain_DisplayTextUseDefault,
    kAccountConfigField_AccountDomain_DisplayTextResourceFile,
    kAccountConfigField_AccountDomain_DisplayTextResourceID,
    kAccountConfigField_AccountDomain_DefaultValue,
    kAccountConfigField_Account_AuthFormat,
    kAccountConfigField_AccountPassword_Type,
    kAccountConfigField_AccountPassword_CacheInterval,
    kAccountConfigField_AccountPassword_CacheType,
    kAccountConfigField_AccountPassword_CacheAllowEdit,
    kAccountConfigField_AccountPassword_Show,
    kAccountConfigField_AccountPassword_AllowModify,
    kAccountConfigField_AccountPassword_DisplayText,
    kAccountConfigField_AccountPassword_DisplayTextUseDefault,
    kAccountConfigField_AccountPassword_DisplayTextResourceFile,
    kAccountConfigField_AccountPassword_DisplayTextResourceID,
    kAccountConfigField_AccountPassword_DefaultValue,
    kAccountConfigField_Count
};

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSInteger, AccountConfigNodeContext)
{
    kAccountConfigNodeContext__Accounts,
    kAccountConfigNodeContext__Account,
    kAccountConfigNodeContext__Count
};

//  Wrapper class for Accounts
//  Encapsulates the xml document parsing, and document value storage, and document's metadata
//  Exposes uniform get methods for each data element 
@interface AccountConfigWrapper : NSObject 
{
@private
    iPassXMLDocument *mDocument;
    NSError         *mErr;
    int             mAccountCount;
    BOOL            mStatusOk;
}

- (id) initWithPath:(NSString *)filePath;
- (BOOL) isOk;
- (BOOL) isParsedOk;
- (void) print;

#pragma mark - Getters
- (NSString *)getProfileId;
- (NSString *)getMasterAccountName;
- (BOOL) isPreAuthValidationEnabled;
- (BOOL) isACAEnabled;
- (BOOL) isACAReactivationRequired;
#pragma mark - Account Level Getters
- (BOOL)validateCorrectness;
- (int)getAccountCount;
- (NSString *)getAccountName:(int) index;
- (NSString *)getAccountDescription:(int) index;
- (NSString *)getAccountDescriptionResourceID:(int) index;
- (NSString *)getAccountDescriptionResourceFile:(int) index;
- (NSString *)getAccountDisplayText:(int) index;
- (NSString *)getAccountUserNameType:(int) index;
- (NSString *)getAccountUserNameShow:(int) index;
- (NSString *)getAccountUserNameAllowModify:(int) index;
- (NSString *)getAccountUserNameDisplayText:(int) index;
- (NSString *)getAccountUserNameDefaultValue:(int) index;
- (NSString *)getAccountUserNameDisplayTextUseDefault:(int) index;
- (NSString *)getAccountUserNameDisplayTextResourceID:(int) index;
- (NSString *)getAccountUserNameDisplayTextResourceFile:(int) index;

- (NSString *)getAccountPrefixShow:(int) index;
- (NSString *)getAccountPrefixAllowModify:(int) index;
- (NSString *)getAccountPrefixDisplayText:(int) index;
- (NSString *)getAccountPrefixDefaultValue:(int) index;
- (NSString *)getAccountPrefixDisplayTextUseDefault:(int) index;
- (NSString *)getAccountPrefixDisplayTextResourceID:(int) index;
- (NSString *)getAccountPrefixDisplayTextResourceFile:(int) index;

- (BOOL)     isDomainConfiguredAndPresent:(int) index;
- (NSArray *)getAccountDomainList:(int) index;
- (NSString *)getAccountDomainShow:(int) index;
- (NSString *)getAccountDomainAllowModify:(int) index;
- (NSString *)getAccountDomainDisplayText:(int) index;
- (NSString *)getAccountDomainDefaultValue:(int) index;
- (NSString *)getAccountDomainDisplayTextUseDefault:(int) index;
- (NSString *)getAccountDomainDisplayTextResourceID:(int) index;
- (NSString *)getAccountDomainDisplayTextResourceFile:(int) index;

- (NSString *)getAccountAuthFormat:(int) index;

- (NSString *)getAccountPasswordType:(int) index;
- (NSString *)getAccountPasswordCacheInterval:(int) index;
- (NSString *)getAccountPasswordCacheType:(int) index;
- (NSString *)getAccountPasswordCacheAllowEdit:(int) index;

- (NSString *)getAccountPasswordShow:(int) index;
- (NSString *)getAccountPasswordAllowModify:(int) index;
- (NSString *)getAccountPasswordDisplayText:(int) index;
- (NSString *)getAccountPasswordDefaultValue:(int) index;
- (NSString *)getAccountPasswordDisplayTextUseDefault:(int) index;
- (NSString *)getAccountPasswordDisplayTextResourceID:(int) index;
- (NSString *)getAccountPasswordDisplayTextResourceFile:(int) index;

@end