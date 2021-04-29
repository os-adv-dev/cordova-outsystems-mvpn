//
//  CTXMAMDataStorage.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 6/3/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManagerPrivate.h"

typedef NS_ENUM(NSUInteger, CTXMAMStorageType)
{
    CTXMAMStorageNotSet = 0,
    CTXMAMStorageLocal,
    CTXMAMStorageShared
};

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMDataStorage : NSObject

@property (nonatomic, assign) CTXMAMPolicyMode policyMode;
@property (nonatomic, assign) CTXMAMStorageType storageType;
@property (strong, nonatomic, nullable) NSString * name;

- (id) initWithStorageName: (nullable NSString *) storageName andStorageType: (CTXMAMStorageType) storagetype outError:(NSError **) err;
- (id) initWithPolicyMode: (CTXMAMPolicyMode) policyMode name: (nullable NSString *) storageName andStorageType: (CTXMAMStorageType) storagetype outError:(NSError **) err;
- (id) getDataAsObjectForKey: (NSString *) key outError:(NSError **) err;
- (nullable id) removeDataForKey: (NSString *) key  outError:(NSError **) err;
- (BOOL) setDataForKey: (NSString *) key objectValue: (id) objectValue outError:(NSError **) err;
- (BOOL) setDataForKey: (NSString *) key objectValue: (id) objectValue syncNow:(BOOL)syncNow outError:(NSError **) err;

- (BOOL) syncDataWithError:(NSError **)err;

- (void) deleteStorage;

@end

NS_ASSUME_NONNULL_END
