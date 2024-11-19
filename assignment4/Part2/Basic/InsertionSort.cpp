#include <iostream>
#include <vector>
#include "InsertionSort.h"
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than `key` one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Show array state after each iteration
        cout << "Iteration " << i << ": ";
        for (int num : arr) cout << num << " ";
        cout << "\n";
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45, 33};
    cout << "Insertion Sort:\nOriginal array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    return 0;
}

