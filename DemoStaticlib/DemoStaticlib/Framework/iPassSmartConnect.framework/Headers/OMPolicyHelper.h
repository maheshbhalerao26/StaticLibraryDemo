//
//  OMPolicyManager.h
//  TestSessionTimeOut
//
//  Created by Sriram on 5/9/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OMPolicyParam;
@interface OMPolicyHelper : NSObject
+(BOOL) isCriteriaSatisfied:(NSDictionary*) criteria forParams:(OMPolicyParam*)params;
+(BOOL) evaluateCondition:(NSDictionary*) condition forParams:(OMPolicyParam*) params;
@end
