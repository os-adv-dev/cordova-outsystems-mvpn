//
//  CTXMAMDataEncryption.h
//  DataEncryption
//
//  Created on 10/2/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <CryptoEngine/CryptoEngine.h>
#pragma clang diagnostic pop

#import "DataEncryptionC.h"




#define kCTXVAULT1     @"-vault1"
#define kCTXVAULT2     @"-vault2"

#define VAULT_ITEM_S1_NAME              @"Secret1"
#define VAULT_ITEM_S2_NAME              @"Secret2"
#define VAULT_ITEM_DEVICE_ID_NAME       @"DeviceId"
#define IPC_ITEM_ERROR_CODE             @"ErrorCode"        


@interface CTXMAMDataEncryption : NSObject
{
    DataEncryptionOption _dataEncryptionOption;
}

@property (nonatomic, assign) DataEncryptionOption dataEncryptionOption;


// Singleton method
+ (CTXMAMDataEncryption *)sharedDataEncryption;

-(DataEncryptionOption) GetDataEncryptionOption;
-(void) SetDataEncryptionOption:(DataEncryptionOption)option;

-(NSData *) generateMasterKeyWithKeyMaterial1:(NSData *)keyMaterial1 keyMaterial2:(NSData *)keyMaterial2 keyMaterial3:(NSData *)keyMaterial3;

@end
