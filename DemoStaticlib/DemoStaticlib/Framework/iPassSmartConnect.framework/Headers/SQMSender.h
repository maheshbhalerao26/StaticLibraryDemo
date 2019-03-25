//
//  SQMSender.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 11/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SingletonPattern.h"
#import "BackgroundFetchDelegate.h"
#import "SQMRecord.h"

@interface SQMSender : NSObject<SingletonPattern, BackgroundFetchDelegate>

//! @brief Method is used to enqueue a record in the upload queue
-(void)enqueueRecord:(id<Recordable>)record;

//! @brief Method is used to enqueue a record in the upload queue, and will only be uploaded if wifi media is available
-(void)enqueueRecordViaWifi:(id<Recordable>)record;

@end
