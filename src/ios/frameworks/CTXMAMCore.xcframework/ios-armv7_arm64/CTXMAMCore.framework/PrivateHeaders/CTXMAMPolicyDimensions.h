//
//  MdxPolicyDimensions.h
//  CTXMAM_WrappedAppLib
//
//  Created by Chris Pavlou on 5/11/16.
//
//

#ifndef CTXMAMPolicyDimensions_h
#define CTXMAMPolicyDimensions_h

typedef NS_ENUM(NSUInteger, CTXMAM_CUSTOMDIMENSION)
{
	/************************************************************************************************************
	 ** WARNING **
	 ** This list and the numbering of its entries has to always match the list of custom dimensions on the Google Analytics portal
	 ** The list of custom dimensions is index-based and can not be re-ordered
	 ** Thus, the numbering here can not and should not change either
	 ** 
	 ** New policy entries can be added at the end of the list, assuming a matching custom dimension for them is also added
	 ** Code needs to also be added in MdxAnalytics.m in -sendPolicyValues to send the new policy value as a custom dimension to Google Analytics
	 ** Such change needs to also be validated, by locating the new custom dimension values on the Google Analytics portal
	 **
	 ** Feature Spec: https://info.citrite.net/display/xenmobile/CXM-10843+-+iOS+MDX+Google+Analytics+Support
	 ** For more information or questions please contact Chris Pavlou <chris.pavlou@citrix.com>
	 ************************************************************************************************************/
    
    CID_INDEX                               = 1,        // CID (UPN Domain Name)
    CDOMAIN_INDEX,                                      // CDomain (Email Domain Name)
	
	USER_CLIENTID_INDEX						= 10,		// ClientID
	
	/************************************************************************************************************
	 ** Secure Hub reserved dimensions (index 11 - 40)
	 ************************************************************************************************************/

	/************************************************************************************************************
	 ** MDX internal value dimensions (index 41 - 49)
	 ** Add new internal value dimensions at the end of this section and enable/setup dimension with same index on GA portal
	 ************************************************************************************************************/

	APPSTATE_APPMODE_INDEX					= 41,		// AppMode
	APPSTATE_MDXVERSION_INDEX,							// MDXVersion
	APPSTATE_APPRUNNINGMODE_INDEX,						// AppRunningMode
    EDP_COMPLIANCE_INDEX,                               // EDP_Compliance
	/************************************************************************************************************
	 ** MDX Policy dimensions (index 50+)
	 ** Add new policy dimensions at the end of this section and add dimension on GA portal to match
	 ************************************************************************************************************/
	PKEY_ANALYTICSDETAIL_INDEX				= 50,		// AnalyticsDetail
	PKEY_ACTIVEPOLLPERIOD_INDEX,						// ActivePollPeriod
	PKEY_APPPASSCODE_INDEX,								// AppPasscode
	PKEY_POLICYBLOCKJAILBROKEN_INDEX,					// BlockJailbrokenDevices
	PKEY_CTXLOG_LOGGING_BLOCKED_INDEX,					// BlockLogs
	PKEY_APPCNT_CUTANDCOPY_INDEX,						// CutAndCopy
	PKEY_POLICY_DATAENCRYPTION_ENUM_INDEX,				// DatabaseEncryptionEnum
	PKEY_CTXLOG_CURRENT_LOG_LEVEL_INDEX,				// DefaultLoggerLevel
	PKEY_CTXLOG_LOG_TARGET_INDEX,						// DefaultLoggerOutput
	PKEY_DEVICEPASSCODE_INDEX,							// DevicePasscode
	PKEY_APPCNT_DISABLEAIRDROP_INDEX,					// DisableAirDrop
	PKEY_APPCNT_DISABLEBACKUP_INDEX,					// DisableBackup
	PKEY_APPCNT_DISABLECAMERA_INDEX,					// DisableCamera
	PKEY_APPCNT_DISABLEDICTATION_INDEX,					// DisableDictation
	PKEY_APPCNT_DISABLEEMAIL_INDEX,						// DisableEmail - Disabled?
	PKEY_APPCNT_DISABLEPHOTOLIBRARY_INDEX,				// DisablePhotoLibrary
	PKEY_APPCNT_DISABLEICLOUD_INDEX,					// DisableiCloud
	PKEY_APPCNT_DISABLEKEYBOARD_INDEX,					// DisableKeyboard
	PKEY_APPCNT_DISABLELOCATION_INDEX,					// DisableLocation
	PKEY_APPCNT_DISABLEMIC_INDEX,						// DisableMicrophone
	PKEY_APPCNT_DISABLEPRINTING_INDEX,					// DisablePrinting
	PKEY_APPCNT_DISABLESMS_INDEX,						// DisableSms
	PKEY_APPCNT_DISABLESOCIALMEDIA_INDEX,				// DisableSocialMedia
	PKEY_APPCNT_DOCEXCHANGE_INDEX,						// DocumentExchange
	PKEY_PERMITVPNMODESWITCHING_INDEX,					// PermitVPNModeSwitching
	PKEY_CTXLOG_ENCRYPT_LOGS_INDEX,						// EncryptLogs						// This policy is not used currently but will be re-enabled later; keep here so indexing does not change
	PKEY_EXPLICITLOGOFFNOTIFICATION_INDEX,				// ExplicitLogoffNotification
	PKEY_GEOFENCERADIUS_INDEX,							// GeofenceRadius
	PKEY_APPCNT_INBOUND_DOCEX_INDEX,					// InboundDocumentExchange
	PKEY_POLICY_KEYCHAINENCRYPTION_ENABLE_INDEX,		// KeychainEncryption
	PKEY_MAIL_COMPOSE_INDEX,							// MailCompose
	PKEY_CTXLOG_MAX_FILE_COUNT_INDEX,					// MaxLogFiles
	PKEY_CTXLOG_MAX_FILE_SIZE_INDEX,					// MaxLogFileSize
	PKEY_MAXIMUMOFFLINEPERIOD_INDEX,					// MaxOfflinePeriod
	PKEY_POLICYNETWORKACCESS_INDEX,						// NetworkAccess
	PKEY_APPCNT_OBSCURESCREEN_INDEX,					// ObscureScreen
	PKEY_ONLINESESSIONREQUIRED_INDEX,					// OnlineSessionRequired
	PKEY_ONLINESESSIONREQUIREDGRACEPERIOD_INDEX,		// OnlineSessionRequiredGracePeriod
	PKEY_APPCNT_PASTE_INDEX,							// Paste
	PKEY_POLICYVPNMODE_INDEX,							// PreferredVpnMode
	PKEY_REQUIREDCERTIFICATE_INDEX,						// RequiredClientCertPrefetch
	PKEY_POLICYREQINTNETWORK_INDEX,						// RequireInternalNetwork
	PKEY_APPCNT_DISABLELOOKUP_INDEX,					// DisableLookUp					// This used to be the RequireUserEntropy policy which was previously deprecated
	PKEY_APPCNT_SECUREVIEWER_INDEX,						// SecureViewer
	PKEY_SWITCHTOSBMODEFORANYAUTH_INDEX,				// SwitchToSBModeForAnyAuth
	PKEY_POLICYUPDATEGRACE_INDEX,						// UpgradeGracePeriod
	PKEY_POLICYWIFIONLY_INDEX,							// WifiOnly
	PKEY_POLICYWIPEDATAONAPPLOCK_INDEX,					// WipeDataOnAppLock
    PKEY_DISABLE_REQUIRED_UPGRADE_INDEX,                // DisableRequiredUpgrade
	PKEY_APPCNT_EXCLUDEURLFILTERFORDOMAINS_INDEX,		// ExcludeUrlFilterForDomains
	PKEY_APPCNT_SECUREWEBDOMAINS_INDEX,					// SecureWebDomains
	PKEY_CITRIXREPORTING_INDEX,							// CitrixReporting
	PKEY_REPORTING_UPLOADTOKEN_INDEX,					// CitrixReportingUploadToken
	PKEY_REPORTING_WIFI_INDEX,							// CitrixReportingWifiOnly
	PKEY_REPORTING_MAXCACHESIZE_INDEX,					// CitrixReportingMaxCacheSize
	PKEY_MVPN_REDIRECTWEBTRAFFICWITHSSO_INDEX,			// MvpnRedirectWebTrafficWithSSO
	PKEY_INTUNE_SESSIONREQUIRED_INDEX,					// MvpnSessionRequired
	PKEY_MVPN_DISABLETCPREDIRECT_INDEX,					// MvpnDisableTcpRedirect
	PKEY_MVPN_EXCLUDEDOMAINS_INDEX,						// MvpnExcludeDomains
    PKEY_POLICY_APPDPCOMPLIANCE_INDEX,                  // AppDataProtectionCompliance
    PKEY_POLICY_EPDPENCRYPTIONRESP_INDEX,               // EDPEncryptionRespEnum
    PKEY_POLICYNETWORKACCESS_NEW_INDEX,                 // MvpnNetworkAccess
    PKEY_POLICY_EPDP_DISABLEMIGRATION_INDEX,            // EDPDisableMigration

	/************************************************************************************************************
	 ** WARNING **
	 ** This list and the numbering of its entries has to always match the list of custom dimensions on the Google Analytics portal
	 ** The list of custom dimensions is index-based and can not be re-ordered
	 ** Thus, the numbering here can not and should not change either
	 **
	 ** New policy entries can be added at the end of the list and above this message, assuming a matching custom dimension for them is also added
	 ** Code needs to also be added in MdxAnalytics.m in -sendPolicyValues to send the new policy value as a custom dimension to Google Analytics
	 ** Such change needs to also be validated, by locating the new custom dimension values on the Google Analytics portal
	 **
	 ** Feature Spec: https://info.citrite.net/display/xenmobile/CXM-10843+-+iOS+MDX+Google+Analytics+Support
	 ** For more information or questions please contact Chris Pavlou <chris.pavlou@citrix.com>
	 ************************************************************************************************************/
	
	CUSTOM_DIMENSION_INDEX_CAP							// This should always be at the end of the ENUM for UnitTest validation
};

#endif /* CtxMAMPolicyDimensions_h */
