//
//  SQMActivationConfirmation.h
//  iPassOpenMobile
//
//  Created by Ronak Shah on 3/28/13.
//

#import <Foundation/Foundation.h>
#import "SQMRecord.h"

// Activation Confirmation fields
typedef NS_ENUM(NSInteger, ActivationConfirmationFields)
{
    // BundleRequest and its subelements
    kActivationConfirmationBundleRequest,
    kActivationConfirmationBundleClass,
    kActivationConfirmationName,
    kActivationConfirmationPlatform,
    kActivationConfirmationVersion,

    kActivationConfirmationComments,
	kActivationConfirmationCompanyId,
	kActivationConfirmationGuid,
	kActivationConfirmationPin,

    // Principal and its subelements
	kActivationConfirmationPrincipal,
    kActivationConfirmationEmail,
    kActivationConfirmationUser,
    kActivationConfirmationNAI,
    kActivationConfirmationPassword,

	kActivationConfirmationProfileId,
	kActivationConfirmationProfileVersion,
	kActivationConfirmationStatus,
	kActivationConfirmationJSessionId,

    kActivationConfirmationTotalActivationFields,
} ;

@interface SQMActivationConfirmation : SQMRecord

@property (nonatomic, strong) NSMutableDictionary *currentActivationConfirmation;

//! Convenience constructor
+ (SQMActivationConfirmation *)newActivationConfirmation;

@end