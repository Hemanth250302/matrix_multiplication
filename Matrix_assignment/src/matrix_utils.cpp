#include "matrix_utils.h"
#include "input_validation.h"
#include "constants.h"
#include <iostream>

void getElementsofMatrix(double **matrix, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "matrix" << i << j << ":";
            matrix[i][j] = getInput("float");
        }
    }
}

void printElementsofMatrix(double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void matrixAddition(double **matrix1, double **matrix2, double **matrix3, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix3 + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
        }
    }
}

void matrixMultiplication(double **matrix1, double **matrix2, double **matrix3, int rows1, int cols1, int rows2, int cols2)
{
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < cols1; ++k)
            {
                *(*(matrix3 + i) + j) += (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j));
            }
        }
    }
}

void getMatrixDimentions(int &rows1, int &cols1, int &rows2, int &cols2)
{
    std::cout << "Enter the no of rows for matrix1:";
    rows1 = getInput("int");
    std::cout << "Enter the no of cols for matrix1:" << '\n';
    cols1 = getInput("int");
    std::cout << "Enter the no of rows for matrix2:" << '\n';
    rows2 = getInput("int");
    std::cout << "Enter the no of cols for matrix2:" << '\n';
    cols2 = getInput("int");
}

double **createMatrix(int rows, int cols)
{
    double **matrix = new double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[cols]{0};
    }
    return matrix;
}

void deleteMatrix(double **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}