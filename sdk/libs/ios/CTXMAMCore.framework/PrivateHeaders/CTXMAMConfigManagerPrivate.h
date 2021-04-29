//
//  CTXMAMConfigManagerPrivate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/18/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import "CTXMAMConfigManager.h"
#import "CTXMAMConfigManagerTypes.h"
#import "CTXMAMConfigurationProvider.h"

#ifndef CTXMAMConfigManagerPrivate_h
#define CTXMAMConfigManagerPrivate_h

typedef NS_ENUM(NSUInteger, CTXMAMVaultType)
{
    Vault_Default = 0,
    Vault_PerApp,
    Vault_Shared,
    Vault_Auth,
    Vault_PublicShared,
    Vault_CWAShared
};

@interface CTXMAMConfigManager()

@property (readonly)        CTXMAMPolicyMode        policyMode;

@property (readonly)        BOOL                    loggedOn;
@property (readonly)        NSString *              packageID;

//Log Settings related policies
@property (readonly)        BOOL                    initialized;
@property (readonly)        NSDictionary *          hubLogonInfo;
@property (readonly)        NSDictionary *          hubAppInfo;
@property (readonly)        NSDictionary *          xmsClientProperties;
@property (readonly)        NSDictionary *          xmsAppInfo;
@property (readonly)        NSDictionary *          xmsPolicyInfo;

//Setters
-(BOOL) set_policyMode:                     (CTXMAMPolicyMode)      value;
-(BOOL) set_hubLogonInfo:                   (NSDictionary *)        value;
-(BOOL) set_hubAppInfo:                     (NSDictionary *)        value;
-(BOOL) set_xmsClientProperties:            (NSDictionary *)        value;
-(BOOL) set_xmsAppInfo:                     (NSDictionary *)        value;

/*!
 Allows application to assign a call back function which gets called when the CTXMAMConfigManager singleton finishes initializing.
 @param eventBlock The pointer to the block which will be executed after initialization is complete.
 */
+(void) registerForInitializationCallBack: (CTXMAMConfigManagerEventBlock) eventBlock;
-(void) registerConfigurationProvider:(id<CTXMAMConfigurationProvider>) configProvider;
-(void) initializeConfigurationProviders;
-(void) refreshConfiguration;
-(void) performCleanUp:(BOOL) fullCleanUp;

-(NSString *)     getConfigAsStringForKey:     (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (NSString *)     defaultValue outError: (NSError **) error;
-(NSNumber *)     getConfigAsNumberForKey:     (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (NSNumber *)     defaultValue outError: (NSError **) error;
-(NSData *)       getConfigAsDataForKey:       (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (NSData *)       defaultValue outError: (NSError **) error;
-(NSDictionary *) getConfigAsDictionaryForKey: (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (NSDictionary *) defaultValue outError: (NSError **) error;
-(NSInteger)      getConfigAsIntegerForKey:    (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (NSInteger)      defaultValue outError: (NSError **) error;
-(double)         getConfigAsDoubleForKey:     (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (double)         defaultValue outError: (NSError **) error;
-(BOOL)           getConfigAsBoolForKey:       (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (BOOL)           defaultValue outError: (NSError **) error;
-(id)             getConfigAsIdForKey:         (NSString *) config fromVault: (CTXMAMVaultType) vault defaultValue: (id)             defaultValue outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault stringValue:  (NSString *)     stringValue  outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault numberValue:  (NSNumber *)     numberValue  outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault dataValue:    (NSData *)       dataValue    outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault dictValue:    (NSDictionary *) dictValue    outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault intValue:     (NSInteger)      intValue     outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault doubleValue:  (double)         doubleValue  outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault boolValue:    (BOOL)           boolValue    outError: (NSError **) error;
-(BOOL)           setConfigForKey:             (NSString *) config toVault:   (CTXMAMVaultType) vault idValue:      (id)             idValue      outError: (NSError **) error;
-(id)             removeConfigForKey:          (NSString *) config fromVault: (CTXMAMVaultType) vault outError:     (NSError **)     error;

@end

#endif /* CTXMAMConfigManagerPrivate_h */
