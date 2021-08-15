//
//  CTXMAMShareFileAPIsConstants.h
//  CTXMAMAppCore
//
//  Created by Jaspreet Singh on 5/28/21.
//  Copyright © 2021 Citrix Systems Inc. All rights reserved.
//

#ifndef CTXMAMShareFileAPIsConstants_h
#define CTXMAMShareFileAPIsConstants_h

// SAML Token request error codes
typedef enum {
    CTXMAMShareFile_NoError = 0,
    CTXMAMShareFile_SAMLToken_NotSetup,
    CTXMAMShareFile_SAMLToken_NoDeviceID,
    CTXMAMShareFile_SAMLToken_Expired,
    CTXMAMShareFile_SAMLToken_MissingData,
    CTXMAMShareFile_SAMLToken_ParsingError,
    CTXMAMShareFile_SAMLToken_LogonFailure,
    CTXMAMShareFile_Connectors_NotSetup,
    CTXMAMShareFile_CannotConnectToHost
} CTXMAMShareFileRequestError;


// Error domains
extern NSString * const CTXMAMShareFileErrorDomain;
extern NSString * const CTXMAMShareFileHTTPErrorDomain;


// SAML token details dictionary keys
extern NSString * const CTXMAMShareFileSAMLToken;
extern NSString * const CTXMAMShareFileSubDomain;

#endif /* CTXMAMShareFileAPIsConstants_h */
