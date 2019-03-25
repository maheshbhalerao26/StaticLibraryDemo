//
//  SQMConnectionQualityRecord.h
//  iPassOpenMobile
//
//  Created by hmuthusankaran on 06/06/13.
//
//

#import <Foundation/Foundation.h>
#import "SQMRecord.h"

// Connection Quality fields
typedef NS_ENUM(NSInteger, kConnectionQualityFields)
{
    kConnectionQualityClientId,
    kConnectionQualityCompanyId,
    kConnectionQualityprofileId,
    kConnectionQualitySessionId,
    kConnectionQualityConnectionMode,
    kConnectionQualityTime,
    kConnectionQualityTestMode,
    kConnectionQualityTestStatus,
    kConnectionQualityUploadServer,
    kConnectionQualityDownloadServer,
    kConnectionQualityDownloadRate,
    kConnectionQualityUploadRate,
    kConnectionQualityLatency,
    kConnectionQualityPacketLoss,
    
   kConnectionQualityTotalFields
} ;

@interface SQMConnectionQualityRecord : SQMRecord

@property (nonatomic, strong) NSMutableDictionary *currentConnectionQualityRecord;

//! Convenience constructor
+ (SQMConnectionQualityRecord *)newConnectionQualityRecord;
- (NSString *)getXMLForElement:(NSString *)elementName value:(NSString *)value;

-(NSString*)currentDateTimeInSQMFormat;
-(BOOL) recordingDisabled;

@end
