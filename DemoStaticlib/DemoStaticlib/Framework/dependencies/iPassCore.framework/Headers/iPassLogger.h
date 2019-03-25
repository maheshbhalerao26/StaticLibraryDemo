//
//  iPassLogger.h
//  iPassCore
//
//  Created by Puru Shukla on 2/1/17.
//  Copyright © 2017 ipass. All rights reserved.
//

#ifndef Logger_h
#define Logger_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SMCLogLevel) {
    SMCLogLevelInfo,
    SMCLogLevelWarning,
    SMCLogLevelDebug,
    SMCLogLevelError,
    SMCLogLevelTrace
};

@protocol iPassLogger <NSObject>

-(void)logWithLevel:(SMCLogLevel)level format:(NSString*)format, ...;
-(void)logWithLevel:(SMCLogLevel)level message:(NSString*)message;
-(void)logUserDebugInfoWithType:(SMCLogLevel)type format:(NSString*)format;

@end

#endif /* Logger_h */
