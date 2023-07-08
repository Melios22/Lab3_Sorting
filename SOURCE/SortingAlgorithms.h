#ifndef SortingAlgorithms.h
#define SortingAlgorithms.h

#include <iostream>
#include <queue>
#include <string>

void selectionSort(int *arr, int n);
void bubbleSort(int *arr, int n);
void shakerSort(int *arr, int n);
void insertionSort(int *arr, int n);
void shellSort(int *arr, int n);
void heapSort(int *arr, int n); // Code in recursion and normally
void mergeSort(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
void countingSort(int *arr, int n);
void radixSort(int *arr, int n, int base = 10);
// void flashSort(int *arr, int n);

#endif