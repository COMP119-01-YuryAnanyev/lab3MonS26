/** \file lab3MonS26.cpp
* \brief Matrix library test program.
* \details This program uses a small matrix library and gives the user a menu.
* \author Yury Ananyev
* \version 0.1
* \date 2026
* \copyright University of Nicosia.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

using namespace std;

int main() {
    const int MAX_ROW = 3;

    double mat[MAX_ROW][MAX_COL] = {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    int choice = -1;
    int row;
    int col;
    double num;

    srand(static_cast<unsigned int>(time(NULL)));

    while (choice != 0) {
        cout << "\n\n0) Quit";
        cout << "\n1) Print matrix";
        cout << "\n2) Fill with random numbers";
        cout << "\n3) Sum of row";
        cout << "\n4) Sum of column";
        cout << "\n5) Check identity matrix";
        cout << "\n6) Make identity matrix";
        cout << "\n7) Sum of diagonal";
        cout << "\n8) Find max value";
        cout << "\n9) Find min value";
        cout << "\n10) Multiply matrix by number";
        cout << "\n11) Sum of all rows";
        cout << "\n12) Sum of all columns";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 0) {
        }
        else if (choice == 1) {
            printMatrix(mat, MAX_ROW);
        }
        else if (choice == 2) {
            fillWithRandomNum(mat, MAX_ROW);
            cout << "\nMatrix filled with random numbers.";
        }
        else if (choice == 3) {
            cout << "\nEnter row number 0 - " << MAX_ROW - 1 << ": ";
            cin >> row;

            cout << "\nSum of row: " << sumOfRow(mat, row, MAX_ROW);
        }
        else if (choice == 4) {
            cout << "\nEnter column number 0 - " << MAX_COL - 1 << ": ";
            cin >> col;

            cout << "\nSum of column: " << sumOfCol(mat, col, MAX_ROW);
        }
        else if (choice == 5) {
            if (isIdentityMatrix(mat, MAX_ROW)) {
                cout << "\nMatrix is identity.";
            }
            else {
                cout << "\nMatrix is not identity.";
            }
        }
        else if (choice == 6) {
            if (makeIdentityMatrix(mat, MAX_ROW)) {
                cout << "\nMatrix changed to identity.";
            }
            else {
                cout << "\nMatrix cannot be identity because it is not square.";
            }
        }
        else if (choice == 7) {
            cout << "\nSum of diagonal: " << sumOfDiagonal(mat, MAX_ROW);
        }
        else if (choice == 8) {
            cout << "\nMax value: " << findMaxValue(mat, MAX_ROW);
        }
        else if (choice == 9) {
            cout << "\nMin value: " << findMinValue(mat, MAX_ROW);
        }
        else if (choice == 10) {
            cout << "\nEnter number: ";
            cin >> num;

            multiplyMatrixByNumber(mat, MAX_ROW, num);
            cout << "\nMatrix multiplied.";
        }
        else if (choice == 11) {
            double* rows = sumOfRows(mat, MAX_ROW);

            for (int i = 0; i < MAX_ROW; i++) {
                cout << "\nRow " << i << " sum = " << rows[i];
            }

            delete[] rows;
        }
        else if (choice == 12) {
            double* cols = sumOfCols(mat, MAX_ROW);

            for (int i = 0; i < MAX_COL; i++) {
                cout << "\nColumn " << i << " sum = " << cols[i];
            }

            delete[] cols;
        }
        else {
            cerr << "\nWrong choice!";
        }
    }

    cout << "\nHave a nice day!\n";

    return 0;
}