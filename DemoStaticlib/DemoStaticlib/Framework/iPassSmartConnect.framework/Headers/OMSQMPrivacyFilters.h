//
//  iPassPrivacyFilter.h
//  TestSQMDataFiltering
//
//  Created by Sriram on 9/1/13.
//  Copyright (c) 2013 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OMSQMPrivacyFilters : NSObject<NSCoding>
@property (strong,readonly,nonatomic) NSDictionary *records;
+(void) clear;
@end
