//
//  CTXMAMCorePrivate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 6/10/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import "CTXMAMSDK.h"
#import "ContainmentApplicationDelegate.h"

#ifndef CTXMAMCorePrivate_h
#define CTXMAMCorePrivate_h

@interface CTXMAMCore()

@property (nonatomic, strong, nullable) id<CTXMAMCoreSdkDelegate> delegate;

@property (nonatomic, strong, nullable) id<CTXMAMContainmentApplicationDelegate> containmentDelegate;

+(CTXMAMCore * _Nonnull) sharedInstance;

-(void) registerSDK:(id<CTXMAMSDK> _Nonnull) sdk;

@end

#endif /* CTXMAMCorePrivate_h */
