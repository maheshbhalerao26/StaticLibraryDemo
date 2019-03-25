//
//  SQMDeviceRecordAssistent.h
//  iPass Open Mobile
//
//  Created by Puru Shukla on 11/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SQMDeviceRecordAssistent : NSObject{
	NSString*	clientId;
	
	NSArray*	deviceRecordXmlTags;
}

@property(nonatomic)NSString*	clientId;

//Method returns the current device record
//in XML stirng format.
-(NSString*)getDeviceRecordAsXMLString:(NSInteger)timestamp;

@end
