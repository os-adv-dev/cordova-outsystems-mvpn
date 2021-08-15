//
//  CTXMAMDataStorage.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 6/3/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMConfigManagerPrivate.h"

#define SHARED_VAULT_KC_VAULTDATA               @"VaultData"
#define SHARED_VAULT_KC_UPDATED_BY_APP          @"UpdatedByApp"
#define SHARED_VAULT_KC_UPDATE_TIMESTAMP        @"UpdateTimestamp"
#define SHARED_VAULT_KC_UPDATE_SEQUENCE_NUM     @"UpdateSequenceNumber"

static NSErrorDomain _Nonnull CTXMAMStorageErrorDomain = @"CTXMAMDataStorageError";

typedef NS_ENUM(NSUInteger, CTXMAMStorageError)
{
    CTXMAMStorageError_Unknown                      = 90000,
    CTXMAMStorageError_AppInBackground              = 90001,
    CTXMAMStorageError_StorageNameNotSet            = 90002,
    CTXMAMStorageError_StorageNotInitialized        = 90003,
    CTXMAMStorageError_DataToBeSavedIsNil           = 90004,
    CTXMAMStorageError_ErrorFromUnderlyingSystem    = 90005,
    CTXMAMStorageError_ValueSpecifiedIsNull         = 90006,
    CTXMAMStorageError_ValueNotFound                = 90007,
    CTXMAMStorageError_KeychainDataIsCorrupted      = 90008,
    CTXMAMStorageError_MigrationHasAlreadyOcurred   = 90009
};

typedef NS_ENUM(NSUInteger, CTXMAMStorageType)
{
    CTXMAMStorageLocal = 1,
    CTXMAMStorageShared
};

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMDataStorage : NSObject

@property (nonatomic, assign) BOOL                  requiresEncryption;
@property (nonatomic, assign) CTXMAMStorageType     storageType;
@property (strong, nonatomic, nullable) NSString *  name;
@property (nonatomic, assign) BOOL                  allowAccessInBackground;

- (id)init NS_UNAVAILABLE;
- (id)initWithStorageName:(nullable NSString *)storageName andStorageType:(CTXMAMStorageType)storagetype andAllowBackgroundAccess:(BOOL)bAllowBackgroundAccess andRequiresEncryption:(BOOL)requiresEncryption outError:(NSError **) err;
- (nullable id)getDataAsObjectForKey:(NSString *)key outError:(NSError **)err;
- (nullable id)removeDataForKey:(NSString *)key outError:(NSError **)err;
- (BOOL)setDataForKey:(NSString *)key objectValue:(id)objectValue outError:(NSError **)err;
/*!
 * @brief This call requests the class to perform I/O operation saving the current data residing in the Data Store class into the keychain.
 * This should only be called if you need to save the changes to the keychain immediately and will be performed asynchronously.
 * This call is called automatically prior to the application going into background and prior to application terminating.
 * In order to prevent unnecessary I/O operations DO NOT call this function unless absolutly necessary.
 * @param completionBlock The block to run once the synchronization operation is complete.
 * Check the nilOrError parameter in order to find out if the operation succeeded, if nilOrError is nil it means success.
 */
- (void)saveDataToKeychainAsyncWithCompletionBlock:(nullable void (^)(NSError * _Nullable nilOrError))completionBlock;
/*!
 * @brief This call requests the class to perform I/O operation saving the current data residing in the Data Store class into the keychain.
 * This should only be called if you need to save the changes to the keychain immediately and will be performed synchronously.
 * This call will block the current thread until all other read and write operations are done, and will block all read and write operations while it is being performed.
 * In order to prevent unnecessary I/O operations DO NOT call this function unless absolutely necessary, since the data store is automatically saved after a specific number of changes and
 * during lifecycle events.
 * @param error A pointer to a NSError object which will receive the error which happens during the save process if one occurs, if there are no errors during the data saving process this parameter is unchanged.
 */
- (BOOL)saveDataToKeychainSynchronouslyWithError:(NSError **)error;
- (void)deleteStorage;
@end

NS_ASSUME_NONNULL_END
