//
//  OMActions.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 07/05/13.
//
//

#import <Foundation/Foundation.h>

//! @enumeration OMActionType
typedef NS_ENUM(NSUInteger, OMActionType){
    kActionTypeNotify,
    kActionTypeConnect,
    kActionTypeDisconnect,
    kActionTypeDeactivate,
    kActionTypeUpdate,
    kOMActionTypeNone
};

//! @enumeration OMActionScope
typedef NS_ENUM(NSUInteger, OMActionScope){
    kActionScopePrivate,
    kActionScopePartner,
    kActionScopeAny
};


@interface OMAction : NSObject<NSCoding>

//! @property action type
@property OMActionType type;

//! @property action scope
@property OMActionScope scope;

//! @properoty action name
@property (nonatomic, strong)NSString* name;

//! @property description
@property (nonatomic, strong)NSString* actionDescription;

//! @property synchronous
@property (nonatomic, readonly, getter = isSynchronous)BOOL synchronous;

-(instancetype)initWithName:(NSString*)name
                      scope:(NSString*)scope
                description:(NSString*)description
                synchronous:(NSString*)synchronous;

@end
