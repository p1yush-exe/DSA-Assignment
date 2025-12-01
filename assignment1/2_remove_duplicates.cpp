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

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    int* arr = new int[size];

    cout << "Please enter " << size << " elements." << endl;
    for(int i = 0; i < size; i++) {
        cout << "Enter element number " << i + 1 << ": ";
        cin >> arr[i];
    }

    selectionSort(arr, size);

    int new_size = removeDuplicates(arr, size);

    cout << "\nArray after removing duplicates: ";
    for(int i = 0; i < new_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
