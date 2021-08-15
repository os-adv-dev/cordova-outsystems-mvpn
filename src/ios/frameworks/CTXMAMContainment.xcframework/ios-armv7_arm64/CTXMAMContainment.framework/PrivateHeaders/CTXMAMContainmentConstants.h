//
//  CTXMAMContainmentConstants.h
//  CTXMAMContainment
//
//  Created by Rolando Cruz on 6/4/19.
//  Copyright © 2019-2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMContainmentConstants_h
#define CTXMAMContainmentConstants_h

#define APPCNT_UNRESTRICTED                 @"Unrestricted"
#define APPCNT_BLOCKED                      @"Blocked"
#define APPCNT_MANAGED_APPS                 @"ManagedApps"
#define APPCNT_SECURITYGROUP                @"SecurityGroup"
#define PKEY_APPCNT_SECURITYGROUP           @"SecurityGroup"
#define DEFAULT_SECURITYGROUP               @""

// App Interaction
#define PKEY_APPCNT_CUTANDCOPY              @"CutAndCopy"
#define DEFAULT_APPCNT_CUTANDCOPY           APPCNT_SECURITYGROUP
#define PKEY_APPCNT_PASTE                   @"Paste"
#define PKEY_APPCNT_SECUREVIEWER            @"SecureViewer"
#define DEFAULT_APPCNT_SECUREVIEWER         NO
#define DEFAULT_APPCNT_PASTE                APPCNT_UNRESTRICTED
#define PKEY_APPCNT_DOCEXCHANGE             @"DocumentExchange"
#define DEFAULT_APPCNT_DOCEXCHANGE          APPCNT_SECURITYGROUP
#define PKEY_APPCNT_DOCEXCHANGE_EXCLUDE_LIST    @"DocumentExchangeExceptionList"
#define DEFAULT_APPCNT_DOCEXCHANGE_EXCLUDE_LIST @""
#define PKEY_APPCNT_INBOUND_DOCEX               @"InboundDocumentExchange"
#define DEFAULT_APPCNT_INBOUND_DOCEX            APPCNT_MANAGED_APPS
#define APPCNT_INBOUND_DOCEX_SYSTEM_WHITELIST   @"com.zenprise.zpmdmbeta,com.citrix.zenprise.zpmdmbeta,jdw.WorxHomeNE,com.citrix.client.x1,com.zenprise.zpmdbbetaInternal"

#define PKEY_APPCNT_INBOUNDURLFILTER        @"InboundURLFilter"
#define DEFAULT_APPCNT_INBOUNDURLFILTER     @""
#define PKEY_APPCNT_OUTBOUNDURLFILTER       @"OutboundURLFilter"
#define DEFAULT_APPCNT_OUTBOUNDURLFILTER    @"^http:=ctxmobilebrowser:,^https:=ctxmobilebrowsers:,^mailto:=ctxmail:"  // redirection filters only

// App Restrictions
#define PKEY_APPCNT_DISABLECAMERA           @"DisableCamera"
#define DEFAULT_APPCNT_DISABLECAMERA        YES
#define PKEY_APPCNT_DISABLEPHOTOLIBRARY     @"DisablePhotoLibrary"
#define DEFAULT_APPCNT_DISABLEPHOTOLIBRARY  NO
#define PKEY_APPCNT_DISABLEMIC              @"DisableMicrophone"
#define DEFAULT_APPCNT_DISABLEMIC           YES
#define PKEY_APPCNT_DISABLEDICTATION        @"DisableDictation"
#define DEFAULT_APPCNT_DISABLEDICTATION     YES
#define PKEY_APPCNT_DISABLELOCATION         @"DisableLocation"
#define DEFAULT_APPCNT_DISABLELOCATION      YES
#define PKEY_APPCNT_DISABLESMS              @"DisableSms"
#define DEFAULT_APPCNT_DISABLESMS           YES
#define PKEY_APPCNT_DISABLEICLOUD           @"DisableiCloud"
#define DEFAULT_APPCNT_DISABLEICLOUD        YES
#define PKEY_APPCNT_DISABLELOOKUP           @"DisableLookUp"
#define DEFAULT_APPCNT_DISABLELOOKUP        YES
#define PKEY_APPCNT_DISABLEBACKUP           @"DisableBackup"
#define DEFAULT_APPCNT_DISABLEBACKUP        YES
#define PKEY_APPCNT_DISABLEPRINTING         @"DisablePrinting"
#define DEFAULT_APPCNT_DISABLEPRINTING      YES
#define PKEY_APPCNT_DISABLEAIRDROP          @"DisableAirDrop"
#define DEFAULT_APPCNT_DISABLEAIRDROP       YES
#define PKEY_APPCNT_DISABLESOCIALMEDIA      @"DisableSocialMedia"
#define DEFAULT_APPCNT_DISABLESOCIALMEDIA   YES
#define PKEY_APPCNT_APPGROUPID              @"AppGroupId"
#define DEFAULT_APPCNT_APPGROUPID           @""
#define PKEY_APPCNT_OBSCURESCREEN           @"ObscureScreen"
#define DEFAULT_APPCNT_OBSCURESCREEN        YES
#define PKEY_APPCNT_ASSINGTOCONTACT         @"DisableAssignToContact"
#define DEFAULT_APPCNT_ASSINGTOCONTACT      YES
#define PKEY_APPCNT_DISABLEKEYBOARD         @"DisableKeyboard"
#define DEFAULT_APPCNT_DISABLEKEYBOARD      YES

// Geofence
#define PKEY_GEOFENCELATITUDE         @"GeofenceLatitude"
#define DEFAULT_GEOFENCELATITUDE      0.0
#define PKEY_GEOFENCELONGITUDE        @"GeofenceLongitude"
#define DEFAULT_GEOFENCELONGITUDE     0.0
#define PKEY_GEOFENCERADIUS           @"GeofenceRadius"
#define DEFAULT_GEOFENCERADIUS        0.0
#define kCTXCTXMAM_LAST_GPS_LOCATION     @"lastGPSLocation"

// Mail Compose Block/Redirection
#define MAIL_COMPOSE_USE_NATIVE                 @"NativeMail"
#define MAIL_COMPOSE_USE_WORXMAIL               @"WorxMail"
#define PKEY_MAIL_COMPOSE                       @"MailCompose"
#define DEFAULT_MAIL_COMPOSE                    APPCNT_BLOCKED

//Vault values
#define PKEY_LISTOFAPPSTOREAPP              @"listOfStoreApps"
#define PKEY_ALLAPPSETTING                  @"allAppsSetting"
#define kCTXCTXMAMRxPB_ISSUBSCRIBED            @"IsSubscribed"
#define kCTXSSO_APPID                       @"AppID"

//CTXMAM_Config
#define kCTXSSO_OPEN_IN_FILELENGTH          @"openinfilelength"
#define kCTXSSO_OPEN_IN_FILESTATE           @"openinfilestate"
#define kCTXSSO_OPEN_IN_FILENAME            @"openinfilename"
#define kCTXSSO_OPEN_IN_SOURCEAPP           @"openinsourceapp"
#define kCTXSSO_OPEN_IN_PASTEBOARD_TYPE     @"com.citrix.sso.openin"
#define kCTXSSO_URL_MAIL_COMPOSE_PREFIX     @"mailcompose"
#define SECUREWEB_HTTP_SCHEME               @"ctxmobilebrowser:"
#define SECUREWEB_HTTPS_SCHEME              @"ctxmobilebrowsers:"
#define kCTXSSO_OPEN_IN_SOURCEAPP_APPID     @"openinsourceappid"
#define kCTXSSO_ENCRYPTIONKEY               @"EncryptionKey"

// Share with EMAM-S-SDK (dictionary name for client properties)
#define kCTXMAMCONTAINMENT_CLIENT_PROPERTIES    @"CTXMAMContainmentClientProperties"
#endif /* CTXMAMContainmentConstants_h */
