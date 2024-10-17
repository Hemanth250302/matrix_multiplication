#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

void getElementsofMatrix(double **matrix, int rows, int cols);
void printElementsofMatrix(double **matrix, int rows, int cols);
void matrixAddition(double **matrix1, double **matrix2, double **matrix3, int rows, int cols);
void matrixMultiplication(double **matrix1, double **matrix2, double **matrix3, int rows1, int cols1, int rows2, int cols2);
void getMatrixDimentions(int &rows1, int &cols1, int &rows2, int &cols2);
double **createMatrix(int rows, int cols);
void deleteMatrix(double **matrix, int rows);

#endif
