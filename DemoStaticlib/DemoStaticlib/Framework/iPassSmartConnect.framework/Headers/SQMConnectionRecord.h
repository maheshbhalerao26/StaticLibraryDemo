//
//  SQMConnectionRecord.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 11/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQMRecord.h"
#import "SMCConnServiceConstants.h"

//fields in the connection record
typedef NS_ENUM(NSUInteger, ConnectionFields) {
	//common fields
	SQMClientId,
    SQMSDKVersion,
    SQMComapnyId,
	SQMStage,
	SQMIndex,
	SQMStartTime,
	SQMEndTime,
    SQMBaseSessionId,
	SQMSessionId,
	SQMSessionLength,
	SQMUserId,
	SQMLoginString,
	SQMTimeToConnect,
	SQMProfileId,
	SQMConnectionStatus,
	SQMConnectionStatusCode,
    SQMConnectReason,
	SQMDisconnectReasonCode,
    SQMDirectoryId,
	//wifi connection related fields
	SQMClientMacAddress,
    SQMRtnStatus,
    SQMLocationClassificationCode,
    SQMConnectionDiagnostics,
	SQMAccessPointMacAddress,
	SQMAccessPoint,
	SQMSsid,
    SQMSignalStrength,
	SQMLocationDescription,
	SQMLocationGroup,
	SQMLocationId,
	SQMAuthMethod,
    SQMLoginURL,
	SQMSecurityMode,
	SQMAccessProcedure,
	SQMNetworkId,
    SQMGisReplyMessage,    
    SQMLatLong,  // For Location coordinates
    SQMGPSSource,
    SQMDirConfidence, // For INR 
    SQMOverallConfidence,
    SQMAppVisibility,
    SQMHistoryAvailability,
    SQMHotspotAvailability,
    SQMHotspotListing,
    SQMUploadedBytes,
    SQMDownloadedBytes,
	//other connection related fields
	SQMTotalConnectionsFields
};

typedef NS_ENUM(NSUInteger, SQMConnectionRecordSubType)
{
    kRecordSubTypeWiFi,
    kRecordSubTypeMB,
    kRecordSubTypeEthernet,
};
@interface SQMConnectionRecord : SQMRecord

//current connection record
@property(nonatomic, strong)NSMutableDictionary* currentRecord;
@property (assign,nonatomic) SQMConnectionRecordSubType subtype;
//! @brief convinient constructor with timestamp
+(SQMConnectionRecord*)connectionRecordWithTimestamp:(NSUInteger)timestamp
                                           mediaType:(SQMConnectionRecordSubType) mediaType;
-(BOOL) recordingDisabled;
@end
