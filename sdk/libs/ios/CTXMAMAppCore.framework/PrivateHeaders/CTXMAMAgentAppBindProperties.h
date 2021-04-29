//
//  CTXMAMAgentAppBindProperties.h
//  CtxSingleSignOn
//
//  Created by Jaspreet Singh on 5/21/15.
//
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTXMAMAgentAppBindProperties : NSObject

@property(nonatomic,strong) NSString* bundleID;
@property(nonatomic,strong) NSString* baseUrlScheme;
@property(nonatomic,assign) int rpcPortCTXMAMWrapLib;
@property(nonatomic,assign) int rpcPortCTXMAMLoggerLib;

@property(nonatomic,strong) NSString* agentAppNameHint;
@property(nonatomic,strong) NSString* appStoreURL;

+(CTXMAMAgentAppBindProperties*) CTXMAMAgentAppBindPropertiesWH;
+(CTXMAMAgentAppBindProperties*) CTXMAMAgentAppBindPropertiesX1;
+(CTXMAMAgentAppBindProperties*) CTXMAMAgentAppBindPropertiesCWATestApp;

@end
