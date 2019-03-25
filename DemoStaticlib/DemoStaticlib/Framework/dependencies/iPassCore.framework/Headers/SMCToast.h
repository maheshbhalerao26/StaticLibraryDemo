//
//  SMCToast.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 19/10/12.
//
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

#ifndef IPASS_APP_EXTENSION

@interface SMCToast : UIView<UIAppearance>

//! @brief Initializer with title, message, timeout and dismissable
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                      timeout:(NSTimeInterval)timeout
                  dismissible:(BOOL)dismissible;

//! @brief Shows SMCToast
- (void)show;

//! @brief Hides SMCToast
- (void)hide;

@end

#endif
