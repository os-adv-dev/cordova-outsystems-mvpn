//
//  CtxSingleSignOn.h
//  CtxSingleSignOn
//
//  Created on 2/25/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CtxObjectCache.h"
#import "CTXMAMLogonManagerPrivateTypes.h"

//TODO: Explicit SDK - There are too many duplicated we need to merge these constants with the constants in CTXMAMConfigManagerConstants

//SSO encrypted key vault item
#define kCTXSSO_PASTEBOARD_TYPE                     @"CtxSSO"
#define kCTXSSO_OBJECT_NAME                         @"CtxSSOData"

#define kCTXSSO_DATAVERSION                         @"DataVersion"
#define kCTXSSO_STOREID                             @"StoreID"
#define kCTXSSO_STOREUUID                           @"StoreUUID"
#define kCTXSSO_STORENAME                           @"StoreName"
#define kCTXSSO_AGENTBUNDLEID	                	@"AgentBundleID"
#define kCTXSSO_APPLICATIONS                        @"Applications"
#define kCTXSSO_APPID                               @"AppID"
#define kCTXSSO_APPNAME                             @"AppName"
#define kCTXSSO_APPRESOURCEID                       @"AppResourceID"
#define kCTXSSO_APPVERSION                          @"Version"              // Legacy name, will be deprecated in v2
#define kCTXSSO_APPPACKAGE_ID                       @"PackageID"            // In v2, this is to replace kCTXSSO_APPVERSION in v1
#define kCTXSSO_APPVERSION_NUMBER                   @"AppVersionNumber"
#define kCTXSSO_APP_UE_ENABLED                      @"AppUserEntropyEnabled"
#define kCTXSSO_APP_DATA_ENCRYPTION                 @"AppDataEncryption"
#define kCTXSSO_APP_LOG_LEVEL                       @"AppLogLevel"
#define kCTXSSO_APP_LOG_TARGET                      @"AppLogTarget"
#define kCTXSSO_APPTIMESTAMP                        @"AppBundleUpdateTimeStamp"
#define kCTXSSO_APPSTOREAPP                         @"AppStoreApp"
#define kCTXSSO_APPPOLICIES                         @"AppPolicies"
#define kCTXSSO_APPPOLICY_TIMESTAMP                 @"AppPolicyTimeStamp"
#define kCTXSSO_APPSTATICKET                        @"STATicket"
#define kCTXSSO_APPSTAFETCHTIMESTAMP                @"STAFetchTimeStamp"
#define kCTXSSO_APPLINKURL			                @"AppResourceURL"
#define kCTXSSO_APPLINKURLTRANSLATED                @"AppResourceURLTranslated"

#define kCTXSSO_LOGONFLAG                           @"LogonFlag"
#define kCTXSSO_FIPSENABLEDFLAG                     @"EnableFIPSMode"
#define kCTXSSO_TIMESTAMP                           @"TimeStamp"
#define kCTXSSO_LASTOFFCHTIMESTAMP                  @"LastOffChTimestamp"
#define kCTXSSO_LASTSTEPUPTIMESTAMP                 @"LastStepupTimestamp"
#define kCTXSSO_INT_LOGON_TIMESTAMP                 @"LastInteractiveLogonTimestamp"
#define kCTXSSO_INTERNALNETWORK                     @"InternalNetwork"
#define kCTXSSO_LOGONERRORCODE                      @"LogonErrorCode"
#define kCTXSSO_AGTOKEN                             @"AGToken"
#define kCTXSSO_APPGROUPKEY                         @"AppGroupEncryptionKey"
#define kCTXSSO_KEYCHAIN_ENCRYPTION                 @"KeychainEncryptionPolicy"
#define kCTXSSO_APPINSTALLED                        @"Installed"
#define kCTXSSO_UE_SHAREDVAULT_KEK                  @"AppMaterial"
#define kCTXSSO_DISABLE_LOGGING                     @"DisableLogging"
#define kCTXSSO_ENABLE_CRASH_REPORT                 @"EnableCrashReport"
#define kCTXSSO_STORE_UE_SETTING                    @"StoreUserEntropySetting"

#define kCTXSSO_ENCRYPTIONKEY                       @"EncryptionKey"

#define kCTXSSO_MOBILEAPPPOLICIES                   @"MobileAppPolicies"
#define kCTXSSO_ACCOUNTSXML                         @"AccountsXML"

#define kCTXSSO_RCVR_BASE_URL                       @"citrixreceiver://"
#define kCTXSSO_RCVR_BUNDLEID                       @"com.citrix.Receiver"
#define kCTXSSO_MEATWORK_BASE_URL                   @"com.citrix.meatwork://"
#define kCTXSSO_MEATWORK_BASE_URL2                  @"zenprisedmpostenroll://"
#define kCTXSSO_MEATWORK_BUNDLEID                   @"com.zenprise.zpmdmbeta"
#define kCTXSSO_X1RECEIVER_BASE_URL	                @"citrixreceiverfd://"
#define kCTXSSO_X1RECEIVER_BUNDLEID	                @"com.citrix.receiver.ios"
#define kCTXSSO_X1TESTAPP_BASE_URL                  @"com.citrix.CtxCWATestApp://"
#define kCTXSSO_X1TESTAPP_BUNDLEID                  @"com.citrix.CtxCWATestApp"
#define kCTXSSO_WORXMAIL_IDENTIFIER_URL             @"ctxmail://"
#define kCTXSSO_WORXMAIL_NEW_IDENTIFIER_URL         @"ctxmailex://"

#define kCTXSSO_URL_PREFIX                          @"com.citrix.sso"
#define kCTXSSO_LAUNCH_REQUEST                      @"launchrequest"
#define kCTXSSO_LOGON_REQUEST                       @"logonrequest"
#define kCTXSSO_LOGON_RESPONSE                      @"logonresponse"
#define kCTXSSO_UPGRADE_REQUEST                     @"upgraderequest"
#define kCTXSSO_UPGRADE_RESPONSE                    @"upgraderesponse"
#define kCTXSSO_AGCLIENTCERT_REQUEST                @"agclientcertrequest"
#define kCTXSSO_AGCLIENTCERT_RESPONSE               @"agclientcertresponse"
#define kCTXSSO_MDM_ALLOWSELFSIGNEDCERTS            @"MDMAllowSelfSignedCerts"
#define kCTXSSO_USERTRUSTEDCERTS                    @"UserTrustedCerts"
#define kCTXSSO_PINNEDCERTS                         @"PinnedCerts"
#define kCTXSSO_REQUIRE_CERT_PINNING                @"RequireCertPinning"
#define kCTXSSO_URL_MAIL_COMPOSE_PREFIX             @"mailcompose"

#define kCTXSSO_SERVERAUTHDATADETAILS			    @"ServerAuthDataDetails"
#define kCTXSSO_ACCOUNTSSTOREPROPERTIES			    @"AccountsStoreProperties"
#define kCTXSSO_DEVICE_ID_V1                        @"DeviceId"
#define kCTXSSO_AUTH_TOKEN                          @"AuthToken"
#define kCTXSSO_AUTH_DOMAIN                         @"AuthDomain"
#define kCTXSSO_SHAREFILERESOURCEURL			    @"SharefileResourceURL"
#define kCTXSSO_SHAREFILERESOURCEURLTRANSLATED	    @"SharefileResourceURLTranslated"
#define kCTXSSO_STATICKETRESOURCEURL			    @"STATicketServiceURL"
#define kCTXSSO_STATICKETRESOURCEURLTRANSLATED	    @"STATicketServiceURLTranslated"
#define kCTXSSO_GATEWAY_TYPE                        @"GatewayType"
#define kCTXSSO_GATEWAY_SUPPORTS_FULLVPN            @"GatewaySupportsFullVPN"

#define kCTXSSO_DATA_COLLECT_TIMESTAMP              @"SSODataCollectTimestamp"

#define kCTXSSO_STORE                               @"store"
#define kCTXSSO_APPIDl                              @"appid"
#define kCTXSSO_URLSCHEME                           @"urlscheme"
#define kCTXSSO_NONCE                               @"nonce"
#define kCTXSSO_PREVIOUSNONCE                       @"previousnonce"
#define kCTXSSO_REAUTH                              @"reauth"
#define kCTXSSO_ENUMERATE                           @"enum"
#define kCTXSSO_RESULT                              @"result"
#define kCTXSSO_AGCLIENTCERTRESULT                  @"agclientcertresult"
#define kCTXSSO_AGCLIENTCERTHASH                    @"agclientcerthash"
#define kCTXSSO_LOGONFAILURES                       @"logonfailures"
#define kCTXSSO_LOGONTYPE                           @"logontype"
#define kCTXSSO_RESPONDWITHURL                      @"respondwithurl"
#define kCTXSSO_UE_CHALLENGED                       @"ue"
#define kCTXSSO_DID_PIN_RESET                       @"pinreset"
#define kCTXSSO_PININCREMENTOR                      @"pinincrementor"
#define kCTXSSO_ADMIN_WIPE                          @"adminwipe"
#define kCTXSSO_SILO_NOTIFY                         @"silonotify"
#define kCTXSSO_NETSCALER_ADDRESS                   @"agaddress"
#define kCTXSSO_AUTH_COOKIE                         @"authcookie"
#define kCTXSSO_APP_INFO                            @"appinfo"


//The following URL parameters must be in lower case if it is parsed in WorxHome.
//Otherwise WorxHome "CustomUrl" can't parse it properly.
#define kCTXSSO_LOGONIFREQUIRED                     @"logonifrequired"
#define kCTXSSO_AUTOSUBSCRIBE                       @"autosubscribe"
#define kCTXSSO_STEPUP_REQUEST                      @"stepuprequest"
#define kCTXSSO_STEPUP_RESPONSE                     @"stepupresponse"
#define kCTXSSO_STEPUP_ADDRESS                      @"stepupaddress"
#define kCTXSSO_STEPUP_FLAG                         @"isSteppedUp"
#define kCTXSSO_FTU_FLAG                            @"isfirsttimeuse"
#define kCTXSSO_IPC_RESTART                         @"restartipc"


#define kCTXSSO_FIRSTINIT                           @"FirstTimeInitComplete"

#define kCTXSSO_OFFLINE_CHALLENGE_REQUEST           @"offlinechallengerequest"
#define kCTXSSO_OFFLINE_CHALLENGE_RESPONSE          @"offlinechallengeresponse"

// Constants added for log settings
#define kCTXLOG_LAUNCH_REQUEST                      @"CtxLogLaunchRequest"
#define kCTXLOG_LAUNCH_RESPONSE                     @"CtxLogLaunchResponse"
#define kCTXLOG_LAUNCH_OPTION                       @"CtxLogLaunchOption"
#define kCTXLOG_LAUNCH_OPTION_REPRO_ISSUE           @"CtxLogLaunchOptionReproIssue"
#define kCTXLOG_LAUNCH_OPTION_RESET                 @"CtxLogLaunchOptionReset"
#define kCTXLOG_LAUNCH_OPTION_FETCH_LOGS            @"CtxLogLaunchOptionFetchLogs"
#define kCTXLOG_LAUNCH_CLEAR_LOGS                   @"CtxLogLaunchClearLogs"
#define kCTXSSO_OFFLINE_PERMITTED_REQUEST           @"offlinepermittedrequest"
#define kCTXSSO_OFFLINE_PERMITTED_RESPONSE          @"offlinepermittedresponse"
#define kCTXSSO_FTU_REQUEST                         @"CtxFirtTimeUseRequest"
#define kCTXSSO_FTU_RESPONSE                        @"CtxFirtTimeUseResponse"



// These macros define the default message used for the UIAlert when
// CtxAuth is not installed.  Override these strings in  your string
// table for other languages.
#define kRCVR_NOT_INSTALLED_BUTTON  ( NSLocalizedString( @"OK", nil ) )
#define kRCVR_NOT_INSTALLED_MESSAGE ( NSLocalizedString( @"Install Worx Home to enable this functionality.", nil ) )
#define kRCVR_NOT_INSTALLED_TITLE   ( NSLocalizedString( @"Unable to Authenticate", nil ) )

#define kCTXSSO_AGBASEURL                           @"AGBaseURL"
#define kCTXSSO_AGCOOKIES                           @"AGCookies"
#define kCTXSSO_XMSBASEURL                          @"XMSBaseURL"
#define kCTXSSO_VAULTMATERIAL                       @"SSOKey"
#define kCTXSSO_SAML_TOKEN                          @"SAMLToken"
#define kCTXSSO_SAML_DOMAIN                         @"SAMLDomain"
#define kCTXSSO_SAML_EXPIRYDATE                     @"SAMLExpiryDate"
#define kCTXSSO_MDM_CERT                            @"MDMCert"
#define kCTXSSO_MDM_CERT_DEFAULT                    @"NetscalerGatewayCert"       // Default label name for MDM Netscaler gateway cert
#define kCTXSSO_MDM_CERT_DATA                       @"MDMCertP12"
#define kCTXSSO_MDM_CERT_HASH                       @"MDMCertP12Hash"
#define kCTXSSO_MDM_CERT_PASSWORD                   @"MDMCertPassword"

#define kCTXSSO_AGCONFIGDATA                        @"AGConfigData"
#define kCTXSSO_AGCOOKIEREFRESHTIMESTAMP            @"AGCookieRefreshTimeStamp"

#define kCTXSSO_AGDEVICECHECKURL                    @"AGDeviceCheckURL"
#define kCTXSSO_APPCDEVICECHECKURL                  @"APPCDeviceCheckURL"
#define kCTXSSO_DEVICEID                            @"DeviceID"
#define kCTXSSO_DEVICESTATE                         @"DeviceState"
#define kCTXSSO_DEVICE_ENROLLMENT                   @"DeviceEnrollmentConfig"
#define kCTXSSO_WORXPINLOCKSTATE                    @"LockState"
#define kCTXSSO_PASSCODE_MAX_ATTEMPTS               @"PasscodeMaxAttempts"
#define kCTSSSO_CLIENTCERTHASH                      @"ClientCertHash"
#define kCTSSSO_MDMPROVIDESCERTS                    @"MdmProvidesClientCerts"
#define kCTSSSO_SHAREFILE_SSO_ENABLED               @"SharefileSSOEnabled"

#define kCTXSSO_INACTIVITY_TIMER                    @"InactivityTimer"
#define kCTXSSO_APP_BACKGROUND_TIMESTAMP            @"AppBackgroundTimeStamp"
#define kCTXSSO_USERNAME                            @"Username"
#define kCTXPERSISTENTDATA                          @"CTXMAM_PersistentData"
#define kCTXSSO_TOUCH_ID_ENABLED                    @"TouchId"

#define kCTXSSO_CONTAINER_SELF_DESTRUCT_PERIOD      @"ContainerSelfDestructPeriod"
#define kCTXSSO_NETWORK_EXTENSION_ENABLED           @"NetworkExtensionEnabled"

#define MAM_REFETCH_CLIENT_CERT                     @"kRefetchClientCert"

#define kSECUREOFFLINE_PIN_RETRIES                  @"SecureOfflinePINretries"


////// WorxMail constants..s
#define PKEY_USERNAME                               @"Username"
#define PKEY_MAILDOMAIN                             @"MailDomain"
#define PKEY_EXCHANGESERVER                         @"ExchangeServer"
#define PKEY_WORXMAIL_APPNAME                       @"WorxMail"


// TODO: Remove the temporary wrapping constants and shift them to their home.
#define WRAPPER_APPUNIQUEID                         @"AppUniqueID"
#define WRAPPER_WRAPPINGTIMESTAMP                   @"WrappingTimestamp"

//Shared Devices Constants
#define kCTXSSO_SHARED_DEVICE_MODE_ENABLED          @"SharedDeviceModeEnabled"
#define kCTXSSO_LOGOFFNOTIFICATION_REQUEST          @"logoffrequest"
#define kCTXSSO_LOGOFFNOTIFICATION_RESPONSE         @"logoffresponse"
#define kCTXSSO_URLSCHEMESTOFORWARDREQUEST          @"urlschemestoforwardrequest"
#define kCTXSSO_APPSILOSTOFORWARDREQUEST            @"appsilostoforwardrequest"
#define kCTXSSO_MDXNOTIFICATIONREQUEST              @"mdxnotificationrequest"
#define kCTXSSO_MDXNOTIFICATIONRESPONSE             @"mdxnotificationresponse"

// Feature flag implementation
#define kCTXSSO_DEVICEVENDORKEY                                      @"DeviceVendorKey"
#define kCTXSSO_DEVICEID_FF                                          @"FeatureFlagDeviceId"
#define kCTXSSO_USERID_FF                                            @"FeatureFlagUserId"
#define kCTXSSO_CUSTOMERID_FF                                        @"FeatureFlagCustomerId"


typedef enum {
    LOGON_SUCCESS = 0,
    LOGON_AUTH_FAILURE,
    LOGON_NETWORK_ERROR,
    LOGON_INVALID_NONCE,
    LOGON_CANCELLED,
    LOGON_INVALID_STORE,
    LOGON_INVALID_APP,
    LOGON_NO_STORE_ADDED,
    LOGON_SUBSCRIPTION_FAILURE,
    LOGON_SERVER_CERT_ERROR,
    LOGON_OTHER_ERROR,
    LOGON_CANCELLED_REENROLL
} eCTXSSO_LOGON;

typedef enum {
    AG_CLIENT_CERT_REQUEST_SUCCESS = 0,
    AG_CLIENT_CERT_REQUEST_FAILURE
} eCTXSSO_AG_CLIENT_CERT;



@interface CtxSingleSignOn : NSObject

@property (strong,nonatomic) NSString*     appName;
@property (strong,nonatomic) NSString*     appId;
@property (strong,nonatomic) NSString*     packageId;

// WorxHome use only. MDX does NOT use store ID for pasteboard anymore. Please use Device Shared Storage's SSOKeyEncryptedVault to get MDX store ID.
@property (strong,nonatomic) NSString*     storeId;
@property (strong,nonatomic) NSString*     encryptionKey;
// end WorxHome use

@property (strong,nonatomic) NSString*     urlScheme;
@property (strong,nonatomic) NSString*     nonce;
@property (strong,nonatomic) NSString*     previousNonce;
@property (strong,nonatomic) NSString*     command;
@property (strong,nonatomic) NSString*     stepUpAddress;
@property (nonatomic)        eCTXSSO_LOGON logonResult;
@property (nonatomic)        NSInteger     logonFailures;
@property (strong,nonatomic) NSString*     certificateHash;
@property (strong,nonatomic) CtxObjectCache* ssoCache;
@property (nonatomic) NSInteger      pinRetryCount;
@property (nonatomic) NSInteger      pinIncrementor;
@property (strong,nonatomic) NSString*     mfurlScheme;
//@property(nonatomic, assign) BOOL isOpenURLReceivedMDXRelated;

//// JIRA item: Artemis: Fix link lost in appLaunch URL delegate call when MDX flips to WH ///
@property(nonatomic, strong) NSURL* incomingNonCTXMAMOpenURLRequest;
@property(nonatomic, strong) id     incomingNonCTXMAMOpenURLAnnotation;
@property(nonatomic, strong) NSURL* handleDeferredOpenURLRequest;
@property(nonatomic, strong) id     handleDeferredOpenURLAnnotation;
@property(nonatomic, assign) BOOL deferUnhandledOpenUrlRequest;

@property(nonatomic, strong) NSString* urlToAddInMdxResponse;
////////////////////////

@property(nonatomic, assign) BOOL appFinishLaunchingDelegateMethodCalled; // todo: move it to MDXUILifeEvent as it's related to life events

// Class initializers
- init;

// Singleton factory method
+ (CtxSingleSignOn *)sharedCtxSingleSignOn;

- (NSString *)baseUrl;
- (NSString *)ctxCWAAppbaseUrl;

- (BOOL)openURL:(NSURL *)url;
- (BOOL)openURL:(NSURL *)url withCompletionBlock:(void(^)(BOOL bSuccess))completionBlock;

// Methods called from Wrapper App
-(BOOL)didAppRunOnce;                           //Use user default AND file to indicate if FTU is complete
-(BOOL)getFirstTimeInitComplete;                //Use file complete status only to indicate if FTU is complete
-(void)setFirstTimeInitComplete:(BOOL)firstTimeInitComplete createFile: (bool) bCreateFile;

- (BOOL)isMeAtWorkInstalled;

- (BOOL)requestAppRegistration;
- (BOOL)requestRecoverDeviceSharedStorage;

- (BOOL)requestLogon:(CTXLogonRequestType)logonType;
- (BOOL)requestLogon:(CTXLogonRequestType)logonType withReauth:(BOOL)reauth;
- (BOOL)requestLogon:(CTXLogonRequestType)logonType withReauth:(BOOL)reauth andTimeStamp:(NSString *)timeStamp;
- (void)requestLogon:(CTXLogonRequestType)logonRequestType withReauth:(BOOL)reauth andTimeStamp:(NSString *)timeStamp withCompletionBlock:(void(^)(BOOL bSuccess)) completionBlock;
- (BOOL)requestVPNLogonWithReauth:(BOOL)reauth p12Hash:(NSString*)p12Hash;

- (BOOL)requestUpgrade;
- (BOOL)requestOfflineChallenge_sendPinIncrementor:(BOOL)sendPinIncrementor;
- (BOOL)requestStepupLogon:(CTXLogonRequestType)logonRequestType gatewayAddress:(NSString*)stepUpAddr;
- (BOOL)requestToHandleDeviceStateChange:(CTXLogonRequestType)logonRequestType gatewayAddress:(NSString*)gatewayAddress;
- (BOOL)requestToHandleDeviceStateChange:(CTXLogonRequestType)logonRequestType
                            andAdminWipe:(BOOL)adminWipe
                            andTimestamp:(NSString *)timestamp;
- (void)requestForgotOfflineADPassword;
- (void)requestForgotPIN;

- (NSString*) logonTypeNameFromEnum:(CTXLogonRequestType)logonType;
- (BOOL) isForcefulLogonType:(CTXLogonRequestType)logonType;
- (BOOL) isDeviceStateChangeType:(CTXLogonRequestType)type;

- (BOOL)handleUrlInWrappedApp:(NSURL *)url;

- (BOOL)IsCtxLoggingRelatedURL: (NSURL *) url;
- (BOOL)isCTXMAMRelatedUrl:(NSURL *)url;
- (BOOL)isCTXMAMAuthV2RelatedUrlCommand:(NSString*)cmd;

- (NSString *)getStoreIDFromKCWithError:(NSError**)error;
- (NSString *)getValueFromKCForKey:(NSString*)key error:(NSError**)error;



// Methods called from Receiver
- (BOOL)sendAGClientCertResponse:(NSString *)urlScheme
        andAGClientCertReqResult:(eCTXSSO_AG_CLIENT_CERT)agClientCertReqResult
                       andResult:(eCTXSSO_LOGON)logonResult;

- (BOOL)sendLogonResponse:(NSString *)urlScheme
               withResult:(eCTXSSO_LOGON)result
                 andNonce:(NSString *)nonce
               andStoreId:(NSString *)storeId;

- (BOOL)sendStepupAuthResponse:(NSString *)urlScheme
                    withResult:(eCTXSSO_LOGON)result
                      andNonce:(NSString *)nonce
                    andStoreId:(NSString *)storeId;

- (BOOL)sendOfflineChallengeResponse:(NSString *)urlScheme
               withResult:(eCTXSSO_LOGON)result
                 andNonce:(NSString *)nonce
               andStoreId:(NSString *)storeId
                andLogonFailures:(NSInteger) logonFailures;

- (BOOL)sendAppLaunch:(NSString *)urlScheme;


//- (BOOL)saveDictionaryToPasteboard:(NSDictionary *)dict;
//- (BOOL)wipePasteboard;

// This method is invoked by wrapper to cleanup keychain items after a succssful upgrade.
//
- (void) cleanupKeychainItemsOnUpgrade;


// General purpose helper class methods
+ (BOOL)canOpenURL:(NSURL *)url;
+ (NSDictionary *)parseUrl:(NSURL *)url;
- (NSString*)generateNonce;
+ (NSString *)obfuscate:(NSString *)string withKey:(NSString *)key;
+ (NSString *)escapedString:(NSString *)string;
+ (NSString *)unescapedString:(NSString *)string;

@end


// we need to keep this in seperate header for now its here :(
#define kCTXMDXRxPB_UNSEC_GENERALINFO       @"RxSDKGeneral"
#define kCTXMDXRxPB_UNSEC_GENERALINFODIC    @"RxSDKGeneralDictionary"

#define kCTXMDXRxPB_UNSEC_TESTINFO          @"RxSDKDateTime"
#define kCTXMDXRxPB_UNSEC_LAST_CHANGE       @"RxSDKLastChange"
#define kCTXMDXRxPB_UNSEC_CHANGEFLAG        @"RxSDKChangeFlag"

#define kCTXMDXRxPB_IPC_vMIN_VALUE          1
#define kCTXMDXRxPB_IPC_vMIN                @"IPC_VERSION_MIN"

// This version always contains the maximum version supported by WorxHome.
#define kCTXMDXRxPB_IPC_vMAX_VALUE          16
#define kCTXMDXRxPB_IPC_vMAX                @"IPC_VERSION_MAX"


// This value indicates the current basically "required" version for MDX app.
// Version is set to 3 means version 3 (Nike MR1 worxhome) is required by *all* MDX apps.
#define kCTXMDX_IPC_CURRENT_VERSION_VALUE   16

//#define kCTXMDXRxPB_STORE_COUNT             @"Store_Count"
#define kCTXMDXRxPB_STORES                  @"Stores"
#define kCTXMDXRxPB_MOBILEAPPLIST           @"MobileAppList"
#define kCTXMDXRxPB_MOBILEAPPSTATE          @"MobileAppState"
#define kCTXMDXRxPB_URLSCHEME               @"UrlScheme"
#define kCTXMDXRxPB_ISSUBSCRIBED            @"IsSubscribed"
#define kCTXMDXRxPB_PIN_VALIDATOR           @"PinValidator"
#define kCTXMDXRxPB_UE_METADATA             @"UserEntropyMetadata"



@interface CtxGeneralPasteBoard : NSObject

@property (strong,nonatomic) NSMutableDictionary *sharedDictionaryObj;
@property (strong,nonatomic) CtxObjectCache* pbCache;

+ (CtxGeneralPasteBoard*) sharedInstance;

-(BOOL) saveDictionary:(NSDictionary*) dict;

@end
