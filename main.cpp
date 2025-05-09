#include <iostream>
using namespace std;

void addMatrices(int rows, int cols, int mat1[][10], int mat2[][10]) {
    int result[10][10];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];

    cout << "\nMatrix Addition Result:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << result[i][j] << "\t";
        cout << endl;
    }
}

void subtractMatrices(int rows, int cols, int mat1[][10], int mat2[][10]) {
    int result[10][10];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];

    cout << "\nMatrix Subtraction Result:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << result[i][j] << "\t";
        cout << endl;
    }
}

void multiplyMatrices(int rows1, int cols1, int mat1[][10], int rows2, int cols2, int mat2[][10]) {
    if (cols1 != rows2) {
        cout << "Error: Cannot multiply matrices. Columns of first must equal rows of second.\n";
        return;
    }

    int result[10][10] = {0};
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols2; j++)
            for (int k = 0; k < cols1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];

    cout << "\nMatrix Multiplication Result:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++)
            cout << result[i][j] << "\t";
        cout << endl;
    }
}

void transposeMatrix(int rows, int cols, int mat[][10]) {
    cout << "\nMatrix Transpose Result:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << mat[j][i] << "\t";
        cout << endl;
    }
}

void readMatrix(int rows, int cols, int mat[][10], const string& name) {
    cout << "Enter elements of " << name << " matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        cout << "  Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\n========== MATRIX CALCULATOR ==========\n";
        cout << "1. Add Two Matrices\n";
        cout << "2. Subtract Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Transpose a Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            int rows1, cols1, rows2, cols2;
            int mat1[10][10], mat2[10][10];

            cout << "\nEnter number of rows for the first matrix: ";
cin >> rows1;
cout << "Enter number of columns for the first matrix: ";
cin >> cols1;


            readMatrix(rows1, cols1, mat1, "first");

            if (choice == 1 || choice == 2 || choice == 3) {
   cout << "\nEnter number of rows for the second matrix: ";
cin >> rows2;
cout << "Enter number of columns for the second matrix: ";
cin >> cols2;


                readMatrix(rows2, cols2, mat2, "second");

                if (choice == 1 || choice == 2) {
                    if (rows1 != rows2 || cols1 != cols2) {
                        cout << "Error: Matrices must have the same dimensions for addition/subtraction.\n";
                        continue;
                    }
                }

                if (choice == 1)
                    addMatrices(rows1, cols1, mat1, mat2);
                else if (choice == 2)
                    subtractMatrices(rows1, cols1, mat1, mat2);
                else
                    multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2);
            } else if (choice == 4) {
                transposeMatrix(rows1, cols1, mat1);
            }
        } else if (choice != 5) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    cout << "Thank you for using the Matrix Calculator. Goodbye!\n";
    return 0;
}
