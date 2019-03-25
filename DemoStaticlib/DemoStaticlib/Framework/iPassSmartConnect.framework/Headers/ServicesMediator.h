//
//  ServicesMediator.h
//  iPassOpenMobile
//
//  Created by Douglas Sjoquist on 10/25/11.
//  Copyright 2011 Ivy Gulch, LLC. All rights reserved.
//
// This class is designed to be single point of access for all services that the
// app depends on.  It becomes the only place that needs to know how to create and set up
// individual services or resources, manages interdependencies, etc.
//
// Resources are loaded lazily using the thread-safe 'dispatch_once(...)' style.
//
// The purpose of doing it this way:
// - reduces dependencies in the using component, it no longer needs to know how or where to
//     get a copy of the shared resource, it just expects it's property to be set with a valid
//     reference before it is used (which is what this class is designed to do)
// - testing individual components becomes easier because of the reduction of dependencies
//     (it is straightforward to substitute a mock resource in place of the shared resource)
//
// TODO: remove all shared singleton access from other classes, create all references here
//       and use "dependency injection" style (set properties after init is called) for each 
//       controller/manager that needs a reference to shared resources
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WiFiManager;
@class OMDSConnectHandler;
@class DirectoryStoreManager;
@class SQMManager;
@class HistoryManager;
@class OMSQMFilterManager;
@class OMPreAuthManager;
@class DevicescapeConnect;
@class OMDSConnectHandler;
@class UpdateController;
@class ConfigurationOperationLock;
@class SMCProfile;
@class SMCNetworkMonitor;
@class ApplicationDataController;
@class SMCConnectionManager;
@class SQMConnRecordGenerator;
@class AccountsInfoWrapper;
@class ResourceInfoWrapper;

@interface ServicesMediator : NSObject{
    UIBackgroundTaskIdentifier bgLoadDataTaskId;
}

@property (nonatomic) UIViewController *mainViewController;
@property (nonatomic) UIBarButtonItem *settingsBBI;
@property (nonatomic) ConfigurationOperationLock *configurationOpLock;

@property (unsafe_unretained, nonatomic, readonly) WiFiManager *wiFiManager;
@property (unsafe_unretained, nonatomic, readonly) SMCProfile *configStoreManager;
@property (unsafe_unretained, nonatomic, readonly) DirectoryStoreManager *directoryStoreManager;
@property (unsafe_unretained, nonatomic, readonly) SQMManager *sqmManager;
@property (unsafe_unretained, nonatomic, readonly) OMSQMFilterManager *sqmFiltersManager;
@property (unsafe_unretained, nonatomic, readonly) OMPreAuthManager *omPreAuthManager;
@property (nonatomic, readonly) DevicescapeConnect *dsConnect;
@property (nonatomic, readonly) OMDSConnectHandler *dsConnectHandler;

// new controllers that separate out AppDelegate behavior in a rough first attempt to isolate behavior
// into separate classes -- uses dependency injection style to configure instances
@property (nonatomic, readonly) SMCNetworkMonitor *networkMonitor;
@property (nonatomic, readonly) ApplicationDataController *applicationDataController;
@property (nonatomic, readonly) SMCConnectionManager  *connectionService;
@property (nonatomic, readonly) SQMConnRecordGenerator *sqmEventReceiver;
@property (nonatomic, readonly) UpdateController* updateController;

@property (nonatomic, readwrite)BOOL userAcceptedEula;

//Profile global accessors
@property (nonatomic, readonly)AccountsInfoWrapper* accountsWrapper;
@property (nonatomic, readonly)ResourceInfoWrapper* resourceWrapper;

+ (ServicesMediator *)sharedServicesMediator;
//! @brief Flag to check if client has detected upgrade
@property (nonatomic, readwrite) BOOL newClientVersionDetected;

-(void)initialize;

- (void)applicationdidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidReceiveLocalNotification:(UILocalNotification *)notification;
- (void)application:(UIApplication*)application openURL:(NSURL *)url;
-(void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;
-(void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)())completionHandler;
#pragma mark Remote push delegate methods

-(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)token;
- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;

- (void)injectServices:(id) owner;
-(void)initializeGoogleAnalytics;
@end
