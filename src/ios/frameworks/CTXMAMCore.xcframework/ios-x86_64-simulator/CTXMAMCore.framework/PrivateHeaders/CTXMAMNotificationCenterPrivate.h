//
//  CTXMAMNotificationCenterPrivate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 9/4/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

@class CTXMAMNotification;

#ifndef CTXMAMNotificationCenterPrivate_h
#define CTXMAMNotificationCenterPrivate_h

#define CTXMAMCORE_MDM_NOT_ENROLLED_MSG             @"LOGON_CANCELLED_MDM_ENROLL_TO_CONTINUE"

@interface CTXMAMNotificationCenter()

- (void) notifySubscribers:(CTXMAMNotification*) notification;

@end

#endif /* CTXMAMNotificationCenterPrivate_h */
