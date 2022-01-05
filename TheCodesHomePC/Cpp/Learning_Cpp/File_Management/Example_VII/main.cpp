#include <fstream>
#include <iostream>
#include <string>

template<typename U, typename T>
int readFromStream(U oChar, T& oHandler = std::cin)
{
    static int counter = 0;
    while (oHandler >> oChar)
    {
        std::cout << "[" << oChar << "]\n";
        ++counter;    
    }
    return counter;
}

int main()
{   
    std::fstream fileHandler{"temp.txt", std::ios::in};
    char c{};
    auto wordCount = readFromStream(c, fileHandler);
    std::cout << "Number of Words: " << wordCount << "\n";
    auto wordCount = readFromStream(c, std::cin);
    std::cout << "Number of Words: " << wordCount << "\n";
}

