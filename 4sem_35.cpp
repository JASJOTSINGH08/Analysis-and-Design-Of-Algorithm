#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int pivot_swap(int n, int arr[], ofstream &outfile) {
    int pivot = arr[0];
    int i = 1;
    int j = n;
    clock_t start_time = clock(); 
    while (i <= j) {
        while (i <= n - 1 && arr[i] < pivot) {
            i++;
        }

        while (j > 0 && arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[0], arr[j]);
    clock_t end_time = clock(); 
    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    outfile << "Pivot Swap," << "," << "," << execution_time << endl; // Write time for pivot swap
    return j;
}

int search(int arr[], int n, int k, ofstream &outfile) {
    int index;
    clock_t start_time, end_time;
    while (true) {
        start_time = clock(); 
        index = pivot_swap(n, arr, outfile);
        end_time = clock(); 
        double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        outfile << "Pivot Swap," << "," << "," << execution_time << endl; // Write time for pivot swap
        if (index == k - 1) {
            return arr[index];
        } else if (index > k - 1) {
            n = index;
        } else {
            arr += index + 1;
            n -= index + 1;
            k -= index + 1;
        }
    }
}

int main() {
    srand(time(0)); 
    const int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }

    ofstream outfile("search_ele_execution_times.csv");
    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    outfile << "Step,Low,High,ExecutionTime" << endl;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    search(arr, n, k, outfile);

    outfile.close();

    return 0;
}
