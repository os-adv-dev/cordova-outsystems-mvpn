//
//  CTXMAMSSMobileAppData.h
//  CTXMAMAppCore
//
//  Created by Jaspreet Singh on 3/17/15.
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTXMAMSSMobileAppData : NSObject <NSCopying>

@property(nonatomic,strong) NSString*	appName;
@property(nonatomic,strong) NSString*	appStoreUrl;
@property(nonatomic,strong) NSString*	appUniqueID;
@property(nonatomic,strong) NSString*	mobileAppID;
@property(nonatomic,strong) NSString*	mobileToolVersion;
@property(nonatomic,strong) NSString*	mobileAppVersion;
@property(nonatomic,strong) NSString*	packageID;
@property(nonatomic,strong) NSString*	policies;
@property(nonatomic,strong) NSDate*		policiesTimestamp;
@property(nonatomic,strong) NSString*	publicKey;
@property(nonatomic,strong) NSString*	resourceID;
@property(nonatomic,strong) NSString*	timestamp;
@property(nonatomic,strong) NSString*	urlScheme;
@property(nonatomic,strong) NSString*   bundleID;
@property(nonatomic,strong) NSString*	wrappingDateTime;

@property(nonatomic,assign) BOOL		requiredUserEntropyPolicyEnabled;

@property(nonatomic,assign) BOOL		isInstalled;
@property(nonatomic,assign) BOOL		isSubscribed;
@property(nonatomic,strong) NSString*	storeID;
@property(nonatomic,assign) int			subscriptionState;

@property(nonatomic,strong) NSString*	resourceURL;
@property(nonatomic,strong) NSString*	resourceTranslatedURL;

@property(nonatomic,strong) NSString *  logTarget;
@property(nonatomic,assign) int32_t     logLevel;

@end
