//
//  WiFiManager.h
//  iPassConnect
//
//  Created by Puru_iPhone on 9/27/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h> 
#import "WiFiMonitorDelegate.h"
#import "WiFiMonitor.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ReachabilityType)
{
	ReachabilityInternet,
	ReachabilityLocalWiFi
};

struct __rssi_data
{
    u_int32_t       version;
    u_int32_t       num_radios;
    u_int32_t       rssi_unit;
    int32_t         rssi[4];             // control channel
    int32_t         aggregate_rssi;                                 // aggregate control channel rssi
    int32_t         rssi_ext[4]; // extension channel rssi
    int32_t         aggregate_rssi_ext;                             // aggregate extension channel rssi
};

//key type for reachability information
extern NSString* keyReachabilityType;
extern NSString* keyReachabilityStatus;

extern const NSInteger kInvalidSignalStrength;

@interface WiFiManager : NSObject{
	//socket
	int		_socket;
	
	//scan dictionary
	NSMutableDictionary*	_scanResults;
	
	//monitoring delegate
	id	_delegate;
	
	WiFiMonitor*	_internetReach;
	WiFiMonitor*	_wifiReach;
	WiFiMonitor*	_hostReach;
	
	uint8_t					_unknown[844];
	
	//handle to the library
	void*	_libHandle;
    
    // Time Stamps
    NSDate *initTime;
    NSDate *startTime;
    NSDate *endTime;
    NSDate *currentTime;
}

+(WiFiManager*)sharedWiFiManager;

//delegate management.
-(id)delegate;
-(void)setDelegate:(id<WiFiMonitorDelegate>)delegate;

#pragma mark - Reachability Methods
//methods are used to start and stop monitoring the reacahbility
-(void)startMonitoring;
-(void)stopMonitoring;
//method returns the initial reachability status
-(SMCReachability)reachabilityStatus;
//reachability notification
-(void)reachabilityNotification:(WiFiMonitor*)sender;

#pragma mark - Netowrk Name
//! @brief Method tells whetehe WiFi si or not associated to any network
-(BOOL)isWiFiOFFOrNotAssociated;
-(BOOL)isWifiInterfacePrimary;

//! @brief Retrieves the list of supported Network Interfaces information from the OS
-(NSArray*)supportedNetworkInterfaces;

//! @brief Retrieves the currently associated WiFi Network from the OS
- (NSString*)currentNetwork;

//Retrieves the currently associated WiFi Network's signal strength in percentage.
- (NSInteger)signalStrength;

#pragma mark - IP and MAC address
-(NSString*)getIpAddress;
-(NSString*)getMacAddressWithMinimumDigits:(int)minimumDigits;

#pragma mark-
#pragma mark Cellular network supported
-(BOOL)isCellularServicePresent;

-(void) updateNetworkReachabilityBasedonNetwork;

@end


NS_ASSUME_NONNULL_END
