#include <iostream>

class InputValidator
{
    public:
    template<typename T>
    bool isValid(T& input)
    {
        std::cout << "isValid(T&) was called. The input: " << input << std::endl;    
        return true;
    }
    
    template<typename T>
    bool isValid(const T& input)
    {
        std::cout << "isValid(const T&) was called. The input: " << input << std::endl;    
        return true;
    }
};