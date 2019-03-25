//
//  NSString+OMURLEncode.h
//  
//
//  Created by Sriram on 11/3/15.
//  Copyright © 2015 Sriram. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (OMURLEncode)
- (NSString *)urlEncodedString;
- (NSString *)urlDecodedString;
@end
