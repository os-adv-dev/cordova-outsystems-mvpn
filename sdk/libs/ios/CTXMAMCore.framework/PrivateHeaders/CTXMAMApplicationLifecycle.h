//
//  CTXMAMApplicationLifecycle.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 9/4/18.
//  Copyright © 2018 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMApplicationDelegate.h"
#import "CTXMAMSceneDelegate.h"

typedef NS_ENUM(NSUInteger, CTXMAMApplicationState)
{
    CTXMAMAppState_unknown,
    CTXMAMAppState_inForeground,
    CTXMAMAppState_inBackground,
    CTXMAMAppState_extension
};

@interface CTXMAMApplicationLifecycle : NSObject

@property (readonly) CTXMAMApplicationState ctxApplicationState;
@property (assign) BOOL shouldTerminate;
@property (assign) BOOL shouldTerminateOnMoveToBackground;
@property (readonly) NSArray * appDelegateLifecycleEventSubscribers;
@property (readonly) NSArray * sceneDelegateLifecycleEventSubscribers;

+(CTXMAMApplicationLifecycle *) sharedLifecycle;
-(BOOL) subscribeToAppDelegateLifecycleEvents:(id<CTXMAMApplicationDelegate>)delegate;
-(BOOL) subscribeToSceneDelegateLifecycleEvents:(id<CTXMAMSceneDelegate>)delegate API_AVAILABLE(ios(13.0));

@end
