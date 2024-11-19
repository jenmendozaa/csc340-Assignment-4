#include "QuickSort.h"
#include <iostream>

using namespace std;

//  g++ -std=c++11 -o quicksort quicksort.cpp
// ./quicksort

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // creating pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // placing pivot into the correct place

    // printing current state
    cout << "Partitioned: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45, 33};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
