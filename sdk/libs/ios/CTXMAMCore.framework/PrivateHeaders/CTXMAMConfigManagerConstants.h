//
//  Constants.h
//  XmsConfigurationSdk
//
//  Created by Daniel Romano on 7/27/18.
//  Copyright © 2018 - 2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

/* Network Policy codes */

//==================================

#define CONFIGMGR_APPFIRSTLAUNCH_COMPLETE                            @"MdxCore_FirstLaunchComplete"
#define CONFIGMGR_SHARED_VAULT_NAME                                  @"ConfigManagerSharedVault"
#define CONFIGMGR_SHARED_CWA_VAULT_NAME                              @"ConfigManagerCWASharedVault"
#define CONFIGMGR_PERAPP_VAULT_NAME                                  @"ConfigManagerPerAppVault"
#define CONFIGMGR_AUTH_VAULT_NAME                                    @"ConfigManagerAuthVault"
#define CONFIGMGR_PUBLIC_SHARED_VAULT_NAME                           @"ConfigManagerPublicSharedVault"
#define CONFIGMGR_SHARED_VAULT_ACCESSGROUP                           @"com.citrix.mdx"
#define CONFIGMGR_SHARED_VAULT_SERVICENAME                           @"MdxConfigurationService"
#define CONFIGMGR_SHARED_VAULT_ENCRYPTION_KEY                        @"CitrixSaltANdPepper"
#define CONFIGMGR_SHARED_VAULT_ENCRYPTION_SECONDARY_KEY              @"ffutSyradnoceSroFdesUgnirtSgnoLAsIsihT"
#define CONFIGMGR_SHARED_VAULT_ENCRYPTION_KEY_SIZE_KEY               @"CitrixSaltANdPepperSize"
#define CONFIGMGR_SHARED_VAULT_ENCRYPTION_KEY_SIZE                   256
#define CONFIGMGR_POLICY_AUTO_REFRESH_INTERVAL                       300

#ifndef IOS_RECEIVER

// Crash reporting related policy
#define POLICY_KEY_ENABLE_CRASH_REPORTING                            @"EnableCrashReporting"
#endif


// Geofence

#define POLICY_KEY_GEOFENCELATITUDE                                  @"GeofenceLatitude"
#define DEFAULT_VALUE_GEOFENCELATITUDE                               0.0
#define POLICY_KEY_GEOFENCELONGITUDE                                 @"GeofenceLongitude"
#define DEFAULT_VALUE_GEOFENCELONGITUDE                              0.0
#define POLICY_KEY_GEOFENCERADIUS                                    @"GeofenceRadius"
#define DEFAULT_VALUE_GEOFENCERADIUS                                 0.0

// Google Analytics

#define POLICY_KEY_GOOGLEANALYTICS                                   @"EnableGoogleAnalytics"
#define DEFAULT_VALUE_GOOGLEANALYTICS                                YES

// Analytics Level of Detail
#define CTXS_ANALYTICSDETAIL_COMPLETE                                @"AnalyticsDetailComplete"
#define CTXS_ANALYTICSDETAIL_ANONYMOUS                               @"AnalyticsDetailAnonymous"
#define CTXS_ANALYTICSDETAIL_DISABLED                                @"AnalyticsDetail_Disabled_"    // NOTE: This option is a non-advertised/secret option. We don't want it in the policy definition and don't want it showing up as an option in the UI either.
#define POLICY_KEY_ANALYTICSDETAIL                                   @"AnalyticsDetail"
#define DEFAULT_VALUE_ANALYTICSDETAIL                                CTXS_ANALYTICSDETAIL_COMPLETE

// ExplicitLogoffNotification

#define EXLN_ENABLED                                                 @"Enabled"
#define EXLN_DISABLED                                                @"Disabled"
#define EXLN_SHAREDDEVICES                                           @"Shared devices only"
#define POLICY_KEY_EXPLICITLOGOFFNOTIFICATION                        @"ExplicitLogoffNotification"
#define DEFAULT_VALUE_EXPLICITLOGOFFNOTIFICATION                     EXLN_SHAREDDEVICES


// Intune Intune policies

#define POLICY_KEY_INTUNE_GATEWAYADDRESS                             @"MvpnGatewayAddress"
#define POLICY_KEY_INTUNE_SESSIONREQUIRED                            @"MvpnSessionRequired"
#define POLICY_KEY_MVPN_REDIRECTWEBTRAFFICWITHSSO                    @"MvpnRedirectWebTrafficWithSSO"
#define POLICY_KEY_MVPN_DISABLETCPREDIRECT                           @"MvpnDisableTcpRedirect"

//TODO: Deprecated; remove these later
#define POLICY_KEY_INTUNE_CLIENTID                                   @"MvpnClientIdOverride"
#define POLICY_KEY_INTUNE_WHITELIST                                  @"MvpnWhitelist"


//Citrix Reporting
#define CTXS_REPORTING_OFF                                           @"CitrixReportingOff"
#define CTXS_REPORTING_ON                                            @"CitrixReportingOn"
#define POLICY_KEY_CITRIXREPORTING                                   @"CitrixReporting"
#define DEFAULT_VALUE_CITRIXREPORTING                                CTXS_REPORTING_OFF

#define POLICY_KEY_REPORTING_UPLOADTOKEN                             @"CitrixReportingCustomerUploadToken"
#define DEFAULT_VALUE_REPORTING_UPLOADTOKEN                          @""

#define POLICY_KEY_REPORTING_WIFI                                    @"CitrixReportingWifiOnly"
#define DEFAULT_VALUE_REPORTING_WIFI                                 YES

#define POLICY_KEY_REPORTING_MAXCACHESIZE                            @"CitrixReportingMaxCacheSize"
#define DEFAULT_VALUE_REPORTING_MAXCACHESIZE                         2

//New Settings
#define POLICY_KEY_INACTIVITYTIMER                                   @"storeInactivityTimerPolicy"
#define DEFAULT_VALUE_INACTIVITYTIMER                                60
#define SETTINGS_KEY_SSOKEY                                          @"storeSSOKey"
#define SETTINGS_KEY_RECOVERABLE_ENTROPY                             @"recoverableEntropy"
#define SETTINGS_KEY_APPREGISTERED                                   @"AppRegistered"
#define SETTINGS_KEY_DEVICEID                                        @"deviceId"
#define SETTINGS_KEY_STORESRID                                       @"storeSRID"
#define SETTINGS_KEY_STOREUUID                                       @"storeUUID"
#define SETTINGS_KEY_SHAREDDEVICEMODEENABLED                         @"shareDeviceModeEnabled"
#define SETTINGS_KEY_APPRESOURCEURL                                  @"appResourceURL"
#define SETTINGS_KEY_APPRESOURCETRANSLATEDSURL                       @"appResourceTranslatedURL"
#define SETTINGS_KEY_AUTH_TOKEN                                      @"authToken"
#define SETTINGS_KEY_AUTH_DOMAIN                                     @"authDomain"
#define SETTINGS_KEY_STORE_URL                                       @"storeURL"
#define SETTINGS_KEY_XMS_SERVER_BASE_URL                             @"xmsServerBaseURL"
#define SETTINGS_KEY_HUB_LOGON_INFO                                  @"secureHubLogonInfo"
#define SETTINGS_KEY_HUB_APP_INFO                                    @"secureHubAppInfo"
#define SETTINGS_KEY_XMS_POLICY_INFO                                 @"xmsPolicyInfo"
#define SETTINGS_KEY_XMS_APP_INFO                                    @"xmsAppInfo"
#define SETTINGS_KEY_XMS_CLIENT_PROPS                                @"xmsClientProperties"
#define SETTINGS_KEY_POLICY_MODE                                     @"policyMode"
#define SETTINGS_KEY_LAST_POLICY_FETCH_TIME                          @"lastPolicyFetchTime"

//User Entropy Constants
//TODO: Explicit SDK - User entropy is most likely phased out. Completely remove from project once we move to phase two.
#define KC_PROTECTED_SECRET                                          @"_ProtectedSecret"

// The following values are defined in "protectedsecret" NSDictionary
#define KC_PROTECTED_SECRET_USERENTROPY                              @"UserEntropy"

// The following values are defined in "ProtectedSecret"'s UserEntropy NSDictionary. Not a direct KC item name.
#define KC_PROTECTED_SECRET_USERENTROPY_TYPE                         @"userEntropyType"
#define KC_PROTECTED_SECRET_USERENTROPY_MAX_RETRY                    @"userEntropyMaxRetry"
#define KC_PROTECTED_SECRET_USERENTROPY_USERNAME                     @"userEntropyUsername"
#define KC_PROTECTED_SECRET_USERENTROPY_PINLEN                       @"userEntropyWorxPinLen"
#define KC_PROTECTED_SECRET_USERENTROPY_PINCOMPLEXITY                @"userEntropyPinComplexity"
#define KC_PROTECTED_SECRET_USERENTROPY_RANDOMKEY                    @"userEntropyRandomKey"
#define KC_PROTECTED_SECRET_USERENTROPY_PINVALIDATOR                 @"userEntropyValidator"
#define KC_PROTECTED_SECRET_USERENTROPY_PININCREMENTOR               @"userEntropyIncrementor"

//Intune
# define SHA256_DIGEST_LENGTH    32
#define IntuneStoreUsername                                          @"storeUserName"
#define kIntuneMAMSettings                                           @"IntuneMAMSettings"
#define PKEY_INTUNE_GATEWAYADDRESS                                   @"MvpnGatewayAddress"

#define SETTINGS_KEY_INTUNE_POLICY_INFO                              @"intunePolicyInfo"
#define SDK_INTUNEMANAGEMENOWFLAG                                    @"IntuneManageMe"
#define SETTINGS_KEY_STOREAGBASEURL                                  @"AGBaseURL"
#define START_TUNNELER_REQUESTED                                     @"StartTunnelerRequested"
#define ADAL_ACCESS_TOKEN                                            @"AdalAccessToken"
#define HasPoliciesFromAppConfigChannel                              @"hasPoliciesFromAppConfigChannel"
#define PKEY_POLICYNETWORKACCESS_NEW                                 @"MvpnNetworkAccess"
#endif /* Constants_h */

// SDK Mode Control
#define PKEY_POLICY_SDKMODECONTROL                                   @"SDKModeControl"
#define DEFAULT_SDKMODECONTROL                                       NO

//SSO Defines for server properties
#define SSO_URL_PREFIX                                               @"com.citrix.sso"
#define SSO_APPNAME                                                  @"AppName"
#define SSO_APPPACKAGE_ID                                            @"PackageID"
#define SSO_APPTIMESTAMP                                             @"AppBundleUpdateTimeStamp"
#define SSO_APPVERSION_NUMBER                                        @"AppVersionNumber"
#define SSO_APPPOLICIES                                              @"AppPolicies"
#define SSO_APPPOLICY_TIMESTAMP                                      @"AppPolicyTimeStamp"
#define SSO_APPSTOREURL                                              @"AppStoreURL"
#define SSO_MOBILEAPPID                                              @"MobileAppId"

#define KEY_MOBILEAPPAGGREGATION                                     @"MobileAppAggregation"


// Client Properties
#define KEY_CLIENTPROPERTY_LDAPATTRIBUTES                            @"SEND_LDAP_ATTRIBUTES"
#define KEY_CLIENTPROPERTY_DISABLELOGGING                            @"DISABLE_LOGGING"

// CEM keys
#define kCtxXenMobileUserAttributes                                  @"XenMobileUserAttributes"

// Apple keys
#define kCtxMDMServerConfigUserDefaultsKey                           @"com.apple.configuration.managed"

// Intune keys
#define kCtxIntuneMAMUPN                                             @"IntuneMAMUPN"

// API keys
#define kCTXMAM_WORX_USERNAME                                        @"Username"
//#define kCTXMAM_SHAREDDEVICE_ENABLED                                  @"SharedDeviceEnabled"

#define CTXMAM_LDAP_USER_PRINCIPAL_NAME                              @"userprincipalname"
#define CTXMAM_LDAP_SAM_ACCOUNT_NAME                                 @"samaccountname"
#define CTXMAM_LDAP_DISPLAY_NAME                                     @"displayname"
#define CTXMAM_LDAP_MAIL                                             @"mail"

#ifdef kCTXSSO_APPLINKURL
#define CONFIGMGR_APPLINKURL                                        kCTXSSO_APPLINKURL
#else
#define CONFIGMGR_APPLINKURL                                        @"AppResourceURL"
#endif

#ifdef kCTXSSO_APPLINKURLTRANSLATED
#define CONFIGMGR_APPLINKURLTRANSLATED                              kCTXSSO_APPLINKURLTRANSLATED
#else
#define CONFIGMGR_APPLINKURLTRANSLATED                              @"AppResourceURLTranslated"
#endif

// Launch Darkly Feature Manager keys
#define kLaunchDarklyFeatureManager                                 @"LaunchDarklyFeatureManager"
