//
//  CTXMAMFeatureMgr.h
//  CTXMAMCore
//
//  Created by Chris Pavlou on 6/9/16.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//



#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import "CTXMAMFeatureMgrService.h"
#import "CTXMAMFeatureMgrConfig.h"
#import "CTXMAMConfigManagerConstants.h"

NS_ASSUME_NONNULL_BEGIN

bool isFeatureOn(const char * _Nullable featureStr);

@protocol CTXMAMFeatureMgrDelegate;

@interface CTXMAMFeatureMgr : NSObject <CTXMAMFeatureMgrServiceDelegate>

@property (nonatomic, strong, readonly) NSString *deviceId;

+(instancetype)sharedInstance;

-(void)appForegroundedFromLaunch:(BOOL)fromLaunch;
-(void)configure:(NSString *) deviceId storeUserId:(NSString *) userId storeCustomerId:(NSString *) customerId;
-(void)didEnterBackground;

// true if flags were checked withing the polling period - this will always return true during normal running conditions after the first check following a launch or foreground event.
// useful when called before first check following a launch or foreground event, to determine if saved flag values are recent.
-(BOOL)areFlagsRecent;

// check if a feature is ON (use only for BOOL flags)
-(BOOL)isFeatureOn:(NSString *)feature;

// check the value of a flag (supports all NSNumber types)
-(NSNumber *)getValueOfFeature:(NSString *)feature featureFlags:(NSDictionary *)featureFlags;

@end

@protocol CTXMAMFeatureMgrDelegate <NSObject>
@optional
-(void)featureMgr:(CTXMAMFeatureMgr *)request feature:(NSString *)feature valueChangedTo:(NSNumber *)value;
@end

NS_ASSUME_NONNULL_END

#else

#include <stdbool.h>

bool isFeatureOn(const char * _Nullable featureStr);

#endif


