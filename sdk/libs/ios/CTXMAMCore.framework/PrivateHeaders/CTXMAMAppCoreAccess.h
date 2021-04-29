//
//  CTXMAMAppCoreAccess.h
//  CTXMAMNetwork
//
//  Created by Daniel Romano on 7/1/20.
//  Copyright © 2020 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManagerTypes.h"

typedef void (^CTXMAMDefaultEventBlock)(bool bSuccess);
typedef void (^AllAppsPropsCompletionBlock)(bool bSuccess,NSMutableDictionary<NSString*,NSDictionary*>* _Nullable  allAppsData);

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMAppCoreAccess : NSObject

-(id) init NS_UNAVAILABLE;

//AppCore calls
+(void) CTXMAMAppCoreInitializeSDK;

//Intune Calls
+(nullable NSDictionary *) configManagerIntunePolicyInfo;
+(BOOL) configManagerIsAppIntuneManaged;

//LogonManagerCalls
+(void) logonManagerRequestNewLogonWithCallBack:(nullable CTXMAMDefaultEventBlock)callback;
+(void) logonManagerPerformDeviceStateChangeRequest:(NSInteger)logonType withAdminWipe:(BOOL)adminWipe;
+(void) logonManagerSubscribeToLogonFinishedEvent:(CTXMAMConfigManagerEventBlock) eventBlock;
+(BOOL) logonManagerDidLastLogonRequestSucceed;
+(BOOL) logonManagerApplication: (UIApplication *) app openURL:(NSURL *) url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *) options;

//ConfigManager Calls.
+(BOOL) configManagerIsAppMobileAggregationEnabled;
+(nullable NSString *) configManagerStoreUserName;
+(BOOL) configManagerIsAppNotEntitled;
+(BOOL) configManagerIsStoreNotConfigured;
+(void) configManagerRegisterForRemoteDataUpdateNotificationsWithBlock:(void(^)(BOOL)) block;

//CtxSingleSignOn Calls;
+(BOOL) ctxSingleSignOnRequestVPNLogonWithReauth:(BOOL)reauth p12Hash:(NSString*)p12Hash;
+(BOOL) ctxSingleSignOnIsCTXMAMRelatedUrl:(NSURL *)url;
+(nullable NSURL *) ctxSingleSignOnHandleDeferredOpenURLRequest;
+(nullable NSURL *) ctxSingleSignOnIncomingNonCTXMAMOpenURLRequest;
+(nullable id) ctxSingleSignOnHandleDeferredOpenURLAnnotation;
+(nullable id) ctxSingleSignOnIncomingNonCTXMAMOpenURLAnnotation;
+(void) ctxSingleSignOnSetIncomingNonCTXMAMOpenURLRequest:(NSURL *)url;
+(void) ctxSingleSignOnSetIncomingNonCTXMAMOpenURLAnnotation:(id)obj;
+(nullable NSString *) ctxSingleSignOnMFURLScheme;
+(BOOL) ctxSingleSignOnCanOpenURL:(NSURL *)url;
+(nullable NSString *) ctxSingleSignOnAppId;
+(BOOL) ctxSingleSignOnRequestUpgrade;
+(BOOL) ctxSingleSignOnIsMeAtWorkInstalled;

//CTXMAMAgentAppBinder
+(BOOL) agentBinderIsCTXMAMAgentAppURLScheme:(NSURL *) url;

//ServerAppData calls
+(void) serverAppDataGetAllAppsPropertyWithSecureHubInfo:(NSDictionary *)secureHubInfo andCompletionBlock:(AllAppsPropsCompletionBlock) block;

//UIOperations
+(BOOL) uiOperationIsLocalAuthInProgress;
+(void) uiOperationSetIsLocalAuthInProgress:(BOOL)value;
+(void) uiOperationObscureScreen:(BOOL) obscureScreen;
+(void) uiOperationCurtainApp:(BOOL) obscureScreen;
+(void) uiOperationUncurtainApp;
+(void) uiOperationUnobscureScreen;

//Alert Engine
+(void) alertControllerDisplayAlertWithTitle:(NSString *)title
                                  andMessage:(NSString *)message
                                    andStyle:(UIAlertControllerStyle)style
                                  andActions:(NSArray<UIAlertAction *> *)actions;

+(void) alertControllerDisplayAlertWithTitle:(NSString *)title
                                  andMessage:(NSString *)message
                                    andStyle:(UIAlertControllerStyle)style
                                  andActions:(NSArray<UIAlertAction *> *)actions
                             andBlockAppView:(BOOL)blockView
                             andErrorContext:(nullable NSError*)error;

+(nullable NSError *) alertActionErrorContext:(UIAlertAction *) action;
+(void) alertActionSetErrorContext:(NSError *) errorContext forAction:(UIAlertAction *) action;

//CtxWorkspaceSignOut Calls
+(void) ctxWorkspaceSignOutCheckLoginStateAndCleanAGCookie;
@end

NS_ASSUME_NONNULL_END
