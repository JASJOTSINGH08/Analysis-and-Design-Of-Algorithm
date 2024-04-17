#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at position (k, i)
bool isSafe(const vector<int>& x, int k, int i) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
            return false;
    }
    return true;
}

// Function to print the positions of queens on the board
void printQueens(const vector<int>& x) {
    for (int i : x) {
        cout << i << "\t";
    }
    cout << endl;
}

// Function to find all possible solutions for placing n queens on an n x n chessboard
void nQueens(vector<int>& x, int n, int k = 0) {
    for (int i = 0; i < n; i++) {
        if (isSafe(x, k, i)) {
            x[k] = i;
            if (k == n - 1)
                printQueens(x);
            else
                nQueens(x, n, k + 1);
        }
    }
}

int main() {
    cout << "Enter the number of queens to be placed: ";
    int n;
    cin >> n;

    vector<int> x(n, 0); // Initialize vector to store positions of queens
    cout << "Possible arrangements for placing " << n << " queens on the chessboard:\n";
    nQueens(x, n);

    return 0;
}
