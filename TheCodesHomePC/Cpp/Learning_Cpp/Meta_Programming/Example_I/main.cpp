#include "main.hpp"

int main(){

    std::cout << "====================================================\n";
    int x{100};
    myFirstTemplateFunction(x);
    std::cout << "After [ myFirstTemplateFunction(x) ] => " << x << "\n";
    std::cout << "====================================================\n";
    mySecondTemplateFunction(x);
    std::cout << "After [ mySecondTemplateFunction(x) ] => " << x << "\n";
    std::cout << "====================================================\n";
    myThirdTemplateFunction(x);
    std::cout << "After [ myThirdTemplateFunction(x) ] => " << x << "\n";
    std::cout << "====================================================\n";
    myFourthTemplateFunction(x);
    std::cout << "After [ myFourthTemplateFunction(x) ] => " << x << "\n";
    std::cout << "====================================================\n";
    return 0;
}