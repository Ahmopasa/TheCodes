#include "LearningCpp.h"

int main()
{
    GreedUser();

    // std::cout << "#######################################" << std::endl;
    // LearningCpp student_1{}; // Base Constructor was called.
    // student_1.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_2{};// First, base consttructor was called. Then sub-class constructor was called.
    // student_2.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // std::cout << "#######################################" << std::endl;
    // LearningCpp student_3{128, 25, 85};
    // student_3.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_4{"Merve Pehlivanli", 25, 70, "Sultangazi"};
    // student_4.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // std::cout << "#######################################" << std::endl;
    
    // std::cout << "#######################################" << std::endl;
    // LearningCpp student_1{}; //Constructor was called.
    // LearningCpp student_2{student_1}; //Copy Constructor was called.
    // LearningCpp student_3; //Constructor was called.
    // student_3 = student_2; //Copy Assignment was made.
    // std::cout << "#######################################" << std::endl;
    // LearningCpp student_10{}; //Constructor was called.
    // LearningCpp student_11{std::move(student_10)}; // Move Constructor was called.
    // LearningCpp student_12; //Constructor was called.
    // student_12 = std::move(student_11); // Move Assignment was made.
    // std::cout << "#######################################" << std::endl;

    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_1{}; // First, constructor of base class was called. Then constructor of derived class was called.
    // student_1.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_4{"Merve Pehlivanli", 25, 70, "Sultangazi"}; // First, constructor of base class was called. Then constructor of derived class was called.
    // student_4.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_2{student_4}; // First, copy constructor of base class was called. Then copy constructor of derived class was called.
    // student_2.ShowDetails();
    // std::cout << "#######################################" << std::endl;
    // DerivedLearningCpp student_3; // First, constructor of base class was called. Then constructor of derived class was called.
    // student_3 = student_2; // First, copy assignment of derived class was called. Then copy assignment of base class was called.
    // student_3.ShowDetails();
    // std::cout << "#######################################" << std::endl;

    std::cout << "#######################################" << std::endl;
    DerivedLearningCpp student_1{}; // First, constructor of base class was called. Then constructor of derived class was called.
    student_1.ShowDetails();
    std::cout << "#######################################" << std::endl;
    DerivedLearningCpp student_4{"Merve Pehlivanli", 25, 70, "Sultangazi"}; // First, constructor of base class was called. Then constructor of derived class was called.
    student_4.ShowDetails();
    std::cout << "#######################################" << std::endl;
    DerivedLearningCpp student_2{std::move(student_1)}; // First, move constructor of base class was called. Then move constructor of sub class was called.
    student_2.ShowDetails();
    std::cout << "#######################################" << std::endl;
    DerivedLearningCpp student_3; // First, constructor of base class was called. Then constructor of derived class was called.
    student_3 = std::move(student_4); // First, move assignment of derived class was called. Then move assignment of base class was called.
    student_3.ShowDetails();
    std::cout << "#######################################" << std::endl;
    
    return 0;
}