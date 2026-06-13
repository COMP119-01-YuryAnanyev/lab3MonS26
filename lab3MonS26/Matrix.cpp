#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow) {
    assert(maxRow > 0);
    assert(row >= 0 && row < maxRow);

    double sum = 0;

    for (int col = 0; col < MAX_COL; col++) {
        sum += mat[row][col];
    }

    return sum;
}

double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow) {
    assert(maxRow > 0);
    assert(column >= 0 && column < MAX_COL);

    double sum = 0;

    for (int row = 0; row < maxRow; row++) {
        sum += mat[row][column];
    }

    return sum;
}

void fillWithRandomNum(double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            mat[row][col] = rand() % 10;
        }
    }
}

void printMatrix(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    cout << "\nMatrix:\n";

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            cout << mat[row][col] << "\t";
        }

        cout << "\n";
    }
}

bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    if (maxRow != MAX_COL) {
        return false;
    }

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            if (row == col && mat[row][col] != 1) {
                return false;
            }

            if (row != col && mat[row][col] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    if (maxRow != MAX_COL) {
        return false;
    }

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            if (row == col) {
                mat[row][col] = 1;
            }
            else {
                mat[row][col] = 0;
            }
        }
    }

    return true;
}

double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    int limit = maxRow;

    if (MAX_COL < limit) {
        limit = MAX_COL;
    }

    double sum = 0;

    for (int i = 0; i < limit; i++) {
        sum += mat[i][i];
    }

    return sum;
}

double findMaxValue(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double maxValue = mat[0][0];

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            if (mat[row][col] > maxValue) {
                maxValue = mat[row][col];
            }
        }
    }

    return maxValue;
}

double findMinValue(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double minValue = mat[0][0];

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            if (mat[row][col] < minValue) {
                minValue = mat[row][col];
            }
        }
    }

    return minValue;
}

void multiplyMatrixByNumber(double mat[][MAX_COL], const int maxRow, const double num) {
    assert(maxRow > 0);

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            mat[row][col] *= num;
        }
    }
}

double* sumOfRows(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double* rows = new double[maxRow];

    for (int row = 0; row < maxRow; row++) {
        rows[row] = sumOfRow(mat, row, maxRow);
    }

    return rows;
}

double* sumOfCols(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double* cols = new double[MAX_COL];

    for (int col = 0; col < MAX_COL; col++) {
        cols[col] = sumOfCol(mat, col, maxRow);
    }

    return cols;
}