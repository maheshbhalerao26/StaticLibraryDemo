//
//  OMNotification.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 08/05/13.
//
//

@import Foundation;
@import UIKit;

#import "OMNotificationLabel.h"

//layer properties
#define NOTIFICATION_MODAL_BACKGROUND_COLOR [UIColor blackColor]
#define NOTIFICATION_MODAL_BACKGROUND_OPACITY 0.7f
#define NOTIFICATION_CORNER_RADIUS 10.0f
#define NOTIFICATION_BACKGROUND_OPACITY 0.7f
#define NOTIFICATION_BORDER_WIDTH 2.0f

#define NOTIFICATION_BORDER_PADDING 10.0f
#define NOTIFICATION_HORIZONTAL_PADDING 18.0f
#define NOTIFICATION_VERTICAL_PADDING 14.0f

#define NO_BUTTON_INDEX -1

typedef NS_ENUM(NSUInteger, OMNotificationPriority){
    kPriorityLow,
    kPriorityMedium,
    kPriorityHigh,
    kPriorityUrgent,
    kPriorityUrgentDismissAll
};

@class OMNotification;


@protocol OMNotificationDelegate <NSObject>
-(void)notification:(OMNotification*)notification tappedButtonAtIndex:(NSInteger)index;
@end

@protocol NotificationManagerDelegate <NSObject>
-(void)notificationDidDismiss:(OMNotification*)notification;
@end

@interface OMNotification : NSObject<NSCoding>

//! @proeprty id
@property (nonatomic, strong)NSString* id;

//! @property text label
@property (nonatomic, strong)OMNotificationLabel* textLabel;

//! @property priority
@property (nonatomic, readonly)OMNotificationPriority priority;

//! @property foregroundDisplay: enforces the notification to be displayed
//in the foreground when ever application transitions to foreground.
@property BOOL foregroundDisplay;

//! @property to indicate whether the notification can be closed or not.
@property (atomic)BOOL canClose;

//! @property delegate
@property (nonatomic, unsafe_unretained)id<OMNotificationDelegate>delegate;

//! @property notification manager delegate
@property (nonatomic, unsafe_unretained)id<NotificationManagerDelegate>nmDelegate;

-(instancetype)initWithId:(NSString*)id
                 priority:(NSString*)priority;


-(CGFloat)maxAllowedWidth;
-(CGFloat)maxAllowedHeight;
-(CGSize)sizeOfString:(NSString*)string withFont:(UIFont*)font;
-(CGFloat)bottomMargin;

#pragma mark - Override Methods
//Subclasses should implement these methods to show their UI. Default
//implementation does noting
-(void)show;
-(void)hide;
-(void)close;
-(BOOL) canBeDismissed;

#pragma mark - Orientation changed helper Methods
-(void) registerForOrientationChangeNotification;
-(void) unregisterForNotification;
-(void) handleOrientationChanged:(UIInterfaceOrientation) orientation;

@end
