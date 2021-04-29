//
//  CTXMAMCoreConstants.h
//  CTXMAMCore
//
//  Created by Jaspreet Singh on 10/1/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMCoreConstants_h
#define CTXMAMCoreConstants_h

#define CTXMAMCORE_ERROR_DOMAIN     @"CTXMAMCoreErrorDomain"
#define ProxiedURLProtocolURLHeader @"X-Header"
#define DONT_USE_VPN_HEADER_VALUE   @"noVPN"
#define SECUREBROWSE_PATH_FORMAT    @"/cvpn/%@"
#define VPNLOGON_URL_PATH           @"/vpn/index.html"

typedef NS_ENUM(NSUInteger, CTXMAMCoreError)
{
    CTXMAMCore_AuthInfoNotFound = 1001,
    CTXMAMCore_ServerResponse_VPNLogon
};

#endif /* CTXMAMCoreConstants_h */
