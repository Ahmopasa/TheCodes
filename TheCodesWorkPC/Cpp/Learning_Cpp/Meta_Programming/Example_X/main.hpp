#ifndef EXAMPLE_X
#define EXAMPLE_X

#include <iostream>
#include <string>
#include <memory>
#include <type_traits>

void ValidateChar(const char& tempChar)
{
    std::cout << "ValidateChar() was called. The Variable : " << tempChar << std::endl;
}

void ValidateInt(const int& tempInt)
{
    std::cout << "ValidateInt() was called. The Variable : " << tempInt << std::endl;
}

void ValidateString(const std::string& tempString)
{
    std::cout << "ValidateString() was called. The Variable : " << tempString << std::endl;
}

template<typename T>
void ValidateData(T& variable)
{
    std::cout << "Data Validation Started...\n" << std::endl;

    if constexpr (std::is_same<T, char>::value) 
    {
        std::cout << "It is a char.\nRelated function will be called..." << std::endl;
        ValidateChar(variable);
    }

    if constexpr (std::is_same<T, int>::value) 
    {
        std::cout << "It is a int.\nRelated function will be called..." << std::endl;
        ValidateInt(variable);
    }

    if constexpr (std::is_same<T, std::string>::value) 
    {
        std::cout << "It is a std::string.\nRelated function will be called..." << std::endl;
        ValidateString(variable);
    }

    std::cout << "Data Validation Ended...\n" << std::endl;
}

#endif