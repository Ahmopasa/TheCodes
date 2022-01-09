#include "InputValidator.h"
#include "Student.h"

int main() {

    InputValidator inputHandler{};
    
    inputHandler.isValid("Ahmet");
    
    inputHandler.isValid('A');

    inputHandler.isValid(100);
    
    inputHandler.isValid(100.5);
    
    std::string name = "Veli";
    inputHandler.isValid(name);
    
    const std::string maidenName = "Mat";
    inputHandler.isValid(maidenName);
    
    char surname[30] = "Akyol";
    inputHandler.isValid(surname);
    
    const char address[30] = "Istanbul";
    inputHandler.isValid(address);
    
    Student student_1{};    
    inputHandler.isValid(student_1);
    
    const Student student_2{};
    inputHandler.isValid(student_2);
    return 0;
}