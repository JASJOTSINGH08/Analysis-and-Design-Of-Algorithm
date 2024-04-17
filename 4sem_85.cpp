#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Function to subtract two matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassenMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrices are 1x1
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide matrices into submatrices
    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Recursive steps
    vector<vector<int>> M1 = strassenMatrixMultiplication(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> M2 = strassenMatrixMultiplication(matrixAddition(A21, A22), B11);
    vector<vector<int>> M3 = strassenMatrixMultiplication(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> M4 = strassenMatrixMultiplication(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> M5 = strassenMatrixMultiplication(matrixAddition(A11, A12), B22);
    vector<vector<int>> M6 = strassenMatrixMultiplication(matrixSubtraction(A21, A11), matrixAddition(B11, B12));
    vector<vector<int>> M7 = strassenMatrixMultiplication(matrixSubtraction(A12, A22), matrixAddition(B21, B22));

    // Calculate result matrices
    vector<vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(M1, M4), M5), M7);
    vector<vector<int>> C12 = matrixAddition(M3, M5);
    vector<vector<int>> C21 = matrixAddition(M2, M4);
    vector<vector<int>> C22 = matrixAddition(matrixSubtraction(matrixAddition(M1, M3), M2), M6);

    // Merge submatrices into result matrix
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Utility function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;

    vector<vector<int>> C = strassenMatrixMultiplication(A, B);

    cout << "Matrix C (Result of Strassen's Matrix Multiplication):" << endl;
    printMatrix(C);

    return 0;
}
