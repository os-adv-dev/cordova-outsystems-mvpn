//
//  CTXMAMTestUtils.h
//  CTXMAMCoreTests
//
//  Created by Jaspreet Singh on 2/7/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface XCTestCase (CTXMAM)

-(NSURL*)CTXMAMGetDocumentsDirectory;

-(void) CTXMAMRemoveItemsInURL:(NSURL *) url;

-(BOOL) CTXMAMCreateNewFile:(NSString*)filename inDir:(NSURL *)dir;
-(BOOL) CTXMAMCreateNewFile:(NSString*)filename inDir:(NSURL *)dir recreate:(BOOL)recreate;

-(BOOL) CTXMAMDoesFile:(NSString*)filename existsInDir:(NSURL *)dir;

-(void) CTXMAMAsyncWaitFor:(NSTimeInterval)fulfillWait;

@end
