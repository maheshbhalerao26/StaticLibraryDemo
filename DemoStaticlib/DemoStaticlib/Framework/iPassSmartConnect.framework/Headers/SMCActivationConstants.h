//
//  SMCActivationConstant.h
//  iPassSmartConnect
//
//  Created by Purushottam Shukla on 12/3/15.
//  Copyright © 2015 ipass. All rights reserved.
//

#ifndef SMCActivationConstant_h
#define SMCActivationConstant_h

@import Foundation;

typedef NS_ENUM(NSInteger, ActivationResult){
    kActivationResultSuccess = 0,     //    The operation succeeded.
    kActivationResultBusy = 1, //    The operation has failed. The operation could not be attempted because an activation, provisioning or update operation is already in progress (perhaps by another program).
    kActivationResultInternalError = 2, //   an unexpected internal error occurred. The Open Mobile program has internally recorded exception information in its status log. Instruct user to perform “Send Logs” operation in the Open Mobile program and then forward the received Open Mobile log to iPass through a customer service ticket.
    
    kActivationResultNotProvisioned = 10,           //  The operation has failed. The OpenMobile installation has not been previously provisioned with a profile and either (1) the profile argument is missing or (2) a blank Profile ID was specified. A valid Profile ID is a decimal value.
    //    kResultInvalidProfileIdPin = 10,     // The operation has failed. An invalid or blank Profile ID was specified. A valid  Profile ID is a decimal value.
    
    kActivationResultInvalidAutologinOrTest = 11, // An invalid value was specified for the autologin or test parameter.
    
    kActivationResultIncompatibleDomain = 20,      // The operation has failed. The effective domain configuration is incompatible with the provisioned profile.
    
    kActivationResultIncompatiblePrefix = 21,      // The operation has failed.The effective user prefix configuration  is incompatible with the provisioned profile.
    
    kActivationResultAutologinWithoutCredential = 22,  // The operation has failed. The requested operation asserts the autologin feature but the effective configuration of the client is missing a valid username, password or domain.
    
    kActivationResultUsernameOrPasswordIsTooLong = 23,   // The operation has failed. The requested username and/or password setting exceed the maximum length of those values. This error will occur if an attempt is made to configure a username value greater than 100 characters in length or a password value that is greater than 64 characters in length.
    
    kActivationResultWrongUsernameOrPassword = 24,
    
    kActivationResultCommunicationInterrupted = 30,    // The operation has failed.Communication with the server was interrupted.The operation has failed.
    
    kActivationResultTransientError = 31,              // The operation has failed.The activation service has reported a transient error. Try the operation again at a later time.
    
    kActivationResultNoInternet = 32,          // The operation has failed. The device does not have a connection to the internet. A connection is required. Establish an internet connection and retry the operation.
    
    kActivationResultNoDeviceProfileOrInvalidProfilePin = 33,     // The operation has failed. The Profile ID does not correspond to an available profile in the indicated mode (production or test) or profile and pin combination is wrong. This error may occur if a non-iOS profile Id is specified in the profile argument but no default iOS profile has been configured for the company by the user’s service administrator.
    
    
    //	kConfigurationSuccessful,
    //	kConfigurationNeedsUsernameAndPassword,
    //	kConfigurationFailedWrongProfileidOrPin,
    //	kConfigurationFailedWrongUsernameOrPassword,
    //    kConfigurationkCommunicationInterrupted,
    //    kConfigurationProfileValidationError,
    //	kConfigurationFailedUnknownError
};


extern NSString* keyTokenParam;

#endif /* SMCActivationConstant_h */
