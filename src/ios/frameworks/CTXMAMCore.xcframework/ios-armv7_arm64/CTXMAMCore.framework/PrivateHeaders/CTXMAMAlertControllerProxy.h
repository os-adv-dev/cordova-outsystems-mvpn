//
//  CTXMAMAlertControllerProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/17/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMAlertControllerProxy : NSObject

@property(nonatomic, strong) NSError * _Nullable context;
@property(nonatomic, assign) BOOL showAppView;

- (nullable instancetype)init NS_UNAVAILABLE;
+ (nullable instancetype)alertControllerWithTitle:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(UIAlertControllerStyle)preferredStyle;
- (void)show;
- (void)dismiss;
- (void)addAction:(UIAlertAction *)action;

@end

NS_ASSUME_NONNULL_END
