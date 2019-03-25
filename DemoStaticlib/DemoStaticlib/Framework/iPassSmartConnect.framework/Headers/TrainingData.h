//
//  TrainingData.h
//  iPassOpenMobile
//
//  Created by Purushottam Shukla on 8/7/15.
//
//

#import <Foundation/Foundation.h>

/// Protocol repsents the training data.
@protocol TrainingData

/// Method returns the input data of the object.
/// @return input of the conforming object.
-(NSArray*)input;

/// Method returns the output data of the object.
/// @return output of the conforming object.
-(NSArray*)output;

@end

/// Class represents the training data for the MLP
@interface TrainingData : NSObject<TrainingData>

/// Method creates a new instance of TrainingData with the input and ouput
/// @param input: NSArray of doubles
/// @param output: NSArray of doubles
///
/// @return New instance of TrainingData
-(instancetype)initWithInput:(NSArray*)input output:(NSArray*)output;

@end