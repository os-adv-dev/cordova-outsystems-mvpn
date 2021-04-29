//
//  CTXMAMCorePrivate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 6/10/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import "CTXMAMSDK.h"

#ifndef CTXMAMCorePrivate_h
#define CTXMAMCorePrivate_h

@interface CTXMAMCore()

@property (nonatomic, strong) id<CTXMAMCoreSdkDelegate> delegate;

+(CTXMAMCore *) sharedInstance;
-(void) registerSDK:(id<CTXMAMSDK>) sdk;

@end

#endif /* CTXMAMCorePrivate_h */
