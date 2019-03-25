//
//  SQMSessionInfo.h
//  iPassOpenMobile
//
//  Created by Shantanu Dutta on 17/02/14.
//
//

#import <Foundation/Foundation.h>

#import "Constants.h"

@interface SQMSessionInfo : NSObject<NSCoding>

-(NSString*)objectForField:(NSUInteger)field;
-(void)setObject:(NSObject*)value forField:(NSUInteger)field;

//! @brief Current session
+(instancetype)lastSession;

//! @brief Method saves the current session
-(void)persist;

//! @brief deletes the session from the store
-(void)clearSession;

@end
