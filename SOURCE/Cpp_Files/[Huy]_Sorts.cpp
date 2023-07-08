#include "../Header_Files/All.h"

//? Heap Sort (enhancing from selection sort) - building a heap structure and gradually swap the root with the last element
void heapify(vector<int>& arr, int size, int pos, int& comparations)
{
    int v = arr[pos];
    bool isHeap = false;
    while (++comparations && (!isHeap && 2 * pos + 1 < size))
    {
        int j = 2 * pos + 1;
        if (++comparations && j < size - 1 && arr[j] < arr[j + 1]) // Get the bigger child node
            j++;
        if (++comparations && arr[pos] >= arr[j]) // Already satisfied a heap at that element to the rest on the right
            isHeap = true;
        else
        {
            std::swap(arr[pos], arr[j]); // Reposition the node
            pos = j;                     // Loop to check validity of the node just has swapped
            ++comparations;
        }
    }
    arr[pos] = v;
}
void heapifyRecursion(vector<int>& arr, int size, int pos, int& comparations)
{
    int largest = pos;
    int left = 2 * pos + 1;
    int right = left + 1;

    if (++comparations && (left < size && arr[left] > arr[largest])) // compare the child node to find if the child is bigger
        largest = left;
    if (++comparations && (right < size && arr[right] > arr[largest]))
        largest = right;

    if (++comparations && largest != pos) // If the position differ from the declaration, it means the child in bigger than its parent
    {
        std::swap(arr[pos], arr[largest]); // Swap to its parent
        heapifyRecursion(arr, size, largest, comparations); // Check validity of the new child
    }
    return;
}
void heapSort(vector<int>& arr, int& comparations)
{
    for (int i = arr.size() / 2 - 1; ++comparations && i >= 0; i--) // Loop from the middle to heapify the whole array
        heapify(arr, arr.size(), i, comparations);
    // heapifyRecursion(arr, n, i);
    for (int i = arr.size() - 1; ++comparations && i > 0; i--)
    {
        std::swap(arr[0], arr[i]); // Swap the first element with the last unsorted element
        heapify(arr, i, 0, comparations);        // Heapify the semi-heap again with the reduced size
        // heapifyRecursion(arr, i, 0);
    }
}

//? Merge Sort - divide the array into small part and combine accordingly
void merge(vector<int>& arr, int left, int mid, int right, int& comparations)
{
    int* tmp_arr = new int[right - left + 1]; // Create a temporary array
    int i = left, j = mid + 1, k = 0;

    while (++comparations && (i <= mid && j <= right))
    {
        if (++comparations && (arr[i] < arr[j]))// Comparing element ant index i, j of the 2 small array, put it accordingly into the tmp list
            tmp_arr[k++] = arr[i++];
        else
        {
            tmp_arr[k++] = arr[j++];
            ++comparations;
        }
    }
    while (++comparations && i <= mid) // Put the rest of the 2 list into the tmp
        tmp_arr[k++] = arr[i++];
    while (++comparations && j <= right)
        tmp_arr[k++] = arr[j++];
    for (int i = left, k = 0; ++comparations && i <= right; i++, k++) // Copy back element to the original array
        arr[i] = tmp_arr[k];
    delete[] tmp_arr;
}
void mergeSort(vector<int>& arr, int left, int right, int& comparations)
{
    if (++comparations && (left < right))
    {
        int mid = left + (right - left) / 2; // get the mid, avoiding overflowing
        mergeSort(arr, left, mid, comparations);           // Recursively divide into small lists
        mergeSort(arr, mid + 1, right, comparations);
        merge(arr, left, mid, right, comparations); // Merge the sorted lists together
    }
}

//? Radix Sort
void radixSort(vector<int>& arr, int base, int& comparations)
{
    std::queue<int>* bucket = new std::queue<int>[base];
    int longest = 0;
    int minVal = arr[0];
    bool negative = false;

    for (int i = 0; ++comparations && i < arr.size(); i++)
        if (++comparations && arr[i] < 0)
        {
            negative = true;                   // Check for negative numbers
            minVal = std::min(minVal, arr[i]); // Get the minimum value of the array
        }

    if (++comparations && negative)
        for (int i = 0; ++comparations && i < arr.size(); i++)
            arr[i] -= minVal; // Add every element up to 0

    for (int i = 0; ++comparations && i < arr.size(); i++)
        longest = std::max(longest, int(std::to_string(arr[i]).size())); // Get the max size of the elements

    int expo = 1;
    while (++comparations && longest--)
    {
        for (int i = 0; ++comparations && i < arr.size(); i++)
        {
            int order = (arr[i] / expo) % 10; // Get the digit from rightmost to leftmost
            bucket[order].push(arr[i]);       // Push into a queue
        }
        expo *= base;

        for (int i = 0, k = 0; ++comparations && i < base; i++)
            while (++comparations && !bucket[i].empty()) // Pop the element gradually and copy back to the array
            {
                arr[k++] = bucket[i].front();
                bucket[i].pop();
            }
    }

    if (++comparations && negative) // Decrement back to its original
        for (int i = 0; ++comparations && i < arr.size(); i++)
            arr[i] += minVal;

    delete[] bucket;
}