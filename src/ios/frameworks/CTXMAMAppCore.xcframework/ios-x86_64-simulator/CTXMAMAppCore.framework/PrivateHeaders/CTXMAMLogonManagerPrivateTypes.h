//
//  CTXMAMLogonManagerPrivateTypes.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 10/17/18.
//  Copyright © 2018 - 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMLogonManagerPrivateTypes_h
#define CTXMAMLogonManagerPrivateTypes_h

//Hub communication constants
#define KEY_PAYLOAD                                                  @"payload"
#define KEY_PAYLOAD_SIZE                                             @"plsize"

typedef NS_ENUM(NSInteger, CTXLogonRequestType)  {
    CTXLogonRequestType_None                         = 0,
    CTXLogonRequestType_UNKNOWN                      = 1,
    CTXLogonRequestType_PolicyBased                  = 3,
    CTXLogonRequestType_LogonRequiredPolicy          = 4,
    CTXLogonRequestType_IPCResponseLogonRequired     = 5,
    CTXLogonRequestType_IPCResponseFailure           = 6,
    CTXLogonRequestType_OfflineLeaseExpired_ReAuth   = 10,
    CTXLogonRequestType_OfflineChallengeRequired     = 12,
    CTXLogonRequestType_TimerWarning                 = 13,
    CTXLogonRequestType_LogonFailed                  = 14,
    CTXLogonRequestType_NetworkAccess                = 18,
    CTXLogonRequestType_STATicketExpired             = 19,
    CTXLogonRequestType_AutoSubscriptionRequest      = 20,
    CTXLogonRequestType_StepupAuthRequired           = 21,
    CTXLogonRequestType_SDKAPI                       = 24,
    CTXLogonRequestType_StatusWatchdogEnforceLock    = 25,
    CTXLogonRequestType_StatusWatchdogEnforceWipe    = 26,
    
    CTXLogonRequestType_SharedDevice_NeedsActiveUser = 30,
    CTXLogonRequestType_SDK_App_Logon                = 31,
    CTXLogonRequestType_SDK_DeviceStateChange        = 32
};

#endif /* CTXMAMLogonManagerPrivateTypes_h */
