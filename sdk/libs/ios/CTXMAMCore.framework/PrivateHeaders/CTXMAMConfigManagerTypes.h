//
//  CTXMAMConfigManagerTypes.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 8/31/18.
//  Copyright © 2018 - 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMConfigManagerTypes_h
#define CTXMAMConfigManagerTypes_h

/** Defines the callback signature for CTXMAMConfigManager event callbacks. */
typedef void (^CTXMAMConfigManagerEventBlock)(bool bSuccess);

typedef NS_ENUM(NSUInteger, CTXMAMPolicyMode)
{
    CTXMAMPoliciesMode_NotSet = 0,
    CTXMAMPoliciesMode_PremiumDefaultPoliciesXML,
    CTXMAMPoliciesMode_Unrestricted,
    CTXMAMPoliciesMode_XenMobile,
    CTXMAMPoliciesMode_Intune
};

typedef NS_ENUM(NSUInteger, DataEncryptionValue)
{
    DataEncryption_On = 0,                          //ENUM_VALUE_DATAENCRYPTION_ON
    DataEncryption_Off,                             //ENUM_VALUE_DATAENCRYPTION_OFF
    DataEncryption_Fips                             //ENUM_VALUE_DATAENCRYPTION_FIPS
};

typedef NS_ENUM(NSUInteger, EncryptionkeyValue)
{
    EncryptionKeysOnline = 0,                       //VALUE_ENCRYPTION_KEYS_ONLINE
    EncryptionKeysOffline,                          //VALUE_ENCRYPTION_KEYS_OFFLINE
    EncryptionKeysSecureOffline                     //VALUE_ENCRYPTION_KEYS_SECURE_OFFLINE
};

typedef NS_ENUM(NSUInteger, DataProtectionClass)
{
    DataProtectionClass_None = 0,                   //DATAPROTECTIONCLASS_NONE
    DataProtectionClass_Complete,                   //DATAPROTECTIONCLASS_COMPLETE
    DataProtectionClass_CompleteUnlessOpen,         //DATAPROTECTIONCLASS_COMPLETEUNLESSOPEN
    DataProtectionClass_UntilFirstUnlock            //DATAPROTECTIONCLASS_UNTILFIRSTUNLOCK
};

typedef NS_ENUM(NSUInteger, EncryptSecretsValue)
{
    EncryptSecretsUsingPasscode_Off = 0,            //ENUM_VALUE_ENCRYPT_SECRETS_USING_PASSCODE_OFF
    EncryptSecretsUsingPasscode_Server,             //ENUM_VALUE_ENCRYPT_SECRETS_USING_PASSCODE_SERVER
};

typedef NS_ENUM(NSUInteger, NetworkAccessValue)
{
    NetworkAccess_Blocked = 0,                      //ENUM_VALUE_NETWORKACCESS_BLOCKED
    NetworkAccess_Unrestricted,                     //ENUM_VALUE_NETWORKACCESS_UNRESTRICTED
    NetworkAccess_Tunneled                          //ENUM_VALUE_NETWORKACCESS_TUNNELED
};

typedef NS_ENUM(NSUInteger, VpnMode)
{
    VpnMode_FullVpn = 0,                            //ENUM_VALUE_VPNMODE_FULLVPN
    VpnMode_SecureBrowse                            //ENUM_VALUE_VPNMODE_SECURE_BROWSE
};

typedef NS_ENUM(NSUInteger, AppContainmentType)
{
    AppContainment_Unrestricted = 0,
    AppContainment_Blocked,
    AppContainment_SecurityGroups,
    AppContainment_ManagedApps
};

typedef NS_ENUM(NSUInteger, MailComposeType)
{
    MailCompose_Blocked = 0,
    MailCompose_UseNative,
    MailCompose_UseWorxMail
};

typedef NS_ENUM(NSUInteger, CtxAnalyticsDetail)
{
    AnalyticsDetail_Complete = 0,
    AnalyticsDetail_Anonymous,
    AnalyticsDetail_Disabled
};

typedef NS_ENUM(NSUInteger, ExplicitLogoffType)
{
    ExplicitLogon_Enabled = 0,
    ExplicitLogon_Disabled,
    ExplicitLogon_SharedDevicesOnly
};

typedef NS_ENUM(NSUInteger, GatewayType)
{
    GatewayType_None = 0,
    GatewayType_NSG = 1,
    GatewayType_NGS = 2
};

typedef NS_ENUM(NSUInteger, CtxReachabilityResult)
{
    CtxReachability_TunnelDown = 0,         // VPN Tunnel Down
    CtxReachability_Tunneled,               // Use VPN Tunnel
    CtxReachability_Direct                  // Use Direct Connection
};

#endif /* CTXMAMConfigManagerTypes_h */
