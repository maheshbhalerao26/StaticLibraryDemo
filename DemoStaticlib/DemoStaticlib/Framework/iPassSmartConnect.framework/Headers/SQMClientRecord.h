//
//  SQMClientRecord.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 11/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQMRecord.h"

@interface SQMClientRecord : SQMRecord

//! Convinient constructor
+(SQMClientRecord*)defaultRecordWithClientId:(NSString*)clientId;
-(BOOL) recordingDisabled;

@end
