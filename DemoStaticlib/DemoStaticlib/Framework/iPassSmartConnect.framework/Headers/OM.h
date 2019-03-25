//
//  OM.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 06/09/12.
//

#import <Foundation/Foundation.h>

// Preauth Validation state
typedef NS_ENUM(NSInteger, CredentialValidationState)
{
    kValidationStateUnknown = 0,
	kValidationStateKeyNotValid =1,
	kValidationStateNoUsername =2,
    kValidationStateNoPassword =3,
    kValidationStateInProgress =4,
    kValidationStateInitiated =5,
	kValidationStateRetryAgain =6, // Send the data as the next RTN message
	kValidationStateAuthSucess =7,
	kValidationStateAuthRejected =8,
	kValidationStateAuthUnresolved =9,
	kValidationStateNotAniPassNetwork =10,
	kValidationStateAuthenticateUsingGIS =11,
	kValidationStateAuthenticateUsingDS =12,
	kValidationStateInaccessibleRadiusServer =13,
	kValidationStateCustomerAAAError =14,    
    kValidationStateIncomplete =15,
    kValidationStateComplete =16
} ;

//! @brief Launch Context
typedef NS_ENUM(NSInteger, OMLaunchContext)
{
    kLCLocalNotifications,
    kLCURL,
    kLCUnknown,
} ;

//! @brief Local Notification Type
typedef NS_ENUM(NSInteger, LocalNotificationType)
{
    kLNPluginUIRequired,
    kLNPluginForegroundAuthentication,
    kLNUsageAlert,
    kLNSessionTimeout,
    kLNNone,
    kLNRoamingAlert,
    kLNSessionLoggedout,
    kLNEmailPromptAcaMigration,
    kLNAcaMigrationSuccess,
    kLNDSTermsAndCondition,
    kLNMotionRequest
} ;

//! @brief Local notification type key
extern NSString* keyLocalNotificationType;

//! @brief Block to be executed on main thread
typedef void(^UIBlock)(void);
typedef void (^VoidBlock)(void);

@interface OM : NSObject

//! @brief returns the shared instance of OM
+ (OM*)sharedOM;

// Returns TRUE whether the environment is qa or debug
//+(BOOL)qaOrDebugEnvironment;

//! @brief OM activated state
//+ (void)setOMActivated:(BOOL)omActivated;
//+ (BOOL)isOMActivated;

//! @brief OM Branded State
//+(NSString*)bundleIdentifier;
+(NSString*)bundleVersion;

//! @brief method returns current OM version
-(NSString*)omVersion;

//! @brief Method return the background time remaining minus 5 seconds.
- (NSTimeInterval)backgroundTimeout;

//Return Originator  description
//-(NSString*)connectionOriginatorDescriptor:(SMCAuthOriginator)originator;

//Returns PreAuth Status Despriction
-(NSString*)preAuthStatusDescription:(CredentialValidationState)validationState;

@end
