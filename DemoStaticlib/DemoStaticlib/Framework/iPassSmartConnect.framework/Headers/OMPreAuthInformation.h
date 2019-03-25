//
//  OMPreAuthInformation.h
//  Open Mobile
//
//  Created by Sriram on 12/26/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString *kOMPreAuthNetworksKey ;
extern NSString *kOMPreAuthConditionsKey ;
@class OMPreAuthAction;

@interface OMPreAuthInformation : NSObject

@property (nonatomic,strong) NSString *preauthUpdateString;

+(instancetype) preAuthInformationWithNetworks:(NSArray*) networks
                                 andConditions:(NSArray*) conditions;
+(instancetype) preAuthInformationWithNetworks:(NSArray*) networks
                                    Conditions:(NSArray*) conditions
                               andUpdateString:(NSString *)updateString;
-(OMPreAuthAction*) actionForNetwork:(NSString*) networkName
                                   matchType:(NSString*) matchType
                                withResponse:(NSString*) responseData
                                    encoding:(NSStringEncoding) enc;
-(BOOL) followHTMLRedirectEnabledForNetwork:(NSString*) networkName matchType:(NSString*) matchType;
- (BOOL) isPreAuthEnabledNetwork:(NSString*) networkName matchType:(NSString*) matchType;
-(NSString*) userAgentForNetwork:(NSString*) networkName matchType:(NSString*) matchType;

@end
