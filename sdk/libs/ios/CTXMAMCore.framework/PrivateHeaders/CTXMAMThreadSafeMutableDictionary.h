//
//  CTXMAMThreadSafeMutableDictionary.h
//
//  Created by Qing Dai on 9/12/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMThreadSafeMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>

- (instancetype) initWithLabel:(nullable NSString*)queueLabel;

- (instancetype) initWithObjects:(ObjectType _Nonnull const [_Nonnull])objects
                         forKeys:(KeyType<NSCopying> _Nonnull const [_Nonnull])keys
                           count:(NSUInteger)cnt
                           label:(nullable NSString*)queueLabel;

- (instancetype) initWithDictionary:(NSDictionary<KeyType, ObjectType>* _Nonnull )otherDictionary
                              label:(nullable NSString*)queueLabel;

- (NSMutableDictionary<KeyType, ObjectType>*)initWithContentsOfFile:(NSString *)path
                                                              label:(nullable NSString*)queueLabel;


@end

NS_ASSUME_NONNULL_END

