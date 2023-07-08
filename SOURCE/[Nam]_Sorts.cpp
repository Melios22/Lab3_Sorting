//! comparisons
#include "SortingAlgorithms.h"

//? Shaker Sort (Cocktail Sort/ Bidirectional Bubble Sort) - similar to bubble sort but doing from both sides
void shakerSort(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        bool swapped = false;
        for (int i = left; i < right; i++) // Passing from left, find the max and move to last
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        right--; // Decrement the last pos which is the current max

        for (int i = right; i > left; i--) // Passing from right, find the min and move to first
            if (arr[i - 1] > arr[i])
            {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        left++; // Increment the first pos which is the current min

        if (!swapped) // There is no swap, the array is sorted
            break;
    }
}