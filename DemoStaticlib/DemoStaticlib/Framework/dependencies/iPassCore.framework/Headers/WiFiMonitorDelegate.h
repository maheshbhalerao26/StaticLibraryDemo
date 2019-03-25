//
//  WiFiMonitorDelegate.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 12/21/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol WiFiMonitorDelegate

-(void)networkReachabilityChanged:(NSDictionary*)networkInfo;

@end
