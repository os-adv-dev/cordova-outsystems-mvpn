//
//  CTXMAMUnlinkedSDKUtils.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/12/21.
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSErrorDomain _Nonnull CTXMAMUnlinkedSDKErrorDomain = @"CTXMAMUnlinkedSDKError";

typedef NS_ENUM(NSUInteger, CTXMAMUnlinkedSDKError)
{
    CTXMAMUnlinkedSDKError_Unknown                      = 80000,
    CTXMAMUnlinkedSDKError_SelectorNotFound             = 80001
};


@interface CTXMAMUnlinkedSDKUtils : NSObject

+ (nullable id)getSingletonInstanceForClassName:(nonnull NSString *)className andSingletonName:(nonnull NSString *)singletonFuncName;
+ (BOOL)shouldCallSelector:(nullable SEL)selector forObject:(nullable id)classInstance;
+ (nullable NSError *)getErrorForCode:(CTXMAMUnlinkedSDKError)code andUnderlyingError:(nullable NSError *)underlyingError;

@end
