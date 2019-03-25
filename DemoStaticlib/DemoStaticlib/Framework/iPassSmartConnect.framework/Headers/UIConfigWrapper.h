//
//  UIConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Ronak Shah on 3/6/12.
//  Copyright (c) 2012 iPass Inc. All rights reserved.
//
//  Revision History: 
//  3/12/12 - Ronak Shah: Added logic to parse the XML file once and store it in a respective .plist file
//

#import <Foundation/Foundation.h>

@class iPassXMLDocument;

/*! @brief Public field identifiers for keying into private metadata for leaf nodes.
 * This enum identifies each leaf node of interest to this app version because it contains 
 * a data element value
 */
typedef NS_ENUM(NSInteger, UIConfigField)
{
    kUIConfigField_ProfileId,
    kUIConfigField_LogoImageName,
} ;

/*! @brief Public field identifiers for keying into private metadata for context nodes.
 * This enum identifies each node of interest to this app version because it can be used as 
 * node context while navigating multi-child nodes.
 */
typedef NS_ENUM(NSInteger, UIConfigNodeContext)
{
    kUIConfigNodeContext__UIConfig,
} ;

@interface UIConfigWrapper : NSObject
{
@private
    iPassXMLDocument *mDocument;
    NSError         *mErr;
    int             mUIConfigCount;
    BOOL            mStatusOk;
}

- (id)initWithPath:(NSString *)filePath;
- (BOOL)isOk;
- (BOOL)isParsedOk;
- (void)print;
- (BOOL)validateCorrectness;

#pragma mark - Getters
- (NSString *)getProfileId;
- (BOOL)getIsClientBranded;
- (NSString *)getLogoImageName;

@end