//
//  UIScene+CTXMANScene.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 1/6/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ContainmentApplicationDelegate.h"
#import "CTXMAMSceneDelegate.h"

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0))
@interface UIScene (CTXMAMScene)

@property (nonatomic, strong, nullable) id<CTXMAMContainmentApplicationDelegate> containmentDelegate;

+ (void)setGlobalContainmentDelegate:(nullable id<CTXMAMContainmentApplicationDelegate>)containmentDelegate;

@end

NS_ASSUME_NONNULL_END
