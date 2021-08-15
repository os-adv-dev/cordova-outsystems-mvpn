//
//  CTXMAMComplianceConstants.h
//  CTXMAMCompliance
//
//  Created by Jaspreet Singh on 7/1/19.
//  Copyright © 2019-2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMComplianceConstants_h
#define CTXMAMComplianceConstants_h

#define PKEY_DEVICEPASSCODE                 @"DevicePasscode"
#define DEFAULT_DEVICEPASSCODE              YES

#define PKEY_POLICYBLOCKJAILBROKEN          @"BlockJailbrokenDevices"
#define DEFAULT_POLICYBLOCKJAILBROKEN       YES

#define PKEY_POLICYWIPEDATAONAPPLOCK        @"WipeDataOnAppLock"
#define DEFAULT_POLICYWIPEDATAONAPPLOCK     NO

#define POLICY_KEY_ACTIVEPOLLPERIOD         @"ActivePollPeriod"
#define DEFAULT_VALUE_ACTIVEPOLLPERIOD      60      // 60 minutes

// App Update
#define PKEY_POLICYUPDATEGRACE              @"UpgradeGracePeriod"
#define DEFAULT_POLICYUPDATEGRACE           168     // In hours (7 days)

#define PKEY_DISABLE_REQUIRED_UPGRADE       @"DisableRequiredUpgrade"
#define DEFAULT_DISABLE_REQUIRED_UPGRADE    NO

#define APPBUNDLE_UPDATEDETECTED_TIMESTAMP  @"AppBundleUpdateDetectTimestamp"


// App Data Protection Compliance
#define ENUM_VALUE_EP_APP_DP_COMPLIANCE_BLOCK                 @"Block"
#define ENUM_VALUE_EP_APP_DP_COMPLIANCE_WARN                  @"Warn"
#define ENUM_VALUE_EP_APP_DP_COMPLIANCE_ALLOW                 @"Allow"
#define ENUM_VALUE_EP_APP_DP_COMPLIANCE_UNDEFINED             @""
#define PKEY_POLICY_EP_APP_DP_COMPLIANCE_ENUM     @"EDPAppComplianceEnum"
#define DEFAULT_EP_APP_DP_COMPLIANCE_ENUM         ENUM_VALUE_EP_APP_DP_COMPLIANCE_BLOCK

#define PKEY_POLICY_EP_APP_DP_COMPLIANCE_CRITERIA     @"EDPAppComplianceCriteria"
#define DEFAULT_EP_APP_DP_COMPLIANCE_CRITERIA     @"iOS10.2+;DebuggerAccess;DataSharing;JailbrokenDevice;DevicePasscode;ObfuscateLogs"

// storage for App Data Protection Compliance Policy
#define USER_DEFAULTS_KEY_FOR_EPDP_APP_COMPLIANCE_POLICY  @"EPDPAppCompliancePolicy"

// storage for App Data Protection Compliance Criteria Policy
#define USER_DEFAULTS_KEY_FOR_EPDP_APP_COMPLIANCE_CRITERIA_POLICY  @"EPDPAppComplianceCriteriaPolicy"


////////// Shared dynamic data /////////
#define SHARED_DATA_LOCKWIPE_VALUE              @"lockWipeValue"
#define SHARED_DATA_SYSTEM_TIME                 @"SystemTime"
#define SHARED_DATA_LAST_TIME_CHANGE            @"LastTimeChange"
#define SHARED_DATA_TIME_CHANGE_FLAG            @"TimeChangeFlag"
#define SHARED_DATA_TIME_CHANGE_DIFF            @"TimeChangeDiff"
#define LAST_SUCCESSFUL_DEVICE_CHECK_TIMESTAMP  @"lastSuccessfulDeviceCheckTimestamp"



#define MAM_LOG_FILENAME        "CtxMAM.log"
#define MAM_CONFIG_FILENAME     "CitrixMAM.config"
#define MAM_LOGFILENAME     @MAM_LOG_FILENAME
#define MAM_CONFIGFILENAME  @MAM_CONFIG_FILENAME

#define kCTXPERSISTENTDATA                          @"CTXMAM_PersistentData"
#define VAULT_ITEMNAME_APPISENABLED                 @"AppIsEnabled"


// Client properties
#define kCTXSSO_AGDEVICECHECKURL                    @"AGDeviceCheckURL"
#define kCTXSSO_APPCDEVICECHECKURL                  @"APPCDeviceCheckURL"
#define kCTXSSO_CONTAINER_SELF_DESTRUCT_PERIOD      @"ContainerSelfDestructPeriod"
#define kCTXSSO_SHARED_DEVICE_MODE_ENABLED          @"SharedDeviceModeEnabled"

#define kCLIENTPROPERTY_CONTAINER_SELF_DESTRUCT_PERIOD    @"CONTAINER_SELF_DESTRUCT_PERIOD"

// SH vault data...
#define kCTXSSO_USERNAME            @"Username"
#define kCTXSSO_DEVICESTATE         @"DeviceState"
#define kCTXSSO_WORXPINLOCKSTATE    @"LockState"
#define kCTXSSO_APPRESOURCEID       @"AppResourceID"

#define kCTXSSO_DEVICEID            @"DeviceID"


#define CITRIXSECUREHUB_APPSTORE_URL                @"https://apps.apple.com/us/app/citrix-secure-hub/id434682528"

#define CTXMAMComplianceInternalError_Min      100
typedef enum CTXMAMComplianceInternalError {
    CTXMAMCompliance_SecurityAction_AdminAppWiped_ReinstallApp = CTXMAMComplianceInternalError_Min,
    CTXMAMCompliance_SecurityAction_AppRemoved,
    CTXMAMCompliance_SecurityAction_StoreRemoved,
    CTXMAMCompliance_SecurityAction_CTXMAMAgentAppUninstalled,
    CTXMAMCompliance_SecurityAction_AppUpdateRequired,
    CTXMAMCompliance_SecurityAction_AppUpdateAvailable,
    CTXMAMCompliance_SecurityAction_AppUpdateFailedToOpenURL,
    CTXMAMCompliance_SecurityAction_AppNotMDMEnrolled,
    CTXMAMComplianceInternalError_Max
} CTXMAMComplianceInternalError;


#define ENV_VAR(x)                  [[[NSProcessInfo processInfo] environment] objectForKey:x]
#define IS_UNIT_TEST_ENV()          ENV_VAR(@"XCTestConfigurationFilePath")

// Share with EMAM-S-SDK
#define kCTXMAMCOMPLIANCE           @"CTXMAMCompliance"

#endif /* CTXMAMComplianceConstants_h */
