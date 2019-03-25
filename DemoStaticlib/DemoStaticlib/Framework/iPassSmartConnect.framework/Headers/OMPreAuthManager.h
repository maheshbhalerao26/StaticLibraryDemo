//
//  OMPreAuthManager.h
//  iPassOpenMobile
//
//  Created by Sriram on 12/30/13.
//
//

#import <Foundation/Foundation.h>

@class OMPreAuthAction;
@interface OMPreAuthManager : NSObject
+ (OMPreAuthManager *) omPreAuthManager;
-(OMPreAuthAction*) actionForNetwork:(NSString*) networkName
                                              matchType:(NSString*) matchType
                                          usingResponse:(NSString*) response
                                               encoding:(NSStringEncoding) enc;
-(BOOL) followHTMLRedirectEnabledForNetwork:(NSString*) networkName matchType:(NSString*) matchType;
-(BOOL) isEnabled;
-(BOOL) isEnabledForNetwork:(NSString*) networkName matchType:(NSString*) matchType;
-(NSString*) userAgentForNetwork:(NSString*) networkName matchType:(NSString*) matchType;
@end
