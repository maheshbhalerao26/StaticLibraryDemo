//
//  ResourceInfoWrapper.h
//  iPassOpenMobile
//
//  Created by hmuthusankaran on 13/03/13.
//
//

#import <Foundation/Foundation.h>
@class ResourceConfigWrapper;

@interface ResourceInfoWrapper : NSObject

-(id)initWithResourceWrapperAtPath:(NSString*)profilePath resourceFileName:(NSString *) resourceFileName;

@property (atomic, strong)ResourceConfigWrapper* resourceConfigWrapper;


#pragma mark - Customized label value
-(NSString *) getResourceXmlLabelValue:(NSString *) resourceID resourceFileName:(NSString *)resourceFileName useDefaultLabel:(BOOL) useDefaultLabel;
@end
