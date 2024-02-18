#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

long long power(int x, int n) {
    if (n == 0) {
        return 1;
    }

    long long halfPower = power(x, n / 2);

    if (n % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return x * halfPower * halfPower;
    }
}

int main() {
    ofstream outfile("execution_times.csv12");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Base,Exponent,ExecutionTime" << endl;

    // Define the range of bases and exponents
    vector<int> bases;
    vector<int> exponents;
    for (int i = 1; i <= 100; ++i) {
        bases.push_back(i);
        exponents.push_back(i);
    }

    int iterations = 10; // Number of iterations to average execution time

    for (int base : bases) {
        for (int exponent : exponents) {
            double totalExecutionTime = 0.0;

            for (int i = 0; i < iterations; ++i) {
                clock_t startTime = clock();
                // Measure the execution time of the power function
                long long result = power(base, exponent);
                clock_t endTime = clock();

                double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
                totalExecutionTime += executionTime;
            }

            double averageExecutionTime = totalExecutionTime / iterations;

            // Output the result to the console
            cout << "Base: " << base << ", Exponent: " << exponent << ", Average Execution Time: " << averageExecutionTime << " seconds" << endl;

            // Write the result to the CSV file
            outfile << base << "," << exponent << "," << averageExecutionTime << endl;
        }
    }

    outfile.close();

    return 0;
}
