//
//  MyConnectionDelegate.m
//  Examples
//
//  Created by Purushottam Shukla on 1/28/16.
//  Copyright © 2016 ipass. All rights reserved.
//

#import "MyConnectionDelegate.h"

@implementation MyConnectionDelegate

-(void)connectionStarted:(SMCConnectionStatus*)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection Started--> %@", connectionStatus);
}

-(void)connectionAborted:(SMCConnectionStatus*)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection Failed--> %@ with error code --> %ld error desc --> %@",connectionStatus,connectionStatus.error.code,connectionStatus.error.localizedDescription);
}

-(void)connectionSuccess:(SMCConnectionStatus*)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection Success--> %@", connectionStatus);
}

-(void)connectionFailed:(SMCConnectionStatus*)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection Failed--> %@ with error code --> %ld error desc --> %@",connectionStatus,connectionStatus.error.code,connectionStatus.error.localizedDescription);
}

-(void)willDisplayCaptcha:(SMCCaptchaViewController*)viewController{
    viewController.title = @"Objc Custom Title";
    viewController.navigationController.navigationBar.barTintColor = [UIColor redColor];
    viewController.navigationController.navigationBar.tintColor = [UIColor whiteColor];
}

- (void)connectionRequiresUI:(enum SMCUIRequiredReason)reason completionHandler:(void (^ _Nullable)(enum SMCUIRequiredResponse, SMCCredentials * _Nullable))completionHandler{
    
    switch (reason) {
        case SMCUIRequiredReasonRequiresAppInForeground:
            if ([UIApplication sharedApplication].applicationState == UIApplicationStateBackground) {
//                NSString *appName = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleName"];
//                UILocalNotification *localNotification = [UILocalNotification new];
//                localNotification.alertBody = [NSString stringWithFormat:@"Please launch %@ for connection",appName];
//                [[UIApplication sharedApplication] presentLocalNotificationNow:localNotification];
            }
            break;
            
        case SMCUIRequiredReasonRequiresManualConnect:
            if ([UIApplication sharedApplication].applicationState == UIApplicationStateBackground) {
//                NSString *appName = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleName"];
//                UILocalNotification *localNotification = [UILocalNotification new];
//                localNotification.alertBody = [NSString stringWithFormat:@"Please launch %@ for connection",appName];
//                [[UIApplication sharedApplication] presentLocalNotificationNow:localNotification];
            }
            break;
        default:
            break;
    }
}

-(void)connectionLoggedOff:(SMCConnectionStatus*)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection logged off--> %@", connectionStatus);
}

-(void)connectionLoggedOffFailed:(SMCConnectionStatus *)connectionStatus{
    NSLog(@"MyConnectionDelegate::Connection logged off Failed--> %@ with error code --> %ld error desc --> %@",connectionStatus,connectionStatus.error.code,connectionStatus.error.localizedDescription);
}

- (void)needCredentialsWithNetwork:(SMCNetwork * _Nonnull)network handler:(SWIFT_NOESCAPE void (^ _Nonnull)(enum SMCAuthChallengeDisposition, SMCCredentials * _Nonnull))handler
{
    if ([network.accessPoint.ssid isEqualToString:@"iRoam"]) {
    	SMCCredentials *creds = [[SMCCredentials alloc] initWithUsername:@"IPASS/username" password:@"*****" domain:@"ipass.com" prefix:@""];
    	handler(SMCAuthChallengeDispositionPerformDefault,creds);
    }
}

@end
