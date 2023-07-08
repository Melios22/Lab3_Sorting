#include "SortingAlgorithms.h"

//? Quick Sort - divide an array according to the chosen pivot and swap
int partition(int *arr, int left, int right)
{
    int pivot = arr[left];
    int i = left + 1;
    for (int j = i; j < right + 1; j++) // let call element less than pivot is L, greater is G
        if (arr[j] < pivot)
            std::swap(arr[j], arr[i++]); // swap the array follows the pivot - L - G

    std::swap(arr[i - 1], arr[left]); // Swap the pivot to the correct sorted position
    return i - 1;                     // return the pivot position
}
void quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1); // Recursively divide the list at pivot position and sort them
        quickSort(arr, p + 1, right);
    }
}

//? Shell Sort (extension of insertion sort) - sort elements that are h position apart
void shellSort(int *arr, int n)
{
    int gap = 1;
    while (gap < n / 3) // generate the gap using Knuth's formula
        gap = gap * 3 + 1;
    // Other: Sedgewick sequence (4^i + 3 * 2^(i - 1) + 1), Hibbard sequence (2^k - 1)

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > tmp) // Insertion sort within the gap
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
        gap /= 3; // Reduce the gap follows above generated formula
    }
}

//? Counting Sort - create another array to count the occurences of element in the array
void countingSort(int *arr, int n)
{
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) // Get the min and max value of the array
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    int slot = maxVal - minVal + 1;
    int *cntArr = new int[slot]; // Create a counting array to store the occurences of elements
    for (int i = 0; i < slot; i++)
        cntArr[i] = 0;

    for (int i = 0; i < n; i++)
        cntArr[arr[i] - minVal]++; // The index is the value of the element, increase by 1

    int k = 0, ind = 0;
    while (ind < slot)
    {
        while (cntArr[ind] > 0) // If the occurence > 0, copying it back to the correct pos in the original array
        {
            arr[k++] = ind + minVal;
            cntArr[ind]--;
        }
        ind++;
    }

    delete[] cntArr;
}