//
//  OMSQMFilterManager.h
//  iPassOpenMobile
//
//  Created by Sriram on 9/8/13.
//
//

#import <Foundation/Foundation.h>
#import "OMNotification.h"

@interface OMSQMFilterManager : NSObject
+ (OMSQMFilterManager *) sqmFilterManager;

/**
 *	checks whether recording disabled for this record type and subtype
 *  sub
 *
 *	@param	recordType - Name of the sqm record
 *	@param	subType	 -  mediatype or application type of the SQM record
 *
 *	@return	YES means disabled or NO otherwise
 */
-(BOOL) recordingDisabledForRecordName:(NSString*) recordType  subType:(NSString*) subType andSQMValues:(NSDictionary*) values;

/**
 *	Applies the filters on the sqm values and returns the transformed values
 *
 *	@param	recordName	- Name of the SQM record
 *	@param	sqmValues	- sqm Values
 *
 *	@return	returns the transformed values
 */
-(NSDictionary*) appyFiltersForRecord:(NSString*) recordName subType:(NSString*) subType values:(NSDictionary*) sqmValues;

/**
 *	updates the data for filters from SQM filter files
 */
-(void) updateData;

/**
 *	checks and returns if the data from the SQM filter file is not loaded
 *
 *	@return	YES if the data is empty
 */
-(BOOL) isEmpty;
@end
