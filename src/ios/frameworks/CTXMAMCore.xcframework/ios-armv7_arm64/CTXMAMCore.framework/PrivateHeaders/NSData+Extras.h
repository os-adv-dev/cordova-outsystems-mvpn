//
//  NSData+Extras.h
//  CTXMAM_WrappedAppLib
//
//  Created by Chris Pavlou on 11/30/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <openssl/bn.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/buffer.h>
#include <err.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Extras)

@property (assign, readonly) NSUInteger unencryptedLength;

/**
 * Compress the receiver's contents.
 * @return A new NSData object with the receiver's contents compressed.
 */
- (nullable NSData *)compress;

/**
 * Returns a new NSData object which contains the SHA256 hash of the data represented this NSData object.
 * @return A new NSData object which contains the SHA256 hash of the data represented this NSData object, if an error occurs the result is nil.
 */
- (nullable NSData *)SHA256Hash;

/**
 * Returns a NSString object which contains a base64 encoded string of the SHA256 hash of the data represented this NSData object.
 * @return A NSString object which contains a base64 encoded string of the SHA256 hash of the data represented this NSData object, if an error occurs the result is nil.
 */
- (nullable NSString *)base64EncodedStringForSHA256Hash;

/**
 * Returns a new NSData object with encrypted bytes by the block AES algorithm
 * @param keyData The encryption key which needs to be used in order to encrypt the data contained in this data object. Key must be at least 32 bytes (256 bits) long, if the key is less than 32 bytes then the data will not be encrypted and the result will be nil, if the key is longer than 32 bytes only the first 32 bytes will be used and the remainder of the key will be ignored.
 * @param pageNo The page number to use with the intialization vector.
 * @return new NSData object with encrypted bytes with Block AES algorithm, this new data object will have it's encrypted property set to YES and the unecrypted size set to the original data size, if an error occurs the result is nil.
 */
- (nullable NSData *)encryptBlockAESWithKey:(NSData *)keyData andPageNumber:(NSUInteger)pageNo;

/**
 * Returns a new NSData object with decrypted bytes by the block AES algorithm
 * @param keyData The encryption key which needs to be used in order to encrypt the data contained in this data object. Key must be at least 32 bytes (256 bits) long, if the key is less than 32 bytes then the data will not be encrypted and the result will be nil, if the key is longer than 32 bytes only the first 32 bytes will be used and the remainder of the key will be ignored.
 * @param pageNo The page number to use with the intialization vector.
 * @return new NSData object with decrypted bytes with Block AES algorithm, this new data object will have it's encrypted property set to NO and the unecrypted size set to zero, if an error occurs the result is nil.
 */
- (nullable NSData *)decryptBlockAESWithKey:(NSData *)keyData andPageNumber:(NSUInteger)pageNo;

/**
 * Returns a new data object with the specified encrypted bytes, length and original length specified.
 * @param bytes The bytes which have been previously encrypted with the encryptBlockAESWithKey:andPageNumber: selector.
 * @param length The amount of bytes contained within the bytes array.
 * @param originalLength The amount of bytes which that the original unencrypted data object had.
 */
+ (nullable instancetype) dataWithEncryptedBytes:(nullable const void *)bytes length:(NSUInteger)length andOriginalLength:(NSUInteger)originalLength;

@end

NS_ASSUME_NONNULL_END
