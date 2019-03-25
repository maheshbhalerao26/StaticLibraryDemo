    //
    //  OMProfileConfig.h
    //  iPassOpenMobile
    //
    //  Created by Puru Shukla on 02/07/13.
    //
    //

#import <Foundation/Foundation.h>

    // Public field identifiers for keying into private metadata for context nodes.
    // This enum identifies each node of interest to this app version because
    // it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSUInteger, ProfileNodeContext){
    kProfileConfigContext_ProfileConfig,
    kProfileConfigContext_ProfileFinderURL,
    kProfileConfigContext_ActivationLoginURL,
    kProfileConfigContext_LoginURL,
    kProfileConfigContext_UpdateURL,
    kProfileConfigContext_ActivationConfirmationURL,
    
        //sqm client url
    kProfileConfigContext_SQMClientURL,
    kProfileConfigContext_SQMConnectionQualityURL,
    kProfileConfigContext_SQMDeviceURL,
    kProfileConfigContext_SQMConnectionURL,
    kProfileConfigContext_SQM,
    
    // AdId url
    kProfileConfigContext_AIDFeed,
    
        //other properties
    kProfileConfigContext_ActivationServerURL,
    kProfileConfigContext_DialerIDServerURL,
    kProfileConfigContext_ACAMigrationServerURL,
    kProfileConfigContext_ACAMigrationReIssueURL,
    kProfileConfigContext_UserAuthorizationURL,
    
        //device registration check URL
    kProfileConfigContext_DeviceRegistrationCheckURL,
    
        //Themis access point query
    kProfileConfigContext_AccessPointQueryURL,
    kProfileConfigContext_AccessPointKeyExchangeURL,
    kProfileConfigContext_AccessPointDnsHost,
    
        //devicescape registration  URL
    kProfileConfigContext_DevicescapeRegistrationURL,
    
        //One click activation cookie read URL
    kProfileConfigContext_OneClickCookieActivationReadURL,
    
        //dynamic code validation url context
    kProfileConfigContext_DynamicCodeValidationURL,
    kProfileConfigContext_DynamicTokenValidationURL,
    
        //RTN urls
    kProfileConfigContext_RTNDNSHost,
    kProfileConfigContext_RTNKeyExchangeURL,
    kProfileConfigContext_RTNCDBUploadURL,
    
        //Push urls
    kProfileConfigContext_PushRegistrationURL,
    kProfileConfigContext_PushAcknowledgementURL,
    
        //Hotspot report URL
    kProfileConfigContext_HotspotReportURL,
    
        //Check crednetials URL
    kProfileConfigContext_CheckCredentialsURL,
    
        //ISEEL Verification URL
    kProfileConfigContext_ISEELVerificationURL,
    
        //Token Activation
    kProfileConfigContext_SDKActivationURL,
    
    
    //scheme Url
    kProfileConfigContext_SchemeURL,
    
        //Log Analysis Server APIs Url
    kProfileConfigContext_LogServiceURL,
    
    //8021x Token Url
     kProfileConfigContext_X8021xTokenURL,
    
    //8021x instal Url
    kProfileConfigContext_X8021xInstalURL,
     //8021x Hello Url
    kProfileConfigContext_X8021xHellolURL,
    
 //  OAA Request Url
    
    kProfileConfigContext_OaaAuthRequestURL,
    
//  OAA Session Stop Url
    kProfileConfigContext_OaaSessionStopURL,
    
        //Log Analysis Server APIs Url
//    kProfileConfigContext_RogueHotspotValidatorURL,

    
        //Voucher Activation
    kProfileConfigContext_SDKVoucherActivationURL
};

@interface OMProfileConfig : NSObject<NSXMLParserDelegate>

    //! @brief URL for the profile finder
    //! @property profileFinderURL
@property (nonatomic, strong)NSString* profileFinderURL;
//! @brief URL for the login on the portal during activation/updates
//! @property loginURL
@property (nonatomic, strong)NSString* activationLoginURL;

    //! @brief URL for the login on the portal during activation/updates
    //! @property loginURL
@property (nonatomic, strong)NSString* loginURL;

    //! @brief URL for the update URL
    //! @property updateURL
@property (nonatomic, strong)NSString* updateURL;

    //! @brief URL for the Activation Confirmation URL
    //! @property activationConfirmationURL
@property (nonatomic, strong)NSString* activationConfirmationURL;

    //! @brief URL for the SQM Client URL
    //! @property sqmClientURL
@property (nonatomic, strong)NSString* sqmClientURL;
    //! @brief URL for the SQM Connection quality URL
    //! @property sqmClientURL
@property (nonatomic, strong)NSString* sqmConnectionQualityURL;
    //! @brief URL for the SQM Device URL
    //! @property sqmClientURL
@property (nonatomic, strong)NSString* sqmDeviceURL;
    //! @brief URL for the SQM Connection URL
    //! @property sqmClientURL
@property (nonatomic, strong)NSString* sqmConnectionURL;
    //! @brief URL for the SQM URL
    //! @property sqmClientURL
@property (nonatomic, strong)NSString* sqmURL;

    //! @brief URL for the Activation Server URL
    //! @property activationServerURL
@property (nonatomic, strong)NSString* activationServerURL;

    //! @brief URL for the Dialer ID Server URL
    //! @property dialerIDServerURL
@property (nonatomic, strong)NSString* dialerIDServerURL;

    //! @brief URL for the ACA Migration Server URL
    //! @property acaMigrationServerURL
@property (nonatomic, strong)NSString* acaMigrationServerURL;
@property (nonatomic, strong)NSString* acaMigrationReIssueURL;

    //! @brief URL for the User Authorization URL
    //! @property userAuthorizationURL
@property (nonatomic, strong)NSString* userAuthorizationURL;

    //! @brief URL for the Hotspot Finder Hostname
    //! @property Hotspot Finder Hostname
@property (nonatomic, strong)NSString* hotspotFinderHostname;

    //! @brief URL for the Push Server Registration URL
    //! @property pushRegistrationURL
@property (nonatomic, strong)NSString* pushRegistrationURL;

    //! @brief URL for the Push Server acknowledgement URL
    //! @property pushAcknowledgementURL
@property (nonatomic, strong)NSString* pushAcknowledgementURL;

    //! @brief URL for the dynamic code validation
    //! @property dynamicCodeValidationURL
@property (nonatomic, strong)NSString* dynamicCodeValidationURL;

    //! @brief URL for the dynamic token validation
    //! @property dynamicTokenValidationURL
@property (nonatomic, strong)NSString* dynamicTokenValidationURL;

    //! @brief URL for the CFC device registration check
    //! @property cfcCheckDeviceRegistrationURL
@property (nonatomic, strong)NSString* cfcCheckDeviceRegistrationURL;

    //! @brief Themis accessPointQueryURL
    //! @property accessPointQueryURL
@property (nonatomic, strong)NSString* accessPointQueryURL;

    //! @brief Themis KeyExchange URL
    //! @property accessPointKeyExchangeURL
@property (nonatomic, strong)NSString* accessPointKeyExchangeURL;

    //! @brief URL Themis Dns Server
    //! @property accessPointDnsHost
@property (nonatomic, strong)NSString* accessPointDnsHost;

#pragma mark - Devicescape Related
    //! @brief URL for the CFC device registration check
    //! @property cfcCheckDeviceRegistrationURL
@property (nonatomic, strong)NSString* devicescapeRegistrationURL;

    //One click activation cookie read URL
@property (nonatomic, strong)NSString* oneClickCookieActivationReadURL;

#pragma mark - RTN Host/URLs
    //! @brief URL RTN Key exchange server
    //! @property rtnKeyExchangeURL
@property (nonatomic, strong)NSString* rtnDNSHost;

    //! @brief URL RTN Key exchange server
    //! @property rtnKeyExchangeURL
@property (nonatomic, strong)NSString* rtnKeyExchangeURL;

    //! @brief URL RTN CDB Upload URL
    //! @property rtnCDBUploadURL
@property (nonatomic, strong)NSString* rtnCDBUploadURL;

    //! @brief URL Hotspot Feedback
    //! @property hotspotFeedbackURL
@property (nonatomic, strong)NSString* hotspotReportURL;

    //! @brief URL Credentials Check URL
    //! @property credentialsCheckURL
@property (nonatomic, strong)NSString* credentialsCheckURL;

    //! @brief URL ISEEL Verification URL
    //! @property iSEELVerificationURL
@property (nonatomic, strong)NSString* iSEELVerificationURL;

    //! @brief Token Activation URL
    //! @property tokenActivationURL
@property (nonatomic, strong)NSString* sdkActivationURL;

@property (nonatomic, strong)NSString* schemeURL;
    //! @brief Log Analysis Server APIs
    //! @property logServiceURL
@property (nonatomic, strong)NSString* logServiceURL;
    //! @property 8021xTokenURL
@property (nonatomic, strong)NSString* x8021xTokenURL;
    //! @property 8021xInstalURL
@property (nonatomic, strong)NSString* x8021xInstalURL;
 //! @property 8021xHellolURL
@property (nonatomic, strong)NSString* x8021xHellolURL;

//! @property AdIdURL
@property (nonatomic, strong)NSString* adIdURL;

//! @property OaaAuthRequestURL
@property (nonatomic, strong)NSString* oaaAuthRequestURL;

//! @property OaaSessionStopURL
@property (nonatomic, strong)NSString* oaaSessionStopURL;


//    //! @brief RogueHotspot Server APIs
//    //! @property RogueHotspotServerURL
//@property (nonatomic, strong)NSString* RogueHotspotValidatorURL;


    //! @brief Voucher Activation URL
    //! @property VoucherActivationURL
@property (nonatomic, strong)NSString* sdkVoucherActivationURL;

    //for Default ProfileID from ServerConfig
@property (nonatomic, strong)NSString *defaultProfileID;


    //creating prfile config
+(instancetype)defaultProfileConfig;
-(instancetype)initWithProfileConfigXMLPath:(NSString*)profileConfigXMLPath;
+(void) resetSharedObject;
@end
