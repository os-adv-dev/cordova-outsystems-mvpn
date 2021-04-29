//
//  CTXMAMLogCollector.h
//  CTXMAMCore
//
//  Created by Jaspreet Singh on 2/6/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMLogCollector : NSObject

-(BOOL) handleLogRequestUrl:(nullable NSURL*) url;
-(BOOL) handleLogRequestUrl:(NSURL*) url withOption:(nullable NSDictionary<UIApplicationOpenURLOptionsKey,id> *) options;
@end

NS_ASSUME_NONNULL_END
