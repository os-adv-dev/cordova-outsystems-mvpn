//
//  NSMutableArray+Stack.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 4/2/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface  CTXMAMStack : NSMutableArray

-(void) push: (id) object;
-(nullable id) pop;
-(nullable id) peek;

@end

NS_ASSUME_NONNULL_END
