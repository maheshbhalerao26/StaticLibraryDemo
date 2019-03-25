//
//  SQMRecord.h
//  iPassOpenMobile
//
//  Created by Puru Shukla on 26/10/12.
//
//

#import <Foundation/Foundation.h>

/*! @enum RecordType enumeration
 *  @discussion The order of the items in this enum is very important and should not be changed
 *              as the items are serialized in a file and the order matters. */
typedef NS_ENUM(NSInteger, RecordType)
{
	kClientRecord = 0,
	kConnectionRecord = 1,
	kDeviceRecord = 2,
    kActivationConfirmation = 3,
    kConnectionQualityRecord = 4,
    kDiagnosticsRecord = 5,
    // Add new items to the enumeration after here
} ;

@protocol Recordable

@optional
//! @brief Gets the record as a xml string
-(NSString*)getAsXmlString;

//! @brief Gets the record as data
-(NSData*)getAsData;

@end

extern NSString* keyRecordData;

@interface SQMRecord : NSObject<Recordable, NSCoding>

//! Record type
@property RecordType type;

//! Property to decide whether to upload
@property BOOL shouldUploadOnlyOnWifi;

//! timestamp of the record
@property NSUInteger timestamp;

//! @brief Gets the record type in string
-(NSString*) recordType;

//!@ Getter/Setter for the fields
-(NSObject*)objectForField:(NSUInteger)field;
-(void)setObject:(NSObject*)value forField:(NSUInteger)field;

//! @brief recording Disabled 
-(BOOL) recordingDisabled:(NSString*) mediaType;

@end
