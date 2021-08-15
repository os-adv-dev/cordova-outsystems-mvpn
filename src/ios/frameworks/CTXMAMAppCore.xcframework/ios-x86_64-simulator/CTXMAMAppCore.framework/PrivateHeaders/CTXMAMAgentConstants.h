//
//  CTXMAMAgentConstants.h
//  CTXMAMAgentSubsystem
//
//  Created by Jaspreet Singh on 5/5/15.
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//


#define kMDXREQUEST_CURRENT_URLVERSION		3

#define MdxSubsystemErrorDomain             @"com.citrix.mdxsubsystem"

/// URL requests...
#define kMDXREQUEST_STARTAPPREGISTRATION	@"mdxss.startappregistration"
#define kMDXREQUEST_NETWORKLOGON			@"mdxss.networklogon"
#define kMDXREQUEST_SDK_APP_LOGON           @"mdxss.sdkapplogon"
#define kMDXREQUEST_SDK_APP_LOGON_CWA       @"mdxss.sdkapplogoncwa"
#define kMDXREQUEST_UPDATEAPP				@"mdxss.updateapp"
#define kMDXREQUEST_DEVICELOCK				@"mdxss.devicelock"
#define kMDXREQUEST_ESDK_DEVICELOCK         @"mdxss.esdk.devicelock"
#define kMDXREQUEST_PASSCODEPINRESET		@"mdxss.passcodepinreset"
#define kMDXREQUEST_RECOVERSHAREDVAULT		@"mdxss.recoversharedvault"
#define kMDXREQUEST_VPNLOGON				@"mdxss.vpnlogon"

#define kMDXREQUEST_ARG_URLVERSION			@"mdxurlversion"
#define kMDXREQUEST_ARG_ISRESPONSE			@"mdxresponse"	/// TODO: change it to purpose..

//#define kNETWORKLOGON_ARG_TYPE			@"logontype"
//#define kNETWORKLOGON_ARG_TYPE_VPN		@"vpn"
//#define kNETWORKLOGON_ARG_TYPE_STEPUP		@"stepup"

#define kPASSCODEPINRESET_ARG_TYPE				@"passcodetype"
#define kPASSCODEPINRESET_ARG_TYPE_ADPASSWORD	@"adpassword"
#define kPASSCODEPINRESET_ARG_TYPE_PIN			@"pin"

#define kMDXREQUEST_TIME                    @"mdxrequest.time" ///Used as encryption seed.

