#include "../Header_Files/All.h"

//? Heap Sort (enhancing from selection sort) - building a heap structure and gradually swap the root with the last element
void heapify(vector<int> &arr, int size, int pos, int &comparisons)
{
    int v = arr[pos];
    bool isHeap = false;
    while (++comparisons && (!isHeap && 2 * pos + 1 < size))
    {
        int j = 2 * pos + 1;
        if (++comparisons && j < size - 1 && arr[j] < arr[j + 1]) // Get the bigger child node
            j++;
        if (++comparisons && arr[pos] >= arr[j]) // Already satisfied a heap at that element to the rest on the right
            isHeap = true;
        else
        {
            std::swap(arr[pos], arr[j]); // Reposition the node
            pos = j;                     // Loop to check validity of the node just has swapped
            ++comparisons;
        }
    }
    arr[pos] = v;
}
void heapifyRecursion(vector<int> &arr, int size, int pos, int &comparisons)
{
    int largest = pos;
    int left = 2 * pos + 1;
    int right = left + 1;

    if (++comparisons && (left < size && arr[left] > arr[largest])) // compare the child node to find if the child is bigger
        largest = left;
    if (++comparisons && (right < size && arr[right] > arr[largest]))
        largest = right;

    if (++comparisons && largest != pos) // If the position differ from the declaration, it means the child in bigger than its parent
    {
        std::swap(arr[pos], arr[largest]); // Swap to its parent
        heapifyRecursion(arr, size, largest, comparisons); // Check validity of the new child
    }
    return;
}
void Heap_Sort(vector<int> &arr, int &comparisons)
{
    for (int i = arr.size() / 2 - 1; ++comparisons && i >= 0; i--) // Loop from the middle to heapify the whole array
        heapify(arr, arr.size(), i, comparisons);
    // heapifyRecursion(arr, n, i);
    for (int i = arr.size() - 1; ++comparisons && i > 0; i--)
    {
        std::swap(arr[0], arr[i]); // Swap the first element with the last unsorted element
        heapify(arr, i, 0, comparisons);        // Heapify the semi-heap again with the reduced size
        // heapifyRecursion(arr, i, 0);
    }
}
void HeapSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Heap_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}

//? Merge Sort - divide the array into small part and combine accordingly
void merge(vector<int> &arr, int left, int mid, int right, int &comparisons)
{
    int* tmp_arr = new int[right - left + 1]; // Create a temporary array
    int i = left, j = mid + 1, k = 0;

    while (++comparisons && (i <= mid && j <= right))
    {
        if (++comparisons && (arr[i] < arr[j]))// Comparing element ant index i, j of the 2 small array, put it accordingly into the tmp list
            tmp_arr[k++] = arr[i++];
        else
        {
            tmp_arr[k++] = arr[j++];
            ++comparisons;
        }
    }
    while (++comparisons && i <= mid) // Put the rest of the 2 list into the tmp
        tmp_arr[k++] = arr[i++];
    while (++comparisons && j <= right)
        tmp_arr[k++] = arr[j++];
    for (int i = left, k = 0; ++comparisons && i <= right; i++, k++) // Copy back element to the original array
        arr[i] = tmp_arr[k];
    delete[] tmp_arr;
}
void Merge_Sort(vector<int> &arr, int left, int right, int &comparisons)
{
    if (++comparisons && (left < right))
    {
        int mid = left + (right - left) / 2; // get the mid, avoiding overflowing
        Merge_Sort(arr, left, mid, comparisons);           // Recursively divide into small lists
        Merge_Sort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons); // Merge the sorted lists together
    }
}
void MergeSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Merge_Sort(arr, 0, arr.size() - 1, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}

//? Radix Sort
void Radix_Sort(vector<int> &arr, int base, int &comparisons)
{
    std::queue<int>* bucket = new std::queue<int>[base];
    int longest = 0;
    int minVal = arr[0];
    bool negative = false;

    for (int i = 0; ++comparisons && i < arr.size(); i++)
        if (++comparisons && arr[i] < 0)
        {
            negative = true;                   // Check for negative numbers
            minVal = std::min(minVal, arr[i]); // Get the minimum value of the array
        }

    if (++comparisons && negative)
        for (int i = 0; ++comparisons && i < arr.size(); i++)
            arr[i] -= minVal; // Add every element up to 0

    for (int i = 0; ++comparisons && i < arr.size(); i++)
        longest = std::max(longest, int(std::to_string(arr[i]).size())); // Get the max size of the elements

    int expo = 1;
    while (++comparisons && longest--)
    {
        for (int i = 0; ++comparisons && i < arr.size(); i++)
        {
            int order = (arr[i] / expo) % 10; // Get the digit from rightmost to leftmost
            bucket[order].push(arr[i]);       // Push into a queue
        }
        expo *= base;

        for (int i = 0, k = 0; ++comparisons && i < base; i++)
            while (++comparisons && !bucket[i].empty()) // Pop the element gradually and copy back to the array
            {
                arr[k++] = bucket[i].front();
                bucket[i].pop();
            }
    }

    if (++comparisons && negative) // Decrement back to its original
        for (int i = 0; ++comparisons && i < arr.size(); i++)
            arr[i] += minVal;

    delete[] bucket;
}
void RadixSort(vector<int> &arr, int &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Radix_Sort(arr, 10, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}