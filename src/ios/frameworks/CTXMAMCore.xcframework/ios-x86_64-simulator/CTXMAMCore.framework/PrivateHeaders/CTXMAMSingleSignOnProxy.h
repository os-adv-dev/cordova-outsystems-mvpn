//
//  CTXMAMSingleSignOnProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/13/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMSingleSignOnProxy : NSObject

+ (BOOL)requestVPNLogonWithReauth:(BOOL)reauth p12Hash:(NSString*)p12Hash;
+ (BOOL)isCTXMAMRelatedUrl:(NSURL *)url;
+ (nullable NSURL *)handleDeferredOpenURLRequest;
+ (nullable NSURL *)incomingNonCTXMAMOpenURLRequest;
+ (nullable id)handleDeferredOpenURLAnnotation;
+ (nullable id)incomingNonCTXMAMOpenURLAnnotation;
+ (void)setIncomingNonCTXMAMOpenURLRequest:(NSURL *)url;
+ (void)setIncomingNonCTXMAMOpenURLAnnotation:(id)obj;
+ (nullable NSString *)mfurlScheme;
+ (BOOL)canOpenURL:(NSURL *)url;
+ (nullable NSString *)appId;
+ (BOOL)requestUpgrade;
+ (BOOL)isMeAtWorkInstalled;

@end

NS_ASSUME_NONNULL_END
