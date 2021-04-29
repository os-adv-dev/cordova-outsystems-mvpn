//
//  CTXMAMClientPropertiesRequest.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 4/3/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMClientPropertiesRequest : NSObject

+(void)requestClientPropertiesFromServerWithLoginInfo:(NSDictionary *)logonInfo
                                   andCompletionBlock:(void(^)(BOOL bSuccess, NSDictionary * clientProperties, NSError * error)) block;

@end

NS_ASSUME_NONNULL_END
