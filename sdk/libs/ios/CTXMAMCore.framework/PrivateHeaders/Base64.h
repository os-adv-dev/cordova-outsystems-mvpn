//
//  Base64.h
//  CtxSingleSignOn
//
//  Created on 3/20/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


// Base64 base class
//
@interface CTXMAM_Base64 : NSObject

+ (NSString *)encode:(NSString *)plainText;
+ (NSString *)decode:(NSString *)base64String;
+ (NSString *)encodeWithoutLinebreaks:(NSString *)plainText;

+ (NSString*)encodeObject:(id)clearObject;
+ (id)objectDecode:(NSString*)encodedString;

@end


