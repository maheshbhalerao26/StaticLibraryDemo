//
//  Logger.h
//  iPass Open Mobile
//
//  Created by Ranjit Bhullar on 29/12/10.
//  Copyright 2010 Ranjit. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import <iPassCore/iPassCore.h>

//typedef NS_ENUM(NSInteger, SMCLogLevel){
//    SMCLogLevelInfo = 0,
//    SMCLogLevelWarning = 1,
//    SMCLogLevelError = 2,
//    SMCLogLevelDebug = 3,
//    SMCLogLevelTrace = 4,
//};

NS_ASSUME_NONNULL_BEGIN

@interface Logger : NSObject<iPassLogger>

//! @brief returns  the sahred logger object
+(instancetype)sharedLogger;
+(void)logWithType:(SMCLogLevel)type message:(NSString*) msg, ...;
+(void)logWithType:(SMCLogLevel)type format:(NSString*)format;
+(void)logHotspotDebugInfoWithType:(SMCLogLevel)type message:(NSString *) msg, ...;
+(void)logHotspotDebugInfoWithType:(SMCLogLevel)type format:(NSString*)format;
+(void)logUserDebugInfoWithType:(SMCLogLevel)type message:(NSString *) msg, ...;
+(void)logUserDebugInfoWithType:(SMCLogLevel)type format:(NSString*)format;


+ (NSString *)findCallerMethod;

+ (void)logWithType:(SMCLogLevel)type component:(NSString*)component transactionId:(NSString*)transactionId message:(NSString *) msg;
+ (void)streamlinedLogWithType:(SMCLogLevel)type component:(NSString*)component transactionId:(NSString*)transactionId
               message:(NSString *) message;

//! Logs basic information about the aplication
+(void)logApplicationInfo;

/*! @brief Resizes the logs file to contain the latest 6MB of data if the size is greater 
 *         than 9MB.
 */
+(void)resizeLogsFile;

/**
 * @brief Method is used to extract all the logs in a zipped format
 * @returns Path of the zip File
 */
-(NSString*)extractLogFiles;

+(NSString*)shortStringFromLogLevel:(SMCLogLevel)level;

/**
 * @brief Method is used to switch(swap) the logSerive filename
 */
- (void)switchLogServiceFile;

/**
 * @brief Method is used to reset (clear) logSerive file 
 */
-(void) resetLogServiceFile;
-(void)formatToJson:(NSArray*) fileArray;
-(NSString*)logFileToZip;
@end

NS_ASSUME_NONNULL_END
