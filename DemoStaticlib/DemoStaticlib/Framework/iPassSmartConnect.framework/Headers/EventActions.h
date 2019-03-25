//
//  EventActions.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 06/05/13.
//
//

#import <Foundation/Foundation.h>
#import "InAppEvent.h"

/*! @brief Public field identifiers for keying into private metadata for context nodes.
 * This enum identifies each node of interest to this app version because it can be used as
 * node context while navigating multi-child nodes.
 */
typedef NS_ENUM(NSUInteger, EventsFieldContext){
    kEvents_Event_Name,
    kEvents_Event_Actions_Action_Scope,
    kEvents_Event_Actions_Action_Description,
    kEvents_Event_Actions_Action_Synchronous,
    kEvents_Event_Actions_Action_NotifyAction_Id,
    kEvents_Event_Actions_Action_ConnectAction_NetworkName,
};

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSUInteger, EventsNodeContext){
    kEventActionContext_CustomEventActions,
    kEventActionContext_Events,
    kEventActionContext_Events_Event,
    kEventActionContext_Events_Event_Actions,
    kEventActionContext_Events_Event_Actions_Action,
    kEventActionContext_Events_Event_Actions_Action_NotifyAction,
    kEventActionContext_Events_Event_Actions_Action_ConnectAction,
    kEventActionContext_Events_Event_Actions_Action_DisconnectAction,
    kEventActionContext_Events_Event_Actions_Action_DeactivateAction,
    kEventActionContext_Events_Event_Actions_Action_Update
};

@interface EventActions : NSObject

//all the notifications that are configured
@property (nonatomic, strong)NSMutableArray* events;
-(InAppEvent*)eventForName:(OMEventName)name;


//clear event actions
+(void)clearEventActions;

@end
