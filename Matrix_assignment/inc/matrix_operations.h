#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <string>

void performOperation(double **matrix1, double **matrix2, double **matrix3, int rows1, int cols1, int rows2, int cols2, std::string operation);
void getMatrixOperation(std::string choice);
void displaymenu();

#endif 
