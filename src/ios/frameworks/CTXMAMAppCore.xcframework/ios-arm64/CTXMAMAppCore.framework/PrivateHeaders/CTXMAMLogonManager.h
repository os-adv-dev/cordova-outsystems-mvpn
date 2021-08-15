//
//  CTXMAMLogonManager.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 5/28/20.
//  Copyright © 2020 Daniel Romano. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManagerPrivate.h"
#import "CTXMAMLogonManagerPrivateTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMLogonManager : NSObject

-(id) init NS_UNAVAILABLE;

+(CTXMAMLogonManager *) sharedLogonManager;
@property (readonly) BOOL loggedOn;
@property (readonly) NSTimeInterval timeIntervalSinceLastFailedLogonRequest;
@property (nonatomic, strong, nullable) NSString * lastLogonRequestTimeStr;
@property (nonatomic, strong, nullable) NSNumber * lastLogonResult;
@property (nonatomic, strong, nullable) NSString * lastFlipTimeStr;

+(BOOL) application: (UIApplication *) app openURL:(NSURL *) url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *) options;
/*!
Requests a new logon to be made, this call will cause your application to open the SecureHub app. Logon occurs asynchronously.
DO NOT CALL THIS API Unless you are 100% positive that a new logon is required.
@param logonRequestFinished The pointer to a block which will be executed and the logon has finished.
*/
-(void) requestNewLogon: (nullable CTXMAMConfigManagerEventBlock) logonRequestFinished;
-(void) subscribeToLogonFinishedEvent: (nonnull  CTXMAMConfigManagerEventBlock) eventBlock;
-(void) performDeviceStateChangeRequest: (CTXLogonRequestType) logonType withAdminWipe:(BOOL)adminWipe;
-(BOOL) didLastLogonRequestSucceed;

-(void) doCEMAndGateWayAuthAndUpdatePayload:(NSDictionary *)payload isCWAFlip:(BOOL)isCWAFlip;
-(NSNumber *) bindState;
-(BOOL) setBindState:(NSNumber *)value;

@end

NS_ASSUME_NONNULL_END
