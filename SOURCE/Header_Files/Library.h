#ifndef Library_h
#define Library_h

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
    string mode;     // "-a", "-c" for compare or perform algo
    string al1, al2; // Algorithm mentioned
    int indexAlgo1, indexAlgo2; //Index of each algorithm in Algo array
    string inFile;   // Input file
    string outPara;  // output parameters: "-time", "-comp", "-both"

    bool useFile = false;
    int inSize;
    string inOrder; // "-rand", "-nsorted", "-sorted", "-rev"
};

typedef void (*MeasureSortingAlgo)(vector<int> &arr, int &comparisons, double &time);

#endif