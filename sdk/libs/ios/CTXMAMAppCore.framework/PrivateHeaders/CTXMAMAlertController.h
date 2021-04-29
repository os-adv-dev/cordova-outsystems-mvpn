//
//  CTXMAMAlertController.h
//  CTXMAMCompliance
//
//  Created by Jaspreet Singh on 12/9/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMAlertController : UIAlertController

@property(nonatomic, strong) NSError* context;
@property(nonatomic, assign) BOOL showAppView;

- (void) show;
- (void) dismiss;

@end

NS_ASSUME_NONNULL_END
