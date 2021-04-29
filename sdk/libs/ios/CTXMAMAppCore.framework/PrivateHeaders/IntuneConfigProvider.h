//
//  IntuneConfigProvider.h
//  CTXMAMAppCore
//
//  Created by Shikha Shah on 6/19/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManagerPrivate.h"

NS_ASSUME_NONNULL_BEGIN

@interface IntuneConfigProvider : NSObject

@end

@interface CTXMAMConfigManager(IntuneConfig)

@property(readonly) NSDictionary* intunePolicyInfo;

-(BOOL) isAppIntuneManaged;

@end

NS_ASSUME_NONNULL_END
