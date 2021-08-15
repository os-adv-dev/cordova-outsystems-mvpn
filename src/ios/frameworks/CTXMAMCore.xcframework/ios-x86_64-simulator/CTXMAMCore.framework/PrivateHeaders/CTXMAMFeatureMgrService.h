//
//  CTXMAMFeatureMgrService.h
//  CTXMAMCore
//
//  Created by Chris Pavlou on 7/26/16.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTXMAMFeatureMgrRequest.h"

#define FEATURE_FLAG_VERSION							@"1.6"


#if BUILD_ENVIRONMENT == 'D'
#define FEATUREMGR_POLLING_INTERVAL                     60      // 1 min
#define FEATUREMGR_POLLING_INTERVAL_ON_FAILURE          2*60    // 2 mins
#define FEATUREMGR_DEFAULT_NOTIFICATION_TYPE            FeatureMgrNotificationTypeAlert

#elif BUILD_ENVIRONMENT == 'T'
#define FEATUREMGR_POLLING_INTERVAL                     10*60   // 10 mins
#define FEATUREMGR_POLLING_INTERVAL_ON_FAILURE          5*60    // 5 mins
#define FEATUREMGR_DEFAULT_NOTIFICATION_TYPE            FeatureMgrNotificationTypeAlert

#elif BUILD_ENVIRONMENT == 'P'
#define FEATUREMGR_POLLING_INTERVAL                     60*60   // 1 hour
#define FEATUREMGR_POLLING_INTERVAL_ON_FAILURE          30*60   // 1/2 hour
#define FEATUREMGR_DEFAULT_NOTIFICATION_TYPE            FeatureMgrNotificationTypeNone
#else
#define FEATUREMGR_POLLING_INTERVAL                     60*60   // 1 hour
//to be removed when build script is updated to define build environment
#define FEATUREMGR_POLLING_INTERVAL_ON_FAILURE          30*60   // 1/2 hour
#define FEATUREMGR_DEFAULT_NOTIFICATION_TYPE            FeatureMgrNotificationTypeAlert
#endif

#define FEATUREMGR_CONNECTION_TIMEOUT					60

typedef NS_ENUM(NSUInteger, FeatureMgrServiceState)
{
	FeatureMgrServiceStateIdle = 0,			// no request sent yet
	
	FeatureMgrServiceStateEvalSent,			// waiting for Eval call results
	FeatureMgrServiceStateEvalNotSent,		// could not make Eval call
	FeatureMgrServiceStateEvalFailed,		// Eval call failed; will not proceed
	FeatureMgrServiceStateEvalSuccess,		// Eval call succeeded; will now continue with the event API call.
	
	FeatureMgrServiceStateEventSent,        // waiting for Event call results
	FeatureMgrServiceStateEventNotSent,		// could not make Event call
	FeatureMgrServiceStateEventFailed,		// Event call failed
	FeatureMgrServiceStateEventSuccess		// Event call succeeded; i.e. both calls succeeded
};

typedef NS_ENUM(NSUInteger, FeatureMgrNotificationType)
{
	FeatureMgrNotificationTypeDefault			= 0,        // will use build environment's default - this is the default
	FeatureMgrNotificationTypeNone				= 1 << 0,   // none - irregardless of environment's default
	
	// These notifications are currently limited to Dev and Test environments only!
	FeatureMgrNotificationTypeAlert				= 1 << 1
};

NS_ASSUME_NONNULL_BEGIN

extern NSString * const FeatureFlagCustomPropertyCustomerIDKey;
extern NSString * const FeatureFlagCustomPropertyOSKey;
extern NSString * const FeatureFlagCustomPropertyCTXMAMVersionKey;
extern NSString * const FeatureFlagCustomPropertyAppModeKey;
extern NSString * const FeatureFlagCustomPropertyDeviceKey;
extern NSString * const FeatureFlagCustomPropertyModelKey;
extern NSString * const FeatureFlagCustomPropertyCountryKey;
extern NSString * const FeatureFlagCustomPropertyLanguageKey;

@protocol CTXMAMFeatureMgrServiceDelegate;

@interface CTXMAMFeatureMgrService : NSObject <CTXMAMFeatureMgrRequestDelegate>

@property (nonatomic, weak)                 id <CTXMAMFeatureMgrServiceDelegate>    delegate;
@property (atomic, readonly)                FeatureMgrServiceState                  serviceState;
@property (nonatomic, strong, readonly)     NSArray *                               featuresArray;			// this is set automatically when you set featureDefaultValues below
@property (nonatomic, strong)               NSDictionary<NSString *, NSNumber *> *  featureDefaultValues;
@property (nonatomic, strong)               NSString *                              mobKey;
@property (nonatomic, strong)               NSString *                              flagsRetrievedNotificationKey;	// if set, a notification will be sent when flags are retrieved

// the object property of the notification will contain an NSNumber with a BOOL with the success/failure of the retrieval
@property (nonatomic, strong, nullable)     NSString *                              lastCheckedKey;
@property (nonatomic, strong, nullable)     NSDate *                                lastCheckedDate;
@property (nonatomic)                       NSTimeInterval                          connectionTimeout;
@property (nonatomic)                       NSTimeInterval                          pollingInterval;
@property (nonatomic)                       NSTimeInterval                          pollingIntervalOnFailure;

// user properties
@property (nonatomic, strong)               NSString *userKey;
@property (nonatomic, strong)               NSString *ip;
@property (nonatomic, strong)               NSString *country;
@property (nonatomic, strong)               NSString *firstName;
@property (nonatomic, strong)               NSString *lastName;
@property (nonatomic, strong)               NSString *name;
@property (nonatomic, strong)               NSString *email;
@property (nonatomic, strong)               NSString *avatar;
@property (nonatomic, assign)               BOOL anonymous;


-(void)setCustomKey:(NSString *)key value:(nullable NSString *)value;
-(void)removeCheckForFlagsTimer;
-(void)checkToRequestFlags;
-(void)requestFlags;
-(BOOL)isWaitingForRequestReponse;
-(BOOL)didLastRequestSucceed;

@end

@protocol CTXMAMFeatureMgrServiceDelegate<NSObject>
@optional
-(void)featureMgrService:(CTXMAMFeatureMgrService *)service didReceiveFlags:(NSDictionary *)flagsDictionary;
-(void)featureMgrService:(CTXMAMFeatureMgrService *)service didCompleteServiceRequestWithSuccess:(BOOL)success;
@end

NS_ASSUME_NONNULL_END
