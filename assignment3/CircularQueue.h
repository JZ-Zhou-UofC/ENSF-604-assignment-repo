//
//  CircularQueue.hpp
//  Circular Queue
//
//  Created by Mahmood Moussavi on 2024-04-09.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include <iostream>
#define SIZE 10

class CircularQueue {
private:
    int head;      // position of head
    int tail;      // position of tail
    int arr[SIZE]; // a queue array with maximum SIZE elements
    int count;     // keeps track of number of valid data in the queue
public:
    
    CircularQueue();
    /* PROMISES: set initial values for head, tail and count*/
    bool isFull()const;
    /* PROMISES: return value is true if queue is full */
    bool isEmpty()const;
    /* PROMISES: return value is true if queue is empty */
    int enqueue(int v);
    /* PROMISES: adds value v to the tail. */
    int dequeue();
    /* PROMISES: returns the position of the element representing, eliminates its value */
    void displayQueue()const;
    /* PROMISES: dispalys the existing values in the queue */
    int counter()const;
    /* PROMISES: returns the number of value in the queue*/
    const int* get_arr()const;
    /* PROMISES: returns the address of the array arr */
};
#endif /* CircularQueue_h */
