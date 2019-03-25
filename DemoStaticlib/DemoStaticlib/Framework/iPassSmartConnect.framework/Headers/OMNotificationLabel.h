//
//  OMNotificationLabel.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 26/06/13.
//
//

#import <Foundation/Foundation.h>

@interface OMNotificationLabel : NSObject

//! @proeprty textid
@property (nonatomic, strong)NSString* textid;
@property (nonatomic, strong)NSString* text;
@property (nonatomic,strong) NSString *text_bg;

-(instancetype)initWithTextId:(NSString*)textid;

@end
