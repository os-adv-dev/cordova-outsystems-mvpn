//
//  CTXMAMServerAppDataRequestProxy.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/17/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMUnlinkedSDKUtils.h"

typedef void (^AllAppsPropsCompletionBlock)(bool bSuccess,NSMutableDictionary<NSString*,NSDictionary*>* _Nullable  allAppsData);

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMServerAppDataRequestProxy : NSObject

+ (void)getAllAppsPropertyWithSecureHubInfo:(NSDictionary *)secureHubInfo andCompletionBlock:(AllAppsPropsCompletionBlock)block;

@end

NS_ASSUME_NONNULL_END
