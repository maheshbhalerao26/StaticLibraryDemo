//
//  iPassSmartConnect.h
//  iPassSmartConnect
//
//  Created by Purushottam Shukla on 11/25/15.
//  Copyright © 2015 ipass. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for iPassSmartConnect.
FOUNDATION_EXPORT double iPassSmartConnectVersionNumber;

//! Project version string for iPassSmartConnect.
FOUNDATION_EXPORT const unsigned char iPassSmartConnectVersionString[];

#import <iPassCore/iPassCore.h>
#import <iPassSmartConnect/SingletonPattern.h>
#import <iPassSmartConnect/Singleton.h>
#import <iPassCore/iPassCore-Swift.h>


/// Private APIs
/// Please do not any APIs in this section as they can change without prior notice.
#import <iPassSmartConnect/AccountConfigWrapper.h>
#import <iPassSmartConnect/AccountContactInfoWrapper.h>
#import <iPassSmartConnect/AccountsInfoWrapper.h>
#import <iPassSmartConnect/CMPolicyConfigWrapper.h>
#import <iPassSmartConnect/DynamicPassword.h>
#import <iPassSmartConnect/EngineConfigWrapper.h>
#import <iPassSmartConnect/GlobalCMPolicyWrapper.h>
#import <iPassSmartConnect/Logger.h>
#import <iPassSmartConnect/MLP.h>
#import <iPassSmartConnect/NSData+Base64.h>
#import <iPassSmartConnect/NSDictionary+QueryItems.h>
#import <iPassSmartConnect/NSString+IVGUtils.h>
#import <iPassSmartConnect/OMCUtil.h>
#import <iPassSmartConnect/OMDNSQuery.h>
#import <iPassSmartConnect/OMGlobalHTTPSecurityPolicy.h>
#import <iPassSmartConnect/OMLocalizer.h>
#import <iPassSmartConnect/OMNotificationCenter.h>
#import <iPassSmartConnect/OMNotificationManager.h>
#import <iPassSmartConnect/OMPolicyHelper.h>
#import <iPassSmartConnect/OMPolicyParam.h>
#import <iPassSmartConnect/OMPreAuth.h>
#import <iPassSmartConnect/OMPreAuthAction.h>
#import <iPassSmartConnect/OMPreAuthCommand.h>
#import <iPassSmartConnect/OMPreAuthInformation.h>
#import <iPassSmartConnect/OMPreAuthManager.h>
#import <iPassSmartConnect/GIXMLWrapper.h>
#import <iPassSmartConnect/GC1XMLWrapper.h>
#import <iPassSmartConnect/CG1XMLWrapper.h>
#import <iPassSmartConnect/OMProfileConfig.h>
#import <iPassSmartConnect/OMSQMPrivacyFilters.h>
#import <iPassSmartConnect/OMServerConfig.h>
#import <iPassSmartConnect/OMWiFiNetwork.h>
#import <iPassSmartConnect/Perceptron.h>
#import <iPassSmartConnect/ProfileConfigWrapper.h>
#import <iPassSmartConnect/HelpConfigWrapper.h>
#import <iPassSmartConnect/ResourceConfigWrapper.h>
#import <iPassSmartConnect/SMCActivationConstants.h>
#import <iPassSmartConnect/SMCCoreObjCServices.h>
#import <iPassSmartConnect/SMCErrorConstants.h>
#import <iPassSmartConnect/SQMConnectionRecord.h>
#import <iPassSmartConnect/SQMDiagRecord.h>
#import <iPassSmartConnect/SQMManager.h>
#import <iPassSmartConnect/SQMSender.h>
#import <iPassSmartConnect/SQMSessionInfo.h>
#import <iPassSmartConnect/ServiceConfigWrapper.h>
#import <iPassSmartConnect/ServicesMediator.h>
#import <iPassSmartConnect/SettingsManager.h>
#import <iPassSmartConnect/SignalThresholdConfigWrapper.h>
#import <iPassSmartConnect/TFHpple.h>
#import <iPassSmartConnect/ThemisKeyExchange.h>
#import <iPassSmartConnect/ThemisLib.h>
#import <iPassSmartConnect/SMCDataUsage.h>
#import <iPassSmartConnect/UIConfigWrapper.h>
#import <iPassSmartConnect/UIDevice+IVGUtils.h>
#import <iPassSmartConnect/UserDefaultsConstants.h>
#import <iPassSmartConnect/ConnProfilerManager.h>
#import <iPassSmartConnect/SpeedTestConstants.h>
#import <iPassSmartConnect/ResourceInfoWrapper.h>
#import <iPassSmartConnect/ip_spap.h>
#import <iPassSmartConnect/SQMActivationConfirmation.h>
#import <iPassSmartConnect/SQMACADiagRecord.h>
#import <iPassSmartConnect/SQMCredCheckDiagRecord.h>
#import <iPassSmartConnect/SQMClientRecord.h>
#import <iPassSmartConnect/SQMConnectionQualityRecord.h>
#import <iPassSmartConnect/SQMDeviceRecordAssistent.h>
#import <iPassSmartConnect/NSString+MD5Addition.h>
#import <iPassSmartConnect/OpenSSLCertificateWrapper.h>
#import <iPassSmartConnect/NotificationMessages.h>
#import <iPassSmartConnect/FHISWebViewEvaluate.h>
#import <iPassSmartConnect/EventActions.h>
#import <iPassSmartConnect/InAppEvent.h>
#import <iPassSmartConnect/OMNotifyAction.h>
