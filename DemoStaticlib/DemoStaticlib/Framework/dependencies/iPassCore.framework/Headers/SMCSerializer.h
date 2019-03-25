//
//  SMCSerializer.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 30/10/12.
//
//

#import <Foundation/Foundation.h>

@interface SMCSerializer : NSObject

+(id)objectFromFile:(NSString*)file;
+(void)serializeObject:(id)object
                toFile:(NSString*)file;

@end
