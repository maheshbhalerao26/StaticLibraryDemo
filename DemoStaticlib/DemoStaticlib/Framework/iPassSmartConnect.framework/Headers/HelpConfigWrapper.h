//
//  HelpConfigWrapper.h
//  iPassOpenMobile
//
//  Created by Almas Daumov on 8/27/13.
//
//

#import <Foundation/Foundation.h>

#define GLOBAL_HELP_XML_FILE   @"GlobalHelp"
#define PARTNER_HELP_XML_FILE  @"PartnerHelp"
#define CUSTOM_HELP_XML_FILE   @"Help"
#define HELP_PLIST_FILE        @"Help.plist"
#define QUESTION_XML_ID        @"Question"
#define ANSWER_XML_ID          @"Answer"

@class iPassXMLDocument;

// Leafs
typedef NS_ENUM(NSInteger, HelpField)
{
    kHelpFieldQuestion,
    kHelpFieldAnswer
} ;

// Context
typedef NS_ENUM(NSInteger, HelpContext)
{
    kHelp,
    kHelpItem
} ;

@interface HelpConfigWrapper : NSObject

- (NSArray *)localizedHelpItems;

@end
