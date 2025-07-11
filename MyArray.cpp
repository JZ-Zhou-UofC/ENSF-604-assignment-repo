#include "MyArray.h"

int search(const MyArray* myArray, int obj)
{
     int currentSize = size(myArray);

    for (int i = 0; i < currentSize; i++)
    {
        if (myArray->array[i] == obj)
        {
            return i;
        }
    }

    return -1;
}
void initialize(MyArray *myArray)
{
    myArray->list_size = 0;
}

int retrieve_at(MyArray *myArray, int pos)
{

    int currentSize = size(myArray);

    if (pos >= 0 && pos < currentSize)
    {
        return myArray->array[pos];
    }

    return 0;
}

int count(MyArray *myArray, int obj)
{

    int occurances_count = 0;
    int currentSize = size(myArray);

    for (int i = 0; i < currentSize; i++)
    {
        if (myArray->array[i] == obj)
        {

            occurances_count++;
        }
    }

    return occurances_count;
}

void append(MyArray *myArray, int array[], int n)
{
    if (myArray->list_size + n <= SIZE)
    {
        int *start = myArray->array + myArray->list_size;
        for (int i = 0; i < n; i++)
        {
            start[i] = array[i];
        }
        myArray->list_size += n;
    }
}

void insert_at(MyArray *myArray, int pos, int val)
{
    int arrayCurrentSize = size(myArray);
    if (pos >= 0 && pos <= arrayCurrentSize)
    {

        for (int i = arrayCurrentSize; i > pos; i--)
        {
            myArray->array[i] = myArray->array[i - 1];
        }
        myArray->array[pos] = val;
        myArray->list_size++;
    }
}

int remove_at(MyArray *myArray, int pos)
{
    int arrayCurrentSize = size(myArray);
 
    if (pos >= 0 && pos < arrayCurrentSize)
    {
        int removedElement = myArray->array[pos];
        for (int i = pos; i < arrayCurrentSize-1; i++)
        {
            myArray->array[i] = myArray->array[i + 1];
        }

        myArray->list_size--;
        return removedElement;
    }
    return 0;
}

int remove_all(MyArray *myArray, int value)
{
    int countRemoved = 0;
    int currentSize = size(myArray);

    for (int i = 0; i < currentSize; i++)
    {
        if (myArray->array[i] == value)
        {
            remove_at(myArray, i);
            countRemoved++;
            i--;
            currentSize--;
        }
    }

    return countRemoved;
}

// You can modify this function however you want:  it will not be tested

void display_all(MyArray *myArray)
{
    for (int i = 0; i < myArray->list_size; i++)
    {
        cout << myArray->array[i] << " ";
    }
    cout << endl;
}

bool is_full(MyArray *myArray)
{
    return myArray->list_size == SIZE;
}

bool isEmpty(MyArray *myArray)
{

    return myArray->list_size == 0;
}

int size(MyArray *myArray)
{

    return myArray->list_size;
}
