//
//  DataEncryptionC.h
//  DataEncryption
//
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//
#ifndef DataEncryption_EncryptionC_h
#define DataEncryption_EncryptionC_h



#define SECRET_LENGTH 128
#define SECRET_256_LENGTH 256

// 128 bit key
#define KEY_128_SIZE 20
// 256 bit key
#define KEY_256_SIZE 32


#define KC_SECRET1_NAME              @"_Secret1"
#define KC_SECRET2_NAME              @"_Secret2"
#define KC_SECRET3_NAME              @"_Secret3"
#define KC_SECRET4_NAME              @"_Secret4"
#define KC_RANDOMSECRET_NAME         @"_RandomSecret"
#define KC_SECRET1_LEN               @"_Secret1_Len"
#define KC_SECRET2_LEN               @"_Secret2_Len"
#define KC_SECRET3_LEN               @"_Secret3_Len"
#define KC_SECRET4_LEN               @"_Secret4_Len"




typedef enum
{
    DataEncryptionOptionOff    = 0,
    DataEncryptionOptionOn     = 1,
    DataEncryptionOptionFips   = 2
} DataEncryptionOption;

DataEncryptionOption GetDataEncryptionOption(void);


unsigned char *generateSalt(int saltSize);

int setNonFIPSEncryptionMode(void);
int setFIPSEncryptionMode(void);
int setEncryptionMode(int reqMode);
int adjustToMultipleOfAesBlockSize(int len);


#endif
