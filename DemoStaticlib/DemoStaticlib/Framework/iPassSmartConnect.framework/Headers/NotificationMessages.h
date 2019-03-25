//
//  NotificationMessages.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 14/05/13.
//
//

#import <Foundation/Foundation.h>

/*! @brief Public field identifiers for keying into private metadata for context nodes.
 * This enum identifies each node of interest to this app version because it can be used as
 * node context while navigating multi-child nodes.
 */
typedef NS_ENUM(NSUInteger, MessagesFieldContext){
    kNotificationsResources_Resource_Id,
    kNotifications_Resources_Resource_Type,
};

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSUInteger, MessagesNodeContext){
    kNotifications_Resources,
    kNotifications_Resources_Resource,
    kNotifications_Resources_Resource_Value,
};
#define PARTNER_NOTIFICATIONS_RESOURCES_XML @"PartnerNotificationsResources"


@interface NotificationMessages : NSObject

//message for message id
-(NSString*)messageForId:(NSString*)messageId;

//clear notification messages
+(void)clearNotificationMessages;

+(NSArray*)findDependencyResourceInPartnerMessagesXMLForFile:(NSString*)fileName;
-(NSDictionary*)messageDetails;
@end
