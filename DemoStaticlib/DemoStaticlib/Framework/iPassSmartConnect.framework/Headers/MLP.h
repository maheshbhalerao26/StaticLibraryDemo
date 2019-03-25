//
//  MLP.h
//  
//
//  Created by Purushottam Shukla on 8/7/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface MLP : NSManagedObject

/// Input Features
@property (nonatomic, retain) NSNumber * battery;
@property (nonatomic, retain) NSNumber * charging;
@property (nonatomic, retain) NSNumber * stationary;
@property (nonatomic, retain) NSNumber * scanOverlap;
@property (nonatomic, retain) NSNumber * wpvf;
@property (nonatomic, retain) NSNumber * dwf;
@property (nonatomic, retain) NSNumber * dad;
@property (nonatomic, retain) NSNumber * ca;

/// Output Features
@property (nonatomic, retain) NSNumber * collect;
@property (nonatomic, retain) NSNumber * frequency;

/// Method returns teh input array
/// @return input array formed with the input data of MLP
-(NSArray*)inputArray;

/// Method returns teh input array
/// @return output array formed with the output data of MLP
-(NSArray*)outputArray;

@end
