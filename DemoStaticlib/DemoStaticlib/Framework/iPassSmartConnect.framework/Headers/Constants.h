//
//  Constants.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 01/10/13.
//
//
#import <Foundation/Foundation.h>

#ifndef __CONSTENTS_H_
#define __CONSTENTS_H_

//Authentication keys
extern NSString* keyHttpRequest;
extern NSString* keyHttpResponseStatus;
extern NSString* keyHttpResponseContent;
extern NSString* keyLookupRedirectCount;
extern NSString* keyGisResponseData;
extern NSString* keyLoginPollURL;

// SQM Diagostics
extern NSString* keyDiagnosticDisDetails;
extern NSString* keyDiagnosticPollDetails;
extern NSString* keyErrorCode;
extern NSString* keyErrorDetails;

// XML Tags
#define		XML_VERSION		@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define		XML_DIAG_XSD_PATH @"<diag xsi:noNamespaceSchemaLocation=\"diag.xsd\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
#define		XML_OPEN_TAG				@"<%@>"		//xml open tag
#define		XML_OPEN_TAG_WITH_ONE_ATTR	@"<%@ %@>"	//xml open tag with one attribute
#define		XML_CLOSE_TAG				@"</%@>"	//xml colsing tag

#define DEFAULT_DIALER_ID   @"00000"

#define keyRecordSQMData    @"keyRecordSQMData"
#define kSqmStoreFile       @"sqmInfo.session"
#define keySessionConnectionRecord @"keySessionConnectionRecord"

// SQM Diagnostic keys
#define DIAG_RESPONSE_KEY   @"Response"
#define DIAG_URL_KEY        @"URL"
#define kCurrentIpAddress   @"ipAddress"
#define kAmionResponse      @"amionResponse"

extern NSString* keyAuthSQMResponseCode;
extern NSString* keySQMConnectionRecord;

extern NSString* diagnosticsAccumulator;


// SQM Connection Record Keys
////common fields
extern NSString* keySQMClientId;
extern NSString* keySQMCompanyId;
extern NSString* keySQMStage;
extern NSString* keySQMIndex;
extern NSString* keySQMStartTime;
extern NSString* keySQMEndTime;
extern NSString* keySQMBaseSessionId;
extern NSString* keySQMSessionId;
extern NSString* keySQMSessionLength;
extern NSString* keySQMUserId;
extern NSString* keyAuthLoginString;
extern NSString* keySQMLoginString;
extern NSString* keySQMTimeToConnect;
extern NSString* keySQMProfileId;
extern NSString* keySQMProfileVersion;
extern NSString* keySQMConnectionStatus;
extern NSString* keySQMConnectionStatusCode;
extern NSString* keySQMConnectReason;
extern NSString* keyDemeterConnectReason;
extern NSString* keySQMDisconnectReasonCode;
extern NSString* keySQMDirectoryId;
extern NSString* keySQMProbeEnabled;
extern NSString* keySQMProbeSuccess;

//wifi connection related fields
extern NSString* keySQMClientMacAddress;
extern NSString* keySQMRtnStatus;
extern NSString* keySQMConnectionDiagnostics;
extern NSString* keySQMAccessPointMacAddress;
extern NSString* keySQMAccessPoint;
extern NSString* keySQMSsid;
extern NSString* keySQMBSSid;
extern NSString* keySQMSignalStrength;
extern NSString* keySQMWasAutoJoined;
extern NSString* keySQMLocationDescription;
extern NSString* keySQMLocationGroup;
extern NSString* keySQMLocationId;
extern NSString* keySQMAuthMethod;
extern NSString* keySQMLoginURL;
extern NSString* keySQMSecurityMode;
extern NSString* keySQMAccessProcedure;
extern NSString* keySQMNetworkId;
extern NSString* keySQMGisReplyMessage;
//DS
extern NSString* keyDSSequenceNumber;
// Location related information
extern NSString* keySQMLatLong;
extern NSString* keySQMGPSSource;
extern NSString* keySQMLocClass;
extern NSString* keySQMFPReasonCode;

extern NSString* keySQMDirConfidence;
extern NSString* keySQMOverallConfidence;
extern NSString* keySQMAppVisibility;
extern NSString* keySQMHistoryAvailability;
extern NSString* keySQMHotspotAvailability;
extern NSString* keySQMHotspotListing;

//FHIS
extern NSString* keySQMFHISDatabasePath;
extern NSString* keySQMFHISActionId;
extern NSString* keySQMFHISJSWebRequestURL;
extern NSString* keySQMFHISFinalURL;
extern NSString* keySQMFHISConnection;
extern NSString* keySQMFHISCaptivePage;
extern NSString* keySQMFHISRegExMatchFound;
extern NSString* keySQMFHISNetworkConfig;
extern NSString* keySQMFHISRegex;
extern NSString* keySQMFHISActionsQueue;

extern NSString* keyCurrentNAI ;
extern NSString* keyNetworkSecurity;

//Kronos
extern NSString* keyKronosStartTime;
extern NSString* keyKronosEndTime;
extern NSString* keyKronosResponseBase64Data;

#endif //__CONSTENTS_H_
