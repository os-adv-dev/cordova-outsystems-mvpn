//
//  CTXMAMServerAppData.h
//  CTXMAMAppCore
//
//  Created by Jaspreet Singh on 5/16/15.
//  Copyright © 2015 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CtxDataXML.h"
#import "CtxGDataXMLHelper.h"

NS_ASSUME_NONNULL_BEGIN

#define WRAPPER_APPUNIQUEID                     @"AppUniqueID"
#define WRAPPER_WRAPPINGTIMESTAMP               @"WrappingTimestamp"
#define SSO_BUNDLE_ID                           @"BundleID"
#define kCTXSSO_XMSSERVERBASEURL                @"xmsServerBaseURL"
#define CTX_ALL_APPS_URL                        @"/Citrix/Store/resourceswithautoprovision/v2"

typedef enum
{
    SUBSCRIBED_PENDING = 1,
    SUBSCRIBED,
    NOT_SUBSCRIBED,
    DENIED
} SubscriptionState;

@class CTXMAMSSMobileAppData;

typedef void (^CTXMAMServerRequestCompletionBlock)(bool bSuccess, NSString * _Nullable xmlData, NSError * _Nullable error);
typedef void (^MobileAppDataCompletionBlock)(bool bSuccess, CTXMAMSSMobileAppData * _Nullable appData);
typedef void (^MobileAllAppDataCompletionBlock)(bool bSuccess, NSMutableArray<CTXMAMSSMobileAppData *> * _Nullable appData);
typedef void (^AllAppDataCompletionBlock)(bool bSuccess, NSMutableDictionary<NSString*,NSDictionary *> * _Nullable  allAppsData);

static NSString * const kSubscriptionNamespace = @"http://citrix.com/delivery-services/2-0/subscriptions";
static NSString * const kResourceNamespace     = @"http://citrix.com/delivery-services/2-0/resources";

@interface CTXMAMServerAppData : NSObject

+ (CTXMAMServerAppData *) sharedInstance;

+(void) refreshAppInfoFromServerWithLogonInfo:(NSDictionary *)logonInfo
                                      appInfo:(NSDictionary *)appInfo
                           andCompletionBlock:(void(^)(BOOL bSuccess, NSDictionary * policies, NSError * error)) block;

+(void)getAllAppsPropertyWithSecureHubInfo:(NSDictionary *)secureHubInfo andCompletionBlock:(AllAppDataCompletionBlock) block;

-(void) getMobileAppDataFromAppResourceURL:(NSString*)appResourceURL
                             withLogonInfo:(NSDictionary *)logonInfo
                           completionBlock:(CTXMAMServerRequestCompletionBlock) completionBlock;

-(CTXMAMSSMobileAppData*)parseMobileAppData:(GDataXMLElement_W*)resource namespaceDict:(NSDictionary *)namespaceDict;

+(NSDictionary *) createMobileAppDataDictionary:(CTXMAMSSMobileAppData*)appData;

@end

NS_ASSUME_NONNULL_END

