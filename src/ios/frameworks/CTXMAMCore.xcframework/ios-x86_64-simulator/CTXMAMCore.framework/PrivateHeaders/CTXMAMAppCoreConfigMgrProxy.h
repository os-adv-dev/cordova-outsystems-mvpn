//
//  CTXMAMAppCoreConfigMgrProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/13/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMAppCoreConfigMgrProxy : NSObject

// Intune Calls
+ (nullable NSDictionary *)intunePolicyInfo;
+ (BOOL)isAppIntuneManaged;

// ConfigManager Calls.
+ (BOOL)isAppMobileAggregationEnabled;
+ (nullable NSString *)storeUserName;
+ (BOOL)isAppNotEntitled;
+ (BOOL)isStoreNotConfigured;
+ (void)registerForRemoteDataUpdateNotificationsWithBlock:(void(^)(NSError *))block;
+ (void)unregisterForRemoteDataUpdateNotificationsWithBlock:(void(^)(NSError *))block;
+ (void)getDeviceStateWithCompletionBlock:(void (^)(NSString *_Nullable deviceState, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END
