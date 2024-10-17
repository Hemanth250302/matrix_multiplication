#include "matrix_operations.h"
#include "matrix_utils.h"
#include "input_validation.h"
#include <iostream>

void performOperation(double **matrix1, double **matrix2, double **matrix3, int rows1, int cols1, int rows2, int cols2, std::string operation)
{

    getElementsofMatrix(matrix1, rows1, cols1);
    printElementsofMatrix(matrix1, rows1, cols1);
    getElementsofMatrix(matrix2, rows2, cols2);
    printElementsofMatrix(matrix2, rows2, cols2);
    if (operation == "addition")
    {
        matrixAddition(matrix1, matrix2, matrix3, rows1, cols1);
        std::cout << "Result of Addition:" << '\n';
        printElementsofMatrix(matrix3, rows1, cols1);
    }
    else if (operation == "multiplication")
    {
        matrixMultiplication(matrix1, matrix2, matrix3, rows1, cols1, rows2, cols2);
        std::cout << "Result of Multiplication:" << '\n';
        printElementsofMatrix(matrix3, rows1, cols2);
    }
}

void getMatrixOperation(std::string choice)
{
    int rows1, rows2, cols1, cols2;
    getMatrixDimentions(rows1, cols1, rows2, cols2);
    std::string operation;

    double **matrix1 = createMatrix(rows1, cols1);

    double **matrix2 = createMatrix(rows2, cols2);

    double **matrix3 = createMatrix(rows1, cols2);

    if (choice[0] == 'a')
    {
        if (rows1 == rows2 && cols1 == cols2)
        {
            operation = "addition";
            performOperation(matrix1, matrix2, matrix3, rows1, cols1, rows2, cols2, operation);
        }
        else
        {
            std::cout << "Matrix dimensions should be equal for addition." << '\n'<< '\n';
        }
    }
    else if (choice[0] == 'm')
    {
        if (cols1 == rows2)
        {
            operation = "multiplication";
            performOperation(matrix1, matrix2, matrix3, rows1, cols1, rows2, cols2, operation);
        }
        else
        {
            std::cout << "Matrix dimensions do not match for multiplication." << '\n' << '\n';
        }
    }
    deleteMatrix(matrix1, rows1);
    deleteMatrix(matrix2, rows2);
    deleteMatrix(matrix3, rows1);
}

void displaymenu()
{
    std::cout << "Select an Operation" << '\n';
    std::cout << "a:addition" << '\n';
    std::cout << "m:multiplication" << '\n';
    std::cout << "Enter your choice" << '\n';
}