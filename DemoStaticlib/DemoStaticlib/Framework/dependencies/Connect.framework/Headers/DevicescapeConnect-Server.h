//
//  DevicescapeConnect-Server.h
//  Devicescape
//
//  Created by John Gordon on 2/26/09.
//  Copyright 2009 Devicescape Software, Inc.. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DevicescapeConnect.h"

// Keys for the user info dictionary
extern NSString * _Nonnull UserCode;
extern NSString * _Nonnull UserEmail;
extern NSString * _Nonnull UserPassword;
extern NSString * _Nonnull UserFreeNetworks;
extern NSString * _Nonnull UserEmailNetworks;
extern NSString * _Nonnull UserCollectLocations;
extern NSString * _Nonnull UserServiceAnnounce;
extern NSString * _Nonnull UserCommunityAnnounce;

// Optional (will be taken from device settings if not specified)
extern NSString * _Nonnull UserCountryCode;
extern NSString * _Nonnull UserLocaleCode;

// Optional (if not present, user will be created active)
extern NSString * _Nonnull UserActive;

// Only needed when creating partner accounts
extern NSString * _Nonnull PartnerID;
extern NSString * _Nonnull PartnerPassword;

// Keys for the credential provider list dictionary
extern NSString * _Nonnull CredentialProviderId;
extern NSString * _Nonnull CredentialProviderType;
extern NSString * _Nonnull CredentialProviderAuthType;
extern NSString * _Nonnull CredentialProviderName;
extern NSString * _Nonnull CredentialProviderDescription;
extern NSString * _Nonnull CredentialProviderHelp;
extern NSString * _Nonnull CredentialProviderUsernameLabel;
extern NSString * _Nonnull CredentialProviderHasCredential;
extern NSString * _Nonnull CredentialProviderTermsLabel;
extern NSString * _Nonnull CredentialProviderTermsURL;

// Keys for the user's credential list
extern NSString * _Nonnull CredentialId;
extern NSString * _Nonnull CredentialType;
extern NSString * _Nonnull CredentialAuthType;
extern NSString * _Nonnull CredentialName;
extern NSString * _Nonnull CredentialDescription;
extern NSString * _Nonnull CredentialHelp;
extern NSString * _Nonnull CredentialUsernameLabel;
extern NSString * _Nonnull CredentialTermsLabel;
extern NSString * _Nonnull CredentialTermsURL;

// Constants for the user account/device options
#define DS_FREE_HOTSPOTS_NONE			0
#define DS_FREE_HOTSPOTS_ALL			1
#define DS_FREE_HOTSPOTS_VALIDATED		2
#define DS_NO_EMAIL_NETWORKS			0
#define DS_EMAIL_NETWORKS			1
#define DS_NO_LOCATION_DATA			0
#define DS_LOCATION_DATA			1
#define DS_SERVICE_CRITICAL			0
#define DS_SERVICE_ALL				1
#define DS_COMMUNITY_NONE			0
#define DS_COMMUNITY_ALL			1
#define DS_COMMUNITY_NEWS_AND_OFFERS		2

@interface DevicescapeConnect (Server)

// Server API functions
- (NSInteger) createCredentialForProvider:(NSInteger)provider withUsername:(NSString * _Nullable)user andPassword:(NSString * _Nullable)pass;
- (NSInteger) updateCredentialForProvider:(NSInteger)provider withUsername:(NSString * _Nullable)user andPassword:(NSString * _Nullable)pass;
- (NSInteger) deleteCredentialForProvider:(NSInteger)provider withUsercode:(NSString * _Nonnull)usercode;
- (NSString * _Nullable) userCreateWithInfo:(NSDictionary * _Nonnull)userInfo;
- (NSInteger) userEditWithInfo:(NSDictionary * _Nonnull)userInfo;

- (NSInteger) deviceAddForUser:(NSString * _Nonnull)usercode;
- (NSDictionary * _Nullable) userInfoForDevice;
- (NSDictionary * _Nullable) userInfoForEmail:(NSString * _Nullable)email withPassword:(NSString * _Nullable)password;
- (NSArray * _Nullable) providerQuery:(NSString * _Nonnull)query;
- (NSArray * _Nullable) credentialList;

- (NSInteger) lastResultCode;

@end
