//
//  CTXMAMAnalyticsConfig.h
//  CTXMAM_WrappedAppLib
//
//  Created by Chris Pavlou on 4/13/17.
//  Copyright © 2017-2021 Citrix Systems, Inc. All rights reserved.
//
#ifndef CTXMAMAnalyticsConfig_h
#define CTXMAMAnalyticsConfig_h


#if BUILD_ENVIRONMENT == 'D'

#define POLICY_UPDATE_TIMEINTERVAL						5*60		// 5 minutes
#define GA_TRACKING_ID									@"UA-76277810-5"	// mdxTrackerTest account
#define GA_DIMENSION_LIMIT								20
#define GA_DISPATCH_INTERVAL							10			// 10 seconds
#define GA_LOGGING_LEVEL								kCAILogLevelVerbose
#define Analytics_Debug_Log(fmt,...)					CTXMAMLOG_Detail(CTXLog_SourceName, fmt, ##__VA_ARGS__)

#elif BUILD_ENVIRONMENT == 'T'

#define POLICY_UPDATE_TIMEINTERVAL						1*60*60		// 1 hour
#define GA_TRACKING_ID									@"UA-54208118-47"	// premium account (Secure Hub iOS QA)
#define GA_DIMENSION_LIMIT								200
#define GA_DISPATCH_INTERVAL							60			// 60 seconds
#define GA_LOGGING_LEVEL								kCAILogLevelVerbose
#define Analytics_Debug_Log(fmt,...)					CTXMAMLOG_Detail(CTXLog_SourceName, fmt, ##__VA_ARGS__)

#elif BUILD_ENVIRONMENT == 'P'

#define POLICY_UPDATE_TIMEINTERVAL						1*24*60*60	// 1 day
#define GA_TRACKING_ID									@"UA-54208118-48"	// premium account (Secure Hub iOS Prod)
#define GA_DIMENSION_LIMIT								200
#define GA_DISPATCH_INTERVAL							3*60		// 3 minutes
#define GA_LOGGING_LEVEL								kCAILogLevelError
#define Analytics_Debug_Log(fmt,...)					// nothing

#endif

#endif

#if BUILD_ENVIRONMENT == 'D'
#define BUILD_ENVIRONMENT_STR                "Dev"
#elif BUILD_ENVIRONMENT == 'T'
#define BUILD_ENVIRONMENT_STR                "Test"
#elif BUILD_ENVIRONMENT == 'P'
#define BUILD_ENVIRONMENT_STR                "Prod"
#endif
