//
//  CTXMAMFeatureMgrConfig.h
//  CTXMAMCore
//
//  Created by Chris Pavlou on 4/6/17.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMFeatureMgrConfig_h
#define CTXMAMFeatureMgrConfig_h


#if BUILD_ENVIRONMENT == 'D'
#define LD_MOB_KEY                                        @"mob-f0b18360-a805-4d90-b5b1-29cbe00d5d8b"
#elif BUILD_ENVIRONMENT == 'T'
#define LD_MOB_KEY                                        @"mob-552414f7-63b0-4b2a-83e6-4791c4f993c4"
#elif BUILD_ENVIRONMENT == 'P'
#define LD_MOB_KEY                                        @"mob-e20efb0c-d42e-4aad-ac07-452d8c9892d2"
#else
#define LD_MOB_KEY                                        @"mob-e20efb0c-d42e-4aad-ac07-452d8c9892d2"
#endif

extern NSString * const CTXMAMFeatureFlagsRetrievedNotification;
extern NSString * const CTXMAMFeatureFlagLastCheckedKey;

// add new CTXMAM features here
extern NSString * const CTXMAMFeature_Dual_Mode_SDK_support;
extern NSString * const CTXMAMFeature_AppExtension_LogCollection;

// Feature Flag Extended Analytics
// Description:
//   Extending analytics enables the sdk to send more analytic events than the usual like how extending logs would add more logging. Example events are worxpin events
// Default value when cant hit server:
//   BOOL: No, FALSE
extern NSString * const MdxFeature_ExtendedAnalytics;
// Feature Flag Enable Analytics
// Description:
//   When turned on along with policy on XMS would enable the SDKs to send analtyics data to google analytics
// Default value when cant hit server:
//   BOOL: No, FALSE
extern NSString * const MdxFeature_EnableAnalytics;
extern NSString * const MdxBugFix_mVPN_hash_fix;
extern NSString * const MdxBugFix_Reload_On_Container_Restart;


// add new CTXMAM features in this dictionary along with its default value (as an NSNumber)
#define CTXMAM_FEATURES_DICTIONARY					@{ \
                                                    CTXMAMFeature_Dual_Mode_SDK_support : @YES, \
                                                    CTXMAMFeature_AppExtension_LogCollection : @NO, \
                                                    MdxFeature_EnableAnalytics : @NO, \
                                                    MdxFeature_ExtendedAnalytics : @NO, \
                                                    MdxBugFix_mVPN_hash_fix : @NO, \
                                                    MdxBugFix_Reload_On_Container_Restart : @YES, \
                                                    }

#endif /* CTXMAMFeatureMgrConfig_h */
