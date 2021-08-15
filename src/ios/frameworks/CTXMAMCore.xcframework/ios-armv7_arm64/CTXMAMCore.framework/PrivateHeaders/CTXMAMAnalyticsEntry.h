//
//  MdxAnalyticsEntry.h
//  CTXMAM_WrappedAppLib
//
//  Created by Chris Pavlou on 4/13/17.
//  Copyright © 2017-2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AnalyticsEntryType)
{
	AnalyticsEntryTypeEvent = 0,
	AnalyticsEntryTypeTiming,
	AnalyticsEntryTypeScreenview
};

@interface CTXMAMAnalyticsEntry : NSObject

@property (nonatomic) AnalyticsEntryType eventType;
@property (nonatomic) BOOL extended;

@end

@interface CTXMAMAnalyticsEventEntry : CTXMAMAnalyticsEntry

@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSNumber *value;

-(instancetype)initWithCategory:(NSString *)category action:(NSString *)action label:(NSString *)label value:(NSNumber *)value extended:(BOOL)extended;

@end

@interface MdxAnalyticsTimingEntry : CTXMAMAnalyticsEntry

@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSNumber *intervalMillis;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *label;

-(instancetype)initWithCategory:(NSString *)category interval:(NSNumber *)intervalMillis name:(NSString *)name label:(NSString *)label extended:(BOOL)extended;

@end

@interface MdxAnalyticsScreenviewEntry : CTXMAMAnalyticsEntry

@property (nonatomic, copy) NSString *screenName;

-(instancetype)initWithScreenview:(NSString *)screenName extended:(BOOL)extended;

@end
