//
//  CtxMAMEncoder.h
//  Symmetric encryption library
//
//  Created by Zhongmin Lang on 2/24/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <Security/Security.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>

// The chosen symmetric key and digest algorithm is AES and SHA1 - iPhone and iPod touch have
// hardware accelerators for those particular algorithms and therefore are energy efficient.

#define kChosenCipherBlockSize	kCCBlockSizeAES128
#define kChosenCipherKeySize	kCCKeySizeAES128
#define SHA256_DIGEST_LENGTH    32

@interface CTXMAMEncoder : NSObject

@property (strong, nonatomic) NSString* key;

- (id) initWithKey:(NSString *)key;
- (NSData *) encryptString:(NSString*) text;
- (NSData *) encryptData:(NSData *) data;
- (NSData *) decryptData:(NSData *) data;

- (NSString *) dataToString:(NSData *) data;


@end
