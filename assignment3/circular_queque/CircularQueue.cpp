//
//  CircularQueue.cpp
//  Circular Queue
// ENSF 694 Summer 2025 LAB 3 - EXERCISE D
//  Created by Mahmood Moussavi on 2024-04-09.
// implemented by: John Zhou

#include "CircularQueue.h"
#include <stdexcept>

CircularQueue::CircularQueue() : head(0), tail(0), count(0)
{
}

bool CircularQueue::isFull() const
{

    return count == (SIZE-1);
}

bool CircularQueue::isEmpty() const
{

    return count == 0;
}

int CircularQueue::enqueue(int v)
{
    if (isFull())
    {
        throw std::overflow_error("Queue is full. Cannot enqueue.");
    }
    arr[tail] = v;
    int inserted_index = tail;
    tail = (tail + 1) % SIZE;
    count++;
    return inserted_index;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        throw std::underflow_error("Queue is empty. Cannot dequeue.");
    }
    int removed_index = head;
    head = (head + 1) % SIZE;
    count--;
    return removed_index;
}
int CircularQueue::counter() const
{

    return count;
}

const int *CircularQueue::get_arr() const
{
    return arr;
}

void CircularQueue::displayQueue() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    int index = head;
    for (int i = 0; i < counter(); i++)
    {
        std::cout << arr[index] << std::endl;
        index = (index + 1) % SIZE;
    }
}
