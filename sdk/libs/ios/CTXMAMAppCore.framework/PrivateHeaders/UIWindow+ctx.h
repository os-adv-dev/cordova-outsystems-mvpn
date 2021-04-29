//
//  UIWindow+ctx.h
//
//  Created by Jaspreet Singh on 9/4/14.
//  Copyright © 2017-2020 Citrix Systems Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIWindow (ctx)

+(UIWindow*) lastKnownWindowMadeKeyAndVisible;

-(void) curtainWindow;
-(void) uncurtainWindow;


@end
