#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
using namespace std;

// Function to print the array (helper)
void printArray(const vector<int>& arr, const string& message);

// Function to maintain the heap property
void heapify(vector<int>& arr, int n, int i);

// Function to perform Heap Sort
void heapSort(vector<int>& arr);

#endif // HEAP_SORT_H
