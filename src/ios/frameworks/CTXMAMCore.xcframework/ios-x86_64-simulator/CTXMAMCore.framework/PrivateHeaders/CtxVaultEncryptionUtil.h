//
//  CtxVaultEncryptionUtil.h
//  MAMSharedLib
//
//  Created by Jessie Qiu on 2/28/14.
//  Copyright © 2014 - 2019 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CTXMAMDataStorage.h"

#define KEY_VAULT_KEY_NAME                  @"citrix.generickeyvault.salt"
#define KEY_VAULT_NAME                      @"citrix.generickeyvault.v1"

#define KEY_SIMPLE_KEY_NAME                 @"citrix.generickeyvault.simple"


@interface CtxVaultEncryptionUtil : NSObject

+ (NSData *) EncryptData: (NSData *) clearData withKey: (NSData *) encryptionKey;
+ (NSData *) DecryptData: (NSData *) encryptedData withKey: (NSData *) encryptionKey withDataLen: (int) dataLen;
+ (NSString *) encryptPasswordStringInMemory:(NSString *) password usingKey: (NSData *) encryptionKey;
+ (NSString *) decryptPasswordStringInMemory:(NSString *) encryptedPassword usingKey: (NSData *) encryptionKey;
+ (NSData *) ArchiveVaultItem: (NSDictionary *) vaultItemDictionary;
+ (NSDictionary *) UnarchiveVaultItem: (NSData *) vaultItemData;
+ (NSData *) encryptKeychainData: (NSData *) plaintext  encryptionKey: (NSData *) keyValue;
+ (NSData *) decryptKeychainData: (NSData *) ciphertext encryptionKey: (NSData *) keyValue;

+ (NSString *)generateEncryptionSeed;
+ (NSData *)getEncryptionKeyUsingStorageName:(NSString *)storageName andStorageType:(CTXMAMStorageType)storageType andAccessGroup:(NSString *)accessGroup;
+ (void)deleteEncryptionSeedFromKeychainForVaultName:(NSString *)vaultName andAccessGroup:(NSString *)accessGroup allowBackgroundAccess:(BOOL)allowbackgroundAccess;


@end
