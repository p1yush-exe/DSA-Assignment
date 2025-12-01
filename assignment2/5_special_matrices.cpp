#include <iostream>
#include <vector>

// 5) Space-efficient storage for special matrices
// Using 1-based indices in set/get for clarity

// (a) Diagonal Matrix
class DiagonalMatrix {
private:
    int n;
    std::vector<int> A;
public:
    DiagonalMatrix(int size) : n(size), A(size, 0) {}

    void set(int i, int j, int x) {
        if (i == j && i >= 1 && i <= n) {
            A[i - 1] = x;
        }
    }

    int get(int i, int j) const {
        if (i == j && i >= 1 && i <= n) {
            return A[i - 1];
        }
        return 0;
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

// (b) Tri-diagonal Matrix
class TriDiagonalMatrix {
private:
    int n;
    std::vector<int> A; // size = 3n - 2
public:
    TriDiagonalMatrix(int size) : n(size), A(3 * size - 2, 0) {}

    void set(int i, int j, int x) {
        if (i - j == 1 && i >= 2 && i <= n) {
            // below main diag: index 0..(n-2)
            A[i - 2] = x;
        } else if (i == j && i >= 1 && i <= n) {
            // main diag: index (n-1)..(2n-2)
            A[n - 1 + (i - 1)] = x;
        } else if (j - i == 1 && i >= 1 && i <= n - 1) {
            // above main diag: index (2n-1)..(3n-3)
            A[2 * n - 1 + (i - 1)] = x;
        }
    }

    int get(int i, int j) const {
        if (i - j == 1 && i >= 2 && i <= n) {
            return A[i - 2];
        } else if (i == j && i >= 1 && i <= n) {
            return A[n - 1 + (i - 1)];
        } else if (j - i == 1 && i >= 1 && i <= n - 1) {
            return A[2 * n - 1 + (i - 1)];
        }
        return 0;
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

// (c) Lower Triangular Matrix (row-major)
class LowerTriangularMatrix {
private:
    int n;
    std::vector<int> A; // size = n(n+1)/2
public:
    LowerTriangularMatrix(int size) : n(size) {
        A.resize(n * (n + 1) / 2, 0);
    }

    void set(int i, int j, int x) {
        if (i >= j && i >= 1 && i <= n && j >= 1 && j <= n) {
            int index = i * (i - 1) / 2 + (j - 1);
            A[index] = x;
        }
    }

    int get(int i, int j) const {
        if (i >= j && i >= 1 && i <= n && j >= 1 && j <= n) {
            int index = i * (i - 1) / 2 + (j - 1);
            return A[index];
        }
        return 0;
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

// (d) Upper Triangular Matrix (row-major)
class UpperTriangularMatrix {
private:
    int n;
    std::vector<int> A; // size = n(n+1)/2
public:
    UpperTriangularMatrix(int size) : n(size), A(size * (size + 1) / 2, 0) {}

    void set(int i, int j, int x) {
        if (i <= j && i >= 1 && i <= n && j >= 1 && j <= n) {
            int index = n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i);
            A[index] = x;
        }
    }

    int get(int i, int j) const {
        if (i <= j && i >= 1 && i <= n && j >= 1 && j <= n) {
            int index = n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i);
            return A[index];
        }
        return 0;
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

// (e) Symmetric Matrix (we store only lower triangular part)
class SymmetricMatrix {
private:
    int n;
    std::vector<int> A; // size = n(n+1)/2, store lower triangular part
public:
    SymmetricMatrix(int size) : n(size) {
        A.resize(n * (n + 1) / 2, 0);
    }

    void set(int i, int j, int x) {
        if (i < 1 || i > n || j < 1 || j > n) return;
        if (i < j) std::swap(i, j); // make sure i >= j (lower triangular)
        int index = i * (i - 1) / 2 + (j - 1);
        A[index] = x;
    }

    int get(int i, int j) const {
        if (i < 1 || i > n || j < 1 || j > n) return 0;
        if (i < j) std::swap(i, j);
        int index = i * (i - 1) / 2 + (j - 1);
        return A[index];
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int n = 4;

    std::cout << "Diagonal Matrix:\n";
    DiagonalMatrix dm(n);
    for (int i = 1; i <= n; ++i) {
        dm.set(i, i, i); // set diagonal elements
    }
    dm.display();

    std::cout << "\nTri-diagonal Matrix:\n";
    TriDiagonalMatrix tdm(n);
    // simple example values
    for (int i = 1; i <= n; ++i) {
        tdm.set(i, i, 5); // main diagonal
        if (i < n) {
            tdm.set(i, i + 1, 1); // upper
            tdm.set(i + 1, i, 2); // lower
        }
    }
    tdm.display();

    std::cout << "\nLower Triangular Matrix:\n";
    LowerTriangularMatrix ltm(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            ltm.set(i, j, i + j);
        }
    }
    ltm.display();

    std::cout << "\nUpper Triangular Matrix:\n";
    UpperTriangularMatrix utm(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            utm.set(i, j, i + j);
        }
    }
    utm.display();

    std::cout << "\nSymmetric Matrix:\n";
    SymmetricMatrix sm(n);
    // Fill only some entries; symmetry is handled automatically
    sm.set(1, 1, 1);
    sm.set(2, 1, 2);
    sm.set(2, 2, 3);
    sm.set(3, 1, 4);
    sm.set(4, 3, 5);
    sm.display();

    return 0;
}
