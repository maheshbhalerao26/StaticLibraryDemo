//
//  SingletonPattern.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 8/1/14.
//
//

#import <Foundation/Foundation.h>

/**
 Returns a singleton instance of the specified class
 */
@protocol SingletonPattern <NSObject>

/// Method returns the shared instance of this class or subclasses of this class.
/// @returns The specified class's instance as shared instance.
+(instancetype)sharedInstance;

@end
