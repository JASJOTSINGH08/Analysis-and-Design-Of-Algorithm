#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void merge(int arr[], int low_a, int high_a, int low_b, int high_b) {
    int i = low_a;
    int j = low_b;
    int k = 0;
    int merged_size = (high_a - low_a + 1) + (high_b - low_b + 1);
    int merged[merged_size];

    while (i <= high_a && j <= high_b) {
        if (arr[i] <= arr[j]) {
            merged[k++] = arr[i++];
        } else {
            merged[k++] = arr[j++];
        }
    }

    while (i <= high_a) {
        merged[k++] = arr[i++];
    }

    while (j <= high_b) {
        merged[k++] = arr[j++];
    }

    for (int p = 0; p < merged_size; p++) {
        arr[low_a + p] = merged[p];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, mid + 1, high);
    }
}

int main() {
    ofstream outfile("merge_sort_execution_times.csv");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "n,Time,Log(n)" << endl;

    for (int n = 10; n <= 1000; n += 10) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        clock_t start_time = clock();

        mergeSort(arr, 0, n - 1);

        clock_t end_time = clock();

        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        double logn = log2(n);

        // Output information for each value of n
        cout << "n = " << n << ", Execution Time = " << elapsed_time << " seconds, Log(n) = " << logn << endl;

        outfile << n << "," << elapsed_time << "," << logn << endl;
    }

    outfile.close();

    return 0;
}
