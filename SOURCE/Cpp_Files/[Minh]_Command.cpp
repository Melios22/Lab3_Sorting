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

    //Print some initial information to console screen
    printCmd(task);

    //Measure time - comparisons
    int comparisons = 0; double time = 0;
    Algo_Measuring[task.indexAlgo1](arr, comparisons, time);

    //Print measured data(s) to console screen
    print2Terminal_a(comparisons, time, task.outPara);
}
