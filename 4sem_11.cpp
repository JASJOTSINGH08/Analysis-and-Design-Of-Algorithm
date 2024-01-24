#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));

    ofstream outfile("execution_times.csv6");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Size,ExecutionTime" << endl;

    for (int n = 1; n <= 10; ++n) {
        int size = pow(2, n);
        int* arr = new int[size];

        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 1000; 
        }

        clock_t startTime = clock();
        selectionSort(arr, size);
        clock_t endTime = clock();

        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Size: " << size << ", Execution Time: " << executionTime << " seconds" << std::endl;

        outfile << size << "," << executionTime << endl;

        delete[] arr;
    }

    outfile.close();

    return 0;
}
