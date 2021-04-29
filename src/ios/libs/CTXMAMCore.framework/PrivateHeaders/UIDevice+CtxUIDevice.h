//
//  UIDevice+CtxUIDevice.h
//
//  Created by David Hoy on 7/20/12.
//  Copyright © 2012 - 2020 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

bool isiOS9OrAbove(void);

@interface UIDevice (CtxUIDevice)

-(NSString *)machine;
-(NSString *)platform;
-(NSString *)majorPlatform;

+(BOOL) iOS8OrAbove;
+(BOOL) iOS9OrAbove;
+(BOOL) iOS102OrAbove;
+(BOOL) iOS11OrAbove;
+(BOOL) iOS13OrAbove;

+(BOOL)iPhone;
+(BOOL)iPad;

+(float)CTXMAMSystemVersion;

@end
