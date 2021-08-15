//
//  CtxWorkspaceSignOutProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/17/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CtxWorkspaceSignOutProxy : NSObject

+ (void)checkLoginStateAndCleanUp;

@end

NS_ASSUME_NONNULL_END
