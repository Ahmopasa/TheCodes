#include "LearningCpp.h"

int main()
{
    DEBUG_MESSAGES

    DerivedLearningCpp student_1 {"ULYA YURUK", 1, 2.2, "USKUDAR"}; // 1. Base, 2. Sub Constructor Called.
    std::cout << student_1 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_2{"Ahmet Kandemir", 3, 4.4}; // 1. Base, 2. Sub Constructor Called.
    std::cout << student_2 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_3{"Merve", 5}; // 1. Base, 2. Sub Constructor Called.
    std::cout << student_3 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_4{"Aynur"}; // 1. Base, 2. Sub Constructor Called.
    std::cout << student_4 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_5{}; // 1. Base, 2. Sub Constructor Called.
    std::cout << student_5 << std::endl; // Overloaded << operator called.

    std::cout << "====================================\n";

     DerivedLearningCpp student_10 { student_1 }; // 1. Base Copy, 2. Sub Copy Constructor Called.
    std::cout << student_10 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_11{}; // 1. Base, 2. Sub Constructor Called.
    student_11 = student_2; // 1. Sub, 2. Base Copy Assignment Called.
    std::cout << student_11 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_12{ std::move(student_3) }; // 1. Base, 2. Sub Move Constructor Called.
    std::cout << student_12 << std::endl; // Overloaded << operator called.

    DerivedLearningCpp student_13{}; // 1. Base, 2. Sub Constructor Called.
    student_13 = std::move( student_4 ); // 1. Sub, 2. Base Move Assignment Called.
    std::cout << student_13 << std::endl; // Overloaded << operator called.

    std::cout << "====================================\n";

    return 0;
}