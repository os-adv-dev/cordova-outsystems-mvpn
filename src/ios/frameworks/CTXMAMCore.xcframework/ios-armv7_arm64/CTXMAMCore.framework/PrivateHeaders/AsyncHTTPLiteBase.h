//
//  AsyncHTTPLite.h
//  ReceiverForiPad
//
//  Created by jeffwi on 10/12/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef HTTP_OK_200
#define HTTP_OK_200 200
#endif
#ifndef HTTP_MOVED_TEMP_302
#define HTTP_MOVED_TEMP_302 302
#endif
#ifndef HTTP_FORBIDDEN_403
#define HTTP_FORBIDDEN_403 403
#endif
#ifndef HTTP_NOTFOUND_404
#define HTTP_NOTFOUND_404 404
#endif
#ifndef HTTP_NOTAUTHORIZED_401
#define HTTP_NOTAUTHORIZED_401 401
#endif
#define DEFAULT_HTTP_CONNECTION_TIMEOUT_SECONDS 30.0
#ifndef HTTP_USER_CANCELLED
#define HTTP_USER_CANCELLED 900
#endif


@interface AsyncHTTPLiteBase : NSObject {
    NSURLConnection       *connection;
    NSMutableURLRequest   *request;
    NSHTTPURLResponse     *response;	
    NSMutableData         *data;
    NSError               *error;
    NSString              *errorString;
    BOOL                   connectionComplete;
    BOOL                   redirect;
    BOOL                   ignoreCertErrors;
    NSTimer* timeoutTimer;
}

@property (nonatomic, strong) NSURLConnection     *connection;
@property (nonatomic, strong) NSMutableURLRequest *request;
@property (nonatomic, strong) NSHTTPURLResponse   *response;
@property (nonatomic, strong) NSMutableData       *data;
@property (nonatomic, strong) NSError             *error;
@property (nonatomic, copy)   NSString            *errorString;
@property (getter=isRedirect) BOOL                redirect;
@property (nonatomic, assign) BOOL                ignoreCertErrors;

@property (readonly) int statusCode;
@property (unsafe_unretained, readonly) NSString *dataAsString;

+ (AsyncHTTPLiteBase *)asyncHTTP;
+ (AsyncHTTPLiteBase *)asyncHTTPWithRedirect:(BOOL)redirect;

- (NSData *)issueRequest:(NSMutableURLRequest *)request withIgnoreCertErrorsOption:(BOOL)ignoreCertificateErrors timeout:(NSTimeInterval)timeout;
- (NSData *)issueRequest:(NSMutableURLRequest *)request withIgnoreCertErrorsOption:(BOOL)ignoreCertificateErrors;
- (int)statusCode;

- (NSString *)valueForHeaderKey:(NSString *)key;
@end
