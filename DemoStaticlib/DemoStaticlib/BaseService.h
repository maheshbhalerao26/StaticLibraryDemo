//
//  BaseService.h
//  DemoStaticlib
//
//  Created by NewUSer on 4/2/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BaseService : NSObject
@property (nonatomic,strong) NSString *APIKey;
@property (nonatomic,strong) NSString *APISecret;
@property (nonatomic,strong)NSString * token;
-(void)activateWiFiUsingBIN:(NSString *)bin uuid: (NSString*)uuid successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error))ErrorHandler;
@end

NS_ASSUME_NONNULL_END
