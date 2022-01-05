#ifndef __I_PRINT__
#define __I_PRINT__

#include <iostream>

#define TOGGLE_DEBUG_MESSAGES // Comment or uncomment this line in order to active or deactive Debugging Messages, respectively.

#ifdef TOGGLE_DEBUG_MESSAGES
#define DEBUG_MESSAGES std::cout << "DEBUG_MESSAGES ACTIVATED" << std::endl;
#define DEBUG_MESSAGES_BASE_CTOR std::cout << "Base class constructor was called." << std::endl;
#define DEBUG_MESSAGES_BASE_COPY_CTOR std::cout << "Base class copy constructor was called." << std::endl;
#define DEBUG_MESSAGES_BASE_MOVE_CTOR std::cout << "Base class move constructor was called." << std::endl;
#define DEBUG_MESSAGES_BASE_COPY_ASSIGN std::cout << "Base class copy assignment was called." << std::endl;
#define DEBUG_MESSAGES_BASE_MOVE_ASSIGN std::cout << "Base class move assignment was called." << std::endl;
#define DEBUG_MESSAGES_BASE_DTOR std::cout << "Base class destructor was called." << std::endl;
#define DEBUG_MESSAGES_SUB_CTOR std::cout << "Sub class constructor was called." << std::endl;
#define DEBUG_MESSAGES_SUB_COPY_CTOR std::cout << "Sub class copy constructor was called." << std::endl;
#define DEBUG_MESSAGES_SUB_MOVE_CTOR std::cout << "Sub class move constructor was called." << std::endl;
#define DEBUG_MESSAGES_SUB_COPY_ASSIGN std::cout << "Sub class copy assignment was called." << std::endl;
#define DEBUG_MESSAGES_SUB_MOVE_ASSIGN std::cout << "Sub class move assignment was called." << std::endl;
#define DEBUG_MESSAGES_SUB_DTOR std::cout << "Sub class destructor was called." << std::endl;
#define DEBUG_MESSAGES_FUNCTION_CALL std::cout << "Sub Class showInfo() was called." << std::endl;
#define DEBUG_MESSAGES_FUNCTION_CALL_OPERATOR_OVERLOADING os << "DerivedLearningCpp will be displayed." << std::endl;
#define DEBUG_MESSAGES_OPERATOR_OVERLOADING std::cout << "The _<<_ operator was overloaded." << std::endl;
#endif

#ifndef TOGGLE_DEBUG_MESSAGES
#define DEBUG_MESSAGES 
#define DEBUG_MESSAGES_BASE_CTOR
#define DEBUG_MESSAGES_BASE_COPY_CTOR
#define DEBUG_MESSAGES_BASE_MOVE_CTOR
#define DEBUG_MESSAGES_BASE_COPY_ASSIGN
#define DEBUG_MESSAGES_BASE_MOVE_ASSIGN
#define DEBUG_MESSAGES_BASE_DTOR
#define DEBUG_MESSAGES_SUB_CTOR
#define DEBUG_MESSAGES_SUB_COPY_CTOR
#define DEBUG_MESSAGES_SUB_MOVE_CTOR
#define DEBUG_MESSAGES_SUB_COPY_ASSIGN
#define DEBUG_MESSAGES_SUB_MOVE_ASSIGN
#define DEBUG_MESSAGES_SUB_DTOR
#define DEBUG_MESSAGES_FUNCTION_CALL
#define DEBUG_MESSAGES_FUNCTION_CALL_OPERATOR_OVERLOADING
#define DEBUG_MESSAGES_OPERATOR_OVERLOADING
#endif


class I_Print
{
private:
    friend std::ostream& operator<< (std::ostream& os, const I_Print& obj);
public:

    //Pure Virtual Fucntion. This function will be implemented in the sub-class of DerivedLearningCpp
    virtual void print(std::ostream& os) const = 0; 
};

#endif // __I_PRINT__