#ifndef Command_h
#define Command_h

#include "Library.h"

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

vector<int> arr2Vec(int *arr, int n);
int SearchAlgorithm (vector<string> Algo, string target);
bool isNum(char *str);
bool supportAlgorithm(string algo);
bool checkVailidity(Task task);
bool getInfo4(int argc, char *argv[], Task &task);
void printBreakLine();
void printInputOrder(Task task);
void printCmd(Task task);
void print2Terminal_a(int comparisons, double time, string requires);
void print2Terminal_c(int comparisons_1, int comparisons_2, double time_1, double time_2);
void exportArrayToFile(vector<int> arr, string file_output);

void Command_1(Task task);
void Command_2(Task task);
void Command_3(Task task);
void Command_4(Task task);
void Command_5(Task task);

#endif