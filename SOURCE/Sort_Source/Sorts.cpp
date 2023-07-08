#include "../Header_Files/SortingAlgorithms.h"

void selectionSort(vector<int> &arr, int &comparisons);
void bubbleSort(vector<int> &arr, int &comparisons);
void shakerSort(vector<int> &arr, int &comparisons);
void insertionSort(vector<int> &arr, int &comparisons);
void shellSort(vector<int> &arr, int &comparisons);
void heapSort(vector<int> &arr, int &comparisons); // Code in recursion and normally
void mergeSort(vector<int> &arr, int left, int right, int &comparisons);
void quickSort(vector<int> &arr, int left, int right, int &comparisons);
void countingSort(vector<int> &arr, int &comparisons);
void radixSort(vector<int> &arr, int &comparisons, int base = 10);
// void flashSort(vector<int> &arr, int &comparisons);

// int main()
// {
//     int arr[] = {4689, -7818, 8341, 6801, 6834, 664, 7872, -6579, -1723, 8493, 7237, -5016};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     std::cout << "Unsorted Array:   ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << "\n\n";

//     // Sorting algorithm
//     // selectionSort(arr, n);
//     // bubbleSort(arr, n);
//     // shakerSort(arr, n);
//     // insertionSort(arr, n);
//     // shellSort(arr, n);
//     // heapSort(arr, n);
//     // mergeSort(arr, 0, n - 1);
//     // quickSort(arr, 0, n - 1);
//     // countingSort(arr, n);
//     // radixSort(arr, n, 10);

//     std::cout << "Sorted Array:     ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << "\n\n";
//     return 0;
// }

//? Selection Sort - swap the min in the unsorted to the last sorted part
void selectionSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Bubble Sort - swap the largest element to the last in every loop
void bubbleSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Shaker Sort (Cocktail Sort/ Bidirectional Bubble Sort) - similar to bubble sort but doing from both sides
void shakerSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Insertion Sort - move the key to its correct pos by shifting the other elements
void insertionSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Shell Sort (extension of insertion sort) - sort elements that are h position apart
void shellSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Heap Sort (enhancing from selection sort) - building a heap structure and gradually swap the root with the last element
void heapify(vector<int> &arr, int &comparisons, int pos)
{
    int n = arr.size();
    int v = arr[pos];
    bool isHeap = false;
    while (!isHeap && 2 * pos + 1 < n)
    {
        int j = 2 * pos + 1;
        if (j < n - 1 && arr[j] < arr[j + 1]) // Get the bigger child node
            j++;
        if (arr[pos] >= arr[j]) // Already satisfied a heap at that element to the rest on the right
            isHeap = true;
        else
        {
            std::swap(arr[pos], arr[j]); // Reposition the node
            pos = j;                     // Loop to check validity of the node just has swapped
        }
    }
    arr[pos] = v;
}
void heapifyRecursion(vector<int> &arr, int &comparisons, int pos)
{
    int n = arr.size();
    int largest = pos;
    int left = 2 * pos + 1;
    int right = left + 1;

    if (left < n && arr[left] > arr[largest]) // compare the child node to find if the child is bigger
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != pos) // If the position differ from the declaration, it means the child in bigger than its parent
    {
        std::swap(arr[pos], arr[largest]); // Swap to its parent
        heapifyRecursion(arr, n, largest); // Check validity of the new child
    }
    return;
}
void heapSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) // Loop from the middle to heapify the whole array
        heapify(arr, n, i);
    // heapifyRecursion(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]); // Swap the first element with the last unsorted element
        heapify(arr, i, 0);        // Heapify the semi-heap again with the reduced size
        // heapifyRecursion(arr, i, 0);
    }
}

//? Merge Sort - divide the array into small part and combine accordingly
void merge(vector<int> &arr, int left, int mid, int right, int &comparisons)
{
    int *tmp_arr = new int[right - left + 1]; // Create a temporary array
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j]) // Comparing element ant index i, j of the 2 small array, put it accordingly into the tmp list
            tmp_arr[k++] = arr[i++];
        else
            tmp_arr[k++] = arr[j++];
    }
    while (i <= mid) // Put the rest of the 2 list into the tmp
        tmp_arr[k++] = arr[i++];
    while (j <= right)
        tmp_arr[k++] = arr[j++];
    for (int i = left, k = 0; i <= right; i++, k++) // Copy back element to the original array
        arr[i] = tmp_arr[k];
    delete[] tmp_arr;
}
void mergeSort(vector<int> &arr, int left, int right, int &comparisons)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // get the mid, avoiding overflowing
        mergeSort(arr, left, mid, comparisons);           // Recursively divide into small lists
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons); // Merge the sorted lists together
    }
}

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

//? Counting Sort - create another array to count the occurences of element in the array
void countingSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
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

//? Radix Sort
void radixSort(vector<int> &arr, int &comparisons, int base)
{
    int n = arr.size();
    std::queue<int> *bucket = new std::queue<int>[base];
    int longest = 0;
    int minVal = arr[0];
    bool negative = false;

    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
        {
            negative = true;                   // Check for negative numbers
            minVal = std::min(minVal, arr[i]); // Get the minimum value of the array
        }

    if (negative)
        for (int i = 0; i < n; i++)
            arr[i] -= minVal; // Add every element up to 0

    for (int i = 0; i < n; i++)
        longest = std::max(longest, int(std::to_string(arr[i]).size())); // Get the max size of the elements

    int expo = 1;
    while (longest--)
    {
        for (int i = 0; i < n; i++)
        {
            int order = (arr[i] / expo) % 10; // Get the digit from rightmost to leftmost
            bucket[order].push(arr[i]);       // Push into a queue
        }
        expo *= base;

        for (int i = 0, k = 0; i < base; i++)
            while (!bucket[i].empty()) // Pop the element gradually and copy back to the array
            {
                arr[k++] = bucket[i].front();
                bucket[i].pop();
            }
    }

    if (negative) // Decrement back to its original
        for (int i = 0; i < n; i++)
            arr[i] += minVal;

    delete[] bucket;
}
