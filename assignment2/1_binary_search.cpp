#include <iostream>
#include <vector>

// 1) Binary Search on a sorted array (iterative)
int binary_search(const std::vector<int>& arr, int x) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; // found
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // not found
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int x;

    std::cout << "Binary Search Demo (Array is: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 == arr.size() ? "" : " ");
    }
    std::cout << ")\n";

    std::cout << "Enter element to search: ";
    std::cin >> x;

    int idx = binary_search(arr, x);
    if (idx != -1) {
        std::cout << "Element " << x << " found at index " << idx << ".\n";
    } else {
        std::cout << "Element " << x << " not found in the array.\n";
    }

    return 0;
}
