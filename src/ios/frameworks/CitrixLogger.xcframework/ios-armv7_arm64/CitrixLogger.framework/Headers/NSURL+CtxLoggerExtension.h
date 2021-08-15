//
//  NSURL+CtxLoggerExtension.h
//  CtxLogger
//
//  Copyright © 2019 Citrix. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AvailabilityMacros.h>

#define INDICATE_QUERY_DEPRECATION DEPRECATED_MSG_ATTRIBUTE("Deprecated in this CitrixLogger version. Please use the method CtxLogManager obfuscateQueriesInUrl:(NSURL*)url.. instead")

@interface NSURL (CtxLoggerExtension)

- (NSString *) ctxStringByObfuscatingQueryParameters INDICATE_QUERY_DEPRECATION ;

@end
