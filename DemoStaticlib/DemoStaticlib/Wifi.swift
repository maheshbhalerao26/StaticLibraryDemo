//
//  Wifi.swift
//  DemoStaticlib
//
//  Created by NewUSer on 3/28/19.
//  Copyright © 2019 dci. All rights reserved.
//

import Foundation
import iPassSmartConnect
import iPassCore
/**
 * This class helps assist the applicaiton in obtaining state about the Wifi feature of this application.
 */
enum ConnectivityState: String {
    case reachabilityStarted = "reachabilityStarted"
    case reachabilityFinished = "reachabilityFinished"
    case connectionStarted = "connectionStarted"
    case connectionWaiting = "connectionWaiting"
    case connectionSuccess = "connectionSuccess"
    case connectionFailed = "connectionFailed"
    case loggingOffStarted = "loggingOffStarted"
    case loggingOffFailed = "loggingOffFailed"
    case loggingOffSuccess = "loggingOffSuccess"
}
enum iPassError: Int {
    case userIsSuspended = 201
    case sdkKeyIsInvalid = 202
    case sdkKeyIsNullOrEmpty = 203
    /**
     * voucher redemption/ setup is not enabled.
     * Company has been not set up for voucher redemption.
     */
    case voucherRedemptionIsNotEnabled = 204
    case voucherIsInvalid = 205
    case voucherHasBeenExpired = 206
    /**
     * Voucher has been suspended. The user will also be suspended.
     */
    case voucherHasBeenSuspended = 207
    case emailAlreadyInUse = 208
    case userCreationFailed = 209
    case voucherIsEmpty = 210
    case voucherRedemptionFailed = 211
    case activationError = -1001
    /** this is a catch all as a default error not supplied by iPassSmartConnect SDK */
    case defaultError = -1
    
}

@objc class Wifi: NSObject {
    /**
     * Initializes the underlying SDK to the Wifi access for the application.
     * This should only be used in the app delegate in `applicationDidFinishLaunchingWithOptions`.
     */
    @objc
    class func initIPassSDK(with sdkKey: String) {
        #if targetEnvironment(simulator)
        // Simulator
        return;
        #else
        do {
            let iPassConnectionEventDelegate = MyConnectionDelegate()
            try SMCCore.initialize(sdkKey, annotation: "DinersClub WiFi", logLevel: .debug)
            let characterizer = SMCCharacterizer()
            let pluginHandler = SMCCaptivePluginHandler(characterizer: characterizer)
            SMCCore.shared.connectionManager?.captivePlugin = SMCCaptivePluginFactory.createPluginWith(pluginHandler)
            SMCCore.shared.connectionManager?.delegate = iPassConnectionEventDelegate
        } catch let e {
            print("=== iPassSmartConnect SDK initialilzation error")
            print(e)
        }
        #endif
    }
    
    @objc
    class func activateVoucherService(voucher: String,
                                onSuccess successHandler: @escaping (_ result: [String:Any]) -> Void,
                                onFailure failureHandler: @escaping (_ errorCode: NSError, _ errorMsg: String) -> Void) -> Void {
        #if targetEnvironment(simulator)
        // Simulator
        return;
        #else
        var voucherActivationResponseDict: [String : Any] = [:]
        let voucherDataObject = SMCVoucherActivationData(voucher)
        let activation = SMCActivation(voucherData: voucherDataObject)
        activation.activate({ () -> () in
            print("Activation Successful")
        
//            self.isPreviousSessionActivated = .registered
            voucherActivationResponseDict = [
                "voucher_code" : voucherDataObject.voucher,
                "success" : true,
            ]
            successHandler(voucherActivationResponseDict)
        }, error: { (error: NSError) -> () in
            print("Activation Failed with Error Code: \(error.description)")
            let activationError = iPassError(rawValue: error.code)
            
            func iPassErrorMessage(for type: iPassError) -> String
            {
                switch type {
                case .voucherIsInvalid:
                    return "voucherIsInvalid"
                case .voucherHasBeenExpired:
                    return "voucherHasBeenExpired"
                default:
                    return "\(type.rawValue)"
                }
            }
            var errMsg = "wifi_error_device_activation"
            if let err = activationError {
                errMsg = iPassErrorMessage(for: err)
                NSLog("Activation Error message : \(errMsg)")
            }
            failureHandler(error, errMsg)

        })
        #endif
    }
}

