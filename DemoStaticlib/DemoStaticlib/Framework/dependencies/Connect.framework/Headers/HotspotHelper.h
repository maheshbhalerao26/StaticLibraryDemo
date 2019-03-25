//
//  HotspotHelper.h
//  Example
//
//  Created by John Gordon on 7/16/15.
//  Copyright © 2015 Devicescape Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NetworkExtension/NEHotspotHelper.h>
#import "DevicescapeConnect.h"
#import "DSNetworkStore.h"

@protocol HotspotHelperDelegate
- (void) authenticationStarted:(NSString * _Nonnull)command;
- (void) authenticationCompleted:(NSString * _Nonnull)command status:(NSNumber * _Nonnull)status sequence:(NSUInteger)sequence;
- (void) evaluationFor:(NEHotspotNetwork * _Nonnull)net curation:(NSDictionary * _Nonnull)info;
- (void) filterScanList:(NSInteger)size matched:(NSInteger)matched;
- (void) notificationPresented:(NSDictionary * _Nonnull)info;
@end

// Dictionary keys for the popup error messages for auth failures
extern NSString * _Nonnull kDSErrorMessageType;
extern NSString * _Nonnull kDSErrorMessageTitle;
extern NSString * _Nonnull kDSErrorMessageBody;
extern NSString * _Nonnull kDSErrorMessageURL;
extern NSString * _Nonnull kDSErrorReason;
extern NSString * _Nonnull kDSErrorCommand;

// Notification center notification names
extern NSString * _Nonnull kHHRegistrationChanged;
extern NSString * _Nonnull kHHAccountSetupComplete;
extern NSString * _Nonnull kHHLocationUpdated;

@interface HotspotHelper : NSObject <DevicescapeConnectDelegate, DSHttpHelperProtocol>

@property (atomic) id<HotspotHelperDelegate> _Nullable delegate;

@property (nonatomic) BOOL allOpenAllowed;

@property (nonatomic) BOOL autoLoginEnabled;

@property (nonatomic) BOOL venueMessagesEnabled;

@property (nonatomic) BOOL suppressErrorNotifications;

@property (nonatomic) NSInteger minimumAcceptableConfidence;

@property (nonatomic, readonly) CLLocation * _Nullable lastLocation;

@property (nonatomic, strong) DSNetworkStore * _Nullable networkStore;

- (id _Nullable) init:(DevicescapeConnect * _Nonnull)dsc;

- (void) handleCommand:(NEHotspotHelperCommand * _Nonnull) command;

- (NSInteger) setupAccount;

- (BOOL) handleNotification:(NSDictionary * _Nonnull)info;


@end
