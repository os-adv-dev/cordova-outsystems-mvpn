//
//  NSMutableArray+CTXMAMQueue.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 4/3/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMQueue : NSMutableArray

-(void) enqueue: (id) object;
-(nullable id) dequeue;
-(nullable id) peek;

@end

NS_ASSUME_NONNULL_END
