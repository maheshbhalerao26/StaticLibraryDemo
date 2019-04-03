//
//  DemoStaticlib.m
//  DemoStaticlib
//
//  Created by NewUSer on 3/19/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import "DemoStaticlib.h"
#import "BaseService.h"
@implementation DemoStaticlib
//@synthesize connectionDelegate;

+(void)greet:(NSString *)name{
    NSLog(@"******************");
    NSLog(@"Hello %@",name);
    NSLog(@"******************");
}

+(void)intiSDK:(NSString *) APIKey {
   MyConnectionDelegate *connectionDelegate = [[MyConnectionDelegate alloc] init];
    NSError* error;
    if (error == nil) {
        if ([UIDevice getSystemVersionAsAnInteger] >= __IPHONE_9_0 ) {
        [SMCCore initialize:APIKey annotation:@"DinersClub WiFi" logLevel:SMCLogLevelDebug error:&error];
        id<Characterizer> characterizer = [[SMCCharacterizer alloc] init];
        id<CaptivePluginHandler> pluginHandler = [[SMCCaptivePluginHandler alloc] initWithCharacterizer:characterizer];
        [SMCCore shared].connectionManager.captivePlugin = [SMCCaptivePluginFactory createPluginWith:pluginHandler];
        [SMCCore shared].connectionManager.delegate = connectionDelegate;
        }
    }
}

+(void)activateVoucherService:(NSString *)voucherCode successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error, NSString *errorMessage))ErrorHandler {
    NSLog(@"activateVoucherService voucherCode : %@", voucherCode);

    SMCVoucherActivationData *voucherDataObj = [[SMCVoucherActivationData alloc] init:voucherCode];
    SMCActivation* activation = [[SMCActivation alloc] initWithVoucherData:voucherDataObj];
    [activation activate:^{
        NSDictionary *responseDict = @{ @"voucherCode" : voucherCode, @"status" : @"true"};
        successHandler(responseDict);
    } error:^(NSError * _Nonnull error) {
         ErrorHandler(error, @"Activation Failed");
    }];
}

+(void)activateVoucherUsingBIN:(NSString *)bin uuid: (NSString*)uuid successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error, NSString *errorMessage))ErrorHandler {
    BaseService *bs = [[BaseService alloc] init];
    [bs activateWiFiUsingBIN:bin uuid:uuid successHandler:^(NSDictionary * _Nonnull resultDict) {
        NSArray *arrVoucher = [[resultDict valueForKey:@"result"] copy];
        NSString *voucherCode = arrVoucher[0];
        NSLog(@"voucherCode: %@", [voucherCode valueForKey:@"registrationCode"]);
        [self activateVoucherService:[voucherCode valueForKey:@"registrationCode"] successHandler:^(NSDictionary *resultDict) {
            NSLog(@"voucherCode activated: %@", resultDict);
            successHandler(resultDict);
        } ErrorHandler:^(NSError *error, NSString *errorMessage) {
            NSLog(@"voucherCode activation failed: %@", resultDict);
            ErrorHandler(error, errorMessage);
        }];
    } ErrorHandler:^(NSError * _Nonnull error) {
        ErrorHandler(error, @"something went wrong.");
    }];
}

@end

