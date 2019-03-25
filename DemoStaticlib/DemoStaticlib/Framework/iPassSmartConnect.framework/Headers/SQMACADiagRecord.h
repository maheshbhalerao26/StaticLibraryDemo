//
//  SQMACADiagRecord.h
//  iPassOpenMobile
//
//  Created by Monish Bhorali on 10/06/14.
//
//

#import <Foundation/Foundation.h>
#import "SQMDiagRecord.h"

#define ACA_XML_VERSION         1
#define ACA_XML_TYPE            @"acamigration"
#define ACA_MIGRATION_RECORD    @"acaMigrationRecord"
#define ACA_REQUEST_PARAMS      @"acaRequestParams"
#define ACA_MIGRATION_RESPONSE  @"acaMigrationResponse"

#define ACA_lang                @"lang"
#define ACA_targetclass         @"targetclass"
#define ACA_targetplatform      @"targetplatform"
#define ACA_productname         @"productname"
#define ACA_productversion      @"productversion"
#define ACA_guid                @"guid"
#define ACA_username            @"username"
#define ACA_username_request    @"username_request"
#define ACA_username_response   @"username_response"
#define ACA_passwordpresent     @"passwordpresent"
#define ACA_emailaddress        @"emailaddress"
#define ACA_timeStamp           @"timeStamp"
#define ACA_requesttimeStamp    @"requesttimeStamp"
#define ACA_responsetimeStamp   @"responsetimeStamp"
#define ACA_httpResponseCode    @"httpResponseCode"
#define ACA_error               @"error"
#define ACA_acaMigrationRespone @"acaMigrationResponseCode"

@interface SQMACADiagRecord : SQMDiagRecord
+ (SQMACADiagRecord *)newDiagRecord;
@end
