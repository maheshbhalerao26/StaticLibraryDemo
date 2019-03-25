//
//  OMGlobalHTTPSecurity.h
//  iPassOpenMobile
//
//  Created by Sriram on 8/1/15.
//
//

#import <Foundation/Foundation.h>
FOUNDATION_EXPORT NSString *const kHTTPProtocolMinVersionKey;
FOUNDATION_EXPORT NSString *const kHTTPProtocolMaxVersionKey;
@interface OMGlobalHTTPSecurityPolicy : NSObject

+ (instancetype)sharedInstance;
-(NSArray*) securityProtocolForNetwork:(NSString*) networkName;
-(NSString*)bestMatchSSLevelForProtocolVersions:(NSArray*)protocolsVersions;
-(void) saveHTTPSecurityPolicies:(NSDictionary*) securityPolicies;
-(BOOL) isFileParsed;
-(void) clearHTTPSecurityPolicies;

@end
