#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void pivot_swap(int n, int arr[]) {
    int i = 1;
    int j = n;
    int pivot = arr[0];

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
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pivot_swap(n, arr);

    cout << "After pivot: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
