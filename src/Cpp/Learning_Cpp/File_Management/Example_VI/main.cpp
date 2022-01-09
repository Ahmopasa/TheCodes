#include <fstream>
#include <iostream>
#include <string>

void getFirstLine(std::fstream& fileHandler, std::string& tempString);
void getWholeTextFile(std::fstream& fileHandler, std::string& tempString);
void getFirstWord(std::fstream& fileHandler, std::string& tempString);
void getWholeTextFile(std::fstream& fileHandler, std::string& tempString, int);
void getFirstChar(std::fstream& fileHandler, char tempChar);
void getCharByChar(std::fstream& fileHandler, char tempChar);

int main()
{
    std::fstream fileHandler{"temp.txt", std::ios::in};
    if (!fileHandler)
    {
        std::cerr << "Such file has been found!\n";
    }
    else
    {
        std::cout << "IT IS OPEN NOW!\n";
        std::string tempString;
        // getFirstLine(fileHandler, tempString);
        // getWholeTextFile(fileHandler, tempString);
        // getFirstWord(fileHandler, tempString);
        // getWholeTextFile(fileHandler, tempString, 2);
         char c{};
        // getFirstChar(fileHandler, c);
         getCharByChar(fileHandler, c);
    }
}

void getFirstLine(std::fstream& fileHandler, std::string& tempString)
{
    std::getline(fileHandler, tempString);
    std::cout << "Word: " << "[" << tempString << "]\n";
}
void getWholeTextFile(std::fstream& fileHandler, std::string& tempString)
{
    while (std::getline(fileHandler, tempString))
    {
        std::cout << "Word: " << "[" << tempString << "]\n";
    }   
}
void getFirstWord(std::fstream& fileHandler, std::string& tempString)
{
    fileHandler >> tempString;
    std::cout << "Word: " << "[" << tempString << "]\n";
}
void getWholeTextFile(std::fstream& fileHandler, std::string& tempString, int )
{
    while (fileHandler >> tempString)
    {
        std::cout << "Word: " << "[" << tempString << "]\n";
    }   
}
void getFirstChar(std::fstream& fileHandler, char tempChar)
{
    fileHandler >> tempChar;
    std::cout << "Word: " << "[" << tempChar << "]\n";
}
void getCharByChar(std::fstream& fileHandler, char tempChar)
{
    while (fileHandler >> tempChar)
    {
        std::cout << "Word: " << "[" << tempChar << "]\n";
    }
}



