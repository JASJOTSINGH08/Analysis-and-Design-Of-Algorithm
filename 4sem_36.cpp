#include <iostream>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int pivot_swap(int arr[], int low, int high) {
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

int search(int arr[], int low, int high, int k) {
    if (low <= high) {
        int index = pivot_swap(arr, low, high);
        if (index == k - 1) {
            return arr[index];
        } else if (index > k - 1) {
            return search(arr, low, index - 1, k);
        } else {
            return search(arr, index + 1, high, k);
        }
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pivot_swap(arr , 0 , n-1 );
    cout<<"Pivot Swap elements : ";
    for (int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout << endl;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int k_small = search(arr, 0, n - 1, k);

    if (k_small != -1) {
        cout << "The k-th smallest element is: " << k_small << endl;
    } else {
        cout << "Invalid value of k" << endl;
    }

    return 0;
}


