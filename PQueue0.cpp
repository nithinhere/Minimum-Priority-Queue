// a nontemplated version
#include "PQueue0.h"

// construct an empty binary heap.
PQueue::PQueue():_size(0){ _array[0]=0;}

// construct a binary heap from an array of element
// assume the array size is smaller than MAX_SIZE
PQueue::PQueue(int* items, int size):_size(size){
    _array[0]=0;
    for (int i = 0; i < size; i++)
        _array[i] = items[i];
    buildHeap();
}

// insert item into the priority queue; duplicates are allowed.
void PQueue::insert(T x){
    _size++;
    _array[_size] = x;
    moveUp();
}

// return the smallest item in the priority queue.
T PQueue::findMin(){
    return _array[0];
}

// temove the smallest item from the priority queue
// throw UnderflowException if empty.
void PQueue::deleteMin(){
    _array[1] = _array[_size--];
    moveDown(1);
}

// test if the priority queue is logically empty.
// return true if empty, false otherwise.
bool PQueue::isEmpty(){
    return _size == 0;
}

// private method to move up the last item in the heap.
void PQueue::moveUp(){
    int hole = _size;
    T item = _array[hole];
    for( ; item < _array[hole/2]; hole /= 2 )
        _array[hole] = _array[hole/2];
    _array[ hole ] = item;
    
}

// Establish heap-order property from an arbitrary
// arrangement of items. Runs in linear time.
void PQueue::buildHeap(){
    for(int i = (_size / 2 - 1); i >= 0; i-- ){
		cout << "moveDown for " << _array[i] << endl;
        moveDown(i);
    }
	for (int i = 0; i < _size; i++)
		cout << _array[i] << " " << endl;
}

// private method to move down in the heap.
// hole is the index at which the move down begins.
void PQueue::moveDown(int hole){
    int child;
    T tmp = _array[hole];
    for( ; hole * 2 <= _size; hole = child ){
        child = (hole * 2) + 1;
		cout << "child=" << child << " array[child]=" << _array[child] << endl;
        if( child != (_size - 1) && _array[child + 1] < _array[child] )
            child++;
        if( _array[child] < tmp )
            _array[hole] = _array[child];
        else
            break;
    }
    _array[hole] = tmp;
}

// return queue size
int PQueue::size(){
    return _size;
}

