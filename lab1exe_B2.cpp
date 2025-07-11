/*
 * lab1exe_B2.cpp
 * ENSF 694 - Lab 1 - Execise B Part Two
 */

#include <iostream>
using namespace std;

void bar(int *a, int *b);

void quux(int *p, int *q);

int main(void)
{
  int x = 500, y = 600;
  quux(&x, &y);
  cout << "x is " << x << ", y is " << y << "." << endl;
  return 0;
}

void bar(int *a, int *b)
{
  *a += 3;
  *b += 4;
  
  /* point one */
  cout << "*a is " << *a << ", *b is " << *b << ".\n";
}

void quux(int *p, int *q)
{
  int n;
  n = *p;
  bar(&n, q);
  cout << "*p is "<< *p << ", *q is " << *q << ".\n";
}
