//
//  CTXMAMKeychainInterface.h
//  TestKeyChain
//
//  Created on 2/22/11.
//  Copyright © 2011 - 2019 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

extern NSString * const CERT_ID;
extern NSString * const CERT_NAME;
extern NSString * const CERT_USER;
extern NSString * const KEYCHAIN_MARKER;
extern NSString * const kCitrixAGCertificateLabel1;


@interface CTXMAMKeychainInterface : NSObject {
    id                      type_;
    NSString *              account_;
    NSData *                key_;
    NSDictionary *          keyChainErrors;
    NSMutableDictionary *   keyChainPasswordTypePrototype;
    NSMutableDictionary *   keyChainKeyTypePrototype;
    NSMutableDictionary *   localKeyChainKeyTypePrototype;
    NSMutableDictionary *   wildcardKeyChainKeyTypePrototype;
    NSMutableDictionary *   keyChainIdentityTypePrototype;
    NSMutableDictionary *   keyChainCertificateTypePrototype;
}

@property (nonatomic, strong) id            type;
@property (nonatomic, strong) NSString *    account;
@property (nonatomic, strong) NSData *      key;

+ (CTXMAMKeychainInterface *)keychainInterface;
+ (CTXMAMKeychainInterface *)keychainInterface:(CFTypeRef)secAttributeType;
+ (CTXMAMKeychainInterface *)sharedInstance;

// Add SFKeychain Equivalents

- (BOOL)addPassword:(NSString *)password forAccount:(NSString *)account;
- (BOOL)deletePasswordForAccount:(NSString *)account;
- (NSString *)passwordForAccount:(NSString *)account;

- (BOOL)setKeyChainValue:(NSString *)val
                  forKey:(NSString *)key
          andServiceName:(NSString *)serviceName
          andAccessGroup:(NSString *)accessGroup;

- (BOOL)setKeyChainValue:(NSString *)val
                  forKey:(NSString *)key
          andServiceName:(NSString *)serviceName;

- (BOOL)setKeyChainValue:(NSString *)val
                  forKey:(NSString *)key;

- (BOOL)removeKeyChainEntryForKey:(NSString *)key;

- (BOOL)removeKeyChainEntryForKey:(NSString *)key
                   andServiceName:(NSString *)serviceName;

- (BOOL)removeKeyChainEntryForKey:(NSString *)key
                   andServiceName:(NSString *)serviceName
                   andAccessGroup:(NSString *)accessGroup;

- (NSString *)getKeyChainValueForKey:(NSString *)key;

- (NSString *)getKeyChainValueForKey:(NSString *)key
                      andServiceName:(NSString *)serviceName;

- (NSString *)getKeyChainValueForKey:(NSString *)key
                      andServiceName:(NSString *)serviceName
                      andAccessGroup:(NSString *)accessGroup;

- (BOOL)addData:(NSData *)data forName:(NSString *)vaultName inAccessGroup:(NSString *)group forServiceName:(NSString *)serviceName accessibleAttribute:(CFTypeRef)secAttrAccessibleType error:(NSError *__autoreleasing *)error;
- (NSData *)getData:(NSString *)vaultName accessGroup:(NSString *)accessGroup serviceName:(NSString *)serviceName accessibleAttribute:(CFTypeRef)secAttrAccessibleType error:(NSError **)error;
- (BOOL)deleteData:(NSString *)vaultName accessGroup:(NSString *)accessGroup serviceName:(NSString *)serviceName accessibleAttribute:(CFTypeRef)secAttrAccessibleType error:(NSError **)error;

- (OSStatus)addCertificate:(NSData *)certificateData withLabel:(NSString *)label forPassword:(NSString *)password;
- (NSDictionary *)certInfoforCertLabel:(NSString *)label;
- (OSStatus)deleteCertificateForCertLabel:(NSString *)certLabel;
- (NSArray *)certificateAndIdentity:(SecIdentityRef *)identityRef forCertId:(NSData *)certId;
- (NSArray *)certificateArray;
- (BOOL)certExistsWithLabel:(NSString *)label;

- (NSData *)createKeyForAES128;
- (BOOL)addKey:(NSData *)key forAccount:(NSString *)account;
- (BOOL)deleteKeyForAccount:(NSString *)account;
- (NSData *)keyForAccount:(NSString *)account;

- (NSMutableDictionary *)readAttributesForItem:(NSDictionary *)item;
- (NSMutableDictionary *)getKeyChainKeyTypePrototype;
- (NSMutableDictionary *)getKeyChainPasswordTypePrototype;
- (NSDictionary *)getKeychainErrors;

- (NSArray *)allItems;


//- (void) printAllItems;

// get cert expiry
- (BOOL) checkIfCertExpired:(NSData *) p12Data password:(NSString *) password;
- (BOOL) checkIfCertWillExpireWithX509Data:(NSData *) x509Data withinDays:(int) remainingDays;

//Utility functions
+ (NSString *)getBundleSeedIDFromKeychainQuery;
+ (NSString *)getLocalAccessGroupFromKeychainQuery;

@end
