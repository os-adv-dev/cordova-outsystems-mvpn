//
//  CTXMAMConfigManager+AppCore.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 7/30/18.
//  Copyright © 2018 - 2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef XmsConfigManagerPrivate_h
#define XmsConfigManagerPrivate_h

#import "CTXMAMConfigManagerPrivate.h"
#import "CTXMAMConfigManagerTypes.h"
#import "CTXMAMLogonManagerPrivateTypes.h"

NS_ASSUME_NONNULL_BEGIN

extern __attribute__((visibility ("default"))) NSString * _Nonnull const kWorxUsername;
//extern __attribute__((visibility ("default"))) NSString * _Nonnull const kSharedDeviceEnabled;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const kCTXMAMLdapUserPrincipalName;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const kCTXMAMLdapSAMAccountName;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const kCTXMAMLdapDisplayName;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const kCTXMAMLdapMail;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const CTXMAMPersistentDeviceId;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const CTXMAMStoreUserId;
extern __attribute__((visibility ("default"))) NSString * _Nonnull const CTXMAMStoreCustomerId;

typedef NS_ENUM(NSInteger, DeviceEnrollmentConfiguration)
{
    DeviceEnrollmentConfig_None = 0,
    DeviceEnrollmentConfig_MAM_ONLY,
    DeviceEnrollmentConfig_MDM_MDX,
    DeviceEnrollmentConfig_MDM_ONLY
};

@interface CTXMAMConfigManager(AppCore)

@property (readonly)        NSString *              packageID;

//Log Settings related policies
-(void) fetchXMSServerConfigAndReloginOnFailure:(BOOL) relogin andNotifyOfRemoteDataUpdate:(BOOL) notify;
-(void) notifyAppNotMDMEnrolled;
-(BOOL) isAppNotEntitled;
-(BOOL) isStoreNotConfigured;
-(nullable NSString *) storeUserName;
-(BOOL) isAppMobileAggregationEnabled;

//SecureWeb / SecureMail specific calls, please keep all of these private
-(id) getValueForPolicyKey:(NSString *) policyKey;
-(void) getSTATicketWithCompletionBlock:(void (^)(NSString *_Nullable STATicket, NSError *_Nullable error)) block;

-(void) getDeviceStateWithCompletionBlock:(void (^)(NSString *_Nullable deviceState, NSError *_Nullable error)) block;
- (NSString *)getConfigurationInfoDescription;

/**
 *  Returns managed user information
 *  @return A dictionary of managed user details keyed by strings declared right after the API.
 */
-(NSDictionary *_Nullable) managedUserInformation;

/**
 * Returns the shared identifier info dictionary
 * @discussion The keys for this dictionary are listed below:
 * @code
 *extern NSString *const CTXMAMPersistentDeviceId;
 *extern NSString *const CTXMAMStoreUserId;
 *extern NSString *const CTXMAMStoreCustomerId;@endcode
 * @return A dictionary with identifier info shared between WH/CTXMAM/Apps
 */
-(NSDictionary<NSString *, NSString *> *_Nullable) getSharedIdentifierInfo;

-(void) registerForPolicyModeChangeNotificationsWithBlock:(void(^)(CTXMAMPolicyMode newPolicyMode)) block;
-(void) registerForRemoteDataUpdateNotificationsWithBlock:(void(^)(BOOL)) block;
-(DeviceEnrollmentConfiguration) getDeviceEnrollmentConfigurationWithError:(NSError **) error;

// Start Launch Darkly
-(void) startLaunchDarkly;
@end

NS_ASSUME_NONNULL_END

#endif /* XmsConfigurationManagerInternal_h */
