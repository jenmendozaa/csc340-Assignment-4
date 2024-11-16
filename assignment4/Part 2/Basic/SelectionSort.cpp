#include <iostream>
#include <vector>
#include "SelectionSort.h"
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

        // Show array state after each iteration
        cout << "Iteration " << i + 1 << ": ";
        for (int num : arr) cout << num << " ";
        cout << "\n";
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45, 33};
    cout << "Selection Sort:\nOriginal array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    return 0;
}
