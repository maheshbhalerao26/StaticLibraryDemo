//
//  DevicescapeConnect.h
//
//  Created by John Gordon on 10/17/08.
//  Copyright 2008-2015 Devicescape Software, Inc.. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <CoreLocation/CoreLocation.h>

#ifndef _DS_CONNECT_H_
typedef struct ds_connect * DS_Connect;
#endif

#define DS_CONNECT_LATITUDE_UNKNOWN     100         /* > 90  */
#define DS_CONNECT_LONGITUDE_UNKNOWN	1000        /* > 180 */
#define DS_CONNECT_ALTITUDE_UNKNOWN     -10000000	/* > earth diameter */

// Number of integers in a license
#define DEVICESCAPE_LICENSE_SIZE	4

// Network states
#define DS_NET_UNKNOWN				0
#define DS_NET_WIFI					1
#define DS_NET_CELLULAR				2
#define DS_NET_DOWN					3

// Registration states (these should match the native code values)
#define DS_REG_UNREGISTERED         0
#define DS_REG_COMPLETE				150
#define DS_REG_PENDING				151
#define DS_REG_ERROR                152
#define DS_REG_UNKNOWN				153

// Connection states
#define DS_CON_NO_WIFI				0
#define DS_CON_ONLINE				1
#define DS_CON_FAILED				2
#define DS_CON_NO_ACCOUNT			3
#define DS_CON_ERROR				4
#define DS_CON_CONNECTING			5
#define DS_CON_DISCONNECTING		6
#define DS_CON_OFFLINE				7
#define DS_CON_NEED_USERNAME		8
#define DS_CON_NEED_PASSWORD		9
#define DS_CON_NEED_BOTH			10
#define DS_CON_WHITELISTED			11
#define DS_CON_NO_NETWORK			12
#define DS_CON_NEED_TC_ACCEPT       13
#define DS_CON_INTERNAL_ERROR		255

// Keys for the login completed info dictionary
extern NSString * _Nonnull kDSConnectLoginStatus;
extern NSString * _Nonnull kDSConnectLoginReference;

// Keys for the Curation Information dictionary
extern NSString * _Nonnull kDSConnectCurationShade;
extern NSString * _Nonnull kDSConnectCurationConfidence;
extern NSString * _Nonnull kDSConnectCurationNeedTerms;
extern NSString * _Nonnull kDSConnectCurationVenueMessage;
extern NSString * _Nonnull kDSConnectCurationInNetwork;
extern NSString * _Nonnull kDSConnectCurationRaw;

// Keys for the Venue Message dictionary
extern NSString * _Nonnull kDSConnectVenueMessageText;
extern NSString * _Nonnull kDSConnectVenueMessageTitle;
extern NSString * _Nonnull kDSConnectVenueMessageUrl;
extern NSString * _Nonnull kDSConnectVenueMessageHash;
extern NSString * _Nonnull kDSConnectVenueMessageTimestamp;

// Network info dictionary keys
extern NSString * _Nonnull kDSConnectNetworkSSID;
extern NSString * _Nonnull kDSConnectNetworkBSSID;
extern NSString * _Nonnull kDSConnectNetworkSignalStrength;
extern NSString * _Nonnull kDSConnectNetworkSecure;
extern NSString * _Nonnull kDSConnectNetworkAutoJoined;
extern NSString * _Nonnull kDSConnectNetworkJustJoined;
extern NSString * _Nonnull kDSConnectNetworkChosenHelper;

@class DevicescapeConnect;

@protocol DevicescapeConnectDelegate
- (NSString * _Nullable) devicescapeGetSSID;
- (NSString * _Nullable) devicescapeGetBSSID;
- (NSDictionary * _Nullable) devicescapeGetNetworkInfo;
@optional
- (void) devicescapeRegistrationStateChanged:(NSNumber * _Nonnull)state;
- (void) devicescapeNetworkState:(NSNumber * _Nonnull)status;
- (void) devicescapeLoginStarted:(NSObject * _Nonnull)reference;
- (void) devicescapeLoginCompleted:(NSDictionary * _Nonnull)info;
- (void) devicescapeLogoutStarted;
- (void) devicescapeLogoutCompleted:(NSNumber * _Nonnull)status;
- (void) devicescapeMessageReceived:(NSString * _Nonnull)message;
- (void) devicescapeLocationReported:(CLLocation * _Nonnull)location;
- (void) devicescapeResults:(NSDictionary * _Nonnull)results;
- (void) devicescapeMatch:(NSDictionary * _Nonnull)match;
- (void) devicescapeProgress:(NSDictionary * _Nonnull)info;
- (void) devicescapeVenueMessage:(NSDictionary * _Nonnull)message;
@end

@protocol DSHttpHelperProtocol
// Hotspot helper interface
- (void) devicescapeHttpBindRequest:(NSMutableURLRequest * _Nonnull)request;
@end

@interface DevicescapeConnect : NSObject

// Delegate property
@property (nonatomic, retain) NSObject<DevicescapeConnectDelegate> * _Nullable delegate;

@property (nonatomic, readonly) NSString * _Nullable debugFilename;

// Initialization
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license;
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license locationManager:(CLLocationManager * _Nullable)locationMgr;
- (id _Nullable) initWithLicense:(NSString *_Nonnull )license locationManager:(CLLocationManager * _Nullable)locationMgr servers:(NSString *_Nonnull) servers;
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license servers:(NSString * _Nonnull) servers;
// Initialization WITH delegate
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license delegate:(id _Nonnull)delegate;
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license locationManager:(CLLocationManager * _Nullable)locationMgr delegate:(id _Nonnull)delegate;
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license locationManager:(CLLocationManager * _Nullable)locationMgr delegate:(id _Nonnull)delegate servers:(NSString * _Nonnull)servers;
- (id _Nullable) initWithLicense:(NSString * _Nonnull)license delegate:(id _Nonnull)delegate servers:(NSString * _Nonnull)servers;

// Popwifi Device ID (to be removed when API exists)
- (NSString * _Nullable) deviceId;

// Provide location from an external source
- (void) updateLocation:(CLLocation * _Nonnull) location;

// Connect location services in running instance (in case permission changes)
- (void) setLocationManager:(CLLocationManager * _Nullable)locationMgr;

// HTTP Helper
- (void) setHttpHelper:(id<DSHttpHelperProtocol> _Nullable) helper;

// Registration
- (NSString * _Nullable) registrationResult;
- (NSNumber * _Nonnull) registrationState;
- (NSString * _Nullable) registrationURL;
- (BOOL) setRegistrationState:(NSNumber * _Nonnull)state;

// Get the public key encrypted version of the device key (for remote registration support)
- (NSString * _Nullable) encryptedKey;

// Alive / login / logout
- (void) alive;
- (void) login:(NSObject * _Nullable)reference;
- (BOOL) canLogout;
- (void) logout;

// Messages
- (NSString * _Nullable) message;
- (NSString * _Nullable) hotspotMessage;

// Register
- (NSInteger) registerDevice;

// Log upload
- (BOOL) logUpload;

// State access
- (NSNumber * _Nonnull) status;
- (NSString * _Nullable) ssidString;
- (NSString * _Nonnull) statusString;
- (NSString * _Nullable) uuid;
- (NSString * _Nullable) signature;
- (NSString * _Nonnull) version;

#ifdef REACHABILITY
// Connection states
- (BOOL) connectionIsUp;
- (BOOL) connectionIsWiFi;
- (BOOL) connectionIsCellular;
#endif

// Terms & conditions
- (NSString * _Nullable) getTermsAndConditions;
- (BOOL) acceptTermsAndConditions;

// Grey shade etc
- (NSDictionary * _Nullable) getCurationInformation;
- (BOOL) hasAccount;
- (NSUInteger) sequence;

// Venue message access
- (NSDictionary * _Nullable) venueMessage;

// Session stats
- (NSDictionary * _Nullable) currentSessionStats;
- (void) endSession;

// Utility
+ (NSString * _Nullable) hexSsid:(NSData * _Nonnull)ssid;
+ (NSString * _Nullable) cleanBssid:(NSString * _Nonnull) bssid;

// Redirect debug
- (void) redirectDebug;

// Cancel HTTP transaction
- (void) cancelHttpTransaction;

@end
