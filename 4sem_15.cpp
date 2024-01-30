#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void permu_data(vector<int> &arr, int start, int n) {
    if (start == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i < n; i++) {
            swap(arr[start], arr[i]);
            permu_data(arr, start + 1, n);
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    ofstream outfile("execution_times.csv8");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Size,ExecutionTime" << endl;

    for (int n = 1; n <= 6; n++) {
        vector<int> elements(n);
        for (int i = 0; i < n; i++) {
            elements[i] = i + 1;
        }

        clock_t startTime = clock();
        permu_data(elements, 0, n);
        clock_t endTime = clock();

        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Size: " << n << ", Execution Time: " << executionTime << " seconds" << std::endl;

        outfile << n << "," << executionTime << endl;
    }

    outfile.close();

    return 0;
}
