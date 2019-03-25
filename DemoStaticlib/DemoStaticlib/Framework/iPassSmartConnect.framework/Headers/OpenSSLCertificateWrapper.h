//
//  OpenSSLCertificateWrapper.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 26/11/13.
//
//

#import <Foundation/Foundation.h>

@interface OpenSSLCertificateWrapper : NSObject

+(nullable instancetype)certificateWithP12Path:(nullable NSString*)p12Path passpharse:(nullable NSString*)passpharse;

//sign and verify
-(nullable NSData*)pkcs7SignData:(nullable NSData*)data;
-(nullable NSData*)pkcs7VerifyData:(nullable NSData*)data;

//create certificate from CSR
-(void)certificateWithCSRData:(NSData*)csrData;
@end
