//
//  SQMManager.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 11/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQMDiagRecord.h"


//Forward declartion
@class SQMSender;
@class SQMConnectionRecord;

@interface SQMManager : NSObject

//singleton methods
+(SQMManager*)sharedSQMManager;

//! @brief creates and returns a new connection record, caller should
//retain if needed outside the scope.
-(SQMConnectionRecord*)newConnectionRecord;

//! @brief creates and returns a new connection record, caller should
//retain if needed outside the scope.
-(SQMConnectionRecord*)newConnectionRecordWithRecord:(NSDictionary*)record;

//! @brief ends the connection record, calling this method adds the
// connection record to the upload queue of the sender.
-(void)closeConnectionRecord:(SQMConnectionRecord*)connectionRecord;

//-(SQMDiagRecord*)newDiagnosticsRecord:(NSInteger)recordType;
-(void)closeDiagnosticsRecord:(SQMDiagRecord*)connectionRecord;

@end
