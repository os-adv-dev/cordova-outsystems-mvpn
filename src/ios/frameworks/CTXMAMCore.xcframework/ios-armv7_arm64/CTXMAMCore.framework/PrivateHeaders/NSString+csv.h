//
//  NSString+csv.h
//  CTXMAM_WrappedAppLib
//
//  Created on 5/9/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (csv)

- (NSArray<NSString *> *)ssidsSeparatedByComma;
- (NSArray<NSString *> *)componentsSeparatedByComma;
- (NSArray<NSString *> *)componentsSeparatedByCommaAndTrimmed;
- (NSString *)trimLeadingCharactersInSet:(NSCharacterSet *)set;
- (NSString *)trimTrailingCharactersInSet:(NSCharacterSet *)set;
- (NSDictionary<NSString *, NSString *> *)keyValuePairsSeparatedByComma;
- (NSString*)sanitizeDomainSuffix;

@end
