#include "SortingAlgorithms.h"

//? Selection Sort - swap the min in the unsorted to the last sorted part
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++) // Find the min element's index
            if (arr[j] < arr[minInd])
                minInd = j;

        if (minInd != i) // Swap the min to its pos if the min's index different from the current
            std::swap(arr[minInd], arr[i]);
    }
}

//? Insertion Sort - move the key to its correct pos by shifting the other elements
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}

//? Bubble Sort - swap the largest element to the last in every loop
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) // Move the largest to last
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped) // If there is no swap, the array is sorted
            break;
    }
}