//
//  CtxEncryptionHelper.h
//  CTXMAM_WrappedAppLib
//
//  Created on 11/20/14.
//  Copyright © 2014 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CtxEncryptionHelper : NSObject

@property (nonatomic,strong)    NSString *encryptionKey;

+ (CtxEncryptionHelper *)sharedInstance;
- (NSData *)decryptData:(NSData *)cypherText;
- (NSData *)encryptData:(NSData *)clearText;
- (id)decryptValue:(NSData *)cypherText;
- (id)decryptValue:(NSData *)cypherText coercedWithPasteboardType:(NSString *)pasteboardType;
- (id)decryptData:(NSData *)cypherText coercedWithPasteboardType:(NSString *)pasteboardType;
+ (id)coerceValue:(id)value withPasteboardType:(NSString *)pasteboardType;
+ (id)coerceData:(id)value withPasteboardType:(NSString *)pasteboardType;
- (NSData *)encryptValue:(id)value;
- (NSString *)md5OfFileAtPath:(NSString *)file;

@end



