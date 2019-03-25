//
//  OMNotifications.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 20/03/12.
//  Copyright (c) 2012 pshukla@ipass.com. All rights reserved.
//

#ifndef iPassOpenMobile_OMNotifications_h
#define iPassOpenMobile_OMNotifications_h

@import Foundation;

//Application data loading finished notification
//extern NSString* OMAppDataLoadingFinishedNotification;

/** @brief Activation specific notification
 */
//extern NSString* OMActivationStartedNotification;
extern NSString* OMActivationSuccessNotification;
extern NSString* OMActivationFailedNotification;

// not a notif
extern NSString* keyActivationErrorCode;

//! Operation Notifications
extern NSString* OMOperationStartNotification;
extern NSString* OMOperationFinishedNotification;

//! Network Status Notifications
extern NSString* OMNetworkStatusChangedNotification;

//! Signal strength change Notifications
//extern NSString* OMSignalStrengthUpdateNotification;

//************* RTN Response related Notifications************//
//extern NSString* OMRtnResponseReceivedNotification;
//extern NSString* keyRtnResponseAction;

//! Captive Network Registration Notifications
//extern NSString* OMNetworkRegistrationStartNotification;
//extern NSString* OMNetworkRegistrationFinishedNotification;

//! Captcha notifications
//extern NSString* OMCaptchaShowNotification;
extern NSString* OMCaptchaHideNotification;
extern NSString* OMDSTermsAndConditionShowNotification;

////! Keys for URL activation
//extern NSString* keyURLActivationProfile;
//extern NSString* keyURLActivationPin;
//
//extern NSString* keyURLProvisionTest;
//extern NSString* keyURLProvisionUsername;
//extern NSString* keyURLProvisionPassword;
//extern NSString* keyURLProvisionDomain;
//extern NSString* keyURLProvisionPrefix;
//extern NSString* keyURLProvisionAutologin;
//extern NSString* keyURLProvisionResultUrlScheme;
//extern NSString* keyURLProvisionObfuscation;

//! Open URL Notification
//extern NSString* OMCOpenURLNotification;

//! User Accepted Eula Notification
//extern NSString* OMCUserAcceptedEulaNotification;

//! URL Request Notifications
//extern NSString* OMCURLActivationRequestedNotification;
//extern NSString* OMCURLDynamicCodeNotification;
//extern NSString* keyProfileCredentials;
//extern NSString *OMUIStateChangeNotification;
//extern NSString *OMShowAccountSettingsNotification;
//extern NSString *OMShowAccountRSSettingsNotification;
//extern NSString *OMDismissAccountSettingsNotification;
//extern NSString *OMDismissAccountRSSettingsNotification;
//extern NSString *OMAccountSettingsUpdatedNotification;
extern NSString *OMShowUsageAlertSettingsNotification;
//extern NSString *OMShowHelpNotification;
extern NSString *OMUsageAlertSettingsUpdatedNotification;
extern NSString *OMUsageDataUpdatedNotification;
//extern NSString *OMNavigationWillHideViewController;
//extern NSString *OMNavigationWillShowViewController;
//extern NSString *OMNavigationDidHideViewController;
//extern NSString *OMNavigationDidShowViewController;
//extern NSString *OMUIPageSwipedNotification;
//extern NSString *OMUIOrientationChangedNotification;

//! @brief application notifications
extern NSString* OMApplicationDidFinishLaunching;
extern NSString *OMApplicationDidEnterBackground;
extern NSString *OMApplicationWillEnterForeground;

//! @brief Dialer Id Notification
//extern NSString* OMDialerIdNotification;

//! Update notifications
extern NSString *OMUpdateNotification;

//! History Updated Notification
extern NSString *OMHistoryUpdatedNotification;

//! Location Service Notifications
extern NSString *OMLocationUpdateSuccessNotification;
extern NSString *OMLocationUpdateFailedNotification;
extern NSString *OMLocationUpdateServiceDisabledNotification;

//! Keys used for querying reverse geocoded data
extern NSString* keyLocationCity;
extern NSString* keyLocationState;
extern NSString* keyLocationIsoCountryCode;

#pragma mark - Network Monitor Notification
extern NSString* OMRequestNetworkDiscoveryNotification;

#pragma mark - Authenticator Plugin Notifications
extern NSString* OMAuthPluginNotification;
extern NSString* OMConnectionStopRecordNotification;
extern NSString* SMSuspendedAuthPluginNotification;

//#pragma mark - Hotspot Finder
//extern NSString *OMHotspotFinderOfflineModePreferenceDidChangeNotification;
//extern NSString *OMHotspotFinderFilterPreferencesDidChange;
//
//#pragma mark - Hotspots LiveTile Notification
//extern NSString *OMHotspotsLiveTileDidGetHotspots;
//extern NSString *OMHotspotsLiveTileDidFailToGetHotspots;
//extern NSString *OMHotspotsLiveTileLocationServicesDisabled;

extern NSString *OMSQMConnectionNotification;

//extern NSString *OMACADiagRecordNotification;
extern NSString *OMCredCheckDiagRecordNotification;
extern NSString *OMISEELDiagRecordNotification;
extern NSString *OMCredentialsVerifierNotification;
//extern NSString *OMHomeCountryDiagRecordNotification;


#pragma mark - Connection Service state machine
//Connection service state machine was created
//extern NSString* OMConnectionServiceCreatedNotification;


#pragma mark - False positive message displayed
//extern NSString * OMFalsePostiveMessageDisplayed;

#pragma mark - Display dashboard alert
//extern NSString *OMDisplayDashboardAlert;

#pragma mark - Travel preferences - home country
//extern NSString *OMHomeCountryChangedNotification;

#pragma mark - ACA Migration Success Notification
extern NSString* OMACAMigrationSuccessNotification;

#pragma mark - Client Deactivation Notification
//extern NSString* OMDeactivationFinishedNotification;

#pragma mark - WHAT'S NEW dialog show notification
//extern NSString* OMWhatsNewDialogShowNotification;

extern NSString* OMConnFailedForRTNNotification;

// Demeter Perceptron
extern NSString* OMMotionActivityNotification;


// Notification Thrown when SDK is initialized
extern NSString* SDKInitializedNotification;

//Notification for RogueHotspot
extern NSString* RogueHotspotNotification;

//extern NSString* keyRecentActivityUpdate;
/* !@class OMNotification
 *  @discussion OMNotification defines the notifications and provides methods to
 *  enqueu/post notifications.
 */
@interface OMNotificationCenter : NSObject
//! Notifications
+ (void)enqueueNotification:(NSNotification *) notification;
+ (void)enqueueNotificationName:(NSString *)aName object:(id)anObject;
+ (void)enqueueNotificationName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo;

//! @brief add observers
+(void)addObserver:(id)observer selector:(SEL)selector name:(NSString *)notificationName object:(id)sender;

//! @brief Method removes the observer from listening for any notifications
+ (void) removeObserver:(id)observer;
+ (void) removeObserver:(id)observer forNotification:(NSString*)name;
@end

#endif
