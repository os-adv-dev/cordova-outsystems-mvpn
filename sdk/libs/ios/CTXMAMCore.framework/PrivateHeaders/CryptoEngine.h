//
//  CryptoEngine.h
//  DataEncryption
//
//  Created by on 10/2/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//



#ifndef DataEncryption_CryptoEngine_h
#define DataEncryption_CryptoEngine_h




#include <openssl/bn.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/buffer.h>
#include <err.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>

typedef unsigned long long spc_uint64_t;

int GenerateSectorIV(const unsigned char* keyData, off_t sector, unsigned char *pIV, ssize_t nIVLen, int *pnIVLen);

unsigned char * encryptBlockAES(unsigned char * plainText, int dataLength, int *outLength, const unsigned char* keyData, int pageNo);
unsigned char * decryptBlockAES(unsigned char * encryptedText, int dataLength, int *outLength, const unsigned char* keyData, int pageNo);

unsigned char * encryptBlockAES_v1(unsigned char * plainText, int dataLength, int *outLength, const unsigned char* keyData, int pageNo);
unsigned char * decryptBlockAES_v1(unsigned char * encryptedText, int dataLength, int *outLength, const unsigned char* keyData, int pageNo);

unsigned char *publicKeyEncrypt( unsigned char *dataToEncrypt, int size, RSA *key, int *returnSize);
unsigned char *unwrapSecret( unsigned char *secret, int secretSize, RSA *rsaKey, int *decryptedLength);
unsigned char *getPublicKeyFromRSA( RSA *rsaKey, int *len );
RSA *generateRSAKeyPair(void);
int wf_base64_decode(char *in, int in_len, char *out, int *out_len);
int generateRandomData(unsigned char *buf, int num);
unsigned char *generateHash( unsigned char *dataToHash, int dataSize);
unsigned char* generate128SHAHash( unsigned char *dataToHash, int dataSize, unsigned int *md_len );
unsigned char *generate256SHAHash( unsigned char *dataToHash, int dataSize, unsigned int *md_len );
unsigned char *generateKeyFromSecrets( unsigned char *secret1, unsigned char *secret2, unsigned char *devId, int devIdSize, unsigned int * keySize);
unsigned char *generateKey128FromSecrets( unsigned char *secret1, unsigned char *secret2, unsigned char *devId, int devIdSize, unsigned int * keySize);
unsigned char *generateKey256FromSecrets( unsigned char *secret1, unsigned char *secret2, unsigned char *devId, int devIdSize, unsigned int * keySize);


//unsigned char *generateSalt(int saltSize);
unsigned char *PBKDF( const char *passwd, int pwdSize, unsigned char *salt, int saltSize);

int PBKDF2(unsigned char *pw, unsigned int pwlen, unsigned char *salt,
           spc_uint64_t saltlen, unsigned int ic, unsigned char *dk,
           spc_uint64_t dklen);

unsigned char* generatePINValidatorUsingPassword(unsigned char * password, int passwordLen, unsigned char * random, int randomLen, int * outEncLen);
unsigned char* generateVaultEncryptionKeyUsingPassword(unsigned char * password, int passwordLen, unsigned char * random, int randomLen);


//New Encryption EVP APIs for FIPS

int encryptInit(unsigned char* keyData, EVP_CIPHER_CTX *enCtx, int pageNo);
unsigned char* encryptUpdate(unsigned char *plainText, int dataLength, int *outLength,EVP_CIPHER_CTX *enCtx);
int encryptFinal(EVP_CIPHER_CTX *enCtx, unsigned char* finalBuffer, int *len );
int decryptInit ( unsigned char* keyData, EVP_CIPHER_CTX *decCtx, int pageNo );
unsigned char *decryptUpdate( unsigned char* ciphertext, int dataLength, int *outLength, EVP_CIPHER_CTX *decCtx);
int decryptFinal(EVP_CIPHER_CTX *decCtx, unsigned char* finalBuffer, int *len );

int ctx_encrypt_wh(void *outData, void *inData, int amt, int *encLen, int IVno, unsigned char *keyData );

void setFipsInitCalled(int);



#if DEBUG


void obfuscateStr( char * , int );

void unobfuscateStr( char * , int );


#else


#define obfuscateStr( str, shift) \
{ \
    int indx = 1; \
    char *eptr = str; \
    char value, normlow, normhigh; \
    while(eptr && *eptr) \
    { \
        value = (char)((shift * indx) % 91) + (char)1; \
        normhigh = (char)L'~' - *eptr; \
        normlow = *eptr - (char)L'#'; \
        if(normlow >= value) \
        { \
            *eptr = *eptr - value; \
        } \
        else \
        { \
            value = value - normlow; \
            *eptr =  (char)(L'~' + 1) - value; \
        } \
        eptr++; \
        indx++; \
    } \
} \


#define unobfuscateStr( str, shift ) \
{ \
int indx = 1;  \
char *eptr = str;  \
char value, normlow, normhigh;  \
while(eptr && *eptr) {  \
value = (char)((shift * indx) % 91) + (char)1;  \
normhigh = (char)L'~' - *eptr;  \
normlow = *eptr - (char)L'#';  \
if(normhigh > value) {  \
*eptr = *eptr + value;  \
} else {  \
value = value - normhigh;  \
*eptr = value + (char)(L'#' - 1);  \
}  \
eptr++;  \
indx++;  \
}  \
} \





#endif

#if defined(i386)

extern const void         *FIPS_text_start(),  *FIPS_text_end();
extern const unsigned char FIPS_rodata_start[], FIPS_rodata_end[];
extern unsigned char       FIPS_signature[20];
extern unsigned int        FIPS_incore_fingerprint(unsigned char *,unsigned int);

#define BN_ULONG  unsigned int


#endif

 #define CTXLog_DataEncryption_Name   "DataEncryption"


#endif
