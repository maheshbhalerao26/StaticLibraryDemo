//
//  DemoStaticlib.m
//  DemoStaticlib
//
//  Created by NewUSer on 3/19/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import "DemoStaticlib.h"

@implementation DemoStaticlib
@synthesize connectionDelegate;


-(void)intiSDK:(NSString *) APIKey {
   self.connectionDelegate = [[MyConnectionDelegate alloc] init];
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

@end

