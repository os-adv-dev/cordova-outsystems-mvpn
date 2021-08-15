//
//  CtxObjectCache.h
//  CtxSingleSignOn
//
//  Created on 9/27/13.
//  Copyright © 2013 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kDefaultCacheAge        5       // 5 seconds

@interface CtxObjectCache : NSObject

@property (strong,nonatomic) NSString* name;
@property (strong,nonatomic) id      cachedObject;
@property (strong,nonatomic) NSDate* cacheTimestamp;
@property (assign,nonatomic) NSTimeInterval     cacheMaxAge;

- (void)invalidateCache;
- (BOOL)isCacheValid;
- (void)updateCacheWithObject:(id)object;

@end
