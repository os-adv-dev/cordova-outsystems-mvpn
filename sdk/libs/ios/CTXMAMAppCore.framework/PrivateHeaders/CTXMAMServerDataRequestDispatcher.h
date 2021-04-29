//
//  CTXMAMServerDataRequestDispatcher.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 11/26/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ServerInfoCompletionBlock)(BOOL bSuccess, NSDictionary * _Nullable appInfo, NSDictionary * _Nullable clientProperties, BOOL bTriggerDataUpdatedEvent);

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMServerDataRequestDispatcher : NSObject

@property (nonatomic, retain) NSDictionary * logonInfo;

+(void) fetchXMSServerConfigWithLogonInfo:(NSDictionary *)logonInfo
                      andRelogonOnFailure:(BOOL)relogon
              andNotifyOfRemoteDataUpdate:(BOOL)notify
                       andCompletionBlock:(ServerInfoCompletionBlock)completionBlock;

- (id) initWithLogonInfo:(NSDictionary *) logonInfo andBlockForPeriodicFetching:(ServerInfoCompletionBlock) completionBlock;

@end

NS_ASSUME_NONNULL_END
