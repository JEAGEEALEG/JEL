#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "Main.h"

void Decode()
{
    std::string Pass;
    std::string Word;
    std::cout << "Enter ciphertext >";
    std::cin >> Pass;
    std::cin >> Word;

    std::transform(Pass.begin(), Pass.end(), Pass.begin(), ::toupper);
    std::transform(Word.begin(), Word.end(), Word.begin(), ::toupper);

    std::string Password;
    if(Pass.length() != Word.length())
        return;
    for (int i = 0; i < Pass.length(); i++)
    {
        Password += Pass.at(i); 
        Password += Word.at(i);
    }

    std::vector<std::string> Pw;
    for (int i = 0; i < Password.length(); i += 2)
    {        
        std::string Temp;
        Temp += Password[i];
        Temp += Password[i+1];
        Pw.push_back(Temp);
    }

    std::string Output;
    for (int i = 0; i < Pw.size(); i++)
    {
        Output += decryptionMap[Pw[i]];
    }
    
    std::cout << Output << std::endl;
}

void Encode()
{
    std::string Pass;
    std::cout << "Enter text that you want encode >";
    std::cin >> Pass;

    std::transform(Pass.begin(), Pass.end(), Pass.begin(), ::toupper);

    std::vector<std::string> Pw;
    for (int i = 0; i < Pass.length(); i ++)
    {
        std::string Temp;
        Temp += Pass[i];
        Pw.push_back(Temp);
    }

    std::string Output;
    for (int i = 0; i < Pw.size(); i++)
    {
        Output += encryptionMap[Pw[i]].substr(0,1);
    }
    Output += " ";
    for (int i = 0; i < Pw.size(); i++)
    {
        Output += encryptionMap[Pw[i]].substr(1,1);
    }
    
    std::cout << Output << std::endl;
}

int main()
{
    char Choose = 'a';
    while (Choose != 'E' && Choose != 'D')
    {
        const char aWelcome[] =
        {
            "[JEL]\n"
            "Encode or Decode?\n"
            "$[E/D] >"
        };
        std::cout << aWelcome;
        std::cin >> Choose;
    }

    if(Choose == 'E')
        Encode();
    else
        Decode();
    return 0;
}
