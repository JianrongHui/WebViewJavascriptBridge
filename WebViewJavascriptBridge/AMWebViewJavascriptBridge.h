//
//  WebViewJavascriptBridge.h
//  ExampleApp-iOS
//
//  Created by Marcus Westin on 6/14/13.
//  Copyright (c) 2013 Marcus Westin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMWebViewJavascriptBridgeBase.h"

#if (__MAC_OS_X_VERSION_MAX_ALLOWED > __MAC_10_9 || __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_7_1)
#define AM_SupportsWKWebView
#endif

#if defined AM_SupportsWKWebView
#import <WebKit/WebKit.h>
#endif

#if defined __MAC_OS_X_VERSION_MAX_ALLOWED
    #define AM_WVJB_PLATFORM_OSX
    #define AM_WVJB_WEBVIEW_TYPE WebView
    #define AM_WVJB_WEBVIEW_DELEGATE_TYPE NSObject<AMWebViewJavascriptBridgeBaseDelegate>
    #define AMWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<AMWebViewJavascriptBridgeBaseDelegate, WebPolicyDelegate>
#elif defined __IPHONE_OS_VERSION_MAX_ALLOWED
    #import <UIKit/UIWebView.h>
    #define AM_WVJB_PLATFORM_IOS
    #define AM_WVJB_WEBVIEW_TYPE UIWebView
    #define AM_WVJB_WEBVIEW_DELEGATE_TYPE NSObject<UIWebViewDelegate>
    #define AMWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<UIWebViewDelegate, AMWebViewJavascriptBridgeBaseDelegate>
#endif

@interface AMWebViewJavascriptBridge : AMWVJB_WEBVIEW_DELEGATE_INTERFACE


+ (instancetype)bridgeForWebView:(id)webView;
+ (instancetype)bridge:(id)webView;

+ (void)enableLogging;
+ (void)setLogMaxLength:(int)length;

- (void)registerHandler:(NSString*)handlerName handler:(AMWVJBHandler)handler;
- (void)removeHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName data:(id)data;
- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(AMWVJBResponseCallback)responseCallback;
- (void)setWebViewDelegate:(id)webViewDelegate;
- (void)disableJavscriptAlertBoxSafetyTimeout;

@end
