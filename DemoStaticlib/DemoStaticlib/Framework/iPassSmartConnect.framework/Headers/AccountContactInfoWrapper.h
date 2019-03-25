//
//  AccountContactInfoWrapper.h
//  iPassOpenMobile
//
//  Created by Matthew Mourlam on 6/30/14.
//
//

#import <Foundation/Foundation.h>

@interface AccountContactInfoWrapper : NSObject

//@property (nonatomic,strong,readonly) NSAttributedString *formattedContactInfo;

+(void) clear;
-(NSAttributedString*) formattedContactInfo;

@end
