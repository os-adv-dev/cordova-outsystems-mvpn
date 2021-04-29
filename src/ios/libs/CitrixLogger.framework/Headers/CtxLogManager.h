//
//  CtxLogManager.h
//  Citrix Logger Framework
//
//  Copyright (c) 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CtxLogManager;

// Method called by Wrapper to get the logger instance
CtxLogManager * CtxWrapperGetLoggerInstance(void);

// C-style interface for logging methods
// All the logging related macros will resolve to either of these methods,
// depending on whether message is in C-style or in Objective-C style

void CTXLOG_logMessage(NSString * source,
                       int msgclass,
                       int logType,
                       const char * file,
                       const char * func,
                       int line,
                       NSString * fmt, ...) NS_FORMAT_FUNCTION(7, 8);
void CTXLOG_logMessageWithArgList(NSString * source,
                                  int level,
                                  int logType,
                                  const char * file,
                                  const char * func,
                                  int line,
                                  NSString * fmt, va_list args);

void CTXLOG_logMessage_C(const char * source,
                         int msgclass,
                         int logType,
                         const char * file,
                         const char * func,
                         int line,
                         const char * fmt, ...) __printflike(7, 8);

// Setters for logger parameters
void CTXLOG_setLogLevel(int level);
void CTXLOG_setLogLevelForLogsPath(int level,NSString *logsPath);

void CTXLOG_setMode(int mode);
void CTXLOG_setModeForLogsPath(int mode,NSString *logsPath);

void CTXLOG_setMaxLogFileSizeInMB(int size);
void CTXLOG_setMaxLogFileSizeInMBForLogsPath(int size,NSString *logsPath);

void CTXLOG_setMaxLogFileCount(int count);
void CTXLOG_setMaxLogFileForLogsPath(int count,NSString *logsPath);

// setter to enable/disable diagnostic logger.
void CTXLOG_setDiagEnabled(BOOL flag);
void CTXLOG_setDiagEnabledForLogsPath(BOOL flag,NSString *logsPath);

// Getters for logger parameters
int CTXLOG_getLogLevel(void);
int CTXLOG_getLogLevelForLogsPath(NSString *logsPath);

int CTXLOG_getMode(void);
int CTXLOG_getModeForLogsPath(NSString *logsPath);

int CTXLOG_getMaxLogFileSizeInMB(void);
int CTXLOG_getMaxLogFileSizeInMBForLogsPath(NSString *logsPath);

int CTXLOG_getMaxLogFileCount(void);
int CTXLOG_getMaxLogFileCountForLogsPath(NSString *logsPath);

BOOL CTXLOG_isLogEnabled(void);
BOOL CTXLOG_isLogEnabledForLogsPath(NSString *logsPath);

/*
 Auxiliary public APIs for Log packaging
 */

// -- compression related handler methods

// API for compressing the logs folder
// This method compresses contents of /Documents/CitrixLogs



/**
 * This method is used to compress logs at a custom Logs Directory
 *
 *
 *
 * @param logsDirectory  The Custom Logs Directory where the logs need to be compressed, if nil, will use the Defaults logs
 * directory /Documents/CitrixLogs. Please note that the logs in a folder named CitrixLogs inside this path will be compressed to
 * CitrixLogs.zip. If this path was not found, it returns without compressing anything.
 *
 *
 * @return          The created shared instance if created, otherwise nil.
 */
NSDictionary * CTXLOG_compressLogsAtPath(NSString *logsDirectory);
NSDictionary * CTXLOG_compressLogs(void);


// -- cleanup related handler methods
/**
 * This method is used to delete logs at a custom Logs Directory
 *
 *
 *
 * @param logsDirectory  The Custom Logs Directory where the logs need to be deleted from, if nil, will use the Defaults logs
 * directory /Documents/CitrixLogs. If this path was not found, it returns without deleting anything.
 *
 *
 * @return          The status of deletion, no if path not found also.
 */

BOOL CTXLOG_cleanLogsAtPath(NSString *logsDirectory);
BOOL CTXLOG_cleanLogs(void);


// This method returns the current version of LoggerSDK
NSString * CTXLOG_currentLoggerVersion(void);

// Methods for performance related logging
void CtxPerfLoggerInitializeWithLevel(int level);

void CTXLOG_logPerfEventWithMsg(NSString * module,
                                int level,
                                NSString * eventName,
                                int eventType,
                                long long eventContext,
                                const char * file,
                                const char * function,
                                int line,
                                NSString * fmt, ...) NS_FORMAT_FUNCTION(9, 10);

void CTXLOG_logPerfEventWithMsg_C(const char * module,
                                  int level,
                                  const char * eventName,
                                  int eventType,
                                  long long eventContext,
                                  const char * file,
                                  const char * function,
                                  int line,
                                  const char * fmt, ...) __printflike(9, 10);

void CTXLOG_logPerfEvent(NSString * module,
                         int level,
                         NSString * eventName,
                         int eventType,
                         long long context,
                         const char * file,
                         const char * function,
                         int line);

void CTXLOG_logPerfEvent_C(const char * module,
                           int level,
                           const char * eventName,
                           int eventType,
                           long long context,
                           const char * file,
                           const char * function,
                           int line);


@interface CtxLogManager : NSObject

@property (nonatomic, assign) int loggingMode;
@property (nonatomic, assign) int logLevel;
@property (nonatomic, assign) int maxLogFileSizeInMB;
@property (nonatomic, assign) int maxLogFileCount;
@property (nonatomic, assign, getter = isEnabled) BOOL enabled;

+ (void) CtxLoggerInitialize;


/**
 * PLEASE NOTE :
 * Use this method to initialise the logger before performing any logging, if you want your logs folder to be in a custom directory
 * @param logsPath The directory where you want the Logger to create the CitrixLogs folder and all the logs and other metadata
 **/
+ (void) CtxLoggerInitializeWithLogsPath:(NSString*)logsPath;


/*
* @param logsPath The directory where you want the Logger to create the CitrixLogs folder and all the logs and other metadata (default value is nil which points to the current location )
**/
+ (CtxLogManager *) sharedInstanceWithLogsDirectory:(NSString*)logsDirectory;
+ (CtxLogManager *) sharedInstance;

/*
 * @param logsPath The directory where you want the Logger to create the CitrixLogs folder and all the logs and other metadata
 * @param createIfAbsent If YES, it creates the directory if it is not found ( Default value is YES )
 **/
+ (NSString *) logsDirectoryAtDirectoryPath:(NSString *)logsDirectory
                       createIfDoesNotExist:(BOOL)createIfAbsent;
+ (NSString *) logsDirectoryAtDirectoryPath:(NSString*)logsDirectory;
+ (NSString *) logsDirectory;


/*
 * @param logsPath The directory where you want the Logger to create the CitrixLogs folder and all the logs and other metadata
 * @param createIfAbsent If YES, it creates the directory if it is not found ( Default value is YES as shown for the other two methods )
 **/
+ (NSString *) diagnosticsLogsDirectoryAtDirectoryPath:(NSString*)logsDirectory
                                  createIfDoesNotExist:(BOOL)createIfAbsent;
+ (NSString *) diagnosticsLogsDirectoryAtDirectoryPath:(NSString*)logsDirectory;
+ (NSString *) diagnosticsLogsDirectory;



/*
 * @param logsPath The directory where you want the Logger to create the CitrixLogs folder and all the logs and other metadata
 **/

+ (NSString *)compressedLogFileAtDirectoryPath:(NSString*)logsDirectory;
+ (NSString *)compressedLogFilePath;

+(int) defaultLogLevel;
+(int) defaultLogMode;


/**
 * This method is used to obfuscate a Url for its query parameters, username and password by replacing those with a ***
 *
 *
 *
 * @param url  The NSUrl which needs Obfuscation
 *
 *
 * @return Obfuscated Url as a NSString
 */

+(NSString*)obfuscateQueriesInUrl:(NSURL*)url;
+(NSString*) defaultLogTargetString;
/**
 * This method is used to initialise a logger instance with a custom Logs Directory
 *
 *
 *
 * @param logsDirectory  The Custom Logs Directory where the logs need to be written, if nil, will use the Defaults logs
 * directory /Documents/CitrixLogs. Please note that the logs will be written in a folder named CitrixLogs inside this path
 * If the path entered was not found, then it will write to /Documents/CitrixLogs, the default loggin path
 *
 *
 * @return          The created shared instance if created, otherwise nil.
 */

+(CtxLogManager*)createLoggerInstanceWithLogsDirectory:(NSString*)logsDirectory;

// This method returns int equivalent for target
// Ex: If input is "file", return value is CTXLOG_MODE_FILE
+ (int) logTargetFromString: (NSString *) target;
+ (NSString*) logTargetStringFromMode:(int)mode;

/** 
 * This method is used to write configuration information to Support bundle.
 *
 * Location of support bundle is /Documents/CitrixLogs/.
 *
 * @param configInfo  Configuration information. This can be any information which will be helpful for debugging.
 * Valid formats are NSString, NSData, NSDictionary and NSArray. This parameter can not be nil.
 * Ex: VPN configuration, ActiveSync policies.
 * 
 * @param fileName    Name to be assigned for the configuration file. File extension needs to be specified.
 * This parameter can not be nil. The string will be prefixed with "CtxLog_" string to avoid file encryption by MDX wrapper.
 * Ex: If file name indicated is "GenericInfo.txt", actual file created in Support bundle will
 * have name "CtxLog_GenericInfo.txt"
 *
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * If you are not interested in details of errors, you may pass in NULL.
 *
 * @return           YES if the file is written successfully, otherwise NO.
 */
+ (BOOL) writeConfigInfoToSupportBundle:(id) configInfo
                           withFileName:(NSString *) fileName
                                  error:(NSError **) error;



/**
 * This method is used to write configuration information to Support bundle.
 *
 * Location of support bundle is /Documents/CitrixLogs/.
 *
 * @param configInfo  Configuration information. This can be any information which will be helpful for debugging.
 * Valid formats are NSString, NSData, NSDictionary and NSArray. This parameter can not be nil.
 * Ex: VPN configuration, ActiveSync policies.
 *
 * @param fileName    Name to be assigned for the configuration file. File extension needs to be specified.
 * This parameter can not be nil. The string will be prefixed with "CtxLog_" string to avoid file encryption by MDX wrapper.
 * Ex: If file name indicated is "GenericInfo.txt", actual file created in Support bundle will
 * have name "CtxLog_GenericInfo.txt"
 *
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * If you are not interested in details of errors, you may pass in NULL.
 *
 * @param logsDirectory The Path where the CitrixLogs folder will be found, if nil, points to the default directory /Documents
 *
 * @return           YES if the file is written successfully, otherwise NO.
 */
+ (BOOL) writeConfigInfoToSupportBundle:(id) configInfo
                           withFileName:(NSString *) fileName
                                  error:(NSError **) error
                          logsDirectory:(NSString *) logsDirectory;



/**
 * This method is used to delete an existing configuration file from Support bundle.
 *
 * Location of support bundle is /Documents/CitrixLogs/.
 *
 * @param fileName    Name of the configuration file which needs to be deleted. File extension needs to be specified.
 * This string will be prefixed with "CtxLog_" string for forming the actual file name for deletion. 
 * Ex: If file name indicated is "GenericInfo.txt", actual file checked for deletion in Support bundle will
 * have name "CtxLog_GenericInfo.txt"
 *
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * If you are not interested in details of errors, you may pass in NULL.
 *
 * @return           YES if the file is deleted successfully, otherwise NO.
 */
+ (BOOL) removeConfigFileFromSupportBundleWithName:(NSString *) fileName
                                             error:(NSError **) error;


/**
 * This method is used to delete an existing configuration file from Support bundle.
 *
 * Location of support bundle is /Documents/CitrixLogs/.
 *
 * @param fileName    Name of the configuration file which needs to be deleted. File extension needs to be specified.
 * This string will be prefixed with "CtxLog_" string for forming the actual file name for deletion.
 * Ex: If file name indicated is "GenericInfo.txt", actual file checked for deletion in Support bundle will
 * have name "CtxLog_GenericInfo.txt"
 *
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * If you are not interested in details of errors, you may pass in NULL.
 *
 * @param logsDirectory The Path where the CitrixLogs folder will be found, if nil, points to the default directory /Documents
 *
 * @return           YES if the file is deleted successfully, otherwise NO.
 */
+ (BOOL) removeConfigFileFromSupportBundleWithName:(NSString *) fileName
                                             error:(NSError **) error
                                     logsDirectory:(NSString*)logsDirectory;

/**
 * This method compresses the Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/
 * @return Returns a dictionary with following keys:
 * CTXLOG_COMPRESSED_FOLDER_PATH: Path to compressed logs folder.
 * CTXLOG_COMPRESSED_FOLDER_MIMETYPE: Mime type of the zip. This is always "application/zip"
 * CTXLOG_COMPRESSED_FOLDER_NAME: Name of compressed file.
 * @param path The Path where the CitrixLogs folder ( and also .zip be created) will be found, if nil, points to the default directory /Documents
 */
+ (NSDictionary *)createZippedLogFilesAtPath:(NSString*)path;



/**
 * This method compresses the Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/
 * @return Returns a dictionary with following keys:
 * CTXLOG_COMPRESSED_FOLDER_PATH: Path to compressed logs folder.
 * CTXLOG_COMPRESSED_FOLDER_MIMETYPE: Mime type of the zip. This is always "application/zip"
 * CTXLOG_COMPRESSED_FOLDER_NAME: Name of compressed file.
 */
+ (NSDictionary *)createZippedLogFiles;

/**
 * This method adds a new key:value pair to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param value The string to store in the Support bundle.
 * @param key The key with which to associate with the value.
 * @return YES if addition of new key-value pair was successful, otherwise NO
 */
+ (BOOL) addStringToSupportBundle:(NSString *)value
                          withKey:(NSString *) key;

/**
 * This method adds a new key:value pair to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param value The string to store in the Support bundle.
 * @param key The key with which to associate with the value.
 * @param logsDirectory The Path where the CitrixLogs folder will be found, if nil, points to the default directory /Documents
 * @return YES if addition of new key-value pair was successful, otherwise NO
 */
+ (BOOL) addStringToSupportBundle:(NSString *)value
                          withKey:(NSString *) key
                         logsPath:(NSString*)logsDirectory;

/**
 * This method appends the contents of input dictionary to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param dictionary Dictionary to be written to AppInfo.txt. 
 
 * Input dictionary can have only property list objects: NSData, NSString, NSNumber, NSDate, NSArray, or NSDictionary. For NSArray and NSDictionary objects, their contents must be property list objects.
 * @return YES if addition of new dictionary was successful, otherwise NO
 */
+ (BOOL) addDictionaryToSupportBundle: (NSDictionary *) dictionary;

/**
 * This method appends the contents of input dictionary to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param dictionary Dictionary to be written to AppInfo.txt.
 
 * Input dictionary can have only property list objects: NSData, NSString, NSNumber, NSDate, NSArray, or NSDictionary. For NSArray and NSDictionary objects, their contents must be property list objects.
 * @param logsDirectory The Path where the CitrixLogs folder will be found, if nil, points to the default directory /Documents
 * @return YES if addition of new dictionary was successful, otherwise NO
 */
+ (BOOL) addDictionaryToSupportBundle: (NSDictionary *) dictionary
                             logsPath:(NSString*)logsDirectory;



/**
 * This method appends the contents of input dictionary to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param dict Dictionary to be written to AppInfo.txt.
 * @param clearExistingEntries If YES, existing entries in AppInfo.txt which were added using this method will be deleted.
 * Input dictionary can have only property list objects: NSData, NSString, NSNumber, NSDate, NSArray, or NSDictionary. For NSArray and NSDictionary objects, their contents must be property list objects.
 * @return YES if addition of new dictionary was successful, otherwise NO
 */
+ (BOOL)addDictionaryToSupportBundle:(NSDictionary *)dict
                clearExistingEntries:(BOOL)clearExistingEntries;

/**
 * This method appends the contents of input dictionary to AppInfo.txt file present in Support bundle.
 * Location of support bundle is /Documents/CitrixLogs/.
 * @param dict Dictionary to be written to AppInfo.txt.
 * @param clearExistingEntries If YES, existing entries in AppInfo.txt which were added using this method will be deleted.
 * Input dictionary can have only property list objects: NSData, NSString, NSNumber, NSDate, NSArray, or NSDictionary. For NSArray and NSDictionary objects, their contents must be property list objects.
 * @param logsDirectory The Path where the CitrixLogs folder will be found, if nil, points to the default directory /Documents
 * @return YES if addition of new dictionary was successful, otherwise NO
 */
+ (BOOL)addDictionaryToSupportBundle:(NSDictionary *)dict
                clearExistingEntries:(BOOL)clearExistingEntries
                            logsPath:(NSString*)logsDirectory;


// Supplimentary APIs for daily purposes.


/*
 * Used to zip any folder present at the path entered as parameter
 * @param folderPath the Absolute path of the folder to be compressed
 * @param customZipPath If you want to specify a path where the compressed logs folder should be present or the path of the compressed logs folder itself, then specify the path here. If nil, then it will create a zip file in the directory where the folder to be compressed is present with the same name and .zip extension. Intermediate directories will be created if they do not originally exist.
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * If you are not interested in details of errors, you may pass in NULL.
 * @return If failure nil else NSDictionary with the following keys
 *  CTXLOG_ZIP_FILE_PATH         value for this is the path of the compressed folder as a .zip file
 *  CTXLOG_ZIP_FILE_MIMETYPE     the mimetype of the compression file, usually a application/zip
 *  CTXLOG_ZIP_FILE_NAME         the name of the compressed zip file.
 */

+(NSDictionary*)zipFolderAtPath:(NSString *)folderPath
                   toCustomPath:(NSString *)customZipPath
                          error:(NSError **)error;

/*
 * Used to unzip any .zip file present at the path entered as parameter
 * @param zipFilePath the Absolute path of the .zip file to be uncompressed
 * @param error      If there is an error, upon return contains an NSError object that describes the problem.
 * @param customPath If you want to specify a path where the uncompressed logs folder should be present(i.e the parent), then specify the path here. If not nil, it will create a folder in the path customPath with the name of the zipFIle(without the .zip) and all zip extracts will be present in that.
 If nil, then it will create a zip file in the directory where the folder to be compressed is present with the same name and .zip extension. Intermediate directories will be created if they do not originally exist.

 * If you are not interested in details of errors, you may pass in NULL.
 * @return If failure nil, else NSDictionary with the following keys
 *  CTXLOG_UNZIP_FOLDER_PATH         path of the uncompressed folder
 *  CTXLOG_UNZIP_FOLDER_NAME         name of the uncompressed folder
 */

+(NSDictionary*)unzipFileAtPath:(NSString *)zipFilePath
                   toCustomPath:(NSString *)customPath
                          error:(NSError **)error;



/**
 * This method appends the contents of App-Info.txt at the logs.zip file mentioned as a parameter
 * @param zipPath The Path where the compressed logs folder will be found, if nil or zipPath is invalid then return is nil
 *  use CTXLOG_CURRENT_APP_LOG_DIRECTORY if u want the app info for the current caller app, or use currentAppInfo method
 * @return App Info Dictionary found at the zip path, nil if invalid path or null path
 * Constants for the keys and the fallback default values are present in the CtxLoggerConstants file
 */

+ (NSDictionary*)appInfoFromLogsZipPath:(NSString*)zipPath;
+ (NSDictionary*)currentAppInfo;

/**
 * This method gets the actual device name from the device code, like iPhone3,1 code maps to iPhone 3GS
 * @param deviceCode the device code, for eg. iPhone 3,1
 * @return the device name if a match found, else the device code itself
 * if device-code is nil or empty string, returns iPhone
 */
+ (NSString*)hardwareNameForCode:(NSString*)deviceCode;

/**
 * This method gets the current device code, like iPhone3,1
 * @return the device code (nullable)
 */
+ (NSString *)currentMachineCode;

/**
 * This method gets the current device name, like iPhone 3GS
 * @return the device name or device code like iPhone 3,1 if the device name could not be deciphered from the device code
 */
+ (NSString *)currentHardwareName;

/**
 * This method checks if the current device is Jailbroken or not
 * @return the jailbreak status of the current device
 */
+ (BOOL)isCurrentDeviceJailbroken;

- (id)initWithLoggerName:(NSString *)loggerName
                 appName:(NSString *)appNameOrNil
                logLevel:(int)level
                    mode:(int)mode
                 enabled:(BOOL) enabled
      maxLogFileSizeInMB:(int)maxLogFileSize
         maxLogFileCount:(int)maxLogFileCount;

- (id)initWithLoggerName:(NSString *)loggerName
                 appName:(NSString *)appNameOrNil
                logLevel:(int)level
                    mode:(int)mode
                 enabled:(BOOL) enabled
      maxLogFileSizeInMB:(int)maxLogFileSize
         maxLogFileCount:(int)maxLogFileCount
            logDirectory:(NSString*)logsDirectory;


- (void) logMessageFromModule: (NSString *) module
                 withLogLevel: (int) level
                         file: (const char *) file
                     function: (const char *) function
                         line: (int) line
                       format: (NSString *) format, ... NS_FORMAT_FUNCTION(6, 7);

- (void) logMessageFromModule: (NSString *) module
                 withLogLevel: (int) level
                         file: (const char *) file
                     function: (const char *) function
                         line: (int) line
                       format: (NSString *) format
                         args: (va_list)args;

- (void) rollCurrentLogFile;
@end

