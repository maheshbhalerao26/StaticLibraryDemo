//
//  BaseService.m
//  DemoStaticlib
//
//  Created by NewUSer on 4/2/19.
//  Copyright © 2019 dci. All rights reserved.
//

#import "BaseService.h"
#import <UIKit/UIKit.h>

@interface BaseService () {
   
}
@end

@implementation BaseService
@synthesize APIKey;
@synthesize APISecret;
@synthesize token;


-(instancetype) init{
    self = [super init];
    if(self) {
        APIKey = @"dcivouchers";
        APISecret = @"TAxCNHytzsgqKChyhsk;fiv{gq2MPjkc";
    }
    return self;
}

-(void)init: (NSString *) APIKey APISecret:(NSString*) APISecret{
    self.APIKey = APIKey;
    self.APISecret = APISecret;
}

-(void)activateWiFiUsingBIN:(NSString *)bin uuid: (NSString*)uuid successHandler: (void(^)(NSDictionary* resultDict))successHandler ErrorHandler: (void(^)(NSError *error))ErrorHandler {
    [self getAuthorizationToken:^(NSDictionary *authResult) {
        NSLog(@"JSON Response: %@", authResult);
        NSLog(@"Token: %@", [authResult valueForKey:@"token"]);
        self.token  = [authResult valueForKey:@"token"];
        [self binValidationServiceCall:bin token:self.token  successHandler:^(NSDictionary *binValidationResult) {
            NSLog(@"BIN Response: %@", binValidationResult);
            [self voucherRequestServiceCall:[self getUUID] token:self.token  successHandler:^(NSDictionary *voucherReqDict) {
                NSLog(@"voucherCode request Response: %@", voucherReqDict);
                NSDictionary *voucherDict = [[voucherReqDict valueForKey:@"result"] copy];
                NSString *voucherCode = [voucherDict valueForKey:@"registrationCode"];
                NSLog(@"voucherCode: %@",voucherCode);
                successHandler(voucherReqDict);
            } ErrorHandler:^(NSError *error) {
                NSLog(@"Error Occurred while fetching voucher Code: %@", error);
                ErrorHandler(error);
            }];
        } ErrorHandler:^(NSError *error) {
            NSLog(@"Error Occurred while validating BIN: %@", error);
            ErrorHandler(error);
        }];
    } ErrorHandler:^(NSError *error) {
        NSLog(@"Error Occurred while fetching token: %@", error);
        ErrorHandler(error);
    }];
}

-(void)getAuthorizationToken: (void(^)(NSDictionary* resultDict))successCompletionHandler ErrorHandler: (void(^)(NSError *error))ErrorCompletionHandler{
    NSURL *url = [NSURL URLWithString:@"https://dinersclubfeed.com/api/v1/users/session.json"];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    NSDictionary *body = @{@"api_key":@"dcivouchers", @"api_secret":@"TAxCNHytzsgqKChyhsk;fiv{gq2MPjkc"};
    [request setHTTPBody:[NSJSONSerialization dataWithJSONObject:body options:NSJSONWritingPrettyPrinted error:nil]];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (!error) {
            NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            successCompletionHandler(json);
        } else {
            ErrorCompletionHandler(error);
        }
    }];
    [dataTask resume];
}

-(void)binValidationServiceCall:(NSString *)bin token:(NSString*)authToken successHandler: (void(^)(NSDictionary* resultDict))BINCompletionSuccessHandler ErrorHandler: (void(^)(NSError *error))BINCompletionErrorHandler{
    NSURL *baseURL = [NSURL fileURLWithPath:@"https://dinersclubfeed.com/api/v1/vouchers/bins.json"];
    NSURL *url = [baseURL URLByAppendingPathComponent:bin];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    [request setHTTPMethod:@"GET"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [request setValue:[NSString stringWithFormat:@"Bearer %@",authToken]  forHTTPHeaderField:@"Authorization"];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (!error) {
            NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            BINCompletionSuccessHandler(json);
        } else {
            NSLog(@"%@", error);
            BINCompletionErrorHandler(error);
        }
    }];
    [dataTask resume];
}

-(void)voucherRequestServiceCall:(NSString *)UUID token:(NSString*)authToken successHandler: (void(^)(NSDictionary* resultDict))voucherReqSuccessHandler ErrorHandler: (void(^)(NSError *error))voucherReqErrorHandler{
    NSURL *baseURL = [NSURL fileURLWithPath:@"https://dinersclubfeed.com/api/v1/vouchers.json"];
    NSURL *url = [baseURL URLByAppendingPathComponent:UUID];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    [request setValue:[NSString stringWithFormat:@"Bearer %@",authToken]  forHTTPHeaderField:@"Authorization"];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (!error) {
            NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            voucherReqSuccessHandler(json);
        } else {
            NSLog(@"%@", error);
            voucherReqErrorHandler(error);
        }
        
    }];
    [dataTask resume];
}

-(NSString*)getUUID {
    NSString* identifier = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    NSLog(@"output is : %@", identifier);
    return identifier;
}

@end
