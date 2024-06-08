#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sys/time.h>

#include "Main.h"

std::vector<std::string> Bank;

int Do()
{
    time_t Seed;
    srand(time(&Seed));
    int Q = rand()%26;
    std::cout << "What is '" << Bank[Q] << "'? >";
    std::string A;
    std::cin >> A;
    std::transform(A.begin(), A.end(), A.begin(), ::toupper);
    if (encryptionMap[A] == Bank[Q])
    {
        std::cout << "Good!\n\n";
        return 1;
    }
    else
        std::cout << "Wrong! Answer: " << decryptionMap[Bank[Q]] << "\n\n";
    return 0;
}

int main()
{
    for (int i,p = 0; i < 26; i++)
    {
        std::string Question;
        if(i%2 == 0)
            p++;
        Question += (p + 'A' - 1);
        Question += std::to_string(i%2);
        Bank.push_back(Question);
    }

    std::cout << "[JEL - Pratice]\n";
    int Max, Score;
    std::cout << "How many question you want challenge? >";
    std::cin >> Max;
    for (int i = 0; i < Max; i++)
    {
        std::cout << "[Q" << i+1 << "/" << Max << "]";
        std::cout << "[Score:" << Score << "] ";
        Score += Do();
    }
    
    std::cout << "Pratice over! Your final score is " << Score << "\n";
    std::cout << "Accuracy: " << float(Score)/float(Max)*100.f << "%\n";
}