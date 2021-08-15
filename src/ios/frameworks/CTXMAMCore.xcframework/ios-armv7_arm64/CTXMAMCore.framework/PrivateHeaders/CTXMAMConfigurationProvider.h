//
//  CTXMAMConfigurationProvider.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 5/18/20.
//  Copyright © 2020 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMConfigurationProvider_h
#define CTXMAMConfigurationProvider_h

@protocol CTXMAMConfigurationProvider

- (NSDictionary *) getPerAppConfiguration;
- (NSDictionary *) getSharedConfiguration;

@end

#endif /* CTXMAMConfigurationProvider_h */
