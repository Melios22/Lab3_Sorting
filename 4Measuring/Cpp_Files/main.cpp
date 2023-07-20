#include "../Header_Files/All.h"

int main()
{
     
    Task testcase[11];

    vector<string> order = { "-rand", "-nsorted", "-sorted", "-rev" };

    vector<int> dataSize = { 10000, 30000, 50000, 100000, 300000, 500000 };

    string fileName = "input.txt";

    for (char size = 4; size < 6; size++) // this
    {
        std::cout << "\n ///////////////// " << dataSize[size] << " ///////////////////////\n";
        for (char ord = 0; ord < 4 - 3; ord++) // this
        {
            for (char i = 0; i < 11; i++) // this
            {
                std::cout << "\nT I M E\n";

                std::cout <<"\n" <<  i + 1 << " " << Algo[i] << std::endl;
                testcase[i].inSize = dataSize[size]; 
                testcase[i].inOrder = order[ord];
                testcase[i].command = 2;
                testcase[i].indexAlgo1 = i;
                testcase[i].al1 = Algo[i];
                testcase[i].outPara = "-time";
                testcase[i].mode = "-a";
                Command_2(testcase[i]);

                std::cout << "\n---------------------\n";
                std::cout << "\nC O M P A R I S I O N\n";

              
                testcase[i].command = 1;
               
                testcase[i].outPara = "-comp";
                testcase[i].mode = "-a";
                testcase[i].inFile = fileName;
                Command_1(testcase[i]);


                std::cout << "\n---------------------\n";
            }
        }
        std::cout << "\n ///////////////// " << dataSize[size] << " ///////////////////////\n";
    }
    return 0;
}