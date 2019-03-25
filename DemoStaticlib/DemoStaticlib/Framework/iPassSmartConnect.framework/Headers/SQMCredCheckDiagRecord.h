//
//  SQMCredCheckDiagRecord.h
//  iPassOpenMobile
//
//  Created by Matthew Mourlam on 6/24/14.
//
//

#import <Foundation/Foundation.h>
#import "SQMDiagRecord.h"

#define CredentialCheck_Response      @"CredCheckResponse"

@interface SQMCredCheckDiagRecord:SQMDiagRecord


+(SQMCredCheckDiagRecord*)newDiagRecord;
- (NSString *)getAsXmlString;

@end
