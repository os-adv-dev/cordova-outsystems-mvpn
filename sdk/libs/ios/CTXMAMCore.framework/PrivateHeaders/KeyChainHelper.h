//
//  KeyChainHelper.h
//  To use keychain service store encrypted info - 
//  1. create app.entitlements during build and define keychain-access-groups, use a unique
//     service name and key name with KeyChainHelper to access/update the keychain item.
//  2. to share key chain among multiple apps, add a common group to the app.entitlement
//     and use that group name when calling [KeyChainHelper initWithServiceName:andGroupName:].
//     Note: all apps need to have the same apple prefix in the app id in order to share keychain data.
//
//  Created on 1/25/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#if 0
#import <Foundation/Foundation.h>

//Sample servie/access group/key names
#define SERVICE_NAME_1  @"com.citrix.mam.sson"
#define ACCESS_GROUP @"7J776C78NF.WrappedAppAccount"  
#define COOKIE_NAME @"cookie"  //key name for kc item

@interface KeyChainHelper : NSObject

@property (strong, nonatomic) NSString *serviceName;
@property (strong, nonatomic) NSString *accessGroup;

//set accessGroup to nil if keychain is not shared among multiple apps
- (id) initWithServiceName:(NSString *) serviceName
              andGroupName:(NSString *) accessGroup;

- (BOOL) setKeyChainValue:(NSString *)value forKey:(NSString *) key;
- (NSData *) getKeyChainDataForKey:(NSString *) key;
- (NSString *) getKeyChainValueForKey:(NSString *) key;
- (void) deleteKeyChainItemForKey:(NSString *) key;

@end
#endif
