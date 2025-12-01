#include <iostream>
#include <vector>
#include <algorithm>

// 8) Count total number of distinct elements in an array
int count_distinct(std::vector<int> arr) {
    if (arr.empty()) return 0;

    std::sort(arr.begin(), arr.end());
    int count = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1]) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive.\n";
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int distinct = count_distinct(arr);
    std::cout << "Total number of distinct elements: " << distinct << "\n";

    return 0;
}
