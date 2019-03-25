//
//  SMCConnServiceConstants.h
//  iPassOpenMobile
//
//  Created by Rakesh Anjanappa on 10/22/13.
//
//

@import Foundation;

extern NSString* SMCConnectionStartdNotification;
extern NSString* SMCConnectionSuccessNotification;
extern NSString* SMCConnectionFailedNotification;
extern NSString* SMCConnectionAbortedNotification;
extern NSString* OMConnectionNotification;
extern NSString* keyConnectionStatus;

extern NSTimeInterval CAPTCHA_TIMEOUT;
extern NSTimeInterval MAX_AUTH_TIMEOUT;

extern NSTimeInterval AMION_RETRY_TIMEOUT_THRESHOLD;

//typedef NS_ENUM(NSInteger, OMOperationActionType)
//{
//    LoginAction = 0,
//    LogoutAction,
//    CancellAction
//};
//
//
//typedef NS_ENUM(NSInteger, connectionRetryContext) {
//    kAuthRetrySameRequest,
//    KAuthRetryNextBaseEntry,
//    kAuthConnectToPendingRequest
//};


//Enumeration for current request
typedef NS_ENUM(NSInteger, AuthRequestType){
    kAuthRequestLogin,
    kAuthRequestLogout
};
//
////!Connection errors
//typedef NS_ENUM(NSInteger, OMConnectionResult){
//    kConnectionNoError,
//    kConnectionNoCredentials,
//    kConnectionUnSupportedNetwork,
//    kConnectionMissingCommandParam,
//    kConnectionManualLoginNeeded,
//    kConnectionUIRequired, //tells the plugin to request for presentUI from iOS
//    kConnectionRequiresPrimaryInterface,
//    kConnectionNoMatchingNetworkFound,
//    kConnectionProtocolError,
//    kConnectionNetworkError,
//    kConnectionHttpError,
//    kConnectionUnknownError,
//    kConnectionRequiresRoamingAlert
//};

//typedef NS_ENUM(NSInteger, SMCReachability) {
//	kNotReachable = 0,
//	kReachableViaWiFi,
//	kReachableViaWiFiConnectionRequired,
//	kReachableViaWWAN,
//    kReachableUnknown
//};


typedef NS_ENUM(NSInteger, SMCLogoutInitiator) {
    SMCLogoutInitiatorUser = 1,
    SMCLogoutInitiatorSessionTimeout = 2,
    SMCLogoutInitiatorPlugin = 3,
    SMCLogoutRogueHotSpotDetected = 4,
};

////!Connection errors
//typedef NS_ENUM(NSInteger, OMDialogUIResponse){
//    kFailedInvalidCommandID,  // Connection failed since no valid commandID was there
//    kRoamingAlertAccepted,
//    KRoamingAlertDeclined,
//    kAccountsDailogDeclined,
//    kAccountsDailogAccepted,
//    kCapchaWiFiMadePrimaryInterface,
//    kUIEnteredForegroundForAuthentication,
//    kUIEnteredForegroundForManuallLogin,
//    kFalsePositiveMessageDisplayed,
//    kBackGroundAuthDisabledNotified,
//    kPostConnectURLLaunchNotified,
//    kConnectButton,
//    kUIGenericDeclined,  //used in cases when we don't know the type of message that was displayed but it has been declined.
//};

#define PRESENTUI_WAIT_TIMEOUT 20
#define SQM_USER_ID_FORMAT  @"%u@%d"
#define SQM_USER_ID_FORMAT_NO_DOMAIN  @"%u"

#define DEFAULT_LOGIN_RETRY_COUNT 2
//There is no way to find this at this moment hardcoded
#define RESOURCES_FILE_NAME       @"Resources"

//#define kALERT_TAG_ROAMING_ALERT 922

//connection result
#define keyConnectionResult @"connectionResult"
#define keyLoginString      @"LoginString"
#define keyAuthRequestType  @"authRequestType"


//wifi entry info tags
#define AUTH_METHOD_GIS         @"GI"
#define AUTH_METHOD_CAPTCHA_GC1 @"GC.1"
#define AUTH_METHOD_CAPTCHA_CG1 @"CG.1"
#define AUTH_METHOD_CAPTCHA_FLT1 @"FLT.1"
#define AUTH_METHOD_CAPTCHA_FLT2 @"FLT.2"
#define AUTH_METHOD_FHIS1 @"FH.1"
#define AUTH_METHOD_FHIS2 @"FH.2"
#define AUTH_METHOD_DS1 @"DS.1"
#define AUTH_METHOD_DS @"DS"
#define AUTH_METHOD_8021X @"8021x"
#define AUTH_METHOD_8021X_OLDERVERSION @"8021X"


#define AUTH_METHOD_8021X_TTLS_PAP @"8021X_TTLS_PAP"
#define AUTH_METHOD_8021X_TTLS_PAP_ANONYMOUS @"8021X_TTLS_PAP_ANONYMOUS"

// Context Tags

//#define kRequiresUINotificationSent @"SentReqUINotification"
//#define kLoginConnectionContext     1
//#define kLogoutConnectionContext    2

extern NSString* OMConnectionAuthPluginNotification;
extern NSString* OMConnectionNotification;

extern NSString* keyConnectionStatus;

//Notification keys
#define kOMActionType        @"Actiontype"
#define kOMAuthOriginator    @"AuthOrigin"
#define kOMIsAutoJoined      @"IsAutoJoined"
#define kOMCommandID         @"CommandID"
#define kNetworkName         @"NetworkName"
#define kLogoutInitiator     @"LogooutInitiator"
#define kRetryCount          @"RetryCount"
#define kSignalStrength      @"SignalStrength"
#define kActiveBssid         @"ActiveBssid"


//SQM Related

//disconnection reason codes
#define kConnectionStatusConnected              @"1"
#define kConnectionStatusNotConnected           @"0"
#define kDisconnectNormal                       @"1"
#define kDisconnectImplicit                     @"7"
#define kDisconnectSessionTimeOut               @"5"
#define kDisconnectRogueHotspotDetected         @"103"



////State Names
//#define kConnectionReadyStateName       @"conn.ReadyState"
//#define kConnNetworkDiscoveryStateName  @"conn.NetworkDiscovery"
//#define kConnPreProcessStateName        @"conn.PreProcess"
//#define kConnWaitingForUserStateName    @"conn.WaitingUserInput"
//#define kConnAbortedStateName           @"conn.Aborted"
//#define kConnFailedStateName            @"conn.Failed"
//#define kConnSuccessStateName           @"conn.Success"
//#define kConnPostProcessStateName       @"conn.PostProcess"
//#define kConnStartLogoutStateName       @"conn.LogginOut"
//#define kConnLoggedOutStateName       @"conn.LoggedOut"
//#define kConnStartLoginStateName        @"conn.LoggingIn"



//Payload Names
//#define kConnListentoConnection         @"conn.ListenToConnectionRequest"


#define SQMConnectionStageStart     @"start"
#define SQMConnectionStageStop      @"stop"
