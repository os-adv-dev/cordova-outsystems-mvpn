//
//  NSFileManager+CtxLoggerExtension.h
//  Pods
//
//  Copyright © 2019 Citrix. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <AvailabilityMacros.h>

#define INDICATE_FILE_ZIP_DEPRECATION DEPRECATED_MSG_ATTRIBUTE("Deprecated in this CitrixLogger version. Please use the method [CtxLogManager zipFolderAtPath:(NSString *) error:(NSError **)] instead")
#define INDICATE_FILE_UNZIP_DEPRECATION DEPRECATED_MSG_ATTRIBUTE("Deprecated in this CitrixLogger version. Please use the method [CtxLogManager unzipFileAtPath:(NSString *) error:(NSError **)] instead")

@interface NSFileManager (CtxLoggerExtension)

+(NSDictionary*)zipFolderAtPath:(NSString *)folderPath
                   toCustomPath:(NSString *)customZipPath
                          error:(NSError **)error  INDICATE_FILE_ZIP_DEPRECATION ;

+(NSDictionary*)unzipFileAtPath:(NSString *)zipFilePath
                    toCustomPath:(NSString *)customPath
                           error:(NSError **)error  INDICATE_FILE_UNZIP_DEPRECATION ;

@end
