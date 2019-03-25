//
//  ServiceConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Luis Marmolejo on 9/28/11.
//  Copyright 2011 iPass. All rights reserved.
//
//  Revision History: 
//  3/12/12 - Ronak Shah: Added logic to parse the XML file once and store it in a respective .plist file
//

#import <Foundation/Foundation.h>

@class iPassXMLDocument;

// Public field identifiers for keying into private metadata for leaf nodes.
// This enum identifies each leaf node of interest to this app version because
// it contains a data element value
typedef NS_ENUM(NSInteger, ServiceConfigField)
{
    kServiceConfigField_ScanPeriod,
    kServiceConfigField_ProfileId,
    kServiceConfigField_ServiceName,
    kServiceConfigField_ServiceURL,    
    kServiceConfigField_Count
} ;

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSInteger, ServiceConfigNodeContext)
{
    kServiceConfigNodeContext_ServiceInterface,
    kServiceConfigNodeContext_Service,
    kServiceConfigNodeContext_Count
} ;

typedef NS_ENUM(NSInteger, ServiceInterface)
{
    kUpdateService,
    kUpdateStatus,
    kSQMClient,
    kSQMConnection,
    kSQMConnectionQuality,
    kSQMUserAcceptance,
    kSQMDevice,
    kSQMUsage,
    kSQM,
    kSQMApplication,
    kLegacyDialer,
    kISEELVerification
} ;

@interface ServiceConfigWrapper : NSObject 
{
@private
    iPassXMLDocument *mDocument;
    NSError          *mErr;
    int              mServiceCount;
    BOOL             mStatusOk;
}

- (id)initWithPath:(NSString *)filePath;
- (BOOL)isOk;
- (BOOL)isParsedOk;
- (void)print;
- (BOOL)validateCorrectness;

#pragma mark - Getters
- (int)getScanPeriod;
- (NSString *)getProfileId;
- (int)getServiceCount;
- (NSString *)getServiceURLForName:(ServiceInterface)serviceName;

@end