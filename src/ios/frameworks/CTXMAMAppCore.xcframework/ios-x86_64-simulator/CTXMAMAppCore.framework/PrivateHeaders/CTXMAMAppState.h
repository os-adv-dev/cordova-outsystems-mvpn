//
//  CTXMAMAppState.h
//  CTXMAMAppCore
//
//  Created by Taoyong Ding on 4/6/2021.
//  Copyright © 2021 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTXMAMAppState : NSObject

@property (nonatomic) BOOL appDidFinishLaunchingByCWA;
@property (nonatomic) BOOL appFirstLogonFlipSkipped;

+ (CTXMAMAppState *)sharedInstance;

@end
