//
//  NSString+Conversions.h
//
//  Created by Chris Pavlou on 5/19/16.
//  Copyright © 2019 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Conversions)

/**
 * Returns a string representating the given boolean value.
 * @param value The boolean value to evaluate.
 * @return A string with "true" or "false" representating the given boolean value.
 */
+(NSString *)trueOrFalseWithBoolean:(BOOL)value;

/**
 * Returns a string representating the given boolean value.
 * @param value The boolean value to evaluate.
 * @return A string with "on" or "off" representating the given boolean value.
 */
+(NSString *)onOrOffWithBoolean:(BOOL)value;

/**
 * Returns a string representating the given boolean value.
 * @param value The boolean value to evaluate.
 * @return A string with "YES" or "NO" representating the given boolean value.
 */
+(NSString *)yesOrNoWithBoolean:(BOOL)value;

/**
 * Returns a string representating the given boolean value.
 * @discussion A wrapper method that just calls the default trueOrFalseWithBoolean: method.
 * @param value The boolean value to evaluate.
 * @return A string with "true" or "false" representating the given boolean value.
 */
+(NSString *)stringWithBoolean:(BOOL)value;

/**
 * Create a Base-64 encoded NSString with no line endings from the receiver's contents.
 * @discussion Encoding uses the default behavior of base64EncodedStringWithOptions: which does not insert line endings.
 * @return A Base-64 encoded string.
 */
-(NSString *)base64Encode;

/**
 * Create a Base-64 encoded NSString with from the receiver's contents using the given line ending options.
 * @param options A mask that specifies options for Base-64 encoding the string. This value is passed to base64EncodedStringWithOptions:.
 * @return A Base-64 encoded string.
 */
-(NSString *)base64EncodeWithOptions:(NSDataBase64EncodingOptions)options;

/**
 * Returns a string object initialized from decoding the given Base-64 encoded string.
 * @discussion Decoding uses the initWithBase64EncodedString:options: method of NSData and using the NSDataBase64DecodingIgnoreUnknownCharacters option.
 * @return A string built by Base-64 decoding the receiver's string. Returns an empty string if the given string could not be decoded.
 */
-(NSString *)base64Decode;

/**
 * Returns an md5 string from the receiver's contents.
 * @return An NSString with the md5 representation of the receiver's contents.
 */
-(NSString *)md5String;

/**
 * Returns a SHA256 string from the receiver's contents.
 * @return An NSString with the SHA256 representation of the receiver's contents.
 */
-(NSString *)sha256String;

/**
 * Returns a reverse version of the receiver's string.
 * @return The reverse of the given string.
 */
-(NSString *)reverse;

@end
