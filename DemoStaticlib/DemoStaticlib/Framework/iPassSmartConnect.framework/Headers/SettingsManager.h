//
//  Settings.h
//  iPassConnect
//
//  Created by Ranjit Singh on 19/10/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KeyCrypto;
@class SMCAuthCredentials;
/// @name Binding Identifiers
/// @{
extern NSString* keySettingsAllowAccountsScreenDisplay;
extern NSString* keySettingsProfileId;
extern NSString* keySettingsBaseSessionId;
extern NSString* keySettingsSessionId;
extern NSString* keySettingsiSEELData;
extern NSString* keySettingsiSEELStatus;

extern NSString* keySettingsCustomerId;
extern NSString* keySettingsPin;
extern NSString* keySettingsProfilePinEmail;
extern NSString* keySettingsPassword;
extern NSString* keySettingsDialerId;
extern NSString* keySettingsCurrCachedSQMCounterValue;
extern NSString* keySettingsCorporateAccount;
extern NSString* keySettingsSandboxInstallId;
extern NSString* keySettingsInstallid;
extern NSString* keySettingsAutoLoginEnabled;
extern NSString* keySettingsAfterConnection;
extern NSString* keySettingsTimestamp;
extern NSString* keySettingsLastUpdate;
extern NSString* keySettingsLastUpdateAttempt;
extern NSString* keySettingsClientRecordUploaded;
extern NSString* keySettingsCfcDeviceRegLastCheckTime;
extern NSString* keySettingsScheme;

extern NSString* keySettingsLastAssociatedNetwork;

//returns the GlobalCMPolicy version info str for profile update
extern NSString* keySettingsGlobalCMPolicyVersionStr;
extern NSString* keySettingsGlobalCMPolicyRateMap;
//to check if 108 open access directory is present

extern NSString* keySettingsisOpenAccessDirectoryPresent;
//warning message
extern NSString* keySettingsDontShowWarningMessage;
extern NSString* keySettingsDontShowCredentialWarningMessage;
extern NSString* keySettingsDontShowPrefixWarningMessage;

extern NSString* keySettingsIsClientConfigured;
extern NSString* keySettingsIsClientDeactivated;

//reference markers for usage data
extern NSString* keySettingsCellRefInBytes;
extern NSString* keySettingsCellRefOutBytes;
extern NSString* keySettingsWiFiRefInBytes;
extern NSString* keySettingsWiFiRefOutBytes;

//usage settings
extern NSString* keySettingsBillingDate;
extern NSString* keySettingsAlerMeEnabled;

//usage alert settings
extern NSString* keySettingsUsageLimit;
extern NSString* keySettingsUsageLimitType;
extern NSString* keySettingsUsageAlertStatus;

//usage tracking
extern NSString* keySettingsTimeLastCommit;
extern NSString* keySettingsLastRecordedUptime;

extern NSString *keySettingsSoftwareVersion;

//upgrading profile
extern NSString* keySettingsProfileDownloadScheduled;

//For Analytics
extern NSString* keySettingMonthlyOnNet;
extern NSString* keySettingFirst5OnNetCount;

// For Hotspot Finder
extern NSString *keySettingsDistanceUnitPreference;

//In Accounts settings page to show warning when right credentials are getting modified
extern NSString *keySettingsLastSuccessfulLoginDate;

//Last time we checked credentials
extern NSString *keySettingsLastCredCheckDate;

// For PreAuthValidation
extern NSString *keySettingsPreConnectEncriptionKey;
extern NSString *keySettingsPreConnectEncriptionKeyDate;

// Offline HSF
extern NSString *keySettingsOfflineHSFExpectedDownloadSize;
extern NSString *keySettingsOfflineHSFZipLastModified;
extern NSString *keySettingsOfflineHSFZipMD5sum;
extern NSString *keySettingsOfflineHSFUserPreffersOfflineMode;

extern NSString *keySettingsHotelFilter;
extern NSString *keySettingsRestaurantFilter;
extern NSString *keySettingsAirportFilter;
extern NSString *keySettingsOtherFilter;

//INR + Filter Scan
extern NSString *keySettingsLastFilterScan;

//Last push registration
extern NSString *keySettingsLastPushRegistration;


// Hotspot regions configuration
extern NSString *keySettingsOfflineHotspotsRegionConfiguration;
// Whitelist, blacklist regions
extern NSString *keySettingsWhiteBlackListRegionConfiguration;
// Home country
extern NSString *keySettingsHomeCountry;

//What's new dialog shown flag
extern NSString *keySettingsWhatsNewDialogDisplayed;

//Last time we performed manual verification of credentials
extern NSString *keySettingsLastManualCredCheckDate;

//Kronos key
extern NSString *keySettingsKronosSharedKey;
extern NSString *keySettingsThemisUUID;
extern NSString *keySettingsThemisLastStoreDeletionTimeStamp;

//Indicates whether devicescape registration successful or not
extern NSString *keySettingsDevicescapeRegistered;

//DynamicPassword
extern NSString *keySettingsIsDynamicPasswordEnabled;

// Touch Id
extern NSString *keySettingsIsTouchIdEnabled;

// Device Registration Check
extern NSString *keySettingsDeviceRegLastCheckDate;

//To know the deviceStatus Registered/Unregistered
extern NSString *keySettingsDevicveStatusCheckResponse;

//To Know the AcaSuspendBackOffIndex
extern NSString *keySettingsAcaSuspendBackOffIndex;
extern NSString *keySettingsACAHash;



NS_ASSUME_NONNULL_END
