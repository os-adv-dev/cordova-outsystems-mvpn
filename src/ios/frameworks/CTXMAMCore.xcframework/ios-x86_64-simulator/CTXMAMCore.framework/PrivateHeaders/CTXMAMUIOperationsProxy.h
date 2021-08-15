//
//  CTXMAMUIOperationsProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/13/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// The following APIs are deprecated in favor of the "conceal/reveal" APIs
__deprecated_msg("Use CTXMAMConcealScreenManagerProxy class instead.")
@interface CTXMAMUIOperationsProxy : NSObject

+ (BOOL)isLocalAuthInProgress __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));
+ (void)setIsLocalAuthInProgress:(BOOL)value __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));
+ (void)obscureScreen:(BOOL)obscureScreen __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));
+ (void)curtainApp:(BOOL)obscureScreen __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));
+ (void)uncurtainApp __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));
+ (void)unobscureScreen __attribute__((deprecated("Use CTXMAMConcealScreenManagerProxy class instead.")));

@end

NS_ASSUME_NONNULL_END
