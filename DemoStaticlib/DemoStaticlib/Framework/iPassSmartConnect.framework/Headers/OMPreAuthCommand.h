//
//  OMPreAuthCommand.h
//  PreAuthProcessingTest
//
//  Created by Sriram on 12/26/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString *kOMPreAuthCommandKey ;
extern NSString *kOMPreAuthCommandValueKey ;
extern NSString *kOMPreAuthNextCommandValueKey;
typedef NS_ENUM(NSUInteger,OMPreAuthCommandType)
{
    OMPreAuthCommandTypeUseAuth,
    OMPreAuthCommandTypeBlackList,
    OMPreAuthCommandTypeShowNotification,
    OMPreAuthCommandTypeNone = NSNotFound
};

typedef NS_ENUM(NSUInteger,OMPreAuthNextCommandType)
{
    OMPreAuthNextCommandTypeDisconnect,
    OMPreAuthNextCommandTypeProceedToLogin,
    OMPreAuthNextCommandTypeStayAssociatedToNetwork,
    OMPreAuthNextCommandTypeNone = NSNotFound
};

@interface OMPreAuthCommand : NSObject
@property (strong,nonatomic,readonly) NSString *commandValue;
@property (strong,nonatomic,readonly) NSString *nextCommand;
+(instancetype) preAuthCommandWithCommand:(NSString*) command
                                    value:(NSString*) value
                              nextCommand:(NSString*) nextCommand;
- (OMPreAuthCommandType) commandType;
- (OMPreAuthNextCommandType) nextCommandType;

@end
