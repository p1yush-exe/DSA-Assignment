#include <iostream>
using namespace std;

#define CAP 100

int heapArr[CAP];
int heapSize = 0;

void swapInt(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void heapifyDown(int i) {
    int largest = i;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        largest = i;
        if (l < heapSize && heapArr[l] > heapArr[largest]) largest = l;
        if (r < heapSize && heapArr[r] > heapArr[largest]) largest = r;
        if (largest != i) {
            swapInt(heapArr[i], heapArr[largest]);
            i = largest;
        } else break;
    }
}

void heapifyUp(int i) {
    while (i != 0) {
        int p = (i - 1) / 2;
        if (heapArr[p] < heapArr[i]) {
            swapInt(heapArr[p], heapArr[i]);
            i = p;
        } else break;
    }
}

void insertKey(int key) {
    if (heapSize == CAP) {
        cout << "Priority queue overflow\n";
        return;
    }
    heapArr[heapSize] = key;
    heapifyUp(heapSize);
    heapSize++;
}

int getMax() {
    if (heapSize <= 0) {
        cout << "Priority queue is empty\n";
        return -1;
    }
    return heapArr[0];
}

int extractMax() {
    if (heapSize <= 0) {
        cout << "Priority queue is empty\n";
        return -1;
    }
    int root = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return root;
}

bool isEmptyPQ() {
    return heapSize == 0;
}

void displayPQ() {
    if (heapSize == 0) {
        cout << "Priority queue is empty\n";
        return;
    }
    cout << "Heap array (priority queue): ";
    for (int i = 0; i < heapSize; i++) cout << heapArr[i] << " ";
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\nPriority Queue using Max-Heap\n";
        cout << "1. Insert key\n";
        cout << "2. Get maximum\n";
        cout << "3. Extract maximum\n";
        cout << "4. Check if empty\n";
        cout << "5. Display heap array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int val;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> val;
                insertKey(val);
                break;
            case 2:
                val = getMax();
                if (!isEmptyPQ()) cout << "Maximum: " << val << "\n";
                break;
            case 3:
                val = extractMax();
                if (!isEmptyPQ() || val != -1) cout << "Extracted: " << val << "\n";
                break;
            case 4:
                if (isEmptyPQ()) cout << "Priority queue is empty\n";
                else cout << "Priority queue is not empty\n";
                break;
            case 5:
                displayPQ();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
