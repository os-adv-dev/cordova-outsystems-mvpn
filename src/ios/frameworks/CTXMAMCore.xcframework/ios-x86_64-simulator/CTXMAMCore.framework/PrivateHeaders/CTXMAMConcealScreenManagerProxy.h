//
//  CTXMAMConcealScreenManagerProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/13/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// ConcealScreenManager
// Use these APIs to conceal and reveal the screen
typedef NS_OPTIONS(NSUInteger, CTXMAMConcealScreenOptions)
{
    CTXMAMConcealScreenOption_NotConcealed    = 0,
    CTXMAMConcealScreenOption_Cover           = 1 << 0,
    CTXMAMConcealScreenOption_Curtain         = 1 << 1
};

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMConcealScreenManagerProxy : NSObject

+ (void)concealScreen:(NSString*)context options:(CTXMAMConcealScreenOptions)options;
+ (void)revealScreen:(NSString*)context;
+ (BOOL)isScreenConcealed;

@end

NS_ASSUME_NONNULL_END
