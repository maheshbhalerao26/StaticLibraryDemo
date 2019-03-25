//
//  FHISWebViewEvaluate.h
//  iPassSmartConnect
//
//  Created by Shantanu Dutta on 9/7/17.
//  Copyright © 2017 ipass. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol CaptivePluginCommand;
    //! @enumeration WebViewEvaluateError
typedef NS_ENUM(NSUInteger, WebViewEvaluateError){
    kWebViewEvaluateErrorWebViewLoadFailed,
    kWebViewEvaluateErrorNoQueryActionError,
    kWebViewEvaluateErrorNoError,
    kWebViewEvaluateAlreadyLoggedIn 
};

typedef void (^JSQueryCompletionHandler) (UIWebView* _Nullable webView, WebViewEvaluateError error);


@interface FHISWebViewEvaluate : NSObject
- (nonnull instancetype)setCaptiveCommand:(nullable id<CaptivePluginCommand>)command;
- (nonnull instancetype)setJQuery:(nonnull NSString *)query;
- (void)updateshouldLoadNextJavaScriptAction:(BOOL)value;
-(void)cleanUpWebView;
- (void)injectJSQueryAction:(nonnull NSURL*)url fhisAction:(nonnull NSString*)fhisAction completionHandler:(nonnull JSQueryCompletionHandler)completionHandler;
@end
