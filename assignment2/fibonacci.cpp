
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define N 2

void myPlot(int *x, double *y1, double *y2, int size)
{
    // This funcitn must be completed by the students
}

// Function to multiply two matrices of size N x N
void multiplyMatrices(int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
// Recursive funciont
void powerMatrix(int A[N][N], int n, int result[N][N]) {
    // Base case: if n == 0, result should be the identity matrix
    if (n == 0) {
        result[0][0] = 1;
        result[0][1] = 0;
        result[1][0] = 0;
        result[1][1] = 1;
        return;
    }

    // Temporary matrix for storing intermediate results
    int temp[N][N];
    cout <<"rrrrrrrrrrrrrrrrrrr"<<'\n'; 
    // Recursive case: divide the exponent by 2 and compute the power of A^(n/2)
    powerMatrix(A, n / 2, temp);

    // Multiply the result by itself
    multiplyMatrices(temp, temp, result);

    // If n is odd, multiply the result by A one more time
    if (n % 2 == 1) {
        multiplyMatrices(result, A, temp);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = temp[i][j];
            }
        }
    }
}

// Function to calculate the nth Fibonacci number using recursive matrix exponentiation
int fibonacciRecursive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int base[N][N] = {{1, 1}, {1, 0}};
    int result[N][N];

    powerMatrix(base, n - 1, result);
    return result[0][0];
}

// Function to calculate the nth Fibonacci number iteratively
int fibonacciIterative(int n)
{
    int prev = 0;
    int cur = 1;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    for (int i = 2; i < n; i++)
    {
        int temp = prev + cur;

        prev = cur;
        cur = temp;
    }

    return cur;
}

// Function to measure the time taken by a function to calculate the nth Fibonacci number
// This function is using a pointer to a funciton called fibonacciFunc
double measureTime(int (*fibonacciFunc)(int), int n)
{
    clock_t start = clock();
    
    int a=fibonacciFunc(n);
    cout <<a<<'\n'; 
    clock_t end = clock();
    
    // Calculate time in seconds
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    return time_taken;
}

int main(void)
{
    const int maxN = 400000000; // Adjust maxN based on the range you want to test
    double recursive_result[50];
    double iterative_result[50];
    int N_value[50];

    cout << "Recursive Matrix Exponentiation Method\n";
    cout << setw(12) << "N" << setw(12) << "Time\n";
    for (int n = 20000000, i = 0; n <= maxN; n += 20000000, i++)
    {
        double time = measureTime(fibonacciRecursive, n);
        recursive_result[i] = time;
        cout << setw(12) << n << setw(12) << recursive_result[i] << endl;
    }

    cout << "\nIterative Method\n";
    cout << setw(12) << "N" << setw(12) << "Time\n";
    for (int n = 20000000, i = 0; n <= maxN; n += 20000000, i++)
    {
        double time = measureTime(fibonacciIterative, n);
        iterative_result[i] = time;
        cout << setw(12) << n << setw(12) << iterative_result[i] << endl;
        N_value[i] = n;
    }

    myPlot(N_value, iterative_result, recursive_result, 30);

    return 0;
}
