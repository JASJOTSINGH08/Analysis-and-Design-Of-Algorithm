#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;


int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size()-1 ;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
}

int main() {
    ofstream outfile("execution_times.csv11");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Size,ExecutionTime" << endl;

    for (int n = 100; n <= 1000; n += 100) {
        vector<int> elements(n);
        for (int i = 0; i < n; i++) {
            elements[i] = i + 1;
        }

        
        int key = rand() % n;

        clock_t startTime = clock();
        int result = binarySearch(elements, key);
        clock_t endTime = clock();

        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Size: " << n << ", Execution Time: " << executionTime << " seconds" << endl;

        outfile << n << "," << executionTime << endl;
    }

    outfile.close();

    return 0;
}
