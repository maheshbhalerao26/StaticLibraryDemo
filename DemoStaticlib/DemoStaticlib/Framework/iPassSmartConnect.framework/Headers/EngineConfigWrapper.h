//
//  EngineConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Luis Marmolejo on 9/28/11.
//  Copyright 2011 iPass. All rights reserved.
//
//  Revision History: 
//  3/12/12 - Ronak Shah: Added logic to parse the XML file once and store it in a respective .plist file
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class iPassXMLDocument;

// Public field identifiers for keying into private metadata for leaf nodes.
// This enum identifies each leaf node of interest to this app version because
// it contains a data element value
typedef NS_ENUM(NSInteger, EngineConfigSV)
{
    kEngineConfigFieldProfileId,
    kEngineConfigFieldDialerIDServerURL,
    kEngineConfigFieldWiFi_AllowUserToDisable,
    kEngineConfigFieldWiFi_USID_Enabled,
    kEngineConfigFieldAutoLogin_Network_Media,
    kEngineConfigFieldAutoLogin_Network_ProvisionerType,
    kEngineConfigFieldAutoLogin_Network_EnableBackgroundAutoLogin,
    kEngineConfigFieldAmIOnResponseSubstring,
    kEngineConfigFieldAmIOnUrl,
    kEngineConfigFieldAmIOnUserAgent,
    kEngineConfigFieldAuth_USID_Enabled,
    kEngineConfigFieldAuth_ISEEL,
    kEngineConfigFieldAuth_ISEEL_Supported,
    kEngineConfigFieldAuth_PublicKey,
    kEngineConfigFieldAuth_KeyVersion,
    kEngineConfigFieldAuth_Algorithm,  
    kEngineConfigFieldHotspotFinderURL,
    kEngineConfigFieldInAppHotspotFinderHostName,
    kEngineConfigFieldWebBasedHotspotFinderURL,
    kEngineConfigFieldDirectory_id,
    kEngineConfigFieldDirectory_AutoConnectEligible,
    kEngineConfigFieldDirectory_Filename,
    kEngineConfigFieldDirectory_Media,
    kEngineConfigFieldDirectory_USID_Enabled,
    kEngineConfigFieldDirectory_icon,
    kEngineConfigFieldDirectory_Account,
    kEngineConfigFieldDirectory_Account_AuthFormat,
    kEngineConfigFieldGlobal_Cmpolicy_FileName,
    kEngineConfigFieldGlobal_Cmpolicy_Id,
    kEngineConfigFieldSendLogsEmailTo,
    kEngineConfigFieldSendLogsEmailText_ResourceID,
    kEngineConfigFieldSendLogsEmailText_ResourceFile,
    kEngineConfigFieldSendLogsEmailText_UseDefault,
    kEngineConfigFieldCredentialsCheck_Enabled,
    kEngineConfigFieldCount
};

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSInteger, EngineConfigMV)
{
    kEngineConfigNodeContextNetworkDirectory,
    kEngineConfigNodeContextDirectory,
    kEngineConfigNodeContextCMPolicyList,
    kEngineConfigNodeContextCount
};

@interface EngineConfigWrapper : NSObject 
{
@private
    iPassXMLDocument *mDocument;
    NSError *mErr;
    int mDirectoryCount;
    int globalCMPolicyFileCount;
    BOOL mStatusOk;
}

- (id)   initWithPath: (NSString *) filePath;
- (id)   initWithFolderPath: (NSString *) path;
- (void) clearPlistFile ;
- (BOOL) isOk;
- (void) print;
- (BOOL) validateCorrectness;

#pragma mark - Getters
- (NSString *)getProfileId;
- (NSString *)getDialerIdServerURL;
- (NSString *)getWIFI_AllowUserToDisable;
- (NSString *)getWIFI_USID_Enabled;
- (NSString *)getAutoLogin_Network_Media;
- (NSString *)getAutoLogin_Network_ProvisionerType;
- (NSString *)getAutoLogin_Network_EnableBackgroundAutoLogin;
- (NSString *)getAuth_USID_Enabled;
- (BOOL) iSEELEnabled;
- (NSString *)iSEELPublicKey;
- (NSString *)iSEELKeyVersion;
- (NSString *)iSEELAlgorithm; 
- (NSString *)getHotspotFinderURL;
- (NSString *)getInAppHotspotFinderHostName;
- (NSString *)getWebBasedHotspotFinderURL;
- (NSString *)getEmailTo;
- (BOOL)getEmailText_ShouldUseDefault;
- (NSString *)getEmailText_ResourceFile;
- (NSString *)getEmailText_ResourceID;
- (BOOL) credentialsCheckEnabled;

#pragma mark - AmIOn Methods
- (NSString*)getAmIOnUrl;
- (NSString*)getAmIOnResponseString;
- (NSString*)getAmIOnUserAgent;

#pragma mark - Directory level getters
- (int)getDirectoryCount;
- (NSString* _Nullable)networkIconForCustomDirectoryWithID:(NSString*) directoryID;
- (NSString *)getDirectoryId:(int)index;
- (NSString *)getDirectory_Filename:(int)index;
- (NSString *)getDirectory_Media:(int)index;
- (NSString *)getDirectory_USID_Enabled:(int)index;
- (NSString *)getDirectory_icon:(int)index;
- (NSString *)getDirectory_Account:(int)index;
- (NSString* _Nullable)getDirectory_Account_AuthFormat:(int)index;
- (NSString *)getDirectory_AutoConnect_Eligible:(int)index;

#pragma mark - GLOBAL_CMPOLICY level getters
- (int)getGlobalCMPolicyFileCount;
- (NSString *)getGlobalCMPolicyFileName:(int) index;
- (NSString *)getGlobalCMPolicyId:(int) index;


#pragma mark - Derived / Inferred getters
- (BOOL)isAutoLoginEnabledInProfile;
- (BOOL)isBackgroundAutoLoginEnabledInProfile;

#pragma mark - Session Timeout
-(NSTimeInterval)alertThreshold;

-(NSTimeInterval)disconnectThreshold;

@end

NS_ASSUME_NONNULL_END
