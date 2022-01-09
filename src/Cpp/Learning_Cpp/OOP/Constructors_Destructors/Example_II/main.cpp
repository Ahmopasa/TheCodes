#include "Myclass.h"

int main()
{
    Myclass class_1{};
    class_1.print(); // NoName & 18
    
    Myclass class_2{25, "Merve"};
    class_2.print(); // Merve & 25
    
    Myclass class_3{27, "Ahmet"};
    class_3.print(); // Ahmet & 27
    
    Myclass class_4{};
    class_4.print(); // NoName & 18
    
    std::cout << "***********\n";
    class_4 = class_3 = class_2;
    //class_4 = class_3;
    //class_4.operator=(class_3.operator=(class_2));
    std::cout << "***********\n";
    class_4.print();
    class_3.print();
    class_2.print();

    return 0;
}

/*
Name: NoName
Age : 18
Parameterized Ctor was called.
Name: Merve
Age : 25
Parameterized Ctor was called.
Name: Ahmet
Age : 27
Name: NoName
Age : 18
***********
Overloaded operator= was called.
Overloaded operator= was called.
***********
Name: Merve
Age : 25
Name: Merve
Age : 25
Name: Merve
Age : 25
*/