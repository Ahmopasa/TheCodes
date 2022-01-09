#include "main.hpp"

int main()
{
    std::cout << "/*====== Normal =====*/\n";
    void (*printI)(int x) = print; printI(105);
    void (*printF)(float x) = print; printF(101.1f);
    void (*printD)(double x) = print; printD(202.2);
    std::cout << "/*====== Typedef ====*/\n";
    printITF myIntFuncPtr {print}; myIntFuncPtr(106);
    printFTF myFloatFuncPtr {print}; myFloatFuncPtr(102.2f);
    printDTF myDoubleFuncPtr {print}; myDoubleFuncPtr(203.3);
    std::cout << "/*====== Normal Array */\n";
    void(*printArray[3])(int x) = { printI, printI, printI };
    for (size_t index = 0; index < sizeof(printArray) / sizeof(*printArray); ++index)
    {
        std::cout << index << ". : " << printArray[index] << "\n";
    }
    std::cout << "/*====== Typedef Array */\n";
    printFTF myFloatFuncPtrArray[10] { printF, printF, printF };
    for (size_t index = 0; index < sizeof(myFloatFuncPtrArray) / sizeof(*myFloatFuncPtrArray); ++index)
    {
        std::cout << index << ". : " << myFloatFuncPtrArray[index] << "\n";
    }

    return 0;
}