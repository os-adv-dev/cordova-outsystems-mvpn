//
//  CtxSharedKeychainVault.h
//  MAMSharedLib
//
//  Created by Jaspreet Singh on 6/20/16.
//  Copyright © 2016 - 2019 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

enum CtxSharedVaultError
{
    CtxSharedVaultError_NoError             = 0,
    CtxSharedVaultError_VaultNotFound		= 5101,
    CtxSharedVaultError_VaultUnreadable		= 5102,
    CtxSharedVaultError_VaultDataMismatch	= 5111,
    CtxSharedVaultError_InvalidInput		= 5121
} ;

extern NSString *const kCtxSharedVaultErrorDomain;



@protocol CtxSharedKeychainVaultProtocol

@required
/// Methods to override
-(NSData*) getDataFromVault:(NSString*)vaultName accessGroup:(NSString*)accessGroup serviceName:(NSString*)serviceName secAttrAccessible:(CFTypeRef)secAttrAccessible error:(NSError**)error;

-(BOOL) saveData:(NSData*)data inVault:(NSString*)vaultName accessGroup:(NSString*)accessGroup serviceName:(NSString*)serviceName secAttrAccessible:(CFTypeRef)secAttrAccessible error:(NSError**)error;

-(BOOL) deleteVault:(NSString*)vaultName accessGroup:(NSString*)accessGroup serviceName:(NSString*)serviceName error:(NSError**)error;

-(NSDictionary*) optionalVaultDictionaryItems;

@end



@interface CtxSharedKeychainVault : NSObject<CtxSharedKeychainVaultProtocol>

@property(nonatomic,readonly,strong) NSString* vaultName;
@property(nonatomic,readonly,strong) NSString* accessGroup;

@property(nonatomic,readonly) BOOL exists;
@property(nonatomic,readonly) BOOL isAccessible;
@property(nonatomic,readonly) BOOL isVaultDataLoaded;
@property(nonatomic,readonly) NSInteger loadedDataSequenceNumber;
@property(nonatomic,readonly,strong) NSError* lastError;

@property(nonatomic,strong) NSMutableDictionary * vaultData;

- (instancetype) initWithVaultName:(NSString*)vaultName accessGroup:(NSString *)accessGroup;

- (instancetype) initWithVaultName:(NSString*)vaultName serviceName:(NSString*)serviceName accessGroup:(NSString*)accessGroup andLoadData:(BOOL)loadData;

- (instancetype) initWithVaultName:(NSString*)vaultName serviceName:(NSString*)serviceName accessGroup:(NSString*)accessGroup encryptionKey:(NSData*)encryptionKey;

- (instancetype) initWithVaultName:(NSString*)vaultName
                       serviceName:(NSString*)serviceName
                       accessGroup:(NSString*)accessGroup
                     encryptionKey:(NSData*)encryptionKey
                       andLoadData:(BOOL)loadData;


// Need to call only when loadData=NO in the instantization
-(void) checkVaultAccessAfterLoadingData;


// To load fresh/updated data from the vault
-(BOOL) loadDataWithError:(NSError *__autoreleasing *)error;


/// To commit changes to vault...
-(BOOL)synchronizeWithError:(NSError *__autoreleasing *)error;
-(BOOL)forceSynchronizeWithError:(NSError *__autoreleasing *)error;


-(BOOL)updateAndSynchronizeVaultItem:(NSString*)vaultItem withValue:(id)itemValue error:(NSError *__autoreleasing *)error;
-(BOOL)updateAndSynchronizeVaultItems:(NSDictionary*)vaultItems error:(NSError *__autoreleasing *)error;


/// To remove vault
-(BOOL) deleteVaultWithError:(NSError *__autoreleasing *)error;

@end
