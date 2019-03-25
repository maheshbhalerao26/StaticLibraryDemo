//
//  AccountsInfoWrapper.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 27/12/11.
//  Copyright (c) 2011 pshukla@ipass.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AccountConfigWrapper;

@interface AccountsInfoWrapper : NSObject

@property (atomic)AccountConfigWrapper* accountsWrapper;

//custom intializer
-(id)initWithAccountsWrapper:(AccountConfigWrapper*)accountsWrapper;
-(id)initWithAccountsWrapperAtPath:(NSString*)profilePath;

#pragma mark - AccountInfo
-(NSString *)getAccountDescriptionResourceID;
-(NSString *)getAccountDescriptionResourceFile;
-(NSString *)getDefaultAccountDescription;

#pragma mark - Prefix Info
- (BOOL)isPrefixConfigured;
- (NSString*)defaultPrefix;
- (BOOL)isShowPrefix;
- (NSString*)displayPrefix;
- (BOOL)isAllowModifyPrefix;
- (BOOL)isPrefixDisplayTextUseDefault;
- (NSString *)getPrefixDisplayTextResourceID;
- (NSString *)getPrefixDisplayTextResourceFile;

#pragma mark - Username Info
- (BOOL)isUsernameConfigured;
- (NSString*)defaultUsername;
- (BOOL)isShowUsername;
- (NSString*)displayUsername;
- (BOOL)isAllowModifyUsername;
- (BOOL)isUserNameDisplayTextUseDefault;
- (NSString *)getUserNameDisplayTextResourceID;
- (NSString *)getUserNameDisplayTextResourceFile;

#pragma mark - Password Info
- (BOOL)isPasswordConfigured;
- (NSString*)defaultPassword;
- (BOOL)isShowPassword;
- (NSString*)displayPassword;
- (BOOL)isAllowModifyPassword;
- (BOOL)isAllowEditCache;
- (NSString*)cacheType;
- (BOOL)isPasswordDisplayTextUseDefault;
- (NSString *)getPasswordDisplayTextResourceID;
- (NSString *)getPasswordDisplayTextResourceFile;

#pragma mark - Domain Info
- (BOOL)isDomainConfigured;
- (NSString*)defaultDomain;
- (BOOL)isShowDomain;
- (NSString*)displayDomain;
- (BOOL)isAllowModifyDomain;
- (nullable NSArray<NSString*>*)domainList;
- (BOOL)isDomainDisplayTextUseDefault;
- (NSString *)getDomainDisplayTextResourceID;
- (NSString *)getDomainDisplayTextResourceFile;

#pragma mark - Account label Info to display
- (NSString *)getAccountDescriptionLabelForDisplay;
- (NSString *)getDisplayLabelForPrefix;
- (NSString *)getDisplayLabelForUserName;
- (NSString *)getDisplayLabelForPassword;
- (NSString *)getDisplayLabelForDomain;

#pragma mark - 
- (BOOL) isPreAuthValidationEnabled;
- (BOOL) isACAEnabled;
- (BOOL) isACAReactivationRequired;
@end
