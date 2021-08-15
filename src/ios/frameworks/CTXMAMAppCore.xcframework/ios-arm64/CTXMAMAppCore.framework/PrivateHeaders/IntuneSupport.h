//
//  InTuneSupport.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 6/7/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface InTuneSupport : NSObject

+ (BOOL) isAppIntuneManaged;

+ (void) setIntuneManagedFlag:(BOOL)bVal;

@end

NS_ASSUME_NONNULL_END
