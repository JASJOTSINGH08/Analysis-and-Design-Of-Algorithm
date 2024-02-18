#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void Magic_square(int n, ofstream& outfile) {
    int magicSquare[n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    int i = n / 2;
    int j = n - 1;

    clock_t start_time, end_time;
    double elapsed_time;

    for (int num = 1; num <= n * n;) {
        start_time = clock();

        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (i < 0)
                i = n - 1;

            if (j == n)
                j = 0;
        }

        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }

        j++;
        i--;

        end_time = clock();
        elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        outfile << num << "," << elapsed_time << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of magic square: ";
    cin >> n;

    ofstream outfile("magic_square_execution_times.csv");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outfile << "Step,Execution Time" << endl;

    Magic_square(n, outfile);

    outfile.close();

    return 0;
}
