//
//  CtxKeyChainHelper.h
//  CTXMAM_WrappedAppLib
//
//  Created by Jaspreet Singh on 11/21/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CtxKeyChainHelper : NSObject

- (id)initWithServiceName:(NSString *) servicename;


- (void)setKeyChainValue:(NSString *) val
                  forKey:(NSString *) key
          updateExisting:(BOOL) bUpdateExisting;
+ (void)setKeyChainValue:(NSString *) val
                  forKey:(NSString *) key
          updateExisting:(BOOL) bUpdateExisting;
+ (BOOL)setKeyChainValue:(NSString *) val
                  forKey:(NSString *) key
          andServiceName:(NSString *) serviceName
          updateExisting:(BOOL) bUpdateExisting
                   error:(NSError **) error;


- (void)removeKeyChainEntryForKey:(NSString *) key;
+ (void)removeKeyChainEntryForKey:(NSString *) key;
+ (BOOL)removeKeyChainEntryForKey:(NSString *) key
                   andServiceName:(NSString *) serviceName
                            error:(NSError **) error;


- (NSString *)getKeyChainValueForKey:(NSString *) key;
+ (NSString *)getKeyChainValueForKey:(NSString *) key;
+ (NSString *)getKeyChainValueForKey:(NSString *) key
                      andServiceName:(NSString *) serviceName
                               error:(NSError **) error;

@end
