//
//  CMPolicyConfigWrapper.h
//  TestSessionTimeOut
//
//  Created by Sriram on 5/5/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, CMPolicyConfigField)
{
    kCMPolicyConfigField_ProfileID,
    kCMPolicyConfigField_Policy,
    kCMPolicyConfigField_PolicyEvent,
    kCMPolicyConfigField_PolicyCriteria,
    kCMPolicyConfigField_PolicyLogicalNode,
    kCMPolicyConfigField_PolicyLogicalNodeType,
    kCMPolicyConfigField_PolicyLogicalNodeLeft,
kCMPolicyConfigField_PolicyLogicalNodeLeft_Condition,kCMPolicyConfigField_PolicyLogicalNodeLeft_ConditionNWMedia,
    kCMPolicyConfigField_PolicyLogicalNodeRight,
    kCMPolicyConfigField_PolicyLogicalNodeRight_Condition,
    kCMPolicyConfigField_PolicyLogicalNodeRight_NWAuthMethod,
    kCMPolicyConfigField_PolicyActionList,
    kCMPolicyConfigField_PolicyActionList_MethodName,
    kCMPolicyConfigField_PolicyActionList_MethodType,
    kCMPolicyConfigField_PolicyActionList_Parameter,
    kCMPolicyConfigField_PolicyActionList_ParameterName,
} ;

typedef NS_ENUM(NSInteger, CMPolicyConfigNodeContext)
{
    kCMPolicyConfigNodeContextCMPolicy,
    kCMPolicyConfigNodeContextPolicy,
    kCMPolicyConfigNodeContextActionList,
    kCMPolicyConfigNodeContextParameter,
    kCMPolicyConfigNodeContextCount
} ;

@class iPassXMLDocument;
@interface CMPolicyConfigWrapper : NSObject
@property(strong,nonatomic) iPassXMLDocument *cmpolicyDoc;
- (id) initWithPath: (NSString *) configDirPath;

#pragma mark - Methods

/*! @brief gets the action list for the in Session policy
 *  @param none
 *  @return returns NSDictionary of action list or nil if no match found */
-(int) indexOfInSessionPolicy;

/*! @brief gets the action list for the in Session policy
 *  @param none
 *  @return returns NSDictionary of action list or nil if no match found */
-(NSDictionary*) actionListForInSessionPolicy;

/*! @brief gets the criteria list for the in Session policy
 *  @param none
 *  @return returns criteria dictionary  or nil if no match found */
-(NSDictionary*) criteriaForInSessionPolicy;

/*! @brief clears the cached insession information
 *  @param none
 *  @return none */
+(void) clearInSessionInformation;
#pragma mark - Method helpers
- (NSString*) methodNameFromActionList:(NSDictionary*) actionList;
- (NSString*) userMessageFromActionList:(NSDictionary*) actionList;
- (NSTimeInterval) warnTimeFromActionList:(NSDictionary*) actionList;
- (NSTimeInterval) sessionTimeOutFromActionList:(NSDictionary*) actionList;
#pragma mark -
@end
