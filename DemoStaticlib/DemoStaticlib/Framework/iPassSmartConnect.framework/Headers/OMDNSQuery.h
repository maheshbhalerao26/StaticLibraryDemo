//
//  OMDNSQuery.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 04/08/13.
//
//

#import <Foundation/Foundation.h>

//query type, these correspond to values in dns_sd.h
typedef NS_ENUM(NSUInteger, DNSQueryType){
    kDNSQueryTypeCNAME = 5,
};

//query class
typedef NS_ENUM(NSUInteger, DNSQueryClass){
    kDNSQueryClassIN = 1,
};

@interface OMDNSQuery : NSObject

-(instancetype)initWithQuery:(NSString*)query
                   interface:(NSString*)interface
             timeoutInterval:(NSTimeInterval)timeoutValue;

//Method synchrnously queries DNS record
-(NSString*)queryRecordForClass:(DNSQueryClass)queryClass
                      queryType:(DNSQueryType)queryType;

//This method performs DNS query using res_query system API
-(NSString*)dnsLookUpUsingResQuery;

//Callback methods
-(void)nativeSocketCallback;
-(void)nativeTimoutCallback;
@end
