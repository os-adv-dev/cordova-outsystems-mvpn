//
//  CTXMAMAlertControllerHelper.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/19/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMAlertControllerProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMAlertControllerHelper : NSObject

+ (nullable CTXMAMAlertControllerProxy *)displayAlertWithTitle:(NSString *)title
                                                    andMessage:(NSString *)message
                                                      andStyle:(UIAlertControllerStyle)style
                                                    andActions:(NSArray<UIAlertAction *> *)actions;

+ (nullable CTXMAMAlertControllerProxy *)displayAlertWithTitle:(NSString *)title
                                                    andMessage:(NSString *)message
                                                      andStyle:(UIAlertControllerStyle)style
                                                    andActions:(NSArray<UIAlertAction *> *)actions
                                               andBlockAppView:(BOOL)blockView
                                               andErrorContext:(nullable NSError*)error;

+ (nullable NSError *)alertActionErrorContext:(UIAlertAction *)action;
+ (void)alertActionSetErrorContext:(NSError *)errorContext forAction:(UIAlertAction *)action;

@end

NS_ASSUME_NONNULL_END
