#include <iostream>
#include <stack>
#include <fstream>
#include <ctime>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, ofstream& outfile) {
    int pivot = arr[high];
    int i = low - 1;
    clock_t start_time = clock(); // Start time of partitioning

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    
    clock_t end_time = clock(); // End time of partitioning
    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    outfile << low << "," << high << "," << execution_time << endl; // Write time interval to file
    
    return (i + 1);
}

int iterativeQuickSort(int arr[], int low, int high, ofstream& outfile) {
    stack<int> stack;
    int num_calls = 0;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();

        low = stack.top();
        stack.pop();

        int pvt_idx = partition(arr, low, high, outfile);

        if (low < pvt_idx - 1) {
            stack.push(low);
            stack.push(pvt_idx - 1);
            num_calls++;
        }

        if (high > pvt_idx + 1) {
            stack.push(pvt_idx + 1);
            stack.push(high);
            num_calls++;
        }
    }
    return num_calls;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 1000;

    ofstream outfile("iterative_execution_times.csv");
    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    outfile << "Low,High,ExecutionTime" << endl;

    cout << "Given array is \n";
    printArray(arr, n);

    int num_calls = iterativeQuickSort(arr, 0, n - 1, outfile);

    cout << "Sorted array is \n";
    printArray(arr, n);

    cout << "Number of recursive calls: " << num_calls << endl;

    outfile.close();

    return 0;
}
