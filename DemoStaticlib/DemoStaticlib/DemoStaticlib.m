//
//  DemoStaticlib.m
//  DemoStaticlib
//
//  Created by NewUSer on 3/19/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import "DemoStaticlib.h"
#import "DemoStaticlib-Swift.h"

@implementation DemoStaticlib
@synthesize connectionDelegate;

-(void)intiSDK:(NSString *) APIKey {
    [Wifi initIPassSDKWith:APIKey];
}

-(void)activateVoucherService:(NSString *)voucherCode successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error, NSString *errorMessage))ErrorHandler {
    [Wifi activateVoucherServiceWithVoucher:voucherCode onSuccess:^(NSDictionary<NSString *,id> * successResult) {
        successHandler(successResult);
    } onFailure:^(NSError * error, NSString * errorMessage) {
        ErrorHandler(error, errorMessage);
    }];
}


@end

