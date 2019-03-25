//
//  GC1XMLWrapper.h
//  iPassSmartConnect
//
//  Created by Purushottam Shukla on 12/2/15.
//  Copyright © 2015 ipass. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GC1XMLWrapper : NSObject

@property (nonatomic, readonly)NSDictionary* parsedDictionary;

-(BOOL)parse:(NSString*)string;
-(BOOL)parsePollReply:(NSString*)string;

@end
