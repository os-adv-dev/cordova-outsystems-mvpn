//
//  CTXMAMAgentAppBinder.h
//  CtxSingleSignOn
//
//  Created by Jaspreet Singh on 4/22/15.
//
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CTXMAMAgentAppBindProperties;

@interface CTXMAMAgentAppBinder : NSObject

+ (CTXMAMAgentAppBinder*)sharedInstance;

- (void) bind;
- (BOOL) forceBindToWorxHome;
- (BOOL) breakCurrentBinding;

- (BOOL) isWorxHomeInstalled;
- (BOOL) isX1ReceiverInstalled;
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
