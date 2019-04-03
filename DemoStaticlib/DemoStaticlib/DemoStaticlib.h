//
//  DemoStaticlib.h
//  DemoStaticlib
//
//  Created by NewUSer on 3/19/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyConnectionDelegate.h"
#import <iPassSmartConnect/iPassSmartConnect.h>

@interface DemoStaticlib : NSObject
+(void)greet:(NSString *)name;
+(void)intiSDK:(NSString *) APIKey;
+(void)activateVoucherService:(NSString *)voucherCode successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error, NSString *errorMessage))ErrorHandler;
+(void)activateVoucherUsingBIN:(NSString *)bin uuid: (NSString*)uuid successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error, NSString *errorMessage))ErrorHandler;
@end
