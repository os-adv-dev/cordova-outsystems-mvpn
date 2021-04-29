//
//  CTXMAMSceneDelegate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/19/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef CTXMAMSceneDelegate_h
#define CTXMAMSceneDelegate_h

API_AVAILABLE(ios(13.0))
@protocol CTXMAMSceneDelegate <NSObject>

@optional
#pragma mark Lifecycle State Transitioning
- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions;
- (void)sceneDidDisconnect:(UIScene *)scene;
- (void)sceneDidBecomeActive:(UIScene *)scene;
- (void)sceneWillResignActive:(UIScene *)scene;
- (void)sceneWillEnterForeground:(UIScene *)scene;
- (void)sceneDidEnterBackground:(UIScene *)scene;

#pragma mark - System Integration
- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts;

#pragma mark - User Activity Integration
- (void)scene:(UIScene *)scene willContinueUserActivityWithType:(NSString *)userActivityType;
- (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity;
- (void)scene:(UIScene *)scene didFailToContinueUserActivityWithType:(NSString *)userActivityType error:(NSError *)error;
- (void)scene:(UIScene *)scene didUpdateUserActivity:(NSUserActivity *)userActivity;

@end

#endif /* CTXMAMSceneDelegate_h */
