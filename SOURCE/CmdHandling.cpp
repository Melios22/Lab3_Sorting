#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Task
{
    int command;     // 1, 2, 3, 4, 5
    string mode;      // "-a", "-c" for compare or perform algo
    string al1, al2; // Algorithm mentioned
    string inFile;   // Input file
    string outPara;  // output parameters: "-time", "-comp", "-both"

    bool useFile = false;
    int inSize;
    string inOrder; // "-rand", "-nsorted", "-sorted", "-rev"
};

vector<string> Algo = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};

//! Algorithm
// todo Cmd1: [File] -a [Algorithm] [input file] [Output para]
// todo Cmd2: [File] -a [Algorithm] [input size] [input order] [Output para]
// todo Cmd3: [File] -a [Algorithm] [input size] [Output para]
//! Comparisons
// todo Cmd4: [File] -c [Algo 1] [Algo 2] [input file]
// todo Cmd5: [File] -c [Algo 1] [Algo 2] [input size] [input order]

//! Cmd3 print all 4 case of input order
//! Explanation
//? input size: integer (< 1m)
//? input order: -rand: random data,
//?              -nsorted: nearly sorted,
//?              -sorted: sorted data,
//?              -rev: reverse order
//? input file: 1st line: an integer n
//?             2nd line: n integers, sep = ' '
//? output para: -time: runnning time
//?              -comp: number of comparisons
//?              -both: both

bool isNum(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] < '0' || '9' > str[i])
            return false;
    return true;
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
        task.al1 = argv[2];
        task.al2 = "";
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
                task.inOrder = argv[4];
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
        task.al1 = argv[2];
        task.al2 = argv[3];
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

void printCmd(Task task)
{
    switch (task.command)
    {
    case 1:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "Output parameter: " << task.outPara.substr(1) << "\n";
        cout << "-------------------------------------------------\n";
        break;
    case 2:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        cout << "Input order: " << task.inOrder.substr(1) << "\n";
        cout << "Output parameter: " << task.outPara.substr(1) << "\n";
        cout << "-------------------------------------------------\n";
        break;
    case 3:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        cout << "Output parameter: " << task.outPara.substr(1) << "\n";
        cout << "-------------------------------------------------\n";
        break;
    case 4:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "-------------------------------------------------\n";
        break;
    case 5:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        cout << "Input order: " << task.inOrder.substr(1) << "\n";
        cout << "-------------------------------------------------\n";
        break;
    }
}

int main(int argc, char *argv[])
{
    if (argc > 6)
    {
        cout << "Wrong format!.\nPlease using one of these:\n";
        cout << "[File] -a [Algorithm] [input file] [Output para]\n";
        cout << "[File] -a [Algorithm] [input size] [input order] [Output para]\n";
        cout << "[File] -a [Algorithm] [input size] [Output para]\n";
        cout << "[File] -c [Algo 1] [Algo 2] [input file]\n";
        cout << "[File] -c [Algo 1] [Algo 2] [input size] [input order]\n";
        return 0;
    }

    Task task;
    bool check = getInfo4(argc, argv, task);
    if (!check)
        return 0; // Return 0 for not raising an error

    printCmd(task);

    return 0;
}