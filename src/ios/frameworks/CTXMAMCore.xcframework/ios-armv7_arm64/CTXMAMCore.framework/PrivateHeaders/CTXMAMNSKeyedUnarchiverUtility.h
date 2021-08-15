//
//  CTXMAMNSKeyedUnarchiverUtility.h
//  CTXMAMCore
//
//  Created by Jaspreet Singh on 6/10/21.
//  Copyright © 2021 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// This class is created for the sole purpose of creating a utility wrapper class, with methods for the deprecated NSKeyedUnarchiver unarchive methods that throw NSException and need to be caught, configured to build with a compiler flag to generate exception-safe code for \@try-\@catch.
///
/// Performing \@try-\@catch is discouraged for multiple reasons. A few listed below:
///  - ARC is not exception-safe by default. To enable exception-safe code generation, a compiler flag -fobjc-arc-exceptions is enabled for this class.
///  - But this introduces extra code that is run even when no exception is thrown.
///  - Without ARC, it is difficult to write code that is safe against memory leaks when exceptions are used.
///
/// Wherever possible, please avoid using these methods and instead use supported iOS unarchive methods such as unarchivedObjectOfClass:fromData:error:, which returns NSError object reference instead of throwing an exception when the input data is invalid.
///
/// For more details, refer to Item# 21 of Effective Objective-C 2.0 by Matt Galloway
///
@interface CTXMAMNSKeyedUnarchiverUtility : NSObject

+ (nullable id)unarchiveObjectWithData:(NSData *)inputData error:(NSError **)error API_DEPRECATED("Use NSKeyedUnarchiver's +unarchivedObjectOfClass:fromData:error: instead", ios(2.0,12.0) );

+ (nullable id)unarchiveObjectWithData:(NSData *)inputData encodedForKey:(nonnull NSString *)encodeKey error:(NSError **)error API_DEPRECATED("Use NSKeyedUnarchiver's -initForReadingFromData:error: instead", ios(2.0,12.0) );

@end

NS_ASSUME_NONNULL_END
