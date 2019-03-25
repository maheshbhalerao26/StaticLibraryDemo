//
//  OMPKIUtil.h
//  iPassOpenMobile
//
//  Created by Ronak Shah on 3/6/13.
//

#import <Foundation/Foundation.h>

@interface OMPKIUtil : NSObject

+ (void)generateOMKeyPair;
+ (SecKeyRef)getOMPrivateKeyRef;
+ (NSString *)getOMPublicKeyString;

@end