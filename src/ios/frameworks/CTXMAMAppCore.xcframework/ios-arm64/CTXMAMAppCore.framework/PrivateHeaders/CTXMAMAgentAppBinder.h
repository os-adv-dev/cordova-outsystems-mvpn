//
//  CTXMAMAgentAppBinder.h
//  CtxSingleSignOn
//
//  Created by Jaspreet Singh on 4/22/15.
//
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    CTXMAMAGENTAPP_BINDSTATE_NOTBOUND = 0,
    CTXMAMAGENTAPP_BINDSTATE_BOUND_TO_WH,
    CTXMAMAGENTAPP_BINDSTATE_BOUND_TO_X1
} CTXMAMAgentAppBindState;

@class CTXMAMAgentAppBindProperties;

@interface CTXMAMAgentAppBinder : NSObject

+ (CTXMAMAgentAppBinder*)sharedInstance;

- (void) bind;
- (BOOL) forceBindToWorxHome;
- (BOOL) forceBindToCWA;
- (BOOL) breakCurrentBinding;

- (BOOL) isWorxHomeInstalled;
- (BOOL) isX1ReceiverInstalled;
- (BOOL) isCWATestAppInstalled;
- (BOOL) isCTXMAMAgentAppInstalled;

- (BOOL) isAppBoundToX1Receiver;
- (BOOL) isAppBoundToWorxHome;

- (BOOL) didCTXMAMAgentAppLaunchThisApp:(NSString*)sourceApplication;
- (BOOL) isCTXMAMAgentAppURLScheme:(NSURL *) url;


- (NSString*) baseUrlScheme;
- (int) rpcPortCTXMAMWrapLib;
- (int) rpcPortCTXMAMLoggerLib;
- (NSString*)agentAppNameHint;
- (NSString*)appStoreURL;


@property(nonatomic,assign) BOOL accountMigratedFromCurrentCTXMAMAgentApp;

@end
