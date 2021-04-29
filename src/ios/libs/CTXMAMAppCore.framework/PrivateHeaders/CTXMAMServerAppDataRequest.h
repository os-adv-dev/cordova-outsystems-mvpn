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
static const NSString *httpAuthorizationHeader  = @"Authorization";

typedef void (^URLRequestCompletionBlock)(bool bSuccess, NSHTTPURLResponse * response, NSData * receivedData, NSError * error);

@interface CTXMAMServerAppDataRequest : NSObject <NSURLSessionTaskDelegate>

@property (nonatomic, strong, nullable) NSURLSession        *connection;
@property (nonatomic, strong, nullable) NSMutableURLRequest *request;
@property (nonatomic, strong, nullable) NSHTTPURLResponse   *response;
@property (nonatomic, strong, nullable) NSMutableData       *data;
@property (nonatomic, strong, nullable) NSError             *error;
@property (nonatomic, copy, nullable)   NSString            *errorString;
@property (getter = isRedirect) BOOL                        redirect;
@property (nonatomic, assign) BOOL                          ignoreCertErrors;

@property (readonly) int statusCode;
@property (unsafe_unretained, readonly) NSString *dataAsString;

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
@end

NS_ASSUME_NONNULL_END
