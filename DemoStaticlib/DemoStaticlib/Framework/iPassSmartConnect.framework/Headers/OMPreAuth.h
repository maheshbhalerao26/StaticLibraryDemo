//
//  OMPreAuth.h
//  PreAuthProcessingTest
//
//  Created by Sriram on 12/26/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>
/*! @brief Public field identifiers for keying into private metadata for context nodes.
 * This enum identifies each node of interest to this app version because it can be used as
 * node context while navigating multi-child nodes.
 */
typedef NS_ENUM(NSUInteger, PreAuthFieldContext){
    kPreAuth_Condition_ID,
    kPreAuth_Condition_Type,
    kPreAuth_Condition_delimiter,
    kPreAuth_Condition_version,
    kPreAuth_Condition_state,
    kPreAuth_Condition_value,
    kPreAuth_Condition_nextCommand,
    kPreAuth_Condition_path,
    kPreAuth_Network_Name,
    kPreAuth_Network_MatchType,
    kPreAuth_Network_FollowHTMLRedirect,
    kPreAuth_Network_UserAgent,
    kPreAuth_Action_Command,
    kPreAuth_Pass_Criteria,
};

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef NS_ENUM(NSUInteger, PreAuthNodeContext){
    kPreAuthContext_PreAuth,
    kPreAuthContext_PreAuth_Conditions,
    kPreAuthContext_PreAuth_Conditions_Condition,
    kPreAuthContext_PreAuth_Network,
    kPreAuthContext_PreAuth_Network_Actions,
    kPreAuthContext_PreAuth_Network_Actions_Action,
    kPreAuthContext_PreAuth_Network_Actions_Action_Execute,
    kPreAuthContext_PreAuth_Network_Actions_Action_PassCriteria,
};

@class OMPreAuthInformation;

@interface OMPreAuth : NSObject
@property(nonatomic,strong) OMPreAuthInformation *preAuthenticationInfo;
+(void) clear;
@end
