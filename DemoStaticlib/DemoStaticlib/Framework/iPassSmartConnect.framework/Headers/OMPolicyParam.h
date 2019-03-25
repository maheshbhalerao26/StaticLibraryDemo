//
//  OMPolicyParam.h
//  TestSessionTimeOut
//
//  Created by Sriram on 5/9/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OMPolicyParam : NSObject
@property(strong) NSString *authMethod ;
@property(strong) NSString *mediaType;

-(NSString*) valueForParam:(NSString*) paramName;
@end
