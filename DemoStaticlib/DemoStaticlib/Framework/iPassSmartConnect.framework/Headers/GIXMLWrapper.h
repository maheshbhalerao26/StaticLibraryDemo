//
//  GIXMLWrapper.h
//  iPassSmartConnect
//
//  Created by Purushottam Shukla on 12/2/15.
//  Copyright © 2015 ipass. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GIXMLWrapper : NSObject

@property (nonatomic, readonly)NSDictionary* parsedDictionary;

-(BOOL)parseString:(NSString*)string;

@end
