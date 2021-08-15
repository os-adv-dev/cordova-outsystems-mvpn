//
//  UIAlertAction+CTXMAM.h
//  CTXMAMCompliance
//
//  Created by Jaspreet Singh on 12/9/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIAlertAction (CTXMAM)

@property(nullable, nonatomic, strong) NSError* CTXMAMContextError;

@end

NS_ASSUME_NONNULL_END
