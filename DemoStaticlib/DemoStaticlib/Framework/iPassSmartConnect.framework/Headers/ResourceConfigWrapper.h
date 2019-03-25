//
//  ResourceConfigWrapper.h
//  iPassOpenMobile
//
//  Created by hmuthusankaran on 28/02/13.
//
//
@import Foundation;

typedef NS_ENUM(NSInteger, ResourceConfigField)
{
    kResourceConfigField_ResourceId,
    kResourceConfigField_ResourceValue,
} ;

/*! @brief Public field identifiers for keying into private metadata for context nodes.
 * This enum identifies each node of interest to this app version because it can be used as
 * node context while navigating multi-child nodes.
 */
typedef NS_ENUM(NSInteger, ResourceConfigNodeContext)
{
    kResourceConfigNodeContext__Resource,
} ;

@class iPassXMLDocument;

@interface ResourceConfigWrapper : NSObject
{
@private
    iPassXMLDocument *mDocument;
    NSError *mErr;
    int             mResourceConfigCount;
}

- (id) initWithPath: (NSString *) filePath resourceFileName:(NSString *)resourceFileName;
-(NSDictionary *)getResourceInfoDictionary;
@end
