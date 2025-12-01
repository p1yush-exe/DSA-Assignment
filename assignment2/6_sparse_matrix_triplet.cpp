#include <iostream>
#include <vector>
#include <map>

// 6) Sparse Matrix using triplet (row, col, value)
struct Triplet {
    int row;
    int col;
    int val;
};

using SparseMatrix = std::vector<Triplet>;

void print_sparse(const SparseMatrix& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        std::cout << "(" << m[i].row << ", " << m[i].col << ", " << m[i].val << ")\n";
    }
}

// (a) Transpose of sparse matrix
SparseMatrix transpose_sparse(const SparseMatrix& m) {
    SparseMatrix result;
    for (size_t i = 0; i < m.size(); ++i) {
        result.push_back({m[i].col, m[i].row, m[i].val});
    }
    return result;
}

// (b) Addition of two sparse matrices (same dimensions)
SparseMatrix add_sparse(const SparseMatrix& A, const SparseMatrix& B) {
    SparseMatrix result;
    size_t i = 0, j = 0;

    SparseMatrix a = A;
    SparseMatrix b = B;

    // Assume A and B are sorted by (row, col), otherwise we could sort them first.
    auto cmp = [](const Triplet& x, const Triplet& y) {
        if (x.row != y.row) return x.row < y.row;
        return x.col < y.col;
    };

    std::sort(a.begin(), a.end(), cmp);
    std::sort(b.begin(), b.end(), cmp);

    while (i < a.size() && j < b.size()) {
        if (a[i].row < b[j].row ||
            (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result.push_back(a[i++]);
        } else if (b[j].row < a[i].row ||
                   (b[j].row == a[i].row && b[j].col < a[i].col)) {
            result.push_back(b[j++]);
        } else {
            int sum = a[i].val + b[j].val;
            if (sum != 0) {
                result.push_back({a[i].row, a[i].col, sum});
            }
            ++i;
            ++j;
        }
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

// (c) Multiplication of two sparse matrices
SparseMatrix multiply_sparse(const SparseMatrix& A, const SparseMatrix& B) {
    // We will use a map from (row, col) pair to value
    std::map<std::pair<int, int>, int> result_map;

    // For easier multiplication, group B entries by row index
    // but simplest is double loop over A and B
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B.size(); ++j) {
            if (A[i].col == B[j].row) {
                std::pair<int,int> key = {A[i].row, B[j].col};
                result_map[key] += A[i].val * B[j].val;
            }
        }
    }

    SparseMatrix result;
    for (auto it = result_map.begin(); it != result_map.end(); ++it) {
        if (it->second != 0) {
            result.push_back({it->first.first, it->first.second, it->second});
        }
    }
    return result;
}

int main() {
    // Example sparse matrices in triplet form (row, col, value)
    // Assume they are of compatible dimensions for multiplication
    SparseMatrix A = {
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3},
        {2, 0, 4}
    };

    SparseMatrix B = {
        {0, 1, 5},
        {1, 2, 6},
        {2, 1, 7}
    };

    std::cout << "Matrix A (triplet form):\n";
    print_sparse(A);
    std::cout << "\nMatrix B (triplet form):\n";
    print_sparse(B);

    std::cout << "\n(a) Transpose of A:\n";
    SparseMatrix At = transpose_sparse(A);
    print_sparse(At);

    std::cout << "\n(b) Addition of A and A (A + A):\n";
    SparseMatrix AplusA = add_sparse(A, A);
    print_sparse(AplusA);

    std::cout << "\n(c) Multiplication of A and B (A * B):\n";
    SparseMatrix A_mul_B = multiply_sparse(A, B);
    print_sparse(A_mul_B);

    return 0;
}
