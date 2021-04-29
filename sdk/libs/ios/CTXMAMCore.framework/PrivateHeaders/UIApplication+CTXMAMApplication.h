//
//  UIApplication+CTXMAMApplication.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 7/18/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContainmentApplicationDelegate.h"
#import "CTXMAMApplicationDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication(CTXMAMApplication)

@property (nonatomic, strong, nullable) id<CTXMAMContainmentApplicationDelegate> containmentDelegate;

@end

NS_ASSUME_NONNULL_END
