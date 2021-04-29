//
//  CtxVaultEncryptionUtil.h
//  MAMSharedLib
//
//  Created by Jessie Qiu on 2/28/14.
//  Copyright © 2014 - 2019 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define KEY_VAULT_KEY_NAME                  @"citrix.generickeyvault.salt"
#define KEY_VAULT_NAME                      @"citrix.generickeyvault.v1"

#define KEY_SIMPLE_KEY_NAME                 @"citrix.generickeyvault.simple"


@interface CtxVaultEncryptionUtil : NSObject

+ (NSData *) EncryptData: (NSData *) clearData withKey: (NSData *) encryptionKey;
+ (NSData *) DecryptData: (NSData *) encryptedData withKey: (NSData *) encryptionKey withDataLen: (int) dataLen;
+ (NSData *) EncryptDataWithRandomHeader: (NSData *) clearData withKey: (NSData *) encryptionKey;
+ (NSData *) DecryptDataWithRandomHeader: (NSData *) encryptedData withKey: (NSData *) encryptionKey withDataLen: (int) dataLen;
+ (NSString *) encryptPasswordStringInMemory:(NSString *) password usingKey: (NSData *) encryptionKey;
+ (NSString *) decryptPasswordStringInMemory:(NSString *) encryptedPassword usingKey: (NSData *) encryptionKey;
+ (NSData *) ArchiveVaultItem: (NSDictionary *) vaultItemDictionary;
+ (NSDictionary *) UnarchiveVaultItem: (NSData *) vaultItemData;
+ (NSData *) GetPBKDF2Hash: (NSData *) key andSalt: (NSData *) salt withIteration: (int) iterationCount;
+ (NSData *) GetSHA256Hash: (NSData *) key andSalt: (NSData *) salt;
+ (NSData *) CreateFinalVaultKeyWithEntropy: (NSData *) entropyKey andSalt: (NSData *) salt;
+ (NSData *) CreateUserEntropyHash: (NSString *) password withSalt: (NSData *) salt;
+ (NSData *) CreateUserEntropyKeyWithHash: (NSData *) entropyHash withSalt: (NSData *) salt;
+ (NSData *) GenerateVaultSalt;
+ (NSData *) GetSimpleDeterministicKey;
+ (NSData *) GenerateDeterministicUniqueKey;
+ (void) InvalidateKeyVaultKeysInMemory;
+ (NSData *) GetKeyVaultKey;
+ (NSString *) GenerateVaultNameHash: (NSString *) vaultName error: (NSError **) error;
+ (NSString *) GenerateVaultNameHashV2: (NSString *) vaultName error: (NSError **) error;
+ (NSData *) encryptKeychainData: (NSData *) plaintext  encryptionKey: (NSData *) keyValue;
+ (NSData *) decryptKeychainData: (NSData *) ciphertext encryptionKey: (NSData *) keyValue;

@end
