//
//  CTXMAMShareFileAPIs.h
//  CTXMAMAppCore
//
//  Created by Jaspreet Singh on 4/6/21.
//  Copyright © 2021 Citrix Systems Inc. All rights reserved.
//

#import <CTXMAMCore/CTXMAMCore.h>
#import <CTXMAMAppCore/CTXMAMShareFileAPIsConstants.h>

NS_ASSUME_NONNULL_BEGIN

// Completion block types
typedef void(^CTXMAMShareFileSAMLTokenRequestCompletionBlock)(NSDictionary * _Nullable samlTokenInfo, NSError * _Nullable error);

typedef void(^CTXMAMShareFileConnectorsRequestCompletionBlock)(NSData * _Nullable connectorsData, NSError * _Nullable error);


@interface CTXMAMShareFileAPIs : NSObject

///
/// Provides already cached SAML token info retrieved from CEM server. This info could have been fetched by MAM SDK or SecureHub
/**
 *  @param error Returns NSError object in case of any failure to retrieve SAML token. You may get one of these error codes, CTXMAMShareFile_SAMLToken_NotSetup, CTXMAMShareFile_SAMLToken_Expired, or  CTXMAMShareFile_SAMLToken_MissingData, with error domain CTXMAMShareFileErrorDomain.
 *  @return If SAML is configured, this API returns a NSDictionary with two string fields, SAMLToken and SubDomain, keyed with CTXMAMSAMLToken and CTXMAMSubDomain respectively. Returns nil, if SAML is not configured for the managed user.
 *  @discussion
 *  This call shouldn't make any network call directly.
 */
+(nullable NSDictionary *) getCachedSAMLTokenDetailsWithError:(NSError **) error;


///
/// Asynchronously requests SAML token from the configured CEM server. over network
/**
 @param timeout Timeout for the network request, in seconds. Recommended 10 seconds.
 @param completionBlock Called when network request finishes. If successful, it returns NSDictionary with SAML token info, otherwise returns NSError object is updated with relevant failure details.
 @return YES if request was sent, NO if SAML is not configured or failed to send the request.
 */
+(BOOL) requestSAMLTokenDetailsWithTimeout:(NSTimeInterval)timeout
                        andCompletionBlock:(CTXMAMShareFileSAMLTokenRequestCompletionBlock) completionBlock;

///
/// Asynchronously requests CEM server to return configured Sharefile connectors.
/**
 @param timeout Timeout for the request.
 @param completionBlock Called when network request finishes. If successful, a JSON payload containing connectors data is set, which contains a string representing an enumeration of configured Sharefile connectors. If API fails, nil is returned and error._code field will be one of:
 kERR_OPERATION_NOT_SUPPORTED - Server does not provide end-point or admin has not configured the SF connectors
 kERR_LOGON_REQUIRED - Client does not have valid logon session to XenMobile server or netscaler gateway
 kERR_NO_NETWORK - Network not bound
 kERR_HTTP_ERROR - HTTPS network request to server failed
 Also, error._domain may include additional information about the error
 @return YES if request was sent successfully, otherwise NO.
 */
+(BOOL) requestShareFileConnectorsWithTimeout:(NSTimeInterval)timeout
                           andCompletionBlock:(CTXMAMShareFileConnectorsRequestCompletionBlock) completionBlock;

@end

NS_ASSUME_NONNULL_END
