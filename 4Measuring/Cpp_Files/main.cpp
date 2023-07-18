#include "../Header_Files/All.h"

int main()
{
     
    Task testcase[11];

    vector<string> order = { "-rand", "-nsorted", "-sorted", "-rev" };

    vector<int> dataSize = { 10000, 30000, 50000};
    vector<int> dataSize2 = { 100000, 300000, 500000 };


    for (int size = 0; size < dataSize2.size() - 1; size++)
    {
        std::cout << "\n ////////////////////SIZE////////////////////// \n";
        std::cout << "size : " << dataSize2[size] << std::endl;
        for (int ord = 0; ord < order.size() ; ord++)
        {
            std::cout << "\n /////////////////ORDER/////////////////////// \n";
            std::cout << "order : " << order[ord] << std::endl;
            for (int i = 2; i < 3; i++) // 0 2 4 8 9
            {   
                
                std::cout << i + 1 << " " << Algo[i] << std::endl;
                testcase[i].inSize = dataSize2[size];
                testcase[i].inOrder = order[ord];
                testcase[i].command = 2;
                testcase[i].indexAlgo1 = i;
                testcase[i].al1 = Algo[i];
                testcase[i].outPara = "-both";
                testcase[i].mode = "-a";
                


                Command_2(testcase[i]);
                std::cout << "\n";

            }

            std::cout << "\n ////////////////ORDER////////////////////// \n";
        
        }

        std::cout << "\n ///////////////////SIZE/////////////////// \n";
    }


   
    return 0;

   
}