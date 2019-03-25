//
//  Peceptron.h
//  iPassOpenMobile
//
//  Created by Purushottam Shukla on 8/6/15.
//
//

#import <Foundation/Foundation.h>
#import "TrainingData.h"

//Error Codes
extern NSInteger kPerceptronTrainingError;
extern NSInteger kPerceptronUpdateError;

@protocol Perceptron <NSObject>

/// Method should returns true if the perceptron is already trained, false otherwise.
/// @return Returns true if the perceptron is trained, false otherwise.
-(BOOL)isTrained;

/// Method trains the perceptron (neural network) with the training data provided. This is the first step
/// after the network is created before any prediction over an input can happen.
///
/// @param trainingData The training data that is used to the train the network. The training data is like a matrix (or database table) and contains rows (arrays) of input and output. See MLPTrainingData for
/// details.
///
/// @return Returns the global error after the training has finished.
///
/// @see -(NSArray*)predict:(NSArray*)input
-(double)train:(NSArray<TrainingData>*)trainingData;

/// Method updateds the normalization data of the MLP which is used for prediction.
///
/// @param One data row The data that is used to update the normalization data of the MLP. Tis method should be called any time
/// training data is cahnged exp. when you insert values in data store.
///
/// @return Nothing
///
/// @see -(NSArray*)predict:(NSArray*)input
-(void)update:(id<TrainingData>)trainingData;

/// Method which predicts the output given an input after the network has been
/// Trained with the method above.
/// @param input an array of double which represents input values for the which
/// to predict to the output.
///
/// @return The predicted putput for the given input.
///
/// @see -(double)train:(NSArray<TrainingData>*)trainingData
-(NSArray*)predict:(NSArray*)input;

/// Method enables logging for MLP.
/// @param filePath to which to log.
/// @return None
/// @see -(void)diableLogging
-(void)enableLogging:(NSString*)filePath;

/// Method enables logging for MLP.
/// @param None
/// @return None
/// @see -(void)enableLogging:(NSString*)filePath
-(void)disableLogging;

@end

@interface Perceptron : NSObject<Perceptron>

/// @description learningRate: Learning rate of the perceptron. Default is 0.2
@property (nonatomic) double learningRate;

/// @description momentum: Momentum with which the network learns. Default is 0.1.
@property (nonatomic) double momentum;

/// @description minError: Minimum tolerable error. Default is 0.0001.
@property (nonatomic) double minError;

/// Method creates the preceptron (neural net) with the given number of hidden layers and number of neurons
/// in each layer.
///
/// @param hiddenLayers: Number of hidden layers in the network.
/// @param neuronsInEachLayer: An NSArray of NSNumber containing unsigned int which represents neurons
/// in each hidden layer.
///
/// @return A new isntance of Perceptron of input and output size created with the given number of hidden
/// layers and number of neurons in each layer.
-(instancetype)initWithInputSize:(NSUInteger)inputSize outputSize:(NSUInteger)outputSize HiddenLayers:(NSUInteger)hiddenLayers neuronsInEachLayer:(NSArray*)neurons logTo:(NSString*)filePath NS_DESIGNATED_INITIALIZER;

/// Method serializes MLP to a file
/// @param fileName file path to which the MLP has to be serailized
/// to.
/// @return Returns YES if the serialization was successful, NO otherwise.
/// @see -(BOOL)deserialize:(NSString*)fileName;
-(BOOL)serialize:(NSString*)fileName;

/// Method which predicts the output given an input after the network has been
/// Trained with the method above.
/// @param fileName file path from which the MLP has to be deserailized
/// to.
/// @return Returns YES if the deserialization was successful, NO otherwise.
/// @see -(BOOL)serialize:(NSString*)fileName;
+(instancetype)deserialize:(NSString*)fileName logTo:(NSString*)filePath;
@end
