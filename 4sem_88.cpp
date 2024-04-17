#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Function to generate permutations of truth table and calculate time complexity
void generatePermutations(vector<vector<bool>>& permutations, int n, ofstream& csvFile) {
    int numPermutations = 1 << n; // Number of permutations = 2^n

    // Iterate over all possible combinations of truth values
    for (int i = 0; i < numPermutations; ++i) {
        vector<bool> currentPermutation(n);

        // Start measuring time
        auto start = high_resolution_clock::now();

        // Generate the truth values for the current permutation
        for (int j = 0; j < n; ++j) {
            currentPermutation[j] = (i >> j) & 1; // Extract j-th bit of i
        }

        // Stop measuring time
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        // Write time complexity to CSV file
        csvFile << duration.count() << endl;

        // Add the current permutation to the list of permutations
        permutations.push_back(currentPermutation);
    }
}

// Function to display permutations of truth table
void displayPermutations(const vector<vector<bool>>& permutations) {
    for (const auto& permutation : permutations) {
        for (bool value : permutation) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of variables in the truth table: ";
    cin >> n;

    vector<vector<bool>> permutations;
    ofstream csvFile("time_complexity.csv");
    if (!csvFile.is_open()) {
        cerr << "Error: Could not open the CSV file!" << endl;
        return 1;
    }

    generatePermutations(permutations, n, csvFile);

    cout << "Permutations of the truth table:" << endl;
    displayPermutations(permutations);

    csvFile.close();

    return 0;
}
