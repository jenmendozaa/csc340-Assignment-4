cmake_minimum_required(VERSION 3.29)
project(csc340_Assignment_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(assignment4/Part3/LinkedBagDS)

add_executable(csc340_Assignment_4
    assignment4/Part1/jacobsthal.cpp
    assignment4/Part1/jacobsthalMemoization_EC.cpp
    assignment4/Part3/LinkedBagDS/BagInterface.h
    assignment4/Part3/LinkedBagDS/LinkedBag.cpp
    assignment4/Part3/LinkedBagDS/LinkedBag.h
    assignment4/Part3/LinkedBagDS/Node.cpp
    assignment4/Part3/LinkedBagDS/Node.h
    assignment4/Part3/linkedBagSortingMain.cpp
    assignment4/Part3/mergeSortChatGPT.cpp
    assignment4/Part3/quickSortChatGPT.cpp
        "assignment4/Part2/Basic/SelectionSort.cpp"
        "assignment4/Part2/Basic/SelectionSort.h"
        "assignment4/Part2/Basic/InsertionSort.cpp"
        "assignment4/Part2/Basic/InsertionSort.h"
        "assignment4/Part2/Faster/quicksort.cpp"
        assignment4/Part2/HeapSort/HeapSort.cpp
        assignment4/Part2/HeapSort/HeapSort.h
        assignment4/Part2/Faster/QuickSort.h)
