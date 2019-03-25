//
//  BackgroundFetchDelegate.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 8/11/14.
//
//

#import <Foundation/Foundation.h>

@protocol BackgroundFetchDelegate <NSObject>
-(BOOL)startFetch;

@optional
-(void)stopFetch;
@end
