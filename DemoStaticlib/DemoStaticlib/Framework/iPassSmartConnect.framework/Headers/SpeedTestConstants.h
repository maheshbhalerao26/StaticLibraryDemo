//
//  SpeedTestConstants.h
//  iPassOpenMobile
//
//  Created by hmuthusankaran on 14/05/13.
//
//

#ifndef iPassOpenMobile_SpeedTestConstants_h
#define iPassOpenMobile_SpeedTestConstants_h

#define APP_TYPE             @"ApplicationsType"
#define MIN_DOWN_SPEED_KBPS     @"MinDownloadSpeedKpbs"
#define MIN_UPLOAD_SPEED_KBPS   @"MinUploadSpeedKpbs"
#define MAX_LATENCY_MS          @"MaxLatencyMilliSec"
#define MAX_PACKET_LOSS         @"MaxPktLoss"

#define QUALITY_RANGE_MIN_SCORE_KEY @"MinScore"
#define QUALITY_RANGE_SCORE_TYPE_KEY @"Type"

#define keySpeedTestSuccessResult @"keySpeedTestResult"


#define SCORE_KEY @"Score"
#define UNIT_KEY @"Unit"
#define MIN_THRESHOLD_KEY @"MinThreshold"
#define GRADE_TYPE @"GradeType"
#define GRADE_WEIGHT @"GradeWeight"
#define GRADE_THRESHOLD_LIST @"GradeThresholdList"

typedef NS_ENUM(NSInteger, ConnectionQualityType)
{
    Excellent = 0,
    VeryGood,
    Good,
    Fair,
    Poor,
    Unknown
};

typedef NS_ENUM(NSInteger, SpeedTestMediaType){
    SpeedTestMediaTypeEMail = 0,
    SpeedTestMediaTypeWebBrowsing,
    SpeedTestMediaTypeVoice,
    SpeedTestMediaTypeVideo,
    SpeedTestMediaTypeUnknown
};

typedef NS_ENUM(NSInteger, SpeedTestModules){
    Latency = 0,
    Download,
    Upload,
    Partial_Test,
    Module_Unknown
};

#endif
