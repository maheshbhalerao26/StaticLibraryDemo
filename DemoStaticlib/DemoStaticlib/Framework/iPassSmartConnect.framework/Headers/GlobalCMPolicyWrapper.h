//
//  GlobalCMPolicyWrapper.h
//  iPassOpenMobile
//
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

typedef NS_ENUM(NSInteger, GlobalCMPolicyField)
{
    CMPolicy_Delimiter,
    CMPolicy_ID,
    CMPolicy_Version,
    Exclude_NetworkFilter,
    Exclude_NetworkFilter_Type,
    Exclude_NetworkFilter_Action,
    Exclude_Networks_Network,
    Exclude_Network_SSID,
    Exclude_Network_MAC,
    Exclude_ManualLogin,
    Exclude_ManualWarn,
    Exclude_ManualDoNotShowAsiPass,
    CMPolicy_RateMap_Rate_Selector,
    CMPolicy_RateMap_Rate_Prefix,
    CMPolicy_RateMap_Rate_Suffix,
    CMPolicy_TimeoutPolicy_Network_Timeout,
    CMPolicy_HTTPSecurityPolicy_Network_Protocols_Protocol_value,
    CMPolicy_AutoRedirectPolicy_AutoRedirect_enabled,
    CMPolicy_AutoRedirectPolicy_AutoRedirect_type
};

typedef NS_ENUM(NSInteger, GlobalCMPolicyNodeContext)
{
    
    kGlobalCMPolicyNodeContext_CannedPolicy,
    kGlobalCMPolicyNodeContext_TimeoutPolicy_Network_Timeout,
    kGlobalCMPolicyNodeContext_RateMap,
    kGlobalCMPolicyNodeContext_HTTPSecurityPolicy_Network_Security,
    kGlobalCMPolicyNodeContext_HTTPSecurityPolicy_Network_Protocols_Protocol,
    kGlobalCMPolicyNodeContext_AutoRedirectPolicy_AutoRedirect
};

#define DIRECTORY_EXCLUDE_GLOBAL_XML_FILE @"GlobalCMPolicy"
#define DIRECTORY_EXCLUDE_CM_XML_FILE @"CMPolicy"

#define DIRECTORY_EXCLUDE_TYPE_BLACKLIST @"BlackList"
#define DIRECTORY_EXCLUDE_TYPE_MANUAL @"ManualNetworkLogin"

#define RATE_MAP_SELECTOR_KEY @"selector"
#define RATE_MAP_PREFIX_KEY @"Prefix"
#define RATE_MAP_SUFFIX_KEY @"Suffix"

@class iPassXMLDocument;

@interface GlobalCMPolicyWrapper : NSObject
{
@private
    iPassXMLDocument *mDocument;
    NSError *mErr;
    BOOL mStatusOk;
    
    int policyCount;
}
-(id) initWithFile: (NSString*) fileName;
-(void) importData;
-(void) importNetworkFilters;
-(void) buildNetworkLists;
-(void) saveDirectoryExcludeNetwork: (NSString*) ssid mac: (NSString*) mac type: (NSString*) type action: (NSString*) action managedObject: (NSManagedObjectContext*) mgdObjCtxt;
-(NSString *) globalPolicyVersionStringForProfileUpdate;
-(NSArray*)globalPolicyRateMap;
@end
