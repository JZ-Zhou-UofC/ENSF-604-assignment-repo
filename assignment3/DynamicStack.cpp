
//
//  DynamicStack.cpp
//  Dynamic Stack

// ENSF 694 Summer 2025 LAB 3 - EXERCISE E
//  Created by Mahmood Moussavi on 2024-04-09.
//  implemented by: John Zhou

#include "DynamicStack.h"
#include <stdexcept>

DynamicStack::DynamicStack(int n)
{
    entry = 0;
    initial_capacity = n;
    current_capacity = n;
    array = new int[current_capacity];
}

DynamicStack::DynamicStack(DynamicStack const &stack)
{
    entry = stack.entry;
    initial_capacity = stack.initial_capacity;
    current_capacity = stack.current_capacity;
    array = new int[current_capacity];
    for (int i = 0; i < entry; ++i)
    {
        array[i] = stack.array[i];
    }
}

DynamicStack::~DynamicStack()
{
    delete[] array;
}

int DynamicStack::top() const
{
    if (entry == 0)
    {
        throw std::underflow_error("stack empty. no top");
    }
    return array[entry - 1];
}

int DynamicStack::size() const
{
    return entry;
}

bool DynamicStack::empty() const
{
    return entry == 0;
}

int DynamicStack::capacity() const
{
    return current_capacity;
}

DynamicStack &DynamicStack::operator=(DynamicStack const &rhs)
{
    if (this != &rhs)
    {
        delete[] array;
        entry = rhs.entry;
        initial_capacity = rhs.initial_capacity;
        current_capacity = rhs.current_capacity;
        array = new int[current_capacity];
        for (int i = 0; i < entry; ++i)
        {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

void DynamicStack::push(const int &obj)
{
    if (entry == current_capacity)
    {
        int new_capacity = current_capacity * 2;
        int *new_array = new int[new_capacity];
        for (int i = 0; i < entry; ++i)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        current_capacity = new_capacity;
    }
    array[entry++] = obj;
}

int DynamicStack::pop()
{
    if (entry == 0)
    {
        throw std::underflow_error("stack empty. can't pop");
    }
    entry--;
    return array[entry];
}

void DynamicStack::clear()
{
    entry = 0;
    if (current_capacity != initial_capacity)
    {

        current_capacity = initial_capacity;
    }
    delete[] array;
    array = new int[initial_capacity];
}

void DynamicStack::display()
{
    if (entry == 0)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        for (int i = 0 ; i < entry; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}
