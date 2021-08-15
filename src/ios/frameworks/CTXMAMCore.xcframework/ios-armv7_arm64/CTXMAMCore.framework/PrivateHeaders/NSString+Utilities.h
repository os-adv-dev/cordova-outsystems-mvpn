//
//  NSString+Utilities.h
//  CTXMAMCore (originally from: CTXMAM_WrappedAppLib)
//
//  Created by Jaspreet Singh on 6/15/17.
//  Copyright © 2017-2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Utilities)

- (NSString *)CTXMAMTrim;
- (NSString *)base64EncodedSHA256Hash;
- (NSData *)SHA256Hash;

@end
