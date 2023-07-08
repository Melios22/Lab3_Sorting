#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr, int &comparisons);
void bubbleSort(vector<int> &arr, int &comparisons);
void shakerSort(vector<int> &arr, int &comparisons);
void insertionSort(vector<int> &arr, int &comparisons);
void shellSort(vector<int> &arr, int &comparisons);
void heapSort(vector<int> &arr, int &comparisons); // Code in recursion and normally
void mergeSort(vector<int> &arr, int left, int right, int &comparisons);
void quickSort(vector<int> &arr, int left, int right, int &comparisons);
void countingSort(vector<int> &arr, int &comparisons);
void radixSort(vector<int> &arr, int &comparisons);
// void flashSort(vector<int> &arr, int &comparisons);
