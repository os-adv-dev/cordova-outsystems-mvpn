//
//  CTXMAMLoggerPrivate.h
//  CTXMAMCore
//
//  Created by Daniel Romano on 2/22/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//
#ifndef CTXMAMLoggerPrivate_h
#define CTXMAMLoggerPrivate_h
#import <Foundation/Foundation.h>
#import "CTXMAMLogger.h"
#import "CTXMAMConfigManager.h"
#import "CTXMAMConfigurationProvider.h"

#define kCTXSSO_APP_LOG_LEVEL       @"AppLogLevel"
#define kCTXSSO_APP_LOG_TARGET      @"AppLogTarget"

// Log settings related policies.
// int
#define POLICY_KEY_CTXLOG_MAX_FILE_SIZE                               @"MaxLogFileSize"
// int
#define DEFAULT_VALUE_CTXLOG_MAX_FILE_SIZE                            2
// int
#define POLICY_KEY_CTXLOG_MAX_FILE_COUNT                              @"MaxLogFiles"
// int
#define DEFAULT_VALUE_CTXLOG_MAX_FILE_COUNT                           2
// int
#define POLICY_KEY_CTXLOG_CURRENT_LOG_LEVEL                           @"DefaultLoggerLevel"
// int
#define DEFAULT_VALUE_CTXLOG_DEFAULT_LOG_LEVEL                        4
// Boolean
#define POLICY_KEY_CTXLOG_LOGGING_BLOCKED                             @"BlockLogs"
// string
#define POLICY_KEY_CTXLOG_LOG_TARGET                                  @"DefaultLoggerOutput"
// string
#define DEFAULT_VALUE_CTXLOG_LOG_TARGET                               @"file"
// Boolean
#define POLICY_KEY_CTXLOG_ENCRYPT_LOGS                                @"EncryptLogs"
#define DEFAULT_VALUE_CTXLOG_ENCRYPT_LOGS                             NO
// string
#define CTXMAMLOG_COMPRESSED_FOLDER_PATH                              @"ctxCompressedLogFolderPath"

// Diagnostic message classes
#define CTXMAMLOG_LVL_NOTHING          CTXMAMLOG_MSG_NOTHING
#define CTXMAMLOG_LVL_CRITICAL         CTXMAMLOG_MSG_CRITICAL
#define CTXMAMLOG_LVL_ERROR            CTXMAMLOG_MSG_ERROR
#define CTXMAMLOG_LVL_WARNING          CTXMAMLOG_MSG_WARNING
#define CTXMAMLOG_LVL_INFO             CTXMAMLOG_MSG_INFO
#define CTXMAMLOG_LVL_DETAIL           CTXMAMLOG_MSG_DETAIL
#define CTXMAMLOG_LVL_DEBUG1           6
#define CTXMAMLOG_LVL_DEBUG2           (CTXMAMLOG_LVL_DEBUG1 + 1)
#define CTXMAMLOG_LVL_DEBUG3           (CTXMAMLOG_LVL_DEBUG2 + 1)
#define CTXMAMLOG_LVL_DEBUG4           (CTXMAMLOG_LVL_DEBUG3 + 1)
#define CTXMAMLOG_LVL_DEBUG5           (CTXMAMLOG_LVL_DEBUG4 + 1)
#define CTXMAMLOG_LVL_DEBUG6           (CTXMAMLOG_LVL_DEBUG5 + 1)
#define CTXMAMLOG_LVL_DEBUG7           (CTXMAMLOG_LVL_DEBUG6 + 1)
#define CTXMAMLOG_LVL_DEBUG8           (CTXMAMLOG_LVL_DEBUG7 + 1)
#define CTXMAMLOG_LVL_DEBUG9           (CTXMAMLOG_LVL_DEBUG8 + 1)
#define CTXMAMLOG_LVL_DEBUG10          (CTXMAMLOG_LVL_DEBUG9 + 1)
#define CTXMAMLOG_LVL_VERBOSE          CTXMAMLOG_LVL_DEBUG10
#define CTXMAMLOG_FILE_PREFIX          "CtxLog_"

//Log type
#define CTXMAMLOG_LOG_TYPE_DIAGNOSTIC          2
#define CTXMAMLOG_LOG_TYPE_SECURE              3
#define CTXMAMLOG_LOG_TYPE_PERFORMANCE         4

#define CTXMAMLOG_Verbose(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_LVL_VERBOSE, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Activity(level, fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, level, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag(level, fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, level, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag1(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG1, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag2(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG2, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag3(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG3, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag4(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG4, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag5(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG5, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag6(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG6, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag7(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG7, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag8(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG8, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag9(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG9, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag10(fmt,...) \
CTXMAMLOG_Message(CTXMAMLOG_DEFAULT_MODULE, CTXMAMLOG_LVL_DEBUG10, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag_ForModule(source, level, fmt,...) \
CTXMAMLOG_Message(source, level, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Diag_For_Debug_Only(level, fmt,...) \
CTXMAMLOG_Message_DebugOnly(CTXMAMLOG_DEFAULT_MODULE, level, CTXMAMLOG_LOG_TYPE_DIAGNOSTIC, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Secure(level, fmt,...) \
CTXMAMLOG_Message_Secure(CTXMAMLOG_DEFAULT_MODULE, level, CTXMAMLOG_LOG_TYPE_SECURE, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define CTXMAMLOG_Secure_ForModule(source, level, fmt,...) \
CTXMAMLOG_Message_Secure(source, level, CTXMAMLOG_LOG_TYPE_SECURE, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#define SANITIZED_LOG_MESSAGE @"**SANITIZED**"


NSString * _Nullable SanitizeLogMessage(NSString * _Nonnull fmt);
void CTXMAMLOG_MessageWithArgsList(NSString * _Nullable source, int level, int logType, const char * _Nullable file, const char * _Nullable func, int line, NSString * _Nullable fmt, va_list args);
void CTXMAMLOG_Message_DebugOnly(NSString * _Nullable source, int level, int logType, const char * _Nullable file, const char * _Nullable func,int line, NSString * _Nullable fmt, ...);
void CTXMAMLOG_Message_Secure(NSString * _Nullable source, int level, int logType, const char * _Nullable file, const char * _Nullable func,int line, NSString * _Nullable fmt, ...);
int CTXMAMLOG_getLogLevel(void);
BOOL CTXMAMLOG_cleanLogs(void);

static NSArray * _Nullable _loggerBannedWords = nil;

NS_ASSUME_NONNULL_BEGIN
@interface CTXMAMLogger()

+(NSString *) logsDirectory;
+(int) logLevel;
+(nullable NSString *) obfuscateQueriesInUrl: (NSURL*)url;
+(NSDictionary *) createZippedLogFiles;

+(void) CTXMAMLog_ActivityForLevel:    (int)level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_DiagForLevel:        (int)level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag1FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag2FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag3FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag4FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag5FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag6FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag7FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag8FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag9FromFile:       (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_Diag10FromFile:      (nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber withFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_DiagForDebugOnly:    (int)level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_DiagFrom:            (NSString *) source andLevel:(int) level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_SecureForLevel:      (int)level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;
+(void) CTXMAMLog_SecureFrom:          (NSString *) source andLevel:(int) level andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int)lineNumber andFormat:(NSString *)fmt, ...;

@end

@interface CTXMAMConfigManager (CTXMAMLogger)

@property (readonly)            int                     maxLogFileSize;
@property (readonly)            int                     maxLogFiles;
@property (readonly)            int                     loggerLevel;
@property (readonly)            BOOL                    blockLogs;
@property (readonly)            NSString *              loggerOutput;
@property (readonly)            BOOL                    encryptLogs;

@end

@interface CTXMAMLoggerConfigProvider: NSObject <CTXMAMConfigurationProvider>

-(NSDictionary *) getPerAppConfiguration;
-(NSDictionary *) getSharedConfiguration;

@end

NS_ASSUME_NONNULL_END

#endif /* CTXMAMLoggerPrivate_h */
