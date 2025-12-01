#include <iostream>
#include <vector>

// 3) Missing number in a sorted array 1..n with exactly one missing

// (a) Linear time using sum formula
int find_missing_linear(const std::vector<int>& arr, int n) {
    long long total_sum = 1LL * n * (n + 1) / 2;
    long long array_sum = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        array_sum += arr[i];
    }
    return static_cast<int>(total_sum - array_sum);
}

// (b) Using binary search (array is sorted, values from 1..n with one missing)
int find_missing_binary_search(const std::vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // In a perfect array without missing, arr[mid] should be mid+1
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // The missing number is left+1
    return left + 1;
}

int main() {
    // Example: numbers from 1..8, missing 5
    std::vector<int> arr = {1, 2, 3, 4, 6, 7, 8};
    int n = 8;

    std::cout << "Array elements (sorted, 1..n with one missing): ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "(a) Linear method: Missing number = "
              << find_missing_linear(arr, n) << "\n";

    std::cout << "(b) Binary search: Missing number = "
              << find_missing_binary_search(arr) << "\n";

    return 0;
}
