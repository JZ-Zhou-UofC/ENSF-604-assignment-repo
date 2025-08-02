

/*
 *  matrix.cpp
 * ENSF 694 - Lab 4 Exercise D
 *  Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */
#include "matrix.h"

Matrix::Matrix(int r, int c) : rowsM(r), colsM(c)
{
    matrixM = new double *[rowsM];
    assert(matrixM != NULL);

    for (int i = 0; i < rowsM; i++)
    {
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);

    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}

Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix &source)
{
    copy(source);
}

Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (&rhs != this)
    {
        destroy();
        copy(rhs);
    }

    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}

void Matrix::sum_of_rows() const
{

    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    // cout << "\nSorry I don't know how to calculate sum of rowsM in a matrix. ";
        for (int i = 0; i < rowsM; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < colsM; j++)
        {
            sum += matrixM[i][j];
        }
        sum_rowsM[i] = sum;
    }
}

void Matrix::sum_of_cols() const
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    // cout << "\nSorry I don't know how to calculate sum of columns in a matrix. ";
        for (int j = 0; j < colsM; j++)
    {
        double sum = 0.0;
        for (int i = 0; i < rowsM; i++)
        {
            sum += matrixM[i][j];
        }
        sum_colsM[j] = sum;
    }
}

void Matrix::copy(const Matrix &source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if (source.matrixM == NULL)
    {
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    rowsM = source.rowsM;
    colsM = source.colsM;
    matrixM = new double*[rowsM];
    assert(matrixM != NULL);
    for (int i = 0; i < rowsM; i++)
    {
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
        for (int i = 0; i < rowsM; i++)
    {
        for (int j = 0; j < colsM; j++)
        {
            matrixM[i][j] = source.matrixM[i][j];
        }
    }


    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);

    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);




    for (int i = 0; i < rowsM; i++)
    {
        sum_rowsM[i] = source.sum_rowsM[i];
    }

    for (int j = 0; j < colsM; j++)
    {
        sum_colsM[j] = source.sum_colsM[j];
    }
    // STUDENTS MUST COMMENT OUT THE FOLLOWING LINE AND FIX THE FUNCTION'S PROBLEM
    // cout << "\nSorry copy fucntion is defective. ";
}

void Matrix::destroy()
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    for (int i = 0; i < rowsM; i++)
    {
        delete[] matrixM[i];
    }
    delete[] matrixM;
    delete[] sum_rowsM;
    delete[] sum_colsM;

    // cout << "\nProgram ended without destroying matrices.\n";
}
