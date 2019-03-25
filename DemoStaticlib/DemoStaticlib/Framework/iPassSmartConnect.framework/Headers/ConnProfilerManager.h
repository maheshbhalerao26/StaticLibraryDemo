//
//  ConnProfilerManager.h
//  SampleSpeed-Test
//
//  Created by hmuthusankaran on 13/05/13.
//  Copyright (c) 2013 hmuthusankaran. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConnProfilerConfigWrapper.h"
#import "SpeedTestConstants.h"

@class DownloadTestController;
@class UploadTestController;
@protocol SpeedTestProtocol;

@interface ConnProfilerManager : NSObject

@property(nonatomic, assign) NSInteger  bestLatencyOfServer;
@property(nonatomic, assign) double packetLossInPercentage;
@property(nonatomic, assign) double avgDownloadSpeedInbps;
@property(nonatomic, assign) double avgUploadSpeedInbps;
@property(nonatomic, retain) NSString* bestDownloadURL;
@property(nonatomic, retain) NSString* bestUploadURL;

@property(nonatomic,assign) BOOL isManualSpeedTestEnabled;

@property(nonatomic,assign) id delegate;

@property(assign) BOOL packetLossExists;

-(void)startPingTest:(NSString *) speedTestType;
-(void)startDownloadTest;
-(void)startUploadTest;

-(void)updateConfigForMiniTest;
-(void)updateConfigForFullTest;

-(NSArray*) getSupportedMediaTypes:(double) cpNetworkLatency DownloadSpeed:(double)cpDownloadSpeed UploadSpeed:(double) cpUploadSpeed PacketLoss:(double)cpPacketLoss;

-(ConnectionQualityType) calculateConnectionQuality:(double) cpNetworkLatency DownloadSpeed:(double)cpDownloadSpeed UploadSpeed:(double) cpUploadSpeed PacketLoss:(double)cpPacketLoss;

-(void) cancelSpeedTest;

@end

@protocol SpeedTestManagerDelegate <NSObject>

-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler didReceiveLatency:(NSInteger) latency packetLoss:(double) packetLoss;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler latencyDidFailWithError:(NSError *) error description:(NSString*) errorDescription;

//download speed in kbps
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler downloadSpeedAtInterval:(NSInteger) downloadSpeedAtInterval;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler didDownloadTestComplete:(NSInteger) downloadSpeed totalDownloadedBytes:(NSInteger) downloadedBytes totalDownloadTime:(NSInteger) totalTime;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler downloadDidFailWithError:(NSError *) error description:(NSString*) errorDescription;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler downloadingProgressInPercentage:(float) percentage;

//Upload speed in kbps
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler uploadSpeedAtInterval:(NSInteger) uploadSpeedAtInterval;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler didUploadTestComplete:(NSInteger) uploadSpeed totalUploadedBytes:(NSInteger) uploadedBytes totalUploadTime:(NSInteger) totalTime;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler uploadDidFailWithError:(NSError *) error description:(NSString*) errorDescription;
-(void)connectionProfiler:(ConnProfilerManager*) connectionProfiler uploadingProgressInPercentage:(float) percentage;

@optional
-(void)connectionProfiler:(ConnProfilerManager *)connectionProfiler didFindPacketLoss: (BOOL) foundPacketLoss;
@end
