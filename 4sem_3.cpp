#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

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

    ofstream outfile("execution_times.csv2");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Size,ExecutionTime" << endl;

    for (int size = 100; size <= 500; size += 100) {
        int* arr = new int[size * size];

        for (int i = 0; i < size * size; ++i) {
            arr[i] = rand() % 1000; 
        }

        clock_t startTime = clock();
        selectionSort(arr, size * size);
        clock_t endTime = clock();

        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Size: " << size * size << ", Execution Time: " << executionTime << " seconds" << std::endl;

        outfile << size * size << "," << executionTime << endl;

        delete[] arr;
    }

    outfile.close();

    return 0;
}
