//
//  DemoStaticlib.h
//  DemoStaticlib
//
//  Created by NewUSer on 3/19/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyConnectionDelegate.h"
#import <iPassSmartConnect/iPassSmartConnect.h>

@interface DemoStaticlib : NSObject
    @property (nonatomic, strong)MyConnectionDelegate* connectionDelegate;
@end
