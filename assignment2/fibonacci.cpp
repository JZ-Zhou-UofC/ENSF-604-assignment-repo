/*
 *  fibonacci.cpp
 *  ENSF 694 Lab 2 Exercise D
 * Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
#define N 2
void myPlot(int *x, double *y1, double *y2, int size)
{
    // I use windows. So this may not be working on a mac or linux.
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    if (gnuplotPipe == NULL)
    {
        printf("Error: Could not open pipe to Gnuplot.\n");
        return;
    }

    fprintf(gnuplotPipe, "set title 'Fibonacci Complexity Comparison'\n");
    fprintf(gnuplotPipe, "set xlabel 'N (Input Size)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Execution Time (Seconds)'\n");
    fprintf(gnuplotPipe, "set key outside\n");
    fprintf(gnuplotPipe, "set grid\n");


    fprintf(gnuplotPipe, "set terminal x11\n");


    fprintf(gnuplotPipe, "set yrange [0:0.3]\n");


    fprintf(gnuplotPipe, "set xtics rotate by -45\n");

    fprintf(gnuplotPipe, "plot '-' using 1:2 with points pt 7 ps 1.5 lc rgb 'blue' title 'Iterative Method', '-' using 1:2 with points pt 7 ps 1.5 lc rgb 'red' title 'Matrix Exponentiation Method'\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(gnuplotPipe, "%d %f\n", x[i], y1[i]);
    }
    fprintf(gnuplotPipe, "e\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(gnuplotPipe, "%d %f\n", x[i], y2[i]);
    }
    fprintf(gnuplotPipe, "e\n");

    fclose(gnuplotPipe);
}

void myPlot_for_recursive_method(int *x, double *y1, int size)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    if (gnuplotPipe == NULL)
    {
        printf("Error: Could not open pipe to Gnuplot.\n");
        return;
    }

    fprintf(gnuplotPipe, "set title 'Fibonacci Recursive Method'\n");
    fprintf(gnuplotPipe, "set xlabel 'N (Input Size)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Execution Time (Seconds)'\n");
    fprintf(gnuplotPipe, "set key outside\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set terminal x11\n");
    fprintf(gnuplotPipe, "set yrange [0:0.00001]\n");
    fprintf(gnuplotPipe, "set xtics rotate by -45\n");

    // Only one dataset plotted
    fprintf(gnuplotPipe, "plot '-' using 1:2 with points pt 7 ps 1.5 lc rgb 'red' title 'Recursive Method'\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(gnuplotPipe, "%d %f\n", x[i], y1[i]);
    }
    fprintf(gnuplotPipe, "e\n");

    fclose(gnuplotPipe);
}

// Function to multiply two matrices of size N x N
void multiplyMatrices(int A[N][N], int B[N][N], int result[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
// Recursive funciont
void powerMatrix(int base[N][N], int exp, int result[N][N])
{

    if (exp == 0)
    {
        result[0][0] = 1;
        result[0][1] = 0;
        result[1][0] = 0;
        result[1][1] = 1;
        return;
    }

    int temp[N][N];

    powerMatrix(base, exp / 2, temp);

    multiplyMatrices(temp, temp, result);

    if (exp % 2 == 1)
    {
        multiplyMatrices(result, base, temp);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
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
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    fibonacciFunc(n);

    auto end = high_resolution_clock::now();
    duration<double> time_taken = end - start;

    return time_taken.count(); // returns time in seconds
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
    myPlot_for_recursive_method(N_value, recursive_result, 30 );
    return 0;
}
