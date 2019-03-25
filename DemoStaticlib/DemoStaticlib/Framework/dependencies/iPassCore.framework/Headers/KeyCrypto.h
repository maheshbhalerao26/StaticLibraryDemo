//
//  KeyCrypto.h
//  iPassOpenMobile
//
//  Created by Ronak Shah on 1/17/12.
//  Copyright (c) 2012 iPass Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KeyCrypto : NSObject

/*! Singleton */
+ (KeyCrypto *)sharedKeyCrypto;

#pragma mark - Symmetric Key Cryptography
/*! @name encrypt:key:salt:
 *  @brief Encrypts a string
 *  @param plainText Plain text to be encrypted
 *  @param key Key to be used for encryption.
 *  @param salt (Optional. Pass nil if no salt is to be added)
 *  @return NSString cipherText */
- (NSString *)encrypt:(NSString *)plainText key:(NSString *)key salt:(NSString *)salt;

/*! @name decrypt:key:salt:
 *  @brief Decrypts a string
 *  @param cipherText Cipher Text to be decrypted.
 *  @param key Key used for decryption.
 *  @param salt (Optional. Pass nil if no salt is to be added)
 *  @return NSString plainText */
- (NSString *)decrypt:(NSString *)cipherText key:(NSString *)key salt:(NSString *)salt;

#pragma mark - Asymmetric Key Cryptography
/*! @name generateKeyPairForPublicTag:PrivateTag:
 *  @brief Generates a public / private key pair and stores it in the device's keychain
 *  @param publicKeyIdentifier Tag to generate the public key with
 *  @param privateKeyIdentifier Tag to generate the private key with */
- (OSStatus)generateKeyPairForPublicTag:(UInt8 *)publicKeyIdentifier PrivateTag:(UInt8 *)privateKeyIdentifier;

/*! @name getPrivateKeyRef
 *  @brief Queries the device's keychain to look for a private key with the provided tag
 *  @param privateKeyIdentifier Tag to query the private key with
 *  @return (SecKeyRef) Reference to the private key in device's keychain. The caller is responsible for the management of the (SecKeyRef) */
- (SecKeyRef)getPrivateKeyRefForTag:(UInt8 *)privateKeyIdentifier;

/*! @name getPublicKeyStringForTag:
 *  @brief Queries the device's keychain to look for a public key with the provided tag
 *  @param publicKeyIdentifier Tag to query the public key with
 *  @return (NSData) Public key bits from device's keychain */
- (NSData*)publicKeyForTag:(UInt8 *)publicKeyIdentifier;
- (NSString *)getRSAPublicKeyAsBase64:(NSData *)keybits;

/*! @name asymmetricDecrypt:cipherData:
 *  @brief Decrypts the cipherData with the privateKey provided. The method performs the decryption on the bytes from the cipherData 
 *         and does not perform any conversion.
 *  @return (NSData) plainData */
- (NSData *)asymmetricDecrypt:(SecKeyRef)privateKey cipherData:(NSData *)cipherData;


/*! generates IV for given Block Size
*/
- (NSData*)generateIV:(NSInteger)Blocksize;

/*! Encrypts string with IV
 */
- (NSString*)encrypt:(NSString*)plainText Key:(NSData*)keyData withIV:(NSData *)ivData keySize:(NSInteger)keySize;

/*! Decrypts string with IV
 */
- (NSString*)decrypt:(NSString*)plainText Key:(NSData*)keyData withIV:(NSData *)ivData keySize:(NSInteger)keySize;

/*! Encrypts hex string with IV
 */

- (NSString*)encryptString:(NSString*)plainText hexKey:(NSString*)hexKeyString withIV:(NSData *)ivData keySize:(NSInteger)keySize;

/*! Decrypts hex string with IV
 */

- (NSString*)decryptString:(NSString*)encryptedHexString hexKey:(NSString*)hexKeyString withIV:(NSData *)ivData keySize:(NSInteger)keySize;

/*! Decrypt obfuscation string with fixed key and IV*/

-(NSString*)decryptObfuscatedString:(NSString*)plainText;

+ (NSString *)decryptResponseForKey:(NSString *)encryptedAESKeyString activationString:(NSString *)activationString;

/*! Decrypt obfuscation provisioning password using private key
 */

- (NSString *)decryptPassword:(NSString *)encryptedPassword forKey:(NSString *)encryptedAESKeyString;
@end
