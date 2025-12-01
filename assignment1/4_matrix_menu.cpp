#include <iostream>

using namespace std;

void swapInts(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapInts(&arr[min_idx], &arr[i]);
        }
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    return j;
}

void handleRemoveDuplicates() {
    int size;
    cout << "--- Remove Duplicates from an Array ---" << endl;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be positive." << endl;
        return;
    }

    int* arr = new int[size];
    cout << "Please enter " << size << " elements." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter element number " << i + 1 << ": ";
        cin >> arr[i];
    }

    selectionSort(arr, size);
    int new_size = removeDuplicates(arr, size);

    cout << "\nArray after removing duplicates: ";
    for (int i = 0; i < new_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
}

void reverseArray() {
    int size;

    cout << "--- Reverse the Elements of an Array ---" << endl;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be positive." << endl;
        return;
    }

    int* arr = new int[size];
    cout << "Please enter " << size << " elements." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter element number " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < size / 2; i++) {
        swapInts(&arr[i], &arr[size - 1 - i]);
    }

    cout << "\nReversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
}

void matrixMultiplication() {
    int r1, c1, r2, c2;
    cout << "--- Matrix Multiplication ---" << endl;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Error! Column of first matrix not equal to row of second." << endl;
        return;
    }

    int** mat1 = new int*[r1];
    for(int i = 0; i < r1; ++i) mat1[i] = new int[c1];

    int** mat2 = new int*[r2];
    for(int i = 0; i < r2; ++i) mat2[i] = new int[c2];

    int** result = new int*[r1];
    for(int i = 0; i < r1; ++i) result[i] = new int[c2];

    cout << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) {
            cout << "Enter element mat1[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }

    cout << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) {
            cout << "Enter element mat2[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "\nOutput Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < r1; ++i) delete [] mat1[i];
    delete [] mat1;
    for(int i = 0; i < r2; ++i) delete [] mat2[i];
    delete [] mat2;
    for(int i = 0; i < r1; ++i) delete [] result[i];
    delete [] result;
}

void transposeMatrix() {
    int r, c;
    cout << "--- Find the Transpose of a Matrix ---" << endl;
    cout << "Enter rows and columns for the matrix: ";
    cin >> r >> c;

    int** mat = new int*[r];
    for(int i = 0; i < r; ++i) mat[i] = new int[c];

    int** transpose = new int*[c];
    for(int i = 0; i < c; ++i) transpose[i] = new int[r];

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cout << "Enter element mat[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            transpose[j][i] = mat[i][j];
        }

    cout << "\nTranspose of the Matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < r; ++i) delete [] mat[i];
    delete [] mat;
    for(int i = 0; i < c; ++i) delete [] transpose[i];
    delete [] transpose;
}

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Remove duplicates from an array" << endl;
        cout << "2. Reverse the elements of an array" << endl;
        cout << "3. Find the matrix multiplication" << endl;
        cout << "4. Find the Transpose of a Matrix" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            handleRemoveDuplicates();
            break;
        case 2:
            reverseArray();
            break;
        case 3:
            matrixMultiplication();
            break;
        case 4:
            transposeMatrix();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
