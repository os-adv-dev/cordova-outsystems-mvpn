//
//  CTXMAMServerAppDataRequest.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 9/24/18.
//  Copyright © 2018 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static const NSString *httpCitrixErrorHeader    = @"X-Citrix-Error-Reason";
static const NSString *httpCitrixErrorAppState  = @"X-Citrix-App-State";
static const NSString *httpCitrixDeviceIdHeader = @"X-Citrix-Device-ID";
static const NSString *httpCitrixAppIDHeader    = @"X-Citrix-AppID";
static const NSString *httpCitrixXHeader        = @"X-Citrix-AppID";
static const NSString *httpAuthorizationHeader  = @"Authorization";

#define ProxiedURLProtocolURLHeader               @"X-Header"

typedef void (^URLRequestCompletionBlock)(bool bSuccess, NSHTTPURLResponse * response, NSData * receivedData, NSError * _Nullable error);

@interface CTXMAMServerAppDataRequest : NSObject <NSURLSessionTaskDelegate>

@property (nonatomic, strong, nullable) NSURLSession        *connection;
@property (nonatomic, strong, nullable) NSMutableURLRequest *request;

+ (NSDictionary *) getAutheticationHeadersBasedOnLogonInfo:(NSDictionary *)logonInfo;

- (void)sendRequestToURL:(NSString * _Nonnull)urlString
                 headers:(NSDictionary *)headers
              sendMethod:(NSString *)sendMethod
                 timeout:(NSTimeInterval)timeout
         completionBlock:(URLRequestCompletionBlock)compBlock;

- (void)issueRequest:(NSMutableURLRequest *)urlRequest
withIgnoreCertErrorsOption:(BOOL)ignoreCertificateErrors
             timeout:(NSTimeInterval)timeout
     completionBlock:(URLRequestCompletionBlock)compBlock;

-(BOOL)isProxyPresent:(NSURL *)url;
-(CFArrayRef)copyProxiesForURL:(NSURL*)url;
-(BOOL)getAllowClientSideProxy;
+(nullable NSURLCredential *)getAGClientCertCredential;
@end

NS_ASSUME_NONNULL_END
