//
//  SQMDiagRecord.h
//  iPassOpenMobile
//
//  Created by Marimuthu Ravindran on 02/04/14.
//
//

#import <Foundation/Foundation.h>
#import "SQMRecord.h"
#import "SBJson.h"
#import "OMSQMFilterManager.h"
#import "OMCUtil.h"

#define	DIAG_PAYLOAD_XML_OPEN_TAG_WITH_ATTR	@"<%@ payloadType=\"%@\" version=\"%d\" timestamp=\"%@\">"

#define	DIAG_PAYLOAD_XML_OPEN_TAG_WITH_ATTR_DBSAVE	@"<%@ payloadType=\"%@\" version=\"%d\" timestamp=\"%@\" dbsave=\"%@\">"

#define FORMAT_PROFILE_AND_VERSION  @"%@.V%@"

#define DIAGNOSTICS_TAG @"diag"



// Connection Quality fields
typedef NS_ENUM(NSInteger, kDiagTags)
{
    kDiagExtAttribute1 = 0,
    kDiagExtAttribute2,
    kDiagExtAttribute3,
    kDiagExtAttribute4,
    kDiagExtAttribute5,
    kDiagPayload,
    kReasoncode,
    kbssids,
    kLatitude,
    kLongitude,
    kLocationSource,
    kDiagTotalFields
};

@protocol DiagType

-(NSString*)getPayloadAsxmlString;

@end

@interface SQMDiagRecord : SQMRecord<DiagType>

@property (nonatomic, strong) NSString * diagExtAttribute1;
@property (nonatomic, strong) NSString * diagExtAttribute2;
@property (nonatomic, strong) NSString * diagExtAttribute3;
@property (nonatomic, strong) NSString * diagExtAttribute4;
@property (nonatomic, strong) NSString * diagExtAttribute5;
@property (nonatomic, strong) NSString * diagPayload;

//! Convenience constructor
+ (SQMDiagRecord *)newDiagRecord;
- (NSString *)getXMLForElement:(NSString *)elementName value:(NSString *)value;
-(NSString*)getXMLForTag:(kDiagTags)diagTag value:(NSString*)value;
-(BOOL) recordingDisabled;
-(NSString*)elementNameForField:(kDiagTags) field;

@end
