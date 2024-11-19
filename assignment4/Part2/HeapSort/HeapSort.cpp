#include <iostream>
#include <vector>
#include "HeapSort.h"

using namespace std;

// g++ -std=c++11 -o HeapSort HeapSort.cpp
// ./HeapSort


// printing the array
void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// function to manage the heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1; // get the left child i
    int right = 2 * i + 2; // get the right child i

    if (left < n) {
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// function to sort an array
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }



    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45, 33};
    int size = arr.size();


    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
