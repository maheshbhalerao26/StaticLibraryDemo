//
//  UIDevice+IVGUtils.h
//  IVGUtils
//
//  Created by Douglas Sjoquist on 3/20/11.
//  Copyright 2011 Ivy Gulch, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPHONE_4 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 480.0f)
#define IS_IPHONE_5 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 568.0f)
#define IS_IPHONE_6 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 667.f)
#define IS_IPHONE_6PLUS (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 736.f)

@interface UIDevice (IVGUtils)

- (NSString *)machine;
- (BOOL) isLimitedMachine;

-(BOOL)isiPhopne4;

/*! @brief Returns whether the device is an iPad */
+ (BOOL)isiPad;

/*! @brief Returns whether the device can make phone calls */
+ (BOOL)canDeviceCall;

+ (BOOL)isPortrait;
+ (BOOL)isLandscape;
+ (UIDeviceOrientation)deviceOrientation;
+ (NSInteger)getSystemVersionAsAnInteger;
+ (BOOL)isIOS6AndHigher;
+ (BOOL)systemVersionIsAtLeast:(NSInteger)minimumVersion;
+(BOOL)isIOS7AndHigher;
+(BOOL)isIOS8AndHigher;


@end
