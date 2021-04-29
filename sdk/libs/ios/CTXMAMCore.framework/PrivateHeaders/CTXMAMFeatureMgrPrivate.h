//
//  CTXMAMFeatureMgrPrivate.h
//  CTXMAMCore
//
//  Created by Michael Volk on 12/12/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMFeatureMgrPrivate_h
#define CTXMAMFeatureMgrPrivate_h

#import "CTXMAMFeatureMgr.h"

@interface CTXMAMFeatureMgr()

+(instancetype)sharedInstance;
-(BOOL) isFeatureOn:(NSString *) feature;

@end

#endif /* CTXMAMFeatureMgrPrivate_h */
