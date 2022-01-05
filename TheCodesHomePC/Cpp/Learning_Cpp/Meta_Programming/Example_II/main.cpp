#include "main.hpp"


int main(){
    std::cout << "\n # Variable Definitions # \n";
    int x{100};
    const int cx{101};
    int& rx{x};
    const int& crx{cx};

    std::cout << "\n # myFirstTemplateFunction(T firstParam) # \n";
    // void myFirstTemplateFunction(T firstParam){ //... }
    myFirstTemplateFunction(x); //   void myFirstTemplateFunction(T) [with T = int], First Parameter : 100 ]
    myFirstTemplateFunction(cx); //  void myFirstTemplateFunction(T) [with T = int], First Parameter : 101 ]
    myFirstTemplateFunction(rx); //  void myFirstTemplateFunction(T) [with T = int], First Parameter : 100 ]
    myFirstTemplateFunction(crx); // void myFirstTemplateFunction(T) [with T = int], First Parameter : 101 ]

    std::cout << "\n # mySecondTemplateFunction(const T firstParam) # \n";
    // void mySecondTemplateFunction(const T firstParam){ //... }
    mySecondTemplateFunction(x); //   void mySecondTemplateFunction(T) [with T = int], First Parameter : 100 ]
    mySecondTemplateFunction(cx); //  void mySecondTemplateFunction(T) [with T = int], First Parameter : 101 ]
    mySecondTemplateFunction(rx); //  void mySecondTemplateFunction(T) [with T = int], First Parameter : 100 ]
    mySecondTemplateFunction(crx); // void mySecondTemplateFunction(T) [with T = int], First Parameter : 101 ]

    std::cout << "\n # myThirdTemplateFunction(T& firstParam) # \n";
    // void myThirdTemplateFunction(T& firstParam){ //... }
    myThirdTemplateFunction(x); //   void myThirdTemplateFunction(T&) [with T = int], First Parameter : 100 ]
    myThirdTemplateFunction(cx); //  void myThirdTemplateFunction(T&) [with T = const int], First Parameter : 101 ]
    myThirdTemplateFunction(rx); //  void myThirdTemplateFunction(T&) [with T = int], First Parameter : 100 ]
    myThirdTemplateFunction(crx); // void myThirdTemplateFunction(T&) [with T = const int], First Parameter : 101 ]

    std::cout << "\n # myFourthTemplateFunction(const T& firstParam) # \n";
    // void myFourthTemplateFunction(const T& firstParam){ //... }
    myFourthTemplateFunction(x); //   void myFourthTemplateFunction(const T&) [with T = int], First Parameter : 100 ]
    myFourthTemplateFunction(cx); //  void myFourthTemplateFunction(const T&) [with T = int], First Parameter : 101 ]
    myFourthTemplateFunction(rx); //  void myFourthTemplateFunction(const T&) [with T = int], First Parameter : 100 ]
    myFourthTemplateFunction(crx); // void myFourthTemplateFunction(const T&) [with T = int], First Parameter : 101 ]
    myFourthTemplateFunction(31); // void myFourthTemplateFunction(const T&) [with T = int], First Parameter : 31, Type Name : i

    std::cout << "\n # myFifthTemplateFunction(T&& firstParam) # \n";
    // void myFifthTemplateFunction(T&& firstParam){ //... }
    myFifthTemplateFunction(x); //   void myFifthTemplateFunction(T&&) [with T = int&], First Parameter : 100 ]
    myFifthTemplateFunction(cx); //  void myFifthTemplateFunction(T&&) [with T = const int&], First Parameter : 101 ]
    myFifthTemplateFunction(rx); //  void myFifthTemplateFunction(T&&) [with T = int&], First Parameter : 100 ]
    myFifthTemplateFunction(crx); // void myFifthTemplateFunction(T&&) [with T = const int&], First Parameter : 101 ]
    myFifthTemplateFunction(31); // void myFifthTemplateFunction(T&&) [with T = int], First Parameter : 31, Type Name : i

}