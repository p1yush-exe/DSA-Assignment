#include <iostream>

using namespace std;

int main() {
    int r, c;
    cout << "--- Find Sum of Rows and Columns ---" << endl;
    cout << "Enter the number of rows for the matrix: ";
    cin >> r;
    cout << "Enter the number of columns for the matrix: ";
    cin >> c;

    if (r <= 0 || c <= 0) {
        cout << "Error: Rows and columns must be positive numbers." << endl;
        return 1;
    }

    int** mat = new int*[r];
    for(int i = 0; i < r; ++i) {
        mat[i] = new int[c];
    }

    cout << "\nEnter the elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter element for position [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }
    }

    cout << "\n--- Calculating Sums ---" << endl;

    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += mat[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nSum of each column:" << endl;
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += mat[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    for(int i = 0; i < r; ++i) {
        delete [] mat[i];
    }
    delete [] mat;

    return 0;
}
