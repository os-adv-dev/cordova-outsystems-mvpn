//
//  CtxSharedVaultCommon.h
//  MAMSharedLib
//
//  Created by Jessie Qiu on 2/20/15.
//  Copyright © 2015 - 2019 Citrix Systems Inc. All rights reserved.
//

//TODO: Explicit SDK - Merge CtxSharedVaultCommon with CTXMAMSharedVaultConstants

#ifndef MAMSharedLib_CtxSharedVaultCommon_h
#define MAMSharedLib_CtxSharedVaultCommon_h

#define CtxSharedVaultErrorDomain                   @"com.citrix.sharedvault.ErrorDomain"
#define CtxVaultErrorDomain                         @"com.citrix.vault.ErrorDomain"

typedef enum _CtxSharedVaultErrorCode {
    CtxSharedVaultInvalidDecoder = 1,
    CtxSharedVaultInvalidEncryptor,
    CtxSharedVaultNoData,
    CtxSharedVaultNoSalt,
    CtxSharedVaultLocked,
    CtxSharedVaultKeyError,
    CtxSharedVaultInvalidKey,
    CtxSharedVaultGenericError
} CtxSharedVaultErrorCode;

typedef enum _CtxVaultErrorCode {
    CtxVaultErrorAlreadyExists = 1,
    CtxVaultErrorDoesNotExist,
    CtxVaultVersionMismatched,
    CtxVaultErrorInvalidKey,
    CtxVaultErrorEncryptionFailure,
    CtxVaultGenericError
} CtxVaultErrorCode;

#define UNMANAGED_CONTAINER_NAME                    @"CitrixMDXData1"
#define SSORECORD_NAME                              @"CitrixMDXData2"
#define SSO_ENCRYPTED_VAULT_NAME                    @"CitrixMDXData3"
#define SSO_ENCRYPTED_DYNAMIC_VAULT_NAME            @"CitrixMDXData5"
#define SHARED_VAULT_NAME                           @"CitrixMDXData4"

#define UNMANAGED_CONTAINER_ENCODER                 @"CitrixUnmanagedContainerEncoder"
#define SSORECORD_ENCODER                           @"CitrixSSORecordEncoder"


// common items in all containers
//#define SHARED_VAULT_VERSION_NAME                 @"DataVersion"
//#define SHARED_VAULT_VERSION_1_0                  @"1.0"

//Unmanaged container
#define UNMANAGED_CONTAINER_ITEM_NAME               @"UnmanagedContainer"
#define UNMANAGED_CONTAINER_DYNAMIC_DICT            @"DynamicDictionary"
#define UNMANAGED_CONTAINER_KEYCHAINACCESSGROUP     @"MasterKeychainAccessGroup"
#define UNMANAGED_CONTAINER_DEVICECONFIG            @"DeviceConfiguration"
#define UNMANAGED_CONTAINER_STOREUUID               @"StoreUUID"
#define UNMANAGED_CONTAINER_MOBILEAPPAGGREGATION    @"MobileAppAggregation"
#define UNMANAGED_CONTAINER_SECUREHUBLASTLAUNCHTIME @"SecureHubLastLaunchTime"

//SSOKey encrypted vault
#define kCTXSSO_VAULT_UE_KEK                        @"KeyEncryptedKeys"
#define kCTXSSO_VAULT_GLOBAL_SETTINGS               @"GlobalSettings"
#define kCTXSSO_VAULT_STORE_STATUS                  @"StoreStatus"
#define kCTXSSO_VAULT_PINUI_POLICIES                @"PinUIPolicies"
#define kCTXSSO_VAULT_PIN_STATUS                    @"PinStatus"
#define kCTXSSO_VAULT_APPS_DICT                     @"AppDictionary"
#define kCTXSSO_DEVICEVENDORKEY     			    @"DeviceVendorKey"
#define kCTXSSO_STORE_UUID                          @"StoreUUID"
#define kCTXSSO_DERIVED_CREDENTIALS_VAULT_ENABLED   @"DerivedCredentialsVaultEnabled"

//Feature flag implementation
#define kCTXSSO_DEVICEID_FF                         @"FeatureFlagDeviceId"
#define kCTXSSO_USERID_FF                           @"FeatureFlagUserId"
#define kCTXSSO_CUSTOMERID_FF                       @"FeatureFlagCustomerId"


//SSOKey encrypted dynamic vault
#define SHARED_DATA_LAST_ACTIVITY                   @"LastActivity"
#define SHARED_DATA_LAST_REBOOT                     @"LastReboot"
#define SHARED_DATA_SYSTEM_TIME                     @"SystemTime"
#define LOGONFAILURECOUNT                           @"LOGONFAILURECOUNT"
#define SHARED_DATA_LOCKWIPE_VALUE                  @"lockWipeValue"
#define SHARED_DATA_LOCKWIPE_VALUE_LOCKED           @"LOCKED"
#define SHARED_DATA_LOCKWIPE_VALUE_NONE             @"NONE"
#define SHARED_DATA_LAST_TIME_CHANGE                @"LastTimeChange"
#define SHARED_DATA_TIME_CHANGE_FLAG                @"TimeChangeFlag"
#define SHARED_DATA_TIME_CHANGE_DIFF                @"TimeChangeDiff"
#define LAST_SUCCESSFUL_DEVICE_CHECK_TIMESTAMP      @"lastSuccessfulDeviceCheckTimestamp"
#define SHARED_DATA_CONTAINER_LOCKED                @"ContainerLocked"

// SSOKey encrypted dynamic vault per app dictionary
#define SHARED_DATA_APP_BUNDLE_PACKAGEID            @"PackageID"
#define SHARED_DATA_APP_BUNDLE_APPVERSION           @"AppVersion"
#define SHARED_DATA_APP_BUNDLE_MDXVERSION           @"MdxVersion"

//Shared vault
#define kCTXSSO_VAULT_GENERAL                       @"General"
#define kCTXSSO_VAULT_CERTIFICATE                   @"Certificate"
#define kCTXSSO_USERPASSWORD                        @"SharedData1"

//SSO Record
#define SSORECORD_EXPIRATION                        @"Expiration"
#define SSORECORD_LASTREBOOT                        @"LastReboot"
#define SSORECORD_ENCRYPTED_SHAREDVAULTKEY          @"SharedVaultMetadata"
#define SSORECORD_EXPIRATION_TIMESTAMPHASH          @"ExpirationTimeStampeHash"
#define SSORECORD_LASTREBOOT_TIMESTAMPHASH          @"LastRebootTimeStampeHash"

#define FIPS_KEY_LEN 32

// Access group names
#define CTXSHAREDKEYCHAIN_ACCESSGROUP_MDX           @"com.citrix.mdx"
#define CTXSHAREDKEYCHAIN_ACCESSGROUP_SECUREAPPS    @"com.citrix.SecureApps"
#define CTXSHAREDKEYCHAIN_ACCESSGROUP_DC            @"com.citrixworxhome.CtxCredentialsVault"

// Vault names
#define CTXSHAREDKEYCHAIN_MDXUSERCERTS              @"MdxUserCertificates"
#define CTXSHAREDKEYCHAIN_CREDENTIALS_STORE         @"MdxCredentials"
#define CTXSHAREDKEYCHAIN_DC_VAULT                  @"derived-credential-vault"

// Credential store fields
#define CREDENTIALS_STORE_PASSWORD                  @"password"
#define CREDENTIALS_STORE_CERTDATA                  @"gatewayCertP12"
#define CREDENTIALS_STORE_CERTPASSWORD              @"gatewayCertPassword"

// Service names
#define CTXSHAREDKEYCHAIN_SERVICENAME_DEFAULT       @"CtxSharedService"
#define CTXSHAREDKEYCHAIN_SERVICENAME_DEFAULT_MDX   @"MdxSharedService"

// Derived credential certificate names
#define DC_VAULT_USER_CERT                          @"__enrollment_DC"

// Derived credential certificate field names
#define DC_VAULT_CERT_DATA                          @"CertP12Data"
#define DC_VAULT_CERT_PASSWORD                      @"P12Password"
#define DC_VAULT_CERT_STATUS                        @"CertStatus"
#define DC_VAULT_CERT_ID                            @"CertId"

// Derived credential certificate status
#define DC_VAULT_CERT_STATUS_UNDEFINED              @"Undefined"
#define DC_VAULT_CERT_STATUS_ACTIVE                 @"Active"
#define DC_VAULT_CERT_STATUS_EXIPIRED               @"Expired"
#define DC_VAULT_CERT_STATUS_SUSPENDED              @"Suspended"
#define DC_VAULT_CERT_STATUS_REVOKED                @"Revoked"

#endif
