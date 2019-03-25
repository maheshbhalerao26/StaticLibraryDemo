//
//  SMCQueue.h
//  iPassOpenMobile
//
//  Created by Ronak Shah on 10/19/12.
//

#import <Foundation/Foundation.h>

extern NSString* keyQueue;

@protocol SMCQueueSortDelegate <NSObject>
-(NSComparisonResult)resultForObject1:(id)obj1 object2:(id)obj2;
@end

@interface SMCQueue : NSObject<NSCoding, NSFastEnumeration>

//! @brief Add anObject to the end of the queue
- (void) enqueue:(id)obj;

//! @brief Returns the first bject in the queue
- (id) firstObject;

//! returns object t index
-(id)objectAtIndex:(NSUInteger)index;

//! delete methods
-(void)deleteFirstObject;
-(void)deleteObjectsAtIndexes:(NSIndexSet*)indexes;
-(void)deleteAllObjects;
-(void)delete:(id)object;
//! @brief Remove the first object from the queue
- (id) dequeue;

//! @brief Returns the count of items in the Queue
- (NSUInteger)count;

//! @brief Returns of the queue has a object
-(BOOL)hasObject:(id)object;

//sort using delegate method. Delegate should implement SMCQueueSortDelegate
-(void)sortUsingDelegate:(id<SMCQueueSortDelegate>)delegate;

@end
