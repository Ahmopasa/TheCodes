#ifndef EXAMPLE_III
#define EXAMPLE_III

#include <iostream>

int counter{0};

void myFirstVariadicTemplate(){
    std::cout << "/*=====================*/\n";
}

template<typename T, typename...Args>
void myFirstVariadicTemplate(T firstPara, Args... args){

    std::cout << ++counter << ". : " << firstPara << "\n";
    myFirstVariadicTemplate(args...);
}

#endif