//
//  OMPreAuthAction.h
//  PreAuthProcessingTest
//
//  Created by Sriram on 12/26/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString *kOMPreAuthActionCommandsKey ;
extern NSString *kOMPreAuthActionPassCriteriaKey;

@interface OMPreAuthAction : NSObject
@property (strong,nonatomic,readonly) NSArray *commands;
@property (strong,nonatomic,readonly) NSString *passCriteria;
+(instancetype) actionWithCommands:(NSArray*) commands
                      passCriteria:(NSString*) passCriteria;

-(BOOL) matchForConditions:(NSArray*) conditions
                              Input:(NSString*) response
                              encoding:(NSStringEncoding) enc
                        conditionCache:(NSArray**) conditionCache;

@end
