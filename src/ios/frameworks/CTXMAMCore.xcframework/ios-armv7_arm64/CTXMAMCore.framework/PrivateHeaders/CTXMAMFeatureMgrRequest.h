//
//  CTXMAMFeatureMgrRequest.h
//  CTXMAMCore
//
//  Created by Chris Pavlou on 7/27/16.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, CTXMAMFeatureMgrRequestType)
{
	CTXMAMFeatureMgrRequestTypeEval = 0,
	CTXMAMFeatureMgrRequestTypeEvent
};

typedef NS_ENUM(NSInteger, CTXMAMFeatureMgrRequestCode)
{
	CTXMAMFeatureMgrRequestCodeNotADictionary = -1,
	CTXMAMFeatureMgrRequestCodeNoJsonData = -2,
	CTXMAMFeatureMgrRequestCodeFailedToDecodeJsonData = -3,
	CTXMAMFeatureMgrRequestCodeBadRequest = -4,
	CTXMAMFeatureMgrRequestCodeFailed = -5	// other failure or bad response code
};

NS_ASSUME_NONNULL_BEGIN

@protocol CTXMAMFeatureMgrRequestDelegate;

@interface CTXMAMFeatureMgrRequest : NSObject

@property (nonatomic, weak, readonly) id <CTXMAMFeatureMgrRequestDelegate> delegate;
@property (atomic, readonly) CTXMAMFeatureMgrRequestType requestType;

// This initializer is for Unit Testing purposes ONLY
-(instancetype)initWithRequestType:(CTXMAMFeatureMgrRequestType)type
				   requestDelegate:(id <CTXMAMFeatureMgrRequestDelegate>)requestDelegate
					  responseData:(nullable NSData *)responseData
					responseStatus:(int)responseStatus
;

-(nullable id)initWithEvalRequestWithApiKey:(NSString *)apiKey
									version:(NSString *)version
						  connectionTimeout:(NSTimeInterval)connectionTimeout
								encodedUser:(NSString *)encodedUser
							requestDelegate:(id <CTXMAMFeatureMgrRequestDelegate>)requestDelegate
;

-(nullable id)initWithBulkEventRequestWithApiKey:(NSString *)apiKey
										 version:(NSString *)version
							   connectionTimeout:(NSTimeInterval)connectionTimeout
										 userKey:(NSString *)userKey
										jsonUser:(NSString *)jsonUser
								 flagsDictionary:(NSDictionary *)flagsDictionary
								 requestDelegate:(nullable id <CTXMAMFeatureMgrRequestDelegate>)requestDelegate
;

@end

@protocol CTXMAMFeatureMgrRequestDelegate<NSObject>
-(void)featureMgrRequest:(CTXMAMFeatureMgrRequest *)request response:(nullable NSDictionary *)responseDictionary error:(nullable NSError *)error;
@end

NS_ASSUME_NONNULL_END
