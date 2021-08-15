//
//  CTXMAMUIOperations.h
//  CTXMAMContainment
//
//  Created by Jaspreet Singh on 10/22/14.
//  Copyright © 2014 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CTXMAMUIOperations : NSObject

@property (nonatomic) BOOL isLocalAuthInProgress;

+(CTXMAMUIOperations*) sharedInstance;

-(void)obscureScreen:(BOOL) obscureScreen;
-(void)curtainApp:(BOOL) obscureScreen;
-(void)uncurtainApp;
-(void)unobscureScreen;
-(BOOL)isCTXMAMObscureScreenWindow:(UIWindow*)window;

@end
