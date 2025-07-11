/*
 *  lab1exe_D.cpp
 *  ENSF 694 Lab 1, exercise D
 *  Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int COL_SIZE = 3;
const int ROW_SIZE = 3;
void try_to_change(double *dest);
void try_to_copy(double dest[], double source[]);
double add_them(double a[5]);

void print_matrix(double matrix[][COL_SIZE], int rows);
/*
 * PROMISES: displays the values in the elements of the 2-D array, matrix,
 * formated in rows columns separated with one or more spaces.
 */

void good_copy(double *dest, double *source, int n);
/* REQUIRES: dest and source points to two array of double numbers with n to n-1 elements
 * PROMISES: copies the values in each element of array source to the corresponding element
 * in array dest.
 */
int main(void)
{
    double sum = 0;
    double x[4];
    double y[] = {2.3, 1.2, 2.2, 4.1};
    double matrix[ROW_SIZE][COL_SIZE] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    cout << " sizeof(double) is " << (int)sizeof(double) << " bytes.\n";
    cout << " size of x in main is: " << (int)sizeof(x) << " bytes.\n";
    cout << " y has " << (int)(sizeof(y) / sizeof(double)) << " elements and its size is: " << (int)sizeof(y) << " bytes.\n";
    cout << " matrix has " << (int)(sizeof(matrix) / sizeof(double)) << " elements and its size is: " << (int)sizeof(matrix) << " bytes.\n";

    try_to_copy(x, y);
    try_to_change(x);

    sum = add_them(&y[1]);
    cout << "\n sum of values in y[1], y[2] and y[3] is: " << sum << endl;

    good_copy(x, y, 4);

    cout << "\nThe values in array x after call to good_copy are expected to be:";
    cout << "\n2.30, -8.25, 2.20, 4.10\n";
    cout << "And the values are:\n";
    for (int i = 0; i < 4; i++)
        cout << fixed << setprecision(2) << x[i] << "  ";

    cout << "\nThe values in matrix are:\n";
    print_matrix(matrix, 3);

    cout << "\nProgram Ends...\n";

    return 0;
}

void try_to_copy(double dest[], double source[])
{
    dest = source;

    /* point one*/

    return;
}

void try_to_change(double *dest)
{
    dest[3] = 49.0;

    /* point two*/
    cout << "\n sizeof(dest) in try_to_change is " << (int)sizeof(dest) << " bytes.\n";
    return;
}

double add_them(double arg[5])
{
    *arg = -8.25;

    /* point three */
    cout << "\n sizeof(arg) in add_them is " << (int)sizeof(arg) << " bytes.\n";
    cout << "\n Incorrect array size computation: add_them says arg has " << (int)(sizeof(arg) / sizeof(double)) << " element.\n";

    return arg[0] + arg[1] + arg[2];
}

void good_copy(double *dest, double *source, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

void print_matrix(double matrix[][COL_SIZE], int rows)
{
    cout << "___________Print Matrix__________\n";
    for (int i = 0; i <rows; i++)
    {
        for (int j = 0;j < COL_SIZE;j++){
           cout << matrix[i][j]<<" ";

        }
         cout << "\n";
    }
}
