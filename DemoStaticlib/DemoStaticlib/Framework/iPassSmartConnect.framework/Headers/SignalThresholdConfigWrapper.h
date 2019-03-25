//
//  SignalThresholdConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Marimuthu Ravindran on 16/05/13.
//
//

#import <Foundation/Foundation.h>

@class iPassXMLDocument;

// Public field identifiers for keying into private metadata for leaf nodes.
// This enum identifies each leaf node of interest to this app version because
// it contains a data element value
typedef NS_ENUM(NSInteger, KTMessagingConfigField)
{
    kSignalThresholdConfigField_MinRange,
    kSignalThresholdConfigField_MaxRange,
    kSignalThresholdConfigField_Type,
    kSignalThresholdConfigField_NotificationId,
    kSignalThresholdConfigField_SignalLevelErrorType
} ;

typedef NS_ENUM(NSInteger, kNotificationType)
{
  kPreConnect,
  kPostConnectFail
};


typedef NS_ENUM(NSInteger, kSignalThresholdConfigNodeContext)
{
    kSignalThresholdConfigNodeContext_Parent,
    kSignalThresholdConfigNodeContext_WiFi,
    kSignalThresholdConfigNodeContext_WiFiSignalNotifications,
    kSignalThresholdConfigNodeContext_WiFiSignalNotification,
    kSignalThresholdConfigNodeContext_WiFiSignalNotificationSignalLevels,
    kSignalThresholdConfigNodeContext_WiFiSignalNotificationSignalLevel,
    kSignalThresholdConfigNodeContext_WiFiSignalNotificationSignalLevelNotification,
    kSignalThresholdConfigNodeContext_WiFiSignalNotificationSignalLevelIncludeError
} ;


@interface SignalThresholdConfigWrapper : NSObject
{
@private
    iPassXMLDocument *Document;
    BOOL             dataFound;
}

- (id)initWithPath:(NSString *)filePath;
- (BOOL) validConfigFound;

-(BOOL) preConnectNotificationId:/*in*/(NSInteger)signalStrength notifyId:/*out*/(NSString**)notificationId;

-(BOOL) postConnectFailNotificationId:/*in*/(NSInteger)signalStrength failureType:/*in*/(NSInteger)errorCode notifyId:/*out*/(NSString**)notificationId signalLevel:(NSInteger*)level;

-(BOOL) postConnectFailNotificationIdForAvgSignalStrength:/*in*/(NSInteger)errorCode notifyId:/*out*/(NSString**)notificationId signalLevel:(NSInteger*)level;

@end
