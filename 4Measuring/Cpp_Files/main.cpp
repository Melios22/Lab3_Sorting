#include "../Header_Files/All.h"

int main()
{

    Task testcase[11];

    vector<string> order = {"-rand", "-nsorted", "-sorted", "-rev"};

    vector<int> dataSize = {10000, 30000, 50000, 100000, 300000, 500000};

    string fileName = "input2.txt";

    for (char size = 5; size < 6; size++) // this
    {
        std::cout << "\n ///////////////// " << dataSize[size] << " ///////////////////////\n";
        for (char ord = 3; ord < 4; ord++) // this
        {
            for (char i = 0; i < 11; i++) // this
            {
                // if ((i == 0 || i == 4 || i == 8 || i == 9))
                if (i != 0 && i != 4 && i != 9)
                    continue;
                std::cout << "\nT I M E\n";

                std::cout << "\n"
                          << i + 1 << " " << Algo[i] << std::endl;
                testcase[i].inSize = dataSize[size];                    // 0 bubble 1 counting 2 flash
                testcase[i].inOrder = order[ord];                       // 3 heap 4 insertion 5 merge
                testcase[i].command = 2;                                // 6 quick 7 radix 8 select
                testcase[i].indexAlgo1 = i;                             // 9 shaker 10 shell
                testcase[i].al1 = Algo[i];
                testcase[i].outPara = "-time";
                testcase[i].mode = "-a";
                Command_2(testcase[i]);

                std::cout << "\n---------------------\n";
                // std::cout << "\nC O M P A R I S O N\n";

                // testcase[i].command = 1;

                // testcase[i].outPara = "-comp";
                // testcase[i].mode = "-a";
                // testcase[i].inFile = fileName;
                // Command_1(testcase[i]);

                // std::cout << "\n---------------------\n";
            }
        }
        std::cout << "\n ///////////////// " << dataSize[size] << " ///////////////////////\n";
    }
    return 0;
}