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
#define LD_MOB_KEY                                        @"mob-db31f32e-5dff-4324-a668-bfb33ea082b0"
#elif BUILD_ENVIRONMENT == 'T'
#define LD_MOB_KEY                                        @"mob-33fd395e-2111-4cf1-aa86-e5c706cbb340"
#elif BUILD_ENVIRONMENT == 'P'
#define LD_MOB_KEY                                        @"mob-f02771ee-8a09-467d-8dd5-8a827cca5cbc"
#else
#define LD_MOB_KEY                                        @"mob-f02771ee-8a09-467d-8dd5-8a827cca5cbc"

#endif

extern NSString * const CTXMAMFeatureFlagsRetrievedNotification;
extern NSString * const CTXMAMFeatureFlagLastCheckedKey;

// add new CTXMAM features here
extern NSString * const CTXMAMFeature_Dual_Mode_SDK_support;
extern NSString * const CTXMAMFeature_AppExtension_LogCollection;


// add new CTXMAM features in this dictionary along with its default value (as an NSNumber)
#define CTXMAM_FEATURES_DICTIONARY					@{ \
                                                    CTXMAMFeature_Dual_Mode_SDK_support : @YES, \
                                                    CTXMAMFeature_AppExtension_LogCollection : @NO, \
                                                    }

#endif /* CTXMAMFeatureMgrConfig_h */
