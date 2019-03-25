//
//  ConnProfilerConfigWrapper.h
//  iPassOpenMobile
//
//  Created by hmuthusankaran on 07/05/13.
//
//

#import <Foundation/Foundation.h>
#import "SpeedTestConstants.h"

@class iPassXMLDocument;

// Public field identifiers for keying into private metadata for leaf nodes.
// This enum identifies each leaf node of interest to this app version because
// it contains a data element value
typedef enum
{
    kConnProfilerConfigField_MonitorQuality_EnableManualTest,
    kConnProfilerConfigField_MonitorQuality_Enabled,
    
    kConnProfilerConfigField_Quality_Range_Value_MinScore,
    kConnProfilerConfigField_Quality_Range_Value_Type,
    
    kConnProfilerConfigField_Quality_Application_MinDownloadKilobitsPerSecond,
    kConnProfilerConfigField_Quality_Application_MinUploadKilobitsPerSecond,
    kConnProfilerConfigField_Quality_Application_Type,
    kConnProfilerConfigField_Quality_Application_MaxLatencyMS,
    kConnProfilerConfigField_Quality_Application_MaxPktLossPercent,
    
    kConnProfilerConfigField_Quality_Param_Type,
    kConnProfilerConfigField_Quality_Param_Weight,
    
    kConnProfilerConfigField_Quality_Param_Grade_MinThreshold,
    kConnProfilerConfigField_Quality_Param_Grade_Score,
    kConnProfilerConfigField_Quality_Param_Grade_Unit,
        
    kConnProfilerConfigField_SpeedTestConfig_Frequency_DeltaKilobytesRecvd,
    kConnProfilerConfigField_SpeedTestConfig_Frequency_DeltaKilobytesSent,
    kConnProfilerConfigField_SpeedTestConfig_Frequency_EnableBackOff,
    kConnProfilerConfigField_SpeedTestConfig_Frequency_Interval,
    
    kConnProfilerConfigField_SpeedTestConfig_DownloadServers_Server_URL,
    kConnProfilerConfigField_SpeedTestConfig_UploadServers_Server_URL,
    
    /* For speed test*/
    kConnProfilerConfigField_SpeedTestConfig_ManualTest,
    kConnProfilerConfigField_SpeedTestConfig_ManualTest_DownloadSizeMB,
    kConnProfilerConfigField_SpeedTestConfig_ManualTest_MaxDownloadTime,
    kConnProfilerConfigField_SpeedTestConfig_ManualTest_MaxUploadTime,
    kConnProfilerConfigField_SpeedTestConfig_ManualTest_UploadSizeMB,
    
    kConnProfilerConfigField_SpeedTestConfig_AutoTest,
    kConnProfilerConfigField_SpeedTestConfig_AutoTest_DownloadSizeMB,
    kConnProfilerConfigField_SpeedTestConfig_AutoTest_MaxDownloadTime,
    kConnProfilerConfigField_SpeedTestConfig_AutoTest_MaxUploadTime,
    kConnProfilerConfigField_SpeedTestConfig_AutoTest_UploadSizeMB,
    kConnProfilerConfigFieldCount
} ConnProfilerConfigSV;

// Public field identifiers for keying into private metadata for context nodes.
// This enum identifies each node of interest to this app version because
// it can be used as node context while navigating multi-child nodes.
typedef enum
{
    kConnProfilerConfigNodeContextQualityRange,
    kConnProfilerConfigNodeContextQualityRangeValue,
    
    kConnProfilerConfigNodeContextQualityApplications,
    kConnProfilerConfigNodeContextQualityApplication,
    
    kConnProfilerConfigNodeContextDownloadServers,
    kConnProfilerConfigNodeContextDownloadServer,
    
    kConnProfilerConfigNodeContextUploadServers,
    kConnProfilerConfigNodeContextUploadServer,
    
    kConnProfilerConfigNodeContextQualityParams,
    kConnProfilerConfigNodeContextQualityParam,
    kConnProfilerConfigNodeContextQualityParamsGrades,
    kConnProfilerConfigNodeContextQualityParamsGrade,
    
    kConnProfilerConfigNodeContextCount
    
} ConnProfilerConfigMV;

@interface ConnProfilerConfigWrapper : NSObject
{
@private
    iPassXMLDocument *mDocument;
    int mApplicationTypeCount;
    int mUploadServerCount;
    int mDownloadServerCount;
    int mQualityRangeScoreValueCount;
    int mParamCount;
    BOOL mStatusOk;
}

- (id) initWithPath: (NSString *) filePath;
-(NSDictionary *)getConnectionProfilerInfoDictionary;


-(NSArray *) getAllUploadServerUrlArr;
-(NSArray *) getAllDownloadServerUrlArr;

-(NSArray *) getApplicationTypeInfoArr;
-(NSArray *) getParamThresholdArr;
-(NSArray *) getScoreRangeThresholdArr;

-(BOOL) isManualTestEnabled;
-(BOOL) isMonitorQualityEnabled;

-(NSString *)getManualTestFileName;
-(NSInteger)getManualTestMaxDownloadTime;
-(NSInteger)getManualTestMaxUploadTime;
-(NSString *)getManualTestDownloadSizeMB;
-(NSString *)getManualTestUploadSizeMB;

-(NSString *)getAutoTestFileName;
-(NSString *)getAutoTestMaxDownloadTime;
-(NSString *)getAutoTestMaxUploadTime;
-(NSString *)getAutoTestDownloadSizeMB;
-(NSString *)getAutoTestUploadSizeMB;

//-(SpeedTestMediaType) mapMediaTypeStrToEnum:(NSString*) strMedia;
//-(NSInteger) timeIntervalInSeconds:(NSString*) strTime;
//
//-(ConnectionQualityType) mapQualityTypeStrToEnum:(NSString *) enumQuality;

@end
