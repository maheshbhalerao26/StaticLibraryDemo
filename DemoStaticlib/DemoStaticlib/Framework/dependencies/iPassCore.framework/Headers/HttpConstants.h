//
//  HttpConstants.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 21/06/12.
//
//

#ifndef iPassOpenMobile_HttpConstents_h
#define iPassOpenMobile_HttpConstents_h

extern NSTimeInterval kInsufficientBackgroundTime;

//default http timeout
extern NSTimeInterval kDefaultHttpTimeout;

//default user agent
extern NSString* kDefaultiPassUserAgentString;

//HTTP Methods, remove upper enumeration later
extern NSString* kHttpGet;
extern NSString* kHttpPost;
extern NSString* kHttpHead;


//Common HTTP Header fields
extern NSString* keyHttpLocation;
extern NSString* keyHttpContentType;
extern NSString* keyHttpUserAgent;
extern NSString* keyHttpSetCookie;
extern NSString* keyHttpCookie;

//http userinfo keys.
extern NSString*	keyHttpResponseCode;
extern NSString*	keyHttpResponseData;
extern NSString*	keyHttpFailureReason;

//HTTP Content Type
typedef NS_ENUM(NSInteger, HttpContentType)
{
	DEFAULT_ENCODING = 0,
	FORM_URL_ENCODED = 1 << 0,
    GZIP_ENCODING = 1 << 1,
} ;

//HTTP request result
typedef NS_ENUM(NSInteger, HttpStatusCode){
    /*kCFErrorDomainCFNetwork code defined in /usr/include/netdb.h*/
    kHttpHostErrorUnknown = 2,	/* temporary failure in name resolution */
    
    /*kCFStreamErrorDomainNetDB codes defined in netdb.h*/
    kHttpNetDBNoHostOrServerName = 8,     /* hostname nor servname provided, or not known */
    
    /*kCFErrorDomainPOSIX error codes. These error codes corresponds to <sys/errorno.h>*/
    kHttpPosixProtocolNotSupported = 46,  /* Protocol family not supported */
    kHttpPosixAddressNotSupported = 47,   /* Address family not supported by protocol family */
    kHttpPosixAddressInUse = 48,          /* Address already in use */
    kHttpPosixAddressNotAvailable = 49,   /* Can't assign requested address */
    kHttpPosixNetDown = 50,               /* Network is down */
    kHttpPosixNetUnreachable = 51,        /* Network is unreachable */
    kHttpPosixNetReset = 52,              /* Network dropped connection on reset */
    kHttpPosixConnectionAborted = 53,     /* Software caused connection abort */
    kHttpPosixConnectionReset = 54,       /* Connection reset by peer */
    kHttpPosixNoBuffer = 55,              /* No buffer space available */
    kHttpPosixSocketConnected = 56,       /* Socket is already connected */
    kHttpPosixSocketNotConnected = 57,    /* Socket is not connected */
    kHttpPosixSocketShutdown = 58,        /* Can't send after socket shutdown */
    kHttpPosixTooManyReferences = 59,     /* Too many references: can't splice */
    kHttpPosixOperationTimedout = 60,     /* Operation timed out */
    kHttpPosixConnectionRefused = 61,     /* Connection refused */
    /*62 and 63 are defined as values related to file operations, which we don't want to handle*/
    kHttpPosixHostDown = 64,              /* Host is down */
    kHttpPosixHostUnReachable = 65,       /* No route to host */
    
    
    /*Open mobile custom error codes*/
    kHttpRequestSentSuccess = 600,       /*Successfully configured and sent http request*/
    kHttpEmptyRequestURL = 601,          /*Empty request URL*/
    kHttpNoMethodSpecified = 602,        /*No HTTP method specified*/
    kHttpRequestCreationFailed = 603,    /*HTTP request creation failed*/
    kHttpAddAuthenticationFailed = 604,  /*Add authentication fialed*/
    kHttpReadStreamCreationFailed = 605, /*Read stream creation failed*/
    kHttpReadStreamOpenFailed = 606,     /*Read stream open failed*/
    kHttpRequestAborted = 607,
    kHttpNoResponseForStatusCode = 608,  /*No response available to get the status code*/
    
    kHttpErrorReadStreamClosed = 609,
    kHttpErrorUnknownError = 610,
    kHttpHostDomainNotFound = -1003,
    
    /*Successful: 2xx status codes*/
	kHttpOk = 200,
    kHttpCreated = 201,
    kHttpAccespted = 202,
    kHttpNonAuthoritativeInformation = 203,
    kHttpNoContent = 204,
    kHttpResetContent = 205,
    kHttpPartialContent = 206,
    
    /*Redirection: 3xx status codes*/
    kHttpMultipleChoices = 300,
    kHttpMovedPermanently = 301,
	kHttpMovedTemporarily = 302,
    kHttpSeeOther = 303,
    kHttpNotModified = 304,
    kHttpUseProxy = 305,
    kHttpUnused = 306,
    kHttpTemporaryRedirect = 307,
    kHttpPermanentRedirect = 308,
    
    /*Client Error: 4xx status codes*/
    kHttpBadRequest = 400,
	kHttpAuthenticationFailed = 401,
    kHttpPaymentRequired = 402,
    kHttpForbidden = 403,
    kHttpNotFound = 404,
    kHttpMethodNotAllowed = 405,
    kHttpNotAcceptible = 406,
    kHttpProxyAuthenticationRequired = 407,
	kHttpRequestTimeout = 408,
    
    /*server Error: 5xx status codes*/
    kHttpInternalServerError = 500,
    kHttpNotImplemented = 501,
    kHttpBadGateway = 502,
    kHttpServiceUnavilable = 503,
    kHttpGatewayTimeout = 504,
    kHttpVersionNotSupported = 505,
};

#endif
