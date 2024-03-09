#include <iostream>
#include <fstream>
#include <climits>
#include <chrono> 
using namespace std;
using namespace std::chrono; 

void min_max_fnc(int arr[], int low, int high, int& min_val, int& max_val) {
    if (low == high) {
        min_val = max_val = arr[low];
    } else if (high == low + 1) {
        min_val = min(arr[low], arr[high]);
        max_val = max(arr[low], arr[high]);
    } else {
        int mid = (low + high) / 2;

        int left_min, left_max, right_min, right_max;
        min_max_fnc(arr, low, mid, left_min, left_max);
        min_max_fnc(arr, mid + 1, high, right_min, right_max);

        min_val = min(left_min, right_min);
        max_val = max(left_max, right_max);
    }
}

int main() {
    const int size = 1000;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; 
    }

      int min_val, max_val;
    min_max_fnc(arr, 0, size - 1, min_val, max_val);

    cout << "Maximum element: " << max_val << endl;
    cout << "Minimum element: " << min_val << endl;


    ofstream outFile("max_min_fnc.csv"); 

    outFile << "Traversal,Execution Time (microseconds)\n"; 

    for (int i = 1; i <= size; ++i) {
        auto start = high_resolution_clock::now(); 
        min_max_fnc(arr, 0, i - 1, min_val, max_val);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 
        outFile << i << "," << duration.count() << "\n"; 
    }

    outFile.close(); 

    cout << "Execution times have been written to max_min_fnc.csv\n";

    return 0;
}
