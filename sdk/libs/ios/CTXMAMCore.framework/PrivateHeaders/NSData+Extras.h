//
//  NSData+Extras.h
//  CTXMAM_WrappedAppLib
//
//  Created by Chris Pavlou on 11/30/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Extras)

/**
 * Returns an md5 string from the receiver's contents.
 * @return An NSString with the md5 representation of the receiver's contents.
 */
-(NSString *)md5String;

/**
 * Compress the receiver's contents.
 * @return A new NSData object with the receiver's contents compressed.
 */
-(NSData *)compress;

@end
