//
//  ContainmentApplicationDelegate.h
//  CTXMAMCore
//
//  Created by Rolando Cruz on 11/18/19.
//  Copyright © 2019-2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef ContainmentApplicationDelegate_h
#define ContainmentApplicationDelegate_h

@protocol CTXMAMContainmentApplicationDelegate <NSObject>

@required
#pragma mark Open URL calls
-(BOOL) application:(UIApplication *) app openURL:(NSURL **) url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> **) options;
-(BOOL) containmentScene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions updatedOptions:(UISceneConnectionOptions **)outParamOptions API_AVAILABLE(ios(13.0));
-(BOOL) containmentScene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts updatedOpenURLContexts:(NSSet<UIOpenURLContext *> **)outParamURLContexts API_AVAILABLE(ios(13.0));
#pragma mark -

@end


#endif /* ContainmentApplicationDelegate_h */
