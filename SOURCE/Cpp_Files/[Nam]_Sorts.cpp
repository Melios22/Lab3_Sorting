#include "../Header_Files/All.h"

//? Shaker Sort (Cocktail Sort/ Bidirectional Bubble Sort) - similar to bubble sort but doing from both sides
void Shaker_Sort(std::vector<int> &arr, long long &comparisons)
{
    int ArraySize = arr.size();
    int left = 0, right = ArraySize - 1;
    while (++comparisons && left < right)
    {
        bool swapped = false;
        for (int i = left; ++comparisons && i < right; i++) // Passing from left, find the max and move to last
            if (++comparisons && arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        right--; // Decrement the last pos which is the current max

        for (int i = right; ++comparisons && i > left; i--) // Passing from right, find the min and move to first
            if (++comparisons && arr[i - 1] > arr[i])
            {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        left++; // Increment the first pos which is the current min

        if (++comparisons && !swapped) // There is no swap, the array is sorted
            break;
    }
}
void ShakerSort(std::vector<int> &arr, long long &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Shaker_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Flash Sort - implement Bucket Sort, a fast sorting algorithm
void Insertion_Sort_Variant(std::vector<int> &arr, int left, int right, long long &comparisons)
{
    for (int i = left + 1; ++comparisons && i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (++comparisons && j >= left && ++comparisons && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}
void Flash_Sort(std::vector<int> &arr, long long &comparisons)
{
    int Arraysize = arr.size(); // Get the size of array
    // Get the number of buckets used for this algorithm, 0.45 is the best number for helping algorithm run effectively
    int numBuckets = (int)(0.45 * Arraysize);

    if (++comparisons && numBuckets > 0)
    {
        // Create an array save the position of the last element in each bucket
        int *EndOfBucket = new int[numBuckets];
        for (int i = 0; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] = 0;

        // Find the minimum value and the position of the maximum value in the array
        int minValue = arr[0];
        int indexMax = 0;
        for (int i = 1; ++comparisons && i < Arraysize; ++i)
        {
            if (++comparisons && arr[i] < minValue)
                minValue = arr[i];
            else if (++comparisons && arr[i] > arr[indexMax])
                indexMax = i;
        }

        // Deliver each element into a certain bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            int indexBucket = (int)(((double)((numBuckets - 1) * (arr[i] - minValue))) / (arr[indexMax] - minValue));
            EndOfBucket[indexBucket]++;
        }

        // Used prefix sum to identify precisely the position of the last element in each bucket
        for (int i = 1; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] += EndOfBucket[i - 1];

        // Save the position of each last element in bucket
        std::vector<int> saveBucketSize;
        for (int i = 0; ++comparisons && i < numBuckets; ++i)
            saveBucketSize.push_back(EndOfBucket[i]);

        // Move the maximum number to the first position
        int temp = arr[indexMax];
        arr[indexMax] = arr[0];
        arr[0] = temp;

        // Move each element to exact bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            int indexBucket = (int)(((double)((numBuckets - 1) * (arr[0] - minValue))) / (temp - minValue));
            std::swap(arr[0], arr[EndOfBucket[indexBucket] - 1]);

            EndOfBucket[indexBucket]--;
            if (++comparisons && EndOfBucket[0] == 0)
                break;
        }

        delete[] EndOfBucket; // Deallocation

        for (int i = 0; ++comparisons && i < numBuckets; ++i)
        {
            if (++comparisons && i == 0)
                Insertion_Sort_Variant(arr, 0, saveBucketSize[i] - 1, comparisons);
            else
                Insertion_Sort_Variant(arr, saveBucketSize[i - 1], saveBucketSize[i] - 1, comparisons);
        }
    }
    else
        Insertion_Sort_Variant(arr, 0, arr.size() - 1, comparisons);
}
void FlashSort(std::vector<int> &arr, long long &comparisons, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    comparisons = 0;
    Flash_Sort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}