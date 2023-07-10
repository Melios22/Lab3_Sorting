#include "../Header_Files/All.h"

void Command_2(Task task)
{
    int n = task.inSize;
    int *array = new int[n];
    if (task.inOrder == "-rand")
        GenerateRandomData(array, n);
    if (task.inOrder == "-sorted")
        GenerateSortedData(array, n);
    if (task.inOrder == "-nsorted")
        GenerateNearlySortedData(array, n);
    if (task.inOrder == "-rev")
        GenerateReverseData(array, n);

    vector<int> arr = arr2Vec(array, n); //? Convert to vector
    exportArrayToFile(arr, "input.txt");        //? Write down the input to input.txt
    delete[] array;

    int comparisons = 0; //? Number of comparisions
    double time = 0;     //? Running time

    /*
        if (task.al1 == "heap-sort")
            todo: heapSort(arr, comparisons, time);
        else if (task.al1 == "merge-sort")
            todo: mergeSort(arr,comparisons, time);
        else if (task.al1 == "radix-sort")
            todo: radixSort(arr, comparisons, time);

        else if (task.al1 == "shell-sort")
            todo: shellSort(arr, comparisons, time);
        else if (task.al1 == "quick-sort")
            todo: quickSort(arr, comparisons, time);
        else if (task.al1 == "counting-sort")
            todo: countingSort(arr, comparisons, time);

        else if (task.al1 == "shaker-sort")
            todo: shakerSort(arr, comparisons);
        else if (task.al1 == "flash-sort")
            todo: flashSort(arr, comparisons);

        else if (task.al1 == "selection-sort")
            todo: selectionSort(arr, comparisons);
        else if (task.al1 == "bubble-sort")
            todo: bubbleSort(arr, comparisons);
        else if (task.al1 == "insertion-sort")
            todo: insertionSort(arr, comparisons);
    */

    //! print the output
    print2Terminal_a(comparisons, time, task.outPara);
}
