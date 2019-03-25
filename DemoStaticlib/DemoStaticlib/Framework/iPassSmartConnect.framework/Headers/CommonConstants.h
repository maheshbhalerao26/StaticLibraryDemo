//
//  CommonConstants.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 06/09/12.
//
//

#ifndef iPassOpenMobile_CoreConstents_h
#define iPassOpenMobile_CoreConstents_h

#import <Foundation/Foundation.h>

//! @brief session timeout constants


//Prefix used in the in app messaging parsing. These prefix are used
//to differentiate similar names under different messaging levels
#define GLOBAL_MESSAGING_PREFIX @"global"
#define PARTNER_MESSAGING_PREFIX @"partner"
#define CUSTOM_MESSAGING_PREFIX @"custom"

#define FALSE_POSITIVE_NOTIFICATION_ID               @"NotifyFalsePositive"
#define SERVICE_OUTAGE_ABORT_LOGIN_NOTIFICATION_ID   @"ServiceOutageAbortLogin"
#define SERVICE_OUTAGE_INFO_NOTIFICATION_ID          @"ServiceOutageInfo"
#define FP_CONN_FAILED_TOAST_NOTIFICATION_ID         @"FalsePositiveToastConnFailed"
#define FP_CONN_AUTH_FAILED_FP_TOAST_NOTIFICATION_ID    @"FalsePositiveToastAuthFailedFP"

#define VALUE_YES @"Yes"

#endif

@interface CommonConstants : NSObject

@end
