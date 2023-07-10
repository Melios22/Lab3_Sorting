#include "../Header_Files/All.h"


//? Selection Sort - swap the min in the unsorted to the last sorted part
void Selection_Sort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    for (int i = 0; ++comparisons && i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; ++comparisons && j < n; j++) // Find the min element's index
            if (++comparisons && arr[j] < arr[minInd])
                minInd = j;

        if (++comparisons && minInd != i) // Swap the min to its pos if the min's index different from the current
            std::swap(arr[minInd], arr[i]);
    }
}
void SelectionSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Selection_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}

//? Insertion Sort - move the key to its correct pos by shifting the other elements
void insertion_Sort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    for (int i = 1; ++comparisons && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (++comparisons && j >= 0 && ++comparisons && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}
void InsertionSort (vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    insertion_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}

//? Bubble Sort - swap the largest element to the last in every loop
void Bubble_Sort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    for (int i = 0; ++comparisons && i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; ++comparisons && j < n - i - 1; j++) // Move the largest to last
            if (++comparisons && arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (++comparisons && !swapped) // If there is no swap, the array is sorted
            break;
    }
}
void BubbleSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Bubble_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}