//
//  ThemisKeyExchange.h
//  iPassOpenMobile
//
//  Created by Rakesh Anjanappa on 10/30/15.
//
//

#import <Foundation/Foundation.h>

typedef enum
{
    kThemisKeyProcessUnknown = 0,
    kThemisKeyProcessInitiated,
    kThemisKeyProcessPublicKeysGenerated,
    kThemisKeyProcessSuccess,
    kThemisKeyProcessFailure,
    kThemisKeyProcessReInitiate
} ThemisKeyProcessState;


@protocol ThemisKeyExchangeProtocol <NSObject>
@property (weak) NSString *pointx;
@property (weak) NSString *pointy;
@property (nonatomic, assign)  ThemisKeyProcessState keyprocessState;
- (ThemisKeyProcessState)GeneratePublicKeys;
- (void)generateEncryptionKeyUsingServerXCoordinate:(NSString *)x YCoordinate:(NSString *)y;
+(NSString*)generateRandomString:(int)num;
-(void)clearExistingKeyData;
@end

@interface ThemisKeyExchange : NSObject<ThemisKeyExchangeProtocol>
@property (weak) NSString *pointx;
@property (weak) NSString *pointy;
@property (nonatomic, assign)  ThemisKeyProcessState keyprocessState;
- (ThemisKeyProcessState)GeneratePublicKeys;
- (void)generateEncryptionKeyUsingServerXCoordinate:(NSString *)x YCoordinate:(NSString *)y;
- (void)saveSharedKey:(NSString *)sharedKey;
+(NSString*)generateRandomString:(int)num;
-(void)clearExistingKeyData;




@end
