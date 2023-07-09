#pragma once
#include "Library.h"

//* Huy's part
void heapSort(vector<int> &arr, int &comparisons);
void mergeSort(vector<int> &arr, int left, int right, int &comparisons);
void radixSort(vector<int> &arr, int base, int &comparisons);

//* Minh's part
void shellSort(vector<int> &arr, int &comparisons, double &time);
void quickSort(vector<int> &arr, int &comparisons, double &time);
void countingSort(vector<int> &arr, int &comparisons, double &time);

//* Nam's part
void shakerSort(std::vector<int> &arr, int &comparisons, double &time);
void FlashSort (std::vector<int> &arr, int &comparisons, double &time);

//* Vy's part
void selectionSort(vector<int> &arr, int &comparisons);
void bubbleSort(vector<int> &arr, int &comparisons);
void insertionSort(vector<int> &arr, int &comparisons);
