#include "../Header_Files/All.h"

vector<int> arr2Vec(int *arr, int n)
{
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        vec[i] = arr[i];
    return vec;
}

int SearchAlgorithm(vector<string> Algo, string target)
{
    int left = 0;
    int right = Algo.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (Algo[mid] == target)
            return mid;
        else if (Algo[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

bool isNum(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] < '0' || '9' > str[i])
            return false;
    return true;
}

string title(char *str)
{
    string s = str;
    s[0] -= 32;
    size_t found = s.find("-");

    while (found != string::npos)
    {
        s[found] = ' ';
        if (found + 1 < s.length())
            s[found + 1] -= 32;
        found = s.find('-', found + 1);
    }
    return s;
}

bool supportAlgorithm(string algo)
{
    for (int i = 0; i < Algo.size(); i++)
        if (algo == Algo[i])
            return true;
    return false;
}
bool checkVailidity(Task task)
{
    if (!supportAlgorithm(task.al1))
    {
        cout << "\nAlgorithm " << task.al1 << " is not supported!\n";
        return false;
    }
    else if (task.mode == "-c" && !supportAlgorithm(task.al2))
    {
        cout << "\nAlgorithm " << task.al2 << " is not supported!\n";
        return false;
    }

    if ((task.command == 1 || task.command == 3) && task.outPara != "-time" && task.outPara != "-comp" && task.outPara != "-both")
    {
        cout << "\nWrong output parameter!!!\n";
        return false;
    }
    if ((task.command == 2 || task.command == 5) && task.inOrder != "-rand" && task.inOrder != "-nsorted" && task.inOrder != "-sorted" && task.inOrder != "-rev")
    {
        cout << "\nWrong input order!!!\n";
        return false;
    }

    return true;
}

bool getInfo4(int argc, char *argv[], Task &task)
{
    task.mode = argv[1];

    if (task.mode != "-a" && task.mode != "-c") // Wrong format
        return false;

    if (task.mode == "-a")
    {
        task.al1 = title(argv[2]);
        task.indexAlgo1 = SearchAlgorithm(Algo, task.al1);
        task.al2 = "";
        task.indexAlgo2 = -1;
        if (argc == 5)
        {
            if (!isNum(argv[3])) // Check for using file or not
            {
                task.command = 1;
                task.useFile = true;
                task.inFile = argv[3];
            }
            else
            {
                task.command = 3;
                task.inSize = atoi(argv[3]);
            }
            task.outPara = argv[4];
        }
        else
        {
            task.command = 2;
            task.inSize = atoi(argv[3]);
            task.inOrder = argv[4];
            task.outPara = argv[5];
        }
    }
    else
    {
        task.al1 = title(argv[2]);
        task.indexAlgo1 = SearchAlgorithm(Algo, task.al1);
        task.al2 = title(argv[3]);
        task.indexAlgo2 = SearchAlgorithm(Algo, task.al2);
        if (argc == 5)
        {
            task.command = 4;
            task.useFile = true;
            task.inFile = argv[4];
        }
        else
        {
            task.command = 5;
            task.inSize = atoi(argv[4]);
            task.inOrder = argv[5];
        }
    }

    return checkVailidity(task);
}

void printBreakLine()
{
    cout << "-------------------------------------------------\n";
}

void printInputOrder(Task task)
{
    if (task.inOrder == "-rand")
        cout << "Input order: Randomize"
             << "\n";
    else if (task.inOrder == "-nsorted")
        cout << "Input order: Nearly Sorted"
             << "\n";
    else if (task.inOrder == "-sorted")
        cout << "Input order: Sorted"
             << "\n";
    else
        cout << "Input order: Reversed"
             << "\n";
}

void printCmd(Task task)
{
    switch (task.command)
    {
    case 1:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printBreakLine();
        break;
    case 2:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printInputOrder(task);
        printBreakLine();
        break;
    case 3:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n\n";
        break;
    case 4:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printBreakLine();
        break;
    case 5:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printInputOrder(task);
        printBreakLine();
        break;
    }
}

// Some secondary functions
void exportArrayToFile(vector<int> arr, string file_output)
{
    // Open file to write
    ofstream ofs;
    ofs.open(file_output);
    if (!ofs.is_open())
    {
        cout << "Error: Cannot open file!"
             << "\n";
        return;
    }

    // Write array into file
    int size = arr.size();
    ofs << size << "\n";
    for (int i = 0; i < size; ++i)
        ofs << arr[i] << " ";

    // Close file
    ofs.close();
}

void print2Terminal_a(long long comparisons, double time, string requires)
{
    if (requires == "-time")
        cout << "Running time: " << time << " ms"
             << "\n";
    else if (requires == "-comp")
        cout << "Comparisons: " << comparisons << "\n";
    else if (requires == "-both")
    {
        cout << "Running time: " << time << " ms"
             << "\n";
        cout << "Comparisons: " << comparisons << "\n";
    }
    cout << "\n";
}

void print2Terminal_c(long long comparisons_1, long long comparisons_2, double time_1, double time_2)
{
    std::cout << "Running time: " << time_1 << " ms | " << time_2 << " ms"
              << "\n";
    std::cout << "Comparisons: " << comparisons_1 << " | " << comparisons_2
              << "\n";
    std::cout << "\n";
}