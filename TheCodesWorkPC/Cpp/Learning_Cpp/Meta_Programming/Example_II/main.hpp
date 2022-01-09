#ifndef EXAMPLE_II
#define EXAMPLE_II

/* # TYPE-DEDUCTION #
    - firstParam is no longer 'const' if the passed parameter is 'const'.
    - firstParam is no longer 'referance' if the passed parameter is 'reference'.
    - firstParam is no longer 'const-reference' if the passed parameter is 'const-reference'. 
*/

#include <iostream>

template<typename T>
void myFirstTemplateFunction(T firstParam){
    std::cout << __PRETTY_FUNCTION__;
    std::cout << ", First Parameter : " << firstParam << " ]\n";
}

template<typename T>
void mySecondTemplateFunction(const T firstParam){
    std::cout << __PRETTY_FUNCTION__;
    std::cout << ", First Parameter : " << firstParam << " ]\n";
}

template<typename T>
void myThirdTemplateFunction(T& firstParam){
    std::cout << __PRETTY_FUNCTION__;
    std::cout << ", First Parameter : " << firstParam << " ]\n";
}

template<typename T>
void myFourthTemplateFunction(const T& firstParam){
    std::cout << __PRETTY_FUNCTION__;
    std::cout << ", First Parameter : " << firstParam << ", Type Name : " << typeid(firstParam).name() << "\n";
}

template<typename T>
void myFifthTemplateFunction(T&& firstParam){
    std::cout << __PRETTY_FUNCTION__;
    std::cout << ", First Parameter : " << firstParam << ", Type Name : " << typeid(firstParam).name() << "\n";
}

#endif