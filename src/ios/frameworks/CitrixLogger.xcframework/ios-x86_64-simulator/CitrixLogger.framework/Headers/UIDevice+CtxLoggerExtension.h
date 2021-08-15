//
//  UIDevice+CtxLoggerExtension.h
//  CtxLogger
//
//  Copyright © 2019 Citrix. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AvailabilityMacros.h>
#import <UIKit/UIKit.h>

#define INDICATE_CODE_DEPRECATION DEPRECATED_MSG_ATTRIBUTE("Deprecated in this CitrixLogger version. Please use the method [CtxLogManager currentMachineCode] instead")
#define INDICATE_NAME_DEPRECATION DEPRECATED_MSG_ATTRIBUTE("Deprecated in this CitrixLogger version. Please use the method [CtxLogManager currentHardwareName] instead")

@interface UIDevice (CtxLoggerExtension)

+ (NSString *)machineCode INDICATE_CODE_DEPRECATION ;
+ (NSString *)machineName INDICATE_NAME_DEPRECATION ;

@end
