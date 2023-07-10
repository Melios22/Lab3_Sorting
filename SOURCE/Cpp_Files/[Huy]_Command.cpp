#include "../Header_Files/All.h"
void Command_5(Task task)
{
    string sortAlgoNo1 = task.al1;
    string sortAlgoNo2 = task.al2;

    int size = task.inSize;
    vector<int> arr1(size);
    vector<int> arr2(size);

    if (task.inOrder == "-rand")
    {
        GenerateRandomData(&arr1, n);
        GenerateRandomData(&arr2, n);

    }
    else if (task.inOrder == "-sorted")
    {
        GenerateSortedData(&arr1, n);
        GenerateSortedData(&arr2, n);

    }
    else if (task.inOrder == "-nsorted")
    {
        GenerateNearlySortedData(&arr1, n);
        GenerateNearlySortedData(&arr2, n);
    }
    else if (task.inOrder == "-rev")
    {
        GenerateReverseData(&arr1, n);
        GenerateReverseData(&arr2, n);

    }

    //comparation
    int comparations1 = 0;
    double time1 = 0.0;

    if (task.al1 == "heap-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        heapSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();
    }
    else if (task.al1 == "merge-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        mergeSort(arr1,0, arr1.size() - 1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();
    }
    else if (task.al1 == "radix-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        radixSort(arr1, comparisons1, 10);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();

    }
    else if (task.al1 == "shell-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        shellSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();
    }
    else if (task.al1 == "quick-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        quickSort(arr1,0, arr1.size() - 1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();
    }
    else if (task.al1 == "counting-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        countingSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();

    }
    else if (task.al1 == "shaker-sort")
    {
       auto startTime = chrono::high_resolution_clock::now();
       shakerSort(arr1, comparisons1);
       auto endTime = chrono::high_resolution_clock::now();

       chrono::duration<double> duration = endTime - startTime;

       time1 = duration.count();
    }
    else if (task.al1 == "flash-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
       flashSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();

    }
    else if (task.al1 == "selection-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        selectionSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();

    }
    else if (task.al1 == "bubble-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        bubbleSort(arr1, comparisons1);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time1 = duration.count();
    }
    else if (task.al1 == "insertion-sort")
    {
         auto startTime = chrono::high_resolution_clock::now();
         insertionSort(arr1, comparisons1);
         auto endTime = chrono::high_resolution_clock::now();

         chrono::duration<double> duration = endTime - startTime;

         time1 = duration.count();
    }


    int comparations2 = 0;
    double time2 = 0.0;
    if (task.al2 == "heap-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        heapSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "merge-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        mergeSort(arr2,0, arr2.size() - 1, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "radix-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        radixSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();

    }
    else if (task.al2 == "shell-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        shellSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "quick-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        quickSort(arr2, 0, arr2.size() - 1, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "counting-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        countingSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();

    }
    else if (task.al2 == "shaker-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        shakerSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "flash-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        flashSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();

    }
    else if (task.al2 == "selection-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        selectionSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();

    }
    else if (task.al2 == "bubble-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        bubbleSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    else if (task.al2 == "insertion-sort")
    {
        auto startTime = chrono::high_resolution_clock::now();
        insertionSort(arr2, comparisons2);
        auto endTime = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = endTime - startTime;

        time2 = duration.count();
    }
    
    printCmd(task);
    print2Terminal_c(comparisons1, comparisons2, time1, time2);


}
