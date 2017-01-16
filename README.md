# Minimum-Priority-Queue

Task 1
The starter code PQueue0.h declares a minimum priority queue class that stores only int elements.
We assume the priority queue will hold a maximum of 100 items.
You need to write the implementation in PQueue0.cpp. The two key methods to write are moveUp
and moveDown.
 The moveUp method assumes the heap property is violated at the very last item in the heap
array so the item needs to be moved up.
 The moveDown method will take an array index position and start “moving down” the item in
that position from there. This method is called to move down the root element during the
dequeue operation, and also used during the Floyd’s O(n) heap construction algorithm.
Here is the algorithm for min heap’s moveDown(int tmp): while the value at index tmp is not a leaf
and is greater than any of its children, swap this value with its smaller child (if two children nodes have
the same key, a random one is selected to be swapped).
Once you are finished, run the given test driver testPQ0.cpp. You should write your own additional
test files to test all the other methods in your implementation.


Task 2
Based on your PQueue0.h and PQueue0.cpp from Task 1, write a class template of the minimum
priority queue. The template can be used to create generic priority queues for any comparable types with
a given maximum queue size.
The template header file should be in PQueue.h and the template implementation file to be
implemented should be named as PQueue.cpp. Note in the template declaration that T is a template
type parameter and MAX_SIZE is a template non-type parameter that specifies the maximum number of
elements in the queue.
template<class T, int MAX_SIZE>
class PQueue{
 // . . .
}
