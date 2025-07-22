
// lab3exe_B.c
// ENSF 694 Fall 2023 LAB 3 - EXERCISE B

#include <iostream>
using namespace std;

#include "cplx_number.h"

void global_print(const Cplx& n);
// REQUIRES: n refers to an object of class Cplx
// PROMISES: displays the values of real and imaginary parts of a complex number.

int main(void)
{
    Cplx num1;
    
    num1.setRealPart(666);
    
    
    global_print(num1);
    
    Cplx num2(34, 5);
    
    global_print(num2);
    
    Cplx *p = &num2;
    
    cout << "\nTesting member functions add and subtract: \n";
    
    num2 = p -> add(num1);
    global_print(*p);
    
    num1 = num1.subtract(p);
    global_print(num1);
    
    return 0;
}

void global_print(const Cplx& n)
{
    cout << "\nYour complex number is: (" << n.getRealPart( )
    << ", "<< n.getImaginaryPart( ) << ")" << endl;
    
}
