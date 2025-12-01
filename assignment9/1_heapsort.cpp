#include <iostream>
using namespace std;

void swapInt(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swapInt(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

void heapSortAscending(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swapInt(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }
    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int order;
    cout << "Enter 1 for increasing order, 2 for decreasing order: ";
    cin >> order;
    heapSortAscending(arr, n);
    if (order == 1) {
        cout << "Sorted (increasing): ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    } else if (order == 2) {
        cout << "Sorted (decreasing): ";
        for (int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n";
    } else {
        cout << "Invalid order option\n";
    }
    delete[] arr;
    return 0;
}
