#include "../Header_Files/All.h"

//? Quick Sort: Write something
int findMedian(vector<int> &arr, int left, int right, int &comparisons)
{
    int mid = left + (right - left) / 2;

    // Sort the three elements
    if (++comparisons && arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);
    if (++comparisons && arr[mid] > arr[right]) // Swap the mid and last elements
        swap(arr[mid], arr[right]);
    if (++comparisons && arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);

    return mid;
}
int partition(vector<int> &arr, int left, int right, int &comparisons)
{
    int pIndex = findMedian(arr, left, right, comparisons); // Find the median of the first, mid, last elements
    int pivot = arr[pIndex];
    swap(arr[pIndex], arr[left]); // Switch it back to the first element

    int i = left + 1;
    for (int j = i + 1; ++comparisons && j <= right; j++) // Move the elements smaller than pivot to the left
    {
        if (++comparisons && arr[j] < pivot)
            swap(arr[j], arr[i++]);
    }
    swap(arr[i - 1], arr[left]); // Switch the pivot to its position
    return i - 1;
}
void Quick_Sort(vector<int> &arr, int left, int right, int &comparisons)
{
    if (++comparisons && left < right)
    {
        int p = partition(arr, left, right, comparisons); // Find the pivot
        Quick_Sort(arr, left, p - 1, comparisons);         // Sort the left part
        Quick_Sort(arr, p + 1, right, comparisons);        // Sort the right part
    }
}
void QuickSort(vector<int> &arr, int &comparisons, double &time)
{   
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Quick_Sort(arr, 0, arr.size() - 1, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//?Shell Sort: Write something
void Shell_Sort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    int gap = 1;
    while (++comparisons && gap < n / 3) // generate the gap using Knuth's formula
        gap = gap * 3 + 1;
    // Other: Sedgewick sequence (4^i + 3 * 2^(i - 1) + 1), Hibbard sequence (2^k - 1)

    while (++comparisons && gap > 0)
    {
        for (int i = gap; ++comparisons && i < n; i++)
        {
            int tmp = arr[i];
            int j = i;
            while ((++comparisons && j >= gap) && (++comparisons && arr[j - gap] > tmp)) // Insertion sort within the gap
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
        gap /= 3; // Reduce the gap follows above generated formula
    }
}
void ShellSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Shell_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Counting Sort: Write something
void Counting_Sort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    int Min = arr[0], Max = arr[0];
    for (auto x : arr)
    {
        if (++comparisons && x < Min)
            Min = x;
        if (++comparisons && x > Max)
            Max = x;
    }

    int range = Max - Min + 1;
    vector<int> count(range, 0);
    for (auto x : arr)
        count[x - Min]++;

    int ind = 0;
    for (auto x : count)
    {
        while (++comparisons && x--)
            arr[ind++] = Min;
        Min++;
    }
}
void CountingSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Counting_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}