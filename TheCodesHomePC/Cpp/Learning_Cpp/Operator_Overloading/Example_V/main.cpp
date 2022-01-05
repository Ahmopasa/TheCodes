#include <iostream>

// // Allocate memory using malloc()...
// void* operator new(size_t size)
// {
//     void * m_ptr = malloc(size);
//     std::cout << "[ void* operator new(size_t size) ] was called. Allocated size : " << size << "\n";
//     return m_ptr;
// }
// // Free the memory.
// void operator delete(void* m_ptr)
// {
//     free(m_ptr);
//     m_ptr = nullptr;
//     std::cout << "[ void operator delete(void* m_ptr) ] was called." << "\n";
// }

#define SIZE 10

int myIntArray[SIZE] = {1, 2, 3, 4, 5};

void* operator new[] (size_t size)
{
    std::cout << " [ void* operator new[] (size_t size) ] was called. Size : " << size << "\n";
    return myIntArray;
}

void operator delete[](void* pInt)
{
    std::cout << " [ void operator delete[](void* pInt) ] was called.\n";
    for (size_t i = 0; i < SIZE; i++)
    {
        static_cast<int*>(pInt)[i] /= 100;
    }
}

void print(int* mPtr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i << ". index : " << mPtr[i] << "\n";
    }
}

int main()
{
    int* pInt = new int[SIZE];
    print(pInt, SIZE);

    std::cout << "\n************************\n";

    for (size_t i = 0; i < SIZE; i++)
    {
        pInt[i] = i * 100;
    }
    print(pInt, SIZE);

    std::cout << "\n************************\n";

    delete[] pInt;
    print(pInt, SIZE);

    std::cout << "\n************************\n";


    

}