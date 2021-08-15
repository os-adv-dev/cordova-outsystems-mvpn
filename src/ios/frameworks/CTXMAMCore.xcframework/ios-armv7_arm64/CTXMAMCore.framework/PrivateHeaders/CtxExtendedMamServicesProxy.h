//
//  CtxExtendedMamServicesProxy.h
//  CTXMAMCore
//
//  Created by Kun Ma on 2021/2/23.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#ifndef CtxExtendedMamServicesProxy_h
#define CtxExtendedMamServicesProxy_h

#import <Foundation/Foundation.h>

typedef void (^CTXMAMDeviceStatusCompletionBlock)(NSString * _Nullable status, NSError * _Nullable error);

@interface CtxExtendedMamServicesProxy : NSObject

+(BOOL)isEMAMSExist;
+(nullable NSDictionary *)configurationFromEMAMSSDK;
+(nullable NSDictionary *)serverAppDataGetAllAppsProperty;
+(void)asyncGetDeviceStatusAfterEnrollmentWithCompletion:(CTXMAMDeviceStatusCompletionBlock _Nullable)completion;

@end

#endif /* CtxExtendedMamServicesProxy_h */
