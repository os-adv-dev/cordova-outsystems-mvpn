//
//  Helper.h
//  MAMSharedLib
//
//  Created by Jaspreet Singh on 3/8/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define TIME_IN_MINSEC      1
#define TIME_IN_DAYHOUR     3
#define TIME_IN_WHOLE_NUM   4

#define NOLOCALTAG          @""

////////// Citrix Bundle related //////////
#define CITRIXBUNDLENAME            @"CitrixDylib.bundle"
#define CITRIXPLIST                 @"Citrix.plist"
#define CITRIXPLIST_PACKAGEID       @"PackageID"
#define CITRIXDYLIB_NAME            @"CitrixDylib"
#define CITRIXDYLIB_TYPE            @"dylib"
#define IMAGES_SUBPATH              @"images"
#define CTXMAMASSETSNAME            @"MDXAssets"

/// For future use..
//#define DEVICE_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
//#define DEVICE_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
//#define DEVICE_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
//#define DEVICE_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
//#define DEVICE_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define SuppressPerformSelectorLeakWarning(block) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
block; \
_Pragma("clang diagnostic pop") \
} while (0)

typedef enum {
    eNotSet = -1,
    eNO     =  0,
    eYES    =  1
} TriStateBool;


NSString * CTXMAMLocalizedString(NSBundle * bundle, NSString * key, NSString * comment, NSString * defaultStr);
NSString * CTXWLibLocalizedString(NSString * key, NSString * comment, NSString * defaultString);
NSString * LS(NSString * key, NSString * defaultString);

@interface CTXMAM_Helper : NSObject

+ (NSString *)getCitrixBundleDir;
+ (BOOL)IsIOSVersion5AndAbove;
+ (NSBundle *)getCoreSdkBundle;

+ (NSURL *)getDocumentsURL;
+ (NSURL *)getTmpDirectoryURL;
+ (NSURL *)getCookiesDirectoryURL;
+ (NSURL *)libraryURL;
+ (NSURL *)getPreferencesURL;
+ (NSURL *)getSFDatabaseURL;
+ (NSURL *)getURLFor:(NSSearchPathDirectory)dirType;
+ (void)removeItemsAtURL:(NSURL *)url isDirectory:(BOOL *)isDirectory skipFiles:(NSArray *)filesToSkip;

+ (NSString *)convertSeconds:(NSTimeInterval)ti ToCustomStringFormat:(NSInteger)type Unit:(NSString **)unit;
+ (NSString *)convertDateToString:(NSDate *)dt Format:(NSString *)formatStr;
+ (NSDate *)convertStringToDate:(NSString *)dateStr Format:(NSString *)sFormat;
+ (NSTimeInterval)getSecondsToExpire:(NSDate *)expiryDate Comment:(NSString *)comment;

+ (BOOL)isEmptyOrNil:(NSString *)str;
+ (NSString *)Trim:(NSString *)str;
+ (NSString *)TrimWithQuotesAlso:(NSString *)str;
+ (char *)getCharPointerFromNSString:(NSString *)nsStr;
+ (NSNumber *)getNSNumberIntegerValue:(NSString *)str;
+ (NSArray *)ArrayFromString:(NSString *)mainStr OfComponentsSeparatedByString:(NSString *)delimiterStr;

+ (BOOL)StringArray:(NSArray *)arr Contains:(NSString *)str CaseInsensitiveSearch:(BOOL)CaseInsensitive;
+ (NSArray *)ConvertCArrayToNSArray:(double *)arr OfSize:(int)size;
+ (double)getMaxMinValueInArr:(NSArray *)arr MAX:(BOOL)MaxNotMin;

+ (id)GetValueForCaseInsensitiveKey:(NSString *)sKey FromDict:(NSDictionary *)dict;
+ (NSDictionary *)DictionaryFromDictionary:(NSDictionary *)mainDict skipKeys:(NSArray *)skipKeys;
+ (NSDictionary *)DictionaryFromDictionary:(NSDictionary *)mainDict WithKeys:(NSArray *)withKeys;

+ (NSURL *)appendQueryNode:(NSString *)queryNode toURL:(NSURL *)url;
+ (NSDictionary *)getCitrixPlistDictionary;
+ (NSString *)urlEncode:(NSString *)str;

@end
