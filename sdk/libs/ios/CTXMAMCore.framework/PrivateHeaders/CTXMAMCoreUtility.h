//
//  CTXMAMCoreUtility.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/18/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMCoreUtility : NSObject

+(NSDate *) getRebootTime;
+(NSString*) bundleSeedID;
+(NSString*) appBundleID;

+(BOOL) isSDKRelatedUrl:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
