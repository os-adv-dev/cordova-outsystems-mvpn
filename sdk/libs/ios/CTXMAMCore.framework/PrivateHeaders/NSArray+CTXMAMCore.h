//
//  NSArray+CTXMAMCore.h
//  CTXMAMCore
//
//  Created by Jaspreet Singh on 12/9/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (CTXMAMCore)

- (BOOL)ctxmamContainsString:(NSString *) str caseSensitive:(BOOL)caseSensitive;

@end

NS_ASSUME_NONNULL_END
