#include <iostream>
#include <vector>

// 7) Count inversions in an array (i < j but A[i] > A[j])
int count_inversions(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int inv_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++inv_count;
            }
        }
    }
    return inv_count;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int inversions = count_inversions(arr);
    std::cout << "Number of inversions in the array: " << inversions << "\n";

    return 0;
}
