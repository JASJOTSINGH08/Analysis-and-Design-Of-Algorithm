#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int horner(vector<int>& coefficients, int n, int x, ofstream& csvFile) {
    int result = coefficients[0]; 

    for (int i = 1; i < n; i++) {
        auto start = high_resolution_clock::now();
        result = result * x + coefficients[i];
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        csvFile << i << "," << duration.count() << endl; 
    }

    return result;
}

int main() {
    vector<int> coefficients = {2, -3, 1}; 

    int n = coefficients.size(); 
    int x = 3; 

    ofstream csvFile("horner_time_complexity.csv");
    csvFile << "Step,Time (nanoseconds)" << endl;

    int value = horner(coefficients, n, x, csvFile);

    csvFile.close();

    cout << "Value of the polynomial at x = " << x << " is: " << value << endl;

    return 0;
}
