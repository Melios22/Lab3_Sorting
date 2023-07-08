#pragma once

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <chrono>

// Namespaces
using namespace std;

// Structures
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

// Global variables
vector<string> Algo = {"selection-sort", "insertion-sort", "bubble-sort",
                       "shaker-sort", "shell-sort", "heap-sort", "merge-sort",
                       "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
