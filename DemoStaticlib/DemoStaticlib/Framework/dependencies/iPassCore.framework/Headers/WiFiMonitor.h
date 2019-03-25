//
//  WiFiMonitor.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 12/21/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//


//The code has been adopted from Apple iPhone sample

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSInteger, SMCReachability) {
    kNotReachable = 0,
    kReachableViaWiFi,
    kReachableViaWiFiConnectionRequired,
    kReachableViaWWAN,
    kReachableUnknown
};

@interface WiFiMonitor : NSObject

-(SMCReachability)currentReachabilityStatus;
//WWAN may be available, but not active until a connection has been established.
//WiFi may require a connection for VPN on Demand.
- (BOOL) connectionRequired;

//methods to start and stop monitoring for 
//reachability change
-(BOOL)startMonitoring;
-(void)stopMonitoring;

//reachability methods
+(WiFiMonitor*)reachabilityWithHostName:(NSString*)hostName;
+(WiFiMonitor*)reachabilityForInternetConnection:(BOOL) isDefaultVersion;
+(WiFiMonitor*)reachabilityForLocalWiFi;

@end
