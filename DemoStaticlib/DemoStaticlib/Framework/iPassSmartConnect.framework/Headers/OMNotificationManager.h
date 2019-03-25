//
//  OMNotificationManager.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 19/04/13.
//
//

#import <Foundation/Foundation.h>
#import "OMNotification.h"
#import "OMQueue.h"
#import "OM.h"


@interface OMNotificationManager : NSObject<NotificationManagerDelegate, OMQueueSortDelegate>

+(instancetype)defaultManager;

//Posts the notification
-(void)postNotification:(OMNotification*)notification;

//Cancels already posted notification
-(void)cancelNotification:(OMNotification*)notification;

//Close the active notification
-(BOOL)closeActiveNotification;


//Handling Localnotifications

-(BOOL)warnSessionTimeOutNotificationActive;
-(BOOL)warnSessionTimeOutAlertActive;
-(void)closeSessionTimeoutNotification;
-(void)closeSessionTimeoutAlert;
- (void)applicationDidReceiveLocalNotification:(UILocalNotification *)notification;
-(void)displaySessionAlert;
- (BOOL)displaySessionTimeoutLocalNotificationWithMessage:(NSString *)message
                                         notificationType:(LocalNotificationType)lnType
                                           repeatInterval:(int)repeatInterval;

- (BOOL)displayLocalNotificationWithMessage:(NSString *)message
                           notificationType:(LocalNotificationType)lnType
                             repeatInterval:(int)repeatInterval;
@end
