#pragma once
#ifndef MATRIX_H
#define MATRIX_H

const int MAX_COL = 4;

double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow);
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow);
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow);
void printMatrix(const double mat[][MAX_COL], const int maxRow);

bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow);
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow);
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow);

double findMaxValue(const double mat[][MAX_COL], const int maxRow);
double findMinValue(const double mat[][MAX_COL], const int maxRow);
void multiplyMatrixByNumber(double mat[][MAX_COL], const int maxRow, const double num);

double* sumOfRows(const double mat[][MAX_COL], const int maxRow);
double* sumOfCols(const double mat[][MAX_COL], const int maxRow);

#endif