//
//  CTXMAMLifecycleDelegate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/19/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMApplicationDelegate_h
#define CTXMAMApplicationDelegate_h

NS_ASSUME_NONNULL_BEGIN

@protocol CTXMAMApplicationDelegate <NSObject>
@optional
#pragma mark Initializing the App
- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;
#pragma mark -

#pragma mark Responding to App Life-Cycle Events
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
#pragma mark

#pragma mark Responding to Environment Changes
- (void)applicationProtectedDataDidBecomeAvailable:(UIApplication *)application;
- (void)applicationProtectedDataWillBecomeUnavailable:(UIApplication *)application;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;
- (void)applicationSignificantTimeChange:(UIApplication *)application;
#pragma mark -

#pragma mark Managing App State Restoration
- (BOOL)application:(UIApplication *)application shouldSaveApplicationState:(NSCoder *)coder;
- (BOOL)application:(UIApplication *)application shouldRestoreApplicationState:(NSCoder *)coder;
#pragma mark -

#pragma mark Managing App Extensions
- (BOOL)application:(UIApplication *)application shouldAllowExtensionPointIdentifier:(NSString *)extensionPointIdentifier;
#pragma mark -

#pragma mark Background Sync calls
- (void)application:(UIApplication *)application performFetchWithCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler;

#pragma mark -
@end

#endif /* CTXMAMApplicationDelegate_h */

NS_ASSUME_NONNULL_END
