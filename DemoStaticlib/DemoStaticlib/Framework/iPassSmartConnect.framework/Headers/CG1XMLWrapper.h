//
//  CG1XMLWrapper.h
//  iPassSmartConnect
//
//  Created by Purushottam Shukla on 8/11/16.
//  Copyright © 2016 ipass. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CG1XMLWrapper : NSObject

@property (nonatomic, readonly)NSDictionary* parsedDictionary;

-(BOOL)parse:(NSString*)string;
-(BOOL)parsePollReply:(NSString*)string;

@end
