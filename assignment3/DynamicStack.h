#ifndef DynamicStack_H
#define DynamicStack_H
#include <iostream>
using namespace std;
class DynamicStack {
private:
    int entry;
    int initial_capacity;
    int current_capacity;
    int *array;
public:
    DynamicStack(int n = 5);
    /* PROMISES: sets value of entry to zero, initial_capacity and current_capacity to n,
     * and allocates memory space for array */
    
    /* copy ctor*/
    DynamicStack(DynamicStack const &);
    

    ~DynamicStack();
    /* PROMISES: deallocates memory space allocated for array*/
    
    int top() const;
    /* PROMISES: Returns the value at the top of the stack */
    
    int size() const;
    /* PROMISES: Returns the number values stores in the stack */
    
    bool empty() const;
    /* PROMISES: Returns true if stack is emapty */
    
    int capacity() const;
    /* PROMISES: Returns current capacity of the array in the stack */
    
    DynamicStack &operator=(const DynamicStack& );
    
    void push( const int& v);
    /* PROMISES: The value of v is added at the top of the stack. If the array is full,
     * the current capacity of the array is doubled, the value of v is added.
     */
    int pop();
    /* PROMISES: Removes the element at the top of the stack. If, only one fourth of
     * the array is full,  and the array's capacity is greater than it's initial capacit, the
     * capacity of the array is halved.
     */
    void clear();
    /* PROMISES: removes all the entry vlues from stack and if necessary resizes
     * the array to its initial capacity.
     */
    void display();
    /* PROMISES: displays all the existing vlues in the stack */
};
#endif
