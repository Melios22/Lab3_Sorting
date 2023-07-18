#ifndef SortingAlgorithms_h
#define SortingAlgorithms_h

#include "Library.h"

//* Huy's part
void Heap_Sort(vector<int> &arr, long long &comparisons);
void HeapSort(vector<int> &arr, long long &comparisons, double &time);
void Merge_Sort(vector<int> &arr, int left, int right, long long &comparisons);
void MergeSort(vector<int> &arr, long long &comparisons, double &time);
void Radix_Sort(vector<int> &arr, int base, long long &comparisons);
void RadixSort(vector<int> &arr, long long &comparisons, double &time);

//* Minh's part
void Quick_Sort(vector<int> &arr, int left, int right, long long &comparisons);
void QuickSort(vector<int> &arr, long long &comparisons, double &time);
void Shell_Sort(vector<int> &arr, long long &comparisons);
void ShellSort(vector<int> &arr, long long &comparisons, double &time);
void Counting_Sort(vector<int> &arr, long long &comparisons);
void CountingSort(vector<int> &arr, long long &comparisons, double &time);

//* Nam's part
void Shaker_Sort(std::vector<int> &arr, long long &comparisons);
void ShakerSort(std::vector<int> &arr, long long &comparisons, double &time);
void Flash_Sort(std::vector<int> &arr, long long &comparisons);
void FlashSort(std::vector<int> &arr, long long &comparisons, double &time);

//* Vy's part
void Selection_Sort(vector<int> &arr, long long &comparisons);
void SelectionSort(vector<int> &arr, long long &comparisons, double &time);
void Insertion_Sort(vector<int> &arr, long long &comparisons);
void InsertionSort(vector<int> &arr, long long &comparisons, double &time);
void Bubble_Sort(vector<int> &arr, long long &comparisons);
void BubbleSort(vector<int> &arr, long long &comparisons, double &time);

// Global variables
const vector<string> Algo = {"Bubble Sort",
                             "Counting Sort",
                             "Flash Sort",
                             "Heap Sort",
                             "Insertion Sort",
                             "Merge Sort",
                             "Quick Sort",
                             "Radix Sort",
                             "Selection Sort",
                             "Shaker Sort",
                             "Shell Sort"};

const vector<MeasureSortingAlgo> Algo_Measuring = {
    BubbleSort,
    CountingSort,
    FlashSort,
    HeapSort,
    InsertionSort,
    MergeSort,
    QuickSort,
    RadixSort,
    SelectionSort,
    ShakerSort,
    ShellSort,
};

#endif