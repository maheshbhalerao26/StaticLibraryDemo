// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RTNLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RTNLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef _WINDOWS
#ifdef THEMISLIB_EXPORTS
#define THEMISLIB_API __declspec(dllexport)
#else
#define THEMISLIB_API __declspec(dllimport)
#endif
#else
#define THEMISLIB_API
#endif

#ifdef ANDROID
#include <stdbool.h>
#endif

/* Windows compatibility */
#ifdef _WIN32
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#endif

#define THEMIS_MSG_MAX_LEN  255
#define THEMIS_MSG_HEADER_MAX_LEN 6

static const char THEMIS_KEY_EXCHANGE_API_VERSION = 2;
static const char THEMIS_AP_QUERY_API_VERSION = 7;

static const int THEMIS_HOSTNAME_LABEL_LENGTH = 63;

static const int CHACHA20_IV_LENGTH = 8;
static const int CHACHA20_KEY_LENGTH = 32;

static const int PAY_LOAD_VERSION_LEN = 1;
static const int CALLER_ID_LEN = 5;
static const int PLATFORM_LEN = 1;
static const int PROFILE_ID_VERSION_LEN = 5;

static const int THEMIS_PACKET_FORMAT_LEN = 1;
static const int THEMIS_PAYLOAD_TYPE_LEN = 1;

static const int SSID_HASH_LEN = 8;

static const int SSID_COUNT_BIT_LEN = 4;
static const int BSSID_COUNT_BIT_LEN = 5;
static const int BSSID_VALUE_LEN = 6;
static const int SEC_BIT_LEN = 1;
static const int LOCATION_BITS_LEN = 40;

static const int CELLULAR_NET_COUNT_BITS = 2;
static const int CELLULAR_NET_MCC_BITS = 10;
static const int CELLULAR_NET_MNC_BITS = 10;
static const int CELLULAR_NET_LAC_BITS = 16;
static const int CELLULAR_NET_CID_BITS = 28;
static const int CELLULAR_NET_SID_BITS = 15;
static const int CELLULAR_NET_NID_BITS = 16;
static const int CELLULAR_NET_BID_BITS = 16;

static const signed char THEMIS_SUCCESS_TYPE = 1;
static const signed char THEMIS_FAILURE_TYPE = -1;

static const unsigned int ONE_HOUR_IN_MINUTES = 60;

//1 : misc failure
static const unsigned short MISC_FAILURE = 1;
//10 : bad packet
static const unsigned short BAD_PACKET = 10;
//11 : bad crypto
static const unsigned short BAD_CRYPRO = 11;

typedef enum _THEMIS_API
{
	THEMIS_API_CONNECT_KEY_EXCHANGE=2,
	THEMIS_API_AP_QUERY=3
}THEMIS_API;

typedef enum _PLATFORMTYPE
{
	P_ANDROID=1,
	P_IOS=2,
	P_MAC=3,
	P_WINDOWS=4,
	P_WINTOUCH=5,
	P_WINPHONE=6

}PLATFORMTYPE;


struct ThemisMessageHeader{
	// uuid hex
	char  UUID[11];
	// key hex for chacha20 
	char encryptionKey[65];
	// iv (seed) hex for chacha20
	char iv[17];
};

struct LocationInfo{
	double latitude; 
	double longitude;
};

struct BSSIDList{
	//IN HEX
	char value[13];
};

struct SSIDList{
	//IN HEX
	char SSID[65];
	int bssidCount;
	bool isOpen;
	struct BSSIDList bssid[32];
};

struct CellularNet{
	unsigned int mobileCountryCode;
	char mobileNetworkCode[10];
	unsigned int locationAreaCode;
	unsigned int cellId;
	unsigned int systemId;
	unsigned int networkId;
	unsigned int baseStationId;
};

typedef enum _THEMIS_SERVER_RESPONSE_ACTION
{
	THEMIS_INVALID_RESPONSE_MSG = -3,
	THEMIS_UNKNOWN = -2,
	THEMIS_FAILURE = -1,
	THEMIS_SUCCESS = 0,
	THEMIS_MISC_FAILURE = 1,
	THEMIS_BAD_PACKET = 10,
	THEMIS_BAD_CRYPTO = 11

}THEMIS_ACTION;


typedef enum _THEMIS_API_RET
{
	RET_SUCCESS = 0,
	RET_ERROR_INVALID_INPUT = 1,
	RET_ERROR_TOO_LARGE_INPUT = 2,
	RET_ERROR_UNKNOWN = 3,

}THEMIS_API_RET;



#ifdef __cplusplus
extern "C"
{
#endif

struct ThemisResponseMsgAction{
	THEMIS_ACTION action;
	char  data[2050];
};

THEMISLIB_API  THEMIS_API_RET CreateThemisMsgKeyExchange(const struct ThemisMessageHeader *header,const char * hexClientCallerID,const char* clientPublicX,const char* clientPublicY,const char* hostnameSuffix,char * themisMessage,int *messageLen);
THEMISLIB_API  THEMIS_API_RET CreateThemisMsgAPQuery(const struct ThemisMessageHeader *header, const PLATFORMTYPE pType,const char * profileIDVersion,const char * dialerId,const int ssidCount ,const struct SSIDList *dataList,const int cellularNetworksCount,const struct CellularNet * cellularNetList,const struct LocationInfo *locInfo,const char* hostnameSuffix,char *  themisMessage,int *messageLen);
THEMISLIB_API  void ProcessThemisMsgKeyExchangeResponse(const struct ThemisMessageHeader *header,const char * themisResponse , struct ThemisResponseMsgAction *action);
THEMISLIB_API  void ProcessThemisMsgAPQueryResponse(const struct ThemisMessageHeader *header,const int ssidCount,const int cellularCount ,const char * themisResponse ,struct ThemisResponseMsgAction *action);
//THEMISLIB_API  void	CreateAPQueryRawData( PLATFORMTYPE pType,char * profileIDVersion ,int ssidCount , struct SSIDList *dataList ,char * rawStream,int *messageLen);
//THEMISLIB_API  void	ChaCha20Encrypt( char * key, int keyLen , char * iv ,int ivLen,char * messageStream,int messageStreamLen,char * encryptedStream,int *encryptedMessageLen);

#ifdef __cplusplus
}
#endif
