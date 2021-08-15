//
//  CTXMAMLogonManagerProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/12/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMUnlinkedSDKUtils.h"
#import "CTXMAMConfigManagerTypes.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^CTXMAMDefaultEventBlock)(bool bSuccess);

@interface CTXMAMLogonManagerProxy : NSObject

+ (void)requestNewLogon:(CTXMAMDefaultEventBlock)callback;
+ (void)performDeviceStateChangeRequest:(NSInteger)logonType withAdminWipe:(BOOL)adminWipe;
+ (void)subscribeToLogonFinishedEvent:(CTXMAMConfigManagerEventBlock)eventBlock;
+ (BOOL)didLastLogonRequestSucceed;
+ (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

@end

NS_ASSUME_NONNULL_END
