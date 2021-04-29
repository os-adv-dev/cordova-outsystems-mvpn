//
//  SmartNetworkPrivate.h
//  SmartNetwork
//
//  Created by Shikha Shah on 8/14/18.
//  Copyright © 2018 - 2019 Citrix Systems Inc. All rights reserved.
//

#ifndef SmartNetworkPrivateAPIs_h
#define SmartNetworkPrivateAPIs_h
#import "SmartNetwork.h"
#import "CTXMAMSDK.h"


@interface SmartNetwork() <CTXMAMSDK>

@property(nonatomic, assign) BOOL appMovedToBackground;

/*!
 Initalizes Secure Browse tunnel for NSURL related calls.
 */
+ (void)initializeSmartNetwork;

+ (SmartNetwork * _Nullable)sharedInstance;
+ (BOOL) getSwizzledValue;

+ (NSURLSessionConfiguration * _Nullable) ctxmam_defaultSessionConfiguration;
+ (NSURLSessionConfiguration * _Nullable) ctxmam_ephemeralSessionConfiguration;
+ (NSURLSession * _Nonnull) ctxmam_sessionWithConfiguration: (NSURLSessionConfiguration * _Nonnull) configuration
                                               delegate: (_Nullable id<NSURLSessionDelegate>) delegate
                                          delegateQueue: (NSOperationQueue * _Nullable) queue;

@end

#endif /* SmartNetworkPrivateAPIs_h */
