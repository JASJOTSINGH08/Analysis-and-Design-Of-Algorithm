#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib> 
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int best_case_pt(int arr[], int low, int high) {
    int pivot_index = (low + high) / 2;
    int pivot = arr[pivot_index];
    int i = low;

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[pivot_index]);
    return i;
}

int worst_case_pt(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high, bool best_case, ofstream &outfile) {
    if (low < high) {
        int pivot_index;
        if (best_case) {
            pivot_index = best_case_pt(arr, low, high);
        } else {
            pivot_index = worst_case_pt(arr, low, high);
        }

        // Time measurement for this step
        clock_t start_time = clock(); // Record the start time
        quick_sort(arr, low, pivot_index - 1, best_case, outfile);
        quick_sort(arr, pivot_index + 1, high, best_case, outfile);
        clock_t end_time = clock(); // Record the end time

        double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        outfile << low << "," << high << "," << execution_time << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    const int n = 1000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }

    ofstream outfile("cases_execution_times.csv");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    outfile << "Low,High,ExecutionTime" << endl;

    cout << "Worst case scenario:" << endl;
    quick_sort(arr, 0, n - 1, false, outfile);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Best case scenario:" << endl;
    quick_sort(arr, 0, n - 1, true, outfile);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    outfile.close();

    return 0;
}
