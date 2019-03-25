//
//  ServerConfig.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 01/07/13.
//
//

#import <Foundation/Foundation.h>

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSUInteger, ServerConfigNodeContext){
    kServerConfigContext_ServerConfig,
    kServerConfigContext_ProfileServer,
    kServerConfigContext_DataCollectorServer,
    kServerConfigContext_ActivationServer,
    kServerConfigContext_UserAuthorizationServer,
    kServerConfigContext_HotspotFinderDefaultHostName,
    kServerConfigContext_HotspotReportHostName,
    kServerConfigContext_RemotePushServer,
    kServerConfigContext_ThemisServer,
    kServerConfigContext_ThemisDnsServer,
    //RTN servers
    kServerConfigContext_RtnDnsServer,
    kServerConfigContext_RtnKeyExchangeServer,
    kServerConfigContext_RtnCdbUploadServer,
    //One click activation Server
    kServerConfigContext_OneClickActivationServer,
    //other properties
    kServerConfigContext_DefaultProfileID,
    kServerConfigContext_DefaultCompanyID,
    
    //LogService server
    kServerConfigContext_LogServiceServer,
//    kServerConfigContext_AmiPassServer,
    kServerConfigContext_x8021xServer,
    kServerConfigContext_oaaServer,
    
};

@interface OMServerConfig : NSObject<NSXMLParserDelegate>

//! @brief Hostname for profile server
//! @property profileServer
@property (nonatomic, strong)NSString* profileServer;

//! @brief Hostname for data collector server
//! @property datacollectorServer
@property (nonatomic, strong)NSString* datacollectorServer;

//! @brief Hostname for activation server
//! @property activationServer
@property (nonatomic, strong)NSString* activationServer;

//! @brief Hostname for one click activation server
//! @property oneClickActivationServer
@property (nonatomic, strong)NSString* oneClickActivationServer;

//! @brief Hostname for hotspot finder server
//! @property hotspot finder server
@property (nonatomic, strong) NSString *hotspotFinderDefaultHostName;

//! @brief Hostname for push server
//! @property for push server
@property (nonatomic, strong) NSString *remotePushServer;

//! @brief Themis Server
//! @property themisServer
@property (nonatomic, strong) NSString *themisServer;

//! @brief Themis DNS Server Hostname
//! @property themisDnsServer
@property (nonatomic, strong) NSString *themisDnsServer;

//! @brief Hostname for DNS server
//! @property for DNS server Hostname
@property (nonatomic, strong) NSString *rtnDnsServer;

//! @brief   Key Exchange URL
//! @property Key Exchange URL
@property (nonatomic, strong) NSString *rtnKeyExchangeServer;

//! @brief Rtn Cdb Upload URL
//! @property Rtn Cdb Upload URL
@property (nonatomic, strong) NSString *rtnCdbUploadServer;

//! @property defaultProfileID
@property (nonatomic, strong)NSString* defaultProfileID;

//! @property defaultComapnyID
@property (nonatomic, strong)NSString* defaultComapnyID;

//! @brief Hostname for LogAnalysis server
//! @property for LogAnalysis server Hostname
@property (nonatomic, strong) NSString *logServiceServer;

//@property for 8021xServer
@property (nonatomic, strong) NSString *x8021xServer;

//@propert for OAAServer
@property (nonatomic, strong) NSString *oaaServer;


//
//@property (nonatomic, strong) NSString *amiPassServer; //RogueHotspot
//
//creating OMServerConfig
+(instancetype)defaultServerConfig;
-(instancetype)initWithServerConfigXMLpath:(NSString*)serverConfigXMLPath;
@end
