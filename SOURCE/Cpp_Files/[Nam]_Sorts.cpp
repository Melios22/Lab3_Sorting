#include "../Header_Files/All.h"


//? Shaker Sort (Cocktail Sort/ Bidirectional Bubble Sort) - similar to bubble sort but doing from both sides
void shakerSort(std::vector<int> &arr, int &comparisons, double &time)
{
    int ArraySize = arr.size();
    auto startTime = chrono::high_resolution_clock::now();
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
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}

//? Flash Sort - implement Bucket Sort, a fast sorting algorithm
void FlashSort (std::vector<int> &arr, int &comparisons, double &time)
{
    int Arraysize = arr.size(); //Get the size of array
    // Get the number of buckets used for this algorithm, 0.45 is the best number for helping algorithm run effectively
    int numBuckets = (int)(0.45 * Arraysize);
    auto startTime = chrono::high_resolution_clock::now();

    if (++comparisons && numBuckets > 0)
    {
        //Create an array save the position of the last element in each bucket
        int* EndOfBucket = new int [numBuckets];
        for (int i = 0; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] = 0;

        //Find the minimum value and the position of the maximum value in the array
        int minValue = arr[0]; int indexMax = 0;
        for (int i = 1; ++comparisons && i < Arraysize; ++i)
        {
            if (++comparisons && arr[i] < minValue)
                minValue = arr[i];
            else if (++comparisons && arr[i] > arr[indexMax])
                indexMax = i;
        }

        //Deliver each element into a certain bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            int indexBucket = (int)(((double)((numBuckets - 1) * (arr[i] - minValue))) / (arr[indexMax] - minValue));
            EndOfBucket[indexBucket]++;
        }

        //Used prefix sum to identify precisely the position of the last element in each bucket
        for (int i = 1; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] += EndOfBucket[i - 1];

        //Move the maximum number to the first position
        int temp = arr[indexMax];
        arr[indexMax] = arr[0];
        arr[0] = temp;

        //Move each element to exact bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            int indexBucket = (int)(((double)((numBuckets - 1) * (arr[0] - minValue))) / (temp - minValue));
            std::swap(arr[0], arr[EndOfBucket[indexBucket] - 1]);

            EndOfBucket[indexBucket]--;
            if (++comparisons && EndOfBucket[0] == 0)
                break;
        }

        delete[] EndOfBucket; //Deallocation
    }
    insertionSort(arr, comparisons);
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;
    time = duration.count();
}