//
//  NSDictionary+QueryItems.h
//  TestDialerID
//
//  Created by Sriram on 8/30/15.
//  Copyright © 2015 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (QueryItems)
- (NSString*) URLQueryStringWithSort:(BOOL)trueOrFalse;
- (NSString *) URLQueryString;
@end
