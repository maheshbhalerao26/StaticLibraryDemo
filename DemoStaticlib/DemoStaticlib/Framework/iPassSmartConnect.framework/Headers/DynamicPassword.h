// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DYNAMICPASSWORDLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DYNAMICPASSWORDLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef _WINDOWS
#ifdef DYNAMICPASSWORDLIB_EXPORTS
#define DYNAMICPASSWORDLIB_API __declspec(dllexport)
#else
#define DYNAMICPASSWORDLIB_API __declspec(dllimport)
#endif
#else
#define DYNAMICPASSWORDLIB_API
#endif

#ifdef ANDROID
#include <stdbool.h>
#endif


typedef enum _PLATFORM_IDENTIFIER
{
	
	PLATFORM_ANDROID=0x00, 
	PLATFORM_IOS=0x01, 
	PLATFORM_WINDOWS_PHONE=0x02,
	PLATFORM_WINDOWS_DESKTOP=0x03,
	PLATFORM_MAC=0x04,
	PLATFORM_WINDOWS_TOUCH=0x05
}PLATFORMID;

typedef enum _DP_STATUS_CODE
{
	UNKNOWN= -1,
	SUCCESS=0, // All OK
	INVALID_INPUT_USERTOKEN=1, // user token is null or Length!=32
	INVALID_INPUT_SHAREDSECRET=2, // shared secret is null or Length!=32
	INVALID_INPUT_DIALERCOUNTER=3, //DIALER Counter is null
	INVALID_INPUT_DIALERID =4,//DIALER Counter is null
	OUTPARAM_NULL =5, // output buffer is null

}STATUS;

#define MAX_ITERATIONS 50
#define OUTPUT_PASSWORD_LENGTH 11

#ifdef __cplusplus
extern "C"
{
#endif
DYNAMICPASSWORDLIB_API  STATUS GenerateDynamicPassword(const char* userToken , const char* sharedSecret,const PLATFORMID platformIdentifier ,const char* dialerCounter ,const char* dialerID, char* dynamicPassword );
DYNAMICPASSWORDLIB_API STATUS GenerateOTP(const char* userToken ,const char* sharedSecret,const PLATFORMID platformIdentifier ,const char* dialerCounter ,const char* dialerID, char* otp );
 //DYNAMICPASSWORDLIB_API void CreateSHA256Digest(unsigned char* input,unsigned char* digest);
//DYNAMICPASSWORDLIB_API void Base64Encode(unsigned char* input , unsigned char*encodedData);
//DYNAMICPASSWORDLIB_API void Base64Decode(unsigned char*input,unsigned char* decodedData);
//DYNAMICPASSWORDLIB_API void RC4Encrypt( char* key,char* plainText , char* encryptedText);
//DYNAMICPASSWORDLIB_API void RC4Decrypt(char* key,char* encryptedText , char* plainText);
//DYNAMICPASSWORDLIB_API void GenerateCRC32(char* input,int inputLength , int* crc);
#ifdef __cplusplus
}
#endif
