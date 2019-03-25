//
//  InAppEvent.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 07/05/13.
//
//

#import <Foundation/Foundation.h>
#import "OMAction.h"

//! @enumeration Events
typedef NS_ENUM(NSUInteger, OMEventName){
    kOMEventFirstLaunch,
    kOMEventAppStartup,
    kOMEventActivation,
    kOMEventPreConnect,
    kOMEventConnectionFailure,
    kOMEventConnected,
    kOMEventDisconnected,
    kOMEventSessionLimitReached,
    kOMEventAccountChanged,
};

@interface InAppEvent : NSObject<NSCoding>

//! @proeprty name
@property (nonatomic, readonly)OMEventName name;

//creating event with name
-(instancetype)initWithName:(NSString*)name;

//adding actions
-(void)addAction:(OMAction*)action;
-(void)addActions:(NSArray*)actions;

//getting configured actions for this event
-(NSArray*)actions;
-(OMAction*)actionWithType:(OMActionType)type;
-(OMAction*)actionWithName:(NSString*)name;

//If ation is found returns index of the action
//otherwise returns -1.
-(NSInteger)indexOfAction:(OMAction*)action;

-(BOOL) removeActionWithName:(NSString*) actionName;

@end
