//
//  OMDataUsage.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 22/08/13.
//
//

#import <Foundation/Foundation.h>

//Usage data support for following interfaces
typedef NS_ENUM(NSUInteger, Interface) {
    kCellularInterface = 0,
    kWiFiInterface
};

@class SMCNetStats;

@interface SMCDataUsage : NSObject

//getting the network stats, mainly the inbytes and outbytes
+(nonnull SMCNetStats*)netStatsForInterface:(Interface)interface;

@end
