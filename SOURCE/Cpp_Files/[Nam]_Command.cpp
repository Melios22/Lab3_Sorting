#include "../Header_Files/All.h"

//Handle Command 1
void Command_1 (Task task)
{
    //Open file to read
    ifstream ifs;
    ifs.open(task.inFile);
    if (!ifs.is_open())
    {
        cout << "Error: Cannot open file!" << "\n";
        return;
    }

    //Read size of array
    int size;
    ifs >> size;

    //Read array
    vector<int> arr = vector<int>(size);
    for (int i = 0; i < size; ++i)
        ifs >> arr[i];

    //Close file
    ifs.close();

    //Print some initial information to console screen
    task.inSize = size;
    printCmd(task);

    //Measure time - comparisons
    int comparisons; double time;
    Algo_Measuring[task.indexAlgo1](arr, comparisons, time);

    //Print measured data(s) to console screen
    print2Terminal_a(comparisons, time, task.outPara);

    //Export array
    exportArrayToFile(arr, "output.txt");
}

//Handle Command 3
void Command_3 (Task task)
{
    //Generate four types of array
    vector<int> arr_1 = vector<int> (task.inSize);
    GenerateData(&arr_1[0], task.inSize, 0);
    vector<int> arr_2 = vector<int> (task.inSize);
    GenerateData(&arr_2[0], task.inSize, 3);
    vector<int> arr_3 = vector<int> (task.inSize);
    GenerateData(&arr_3[0], task.inSize, 1);
    vector<int> arr_4 = vector<int> (task.inSize);
    GenerateData(&arr_4[0], task.inSize, 2);

    //Export arrays into 4 files
    exportArrayToFile(arr_1, "input_1.txt");
    exportArrayToFile(arr_2, "input_2.txt");
    exportArrayToFile(arr_3, "input_3.txt");
    exportArrayToFile(arr_4, "input_4.txt");

    //Print some initial information to console screen
    printCmd(task);

    //Randomed array
    cout << "Input order: Randomize" << "\n";
    printBreakLine();

    //Nearly sorted array
    cout << "Input order: Nearly Sorted" << "\n";
    printBreakLine();

    //Sorted array
    cout << "Input order: Sorted" << "\n";
    printBreakLine();

    //Reverse array
    cout << "Input order: Reversed" << "\n";
    printBreakLine();

}