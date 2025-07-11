#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include <iostream>
using namespace std;
#define SIZE 5

struct MyArray
{
    int array[SIZE];
    int list_size;
};

int size(const MyArray* myArray);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: returns value of myArray->list_size.
 */

void initialize(MyArray *myArray);
/* REQUIRES: pointer myArray points to an object of struct MyArray
 * PROMISES: initilizes the member myArray->list_size to zero. In other words since
 * myArray->array is empty the list_size is set to zero.
 */

int search(const MyArray *myArray, int obj);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: returns the position of first occurance of obj in myArray->array. Returns -1
 * if there is no match for obj.
 */

void append(MyArray *myArray, int array[], int n);
/*
 * REQUIRES: pointer list points to an object of struct MyArray and array points to
 * an arrary of n integer numbers.
 * PROMISES: If (myArray->list_size + n), is less than or equal SIZE appends the numbers in
 * array to the end of the myArray->array. Otherwise, it does nothing.
 */

int retrieve_at(MyArray *myArray, int pos);
/*
 * REQUIRES: pos >= 0, and pos < size(), and pointer myArray points to an object of struct
 * MyArray.
 * PROMISES: returns the value of myArray->array at the position pos.
 */

void insert_at(MyArray *myArray, int pos, int val);
/*
 * REQUIRES: pos >= 0 and pos <= size(), and pointer myArray points to an object of struct
 * MyArray.
 * PROMISES: inserts the value of val in myArray->array[pos], after moving the values in the
 * myArray->array to the right of element pos. Then, increments that list_size by one.
 */

int remove_at(MyArray *myArray, int pos);
/*
 * REQUIRES: pos >= 0 and pos <= size(), and pointer myArray points to an object of struct
 * MyArray.
 * PROMISES: removes the value of element myArray->array[pos], by moving the values in the
 * elements of myArray->array, starting from position pos+1, to the left. if process is
 * successful, decrements list_size by one. Also, returns the value of the element that
 * was removed.
 */

void display_all(MyArray *myArray);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: displays the value in myArray->array from elment 0 to list_size-1.
 */

bool is_full(MyArray *myArray);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: returns true is myArray->list_size equals SIZE. Otherwise returns false.
 */

bool isEmpty(MyArray *myArray);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: returns true is myArray->list_size equals zero. Otherwise returns false.
 */

int count(MyArray *myArray, int obj);
/*
 * REQUIRES: pointer myArray points to an object of struct MyArray.
 * PROMISES: returns the count of elements of myArray->array that their value is equal to obj.
 */
int remove_all(MyArray *myArray, int value);
/*
 * PROMISES: removes all the occurances of value and returns the number of removed
 * values.
 */

#endif
