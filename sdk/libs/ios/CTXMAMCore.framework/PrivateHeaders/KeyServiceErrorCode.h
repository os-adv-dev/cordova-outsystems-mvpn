//
//  KeyServiceErrorCode.h
//  DataEncryption
//
//  Created on 12/13/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef DataEncryption_KeyServiceErrorCode_h
#define DataEncryption_KeyServiceErrorCode_h


typedef enum
{
    KeyServiceErr_Success = 0,
    KeyServiceErr_Fail_LogonRequired,  //Error when logon to receiver is required. This error code will cause wrapper to flip to receiver and logon
    KeyServiceErr_Fail_UserCredentialRequired,  // only need the credential, no need for tokens to log on to vault servers
    KeyServiceErr_Fail_DeviceId,
    KeyServiceErr_Fail_VaultServers,
    KeyServiceErr_Fail_AppCurl,
    KeyServiceErr_Fail_OnlineKeys,
    KeyServiceErr_Fail_OfflineKeys,
    KeyServiceErr_Fail_AuthManager,
    KeyServiceErr_Fail_CertError,
    KeyServiceErr_Fail_NoNetwork,
    KeyServiceErr_Fail_Unknown,         // Error when key failure dialog is display
    KeyServiceErr_Fail_CallocFailed,
    KeyServiceErr_Fail_DecodeFailure
}KeyServiceErrorCode;


#endif
