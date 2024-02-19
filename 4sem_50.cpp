#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1); 
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1)
            return arr[pivotIndex];

        if (pivotIndex - low > k - 1)
            return kthSmallest(arr, low, pivotIndex - 1, k);

        return kthSmallest(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }

    return -1;
}

void generateRandomArray(int arr[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 1000; 
}

void drawComplexityGraph(int max_size) {
    ofstream outputFile("output.csv"); 

    if (!outputFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    outputFile << "Array Size,Time (ms)\n";
    for (int size = 50; size <= max_size; size += 50) { 
        int* arr = new int[size];
        generateRandomArray(arr, size);

        clock_t start = clock();
        for (int i = 0; i < size * 10000; ++i) {
            int temp = i * i;
        }
        clock_t end = clock();

        double duration = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        outputFile << size << "," << duration << endl;
        delete[] arr;
    }

    outputFile.close(); 
}

int main() {
    int max_size = 1234; 
    drawComplexityGraph(max_size);

    cout << "Data written to output.csv" << endl;

    return 0;
}
