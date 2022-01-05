#ifndef _LEARNING_CPP_
#define _LEARNING_CPP_

#include <string>
#include <cstring>
#include <memory>

#include "I_Print.h"

class LearningCpp : public I_Print// LearningCpp is no longer abstract base class since it overrides a function from I_Print.
{
private:
    char* name;
    int age;
    double score;

protected:
    std::string homeAddress;
public:
    //Constructor with default variables.
    LearningCpp(const char* name = "NoNameYet", int age = 0, double score = 0.0, std::string homeAddress = "NoAddressYet") : name{new char[100]}, age{age}, score{score}, homeAddress{homeAddress}
    {
        DEBUG_MESSAGES_BASE_CTOR 
        memmove(this->name, name, std::strlen(name) + 1);
    }
    //Virtual Destructor.
    virtual ~LearningCpp() // We need to declare this as virtual to achieve polymorphic behaviour successfully.
    {
        DEBUG_MESSAGES_BASE_DTOR
        delete [] this->name;
    }
    //Copy Constructor
    LearningCpp(const LearningCpp& other) : name{ new char[std::strlen(other.name) + 1] }, age{other.age}, score{other.score}, homeAddress{other.homeAddress}
    {
        DEBUG_MESSAGES_BASE_COPY_CTOR

        //this->name = new char[std::strlen(other.name) + 1];
        std::strcpy(this->name, other.name);

        // this->age = other.age;
        // this->score = other.score;
        // this->homeAddress = other.homeAddress;
    }
    //Move Constructor
    LearningCpp(LearningCpp&& other) : name{ other.name }, age{other.age}, score{other.score}, homeAddress{other.homeAddress}
    {
        DEBUG_MESSAGES_BASE_MOVE_CTOR

        //this->name = other.name;
        other.name = nullptr;

        // this->age = other.age;
        // this->score = other.score;
        // this->homeAddress = other.homeAddress;
    }
    //Copy Assignment
    LearningCpp& operator=(const LearningCpp& other)
    {
        DEBUG_MESSAGES_BASE_COPY_ASSIGN

        if (this == &other)
        {
            return *this;
        }
        
        delete[] this->name;
        this->name = new char[std::strlen(other.name) + 1];
        std::strcpy(this->name, other.name);

        this->age = other.age;
        this->score = other.score;
        this->homeAddress = other.homeAddress;


        return *this;
    }
    //Move Assignment
    LearningCpp& operator=(LearningCpp&& other)
    {
        DEBUG_MESSAGES_BASE_MOVE_ASSIGN

        if (this == &other)
        {
            return *this;
        }

        delete[] this->name;
        this->name = std::move(other.name);
        other.name = nullptr;

        this->age = other.age;
        this->score = other.score;
        this->homeAddress = other.homeAddress;


        return *this;
    }
    //Overloading !operator
    LearningCpp& operator!() = delete;
    
    //Pure Virtual Fucntion. Because of that, we cannot instantiate that type of objects. This function will be implemented in the sub-class.
    virtual void showInfo() const = 0; // We have to override it in the sub class. 

    //Getters
    char* getName() const
    {
        return this->name;
    }
    int getAge() const
    {
        return this->age;
    }
    double getScore() const
    {
        return this->score;
    }   

    //Setters
    void setName(const char* tempName) 
    {
        std::strcpy(this->name, tempName);
    }
    void setAge(int tempAge) 
    {
        this->age = tempAge;
    }
    void setScore(double tempScore) 
    {
        this->score = tempScore;
    }
};

class DerivedLearningCpp final : public LearningCpp // final keyword prevents this class to be inherited by sub classes. [It is a concrete class since it overrided a pure virtual function.]
{
private:
    
public:
    //Constructor with default variables.
    DerivedLearningCpp(const char* name = "NoNameYet", int age = 0, double score = 0.0, std::string homeAddress = "NoAddressYet") : LearningCpp{name, age, score, homeAddress}
    {
        DEBUG_MESSAGES_SUB_CTOR
    }
    //Copy constructor
    DerivedLearningCpp(const DerivedLearningCpp& other) : LearningCpp{ other }
    {
        DEBUG_MESSAGES_SUB_COPY_CTOR
    }
    //Copy Assignment
    DerivedLearningCpp& operator=(const DerivedLearningCpp& other)
    {
        DEBUG_MESSAGES_SUB_COPY_ASSIGN
        
        if (this == &other)
        {
            return *this;
        }

        LearningCpp::operator=(other);

        return *this;
    }
    //Move Constructor
    DerivedLearningCpp(DerivedLearningCpp&& other) : LearningCpp{std::move(other)}
    {
        DEBUG_MESSAGES_SUB_MOVE_CTOR
    }
    //Move Assignment
    DerivedLearningCpp& operator=(DerivedLearningCpp&& other)
    {
        DEBUG_MESSAGES_SUB_MOVE_ASSIGN

        if (this == &other)
        {
            return *this;
        }

        LearningCpp::operator=(std::move(other));

        return *this;
    }

    //Virtual Destructor.
    ~DerivedLearningCpp()
    {
        DEBUG_MESSAGES_SUB_DTOR
    }
    //The implementation of showInfo() function, declared as virtual in the base class.
    void showInfo() const override final // Since that function was declared as virtual, we need to override them. We also add final specifier to prevent being overriden by classes derived from this class.
    {
        DEBUG_MESSAGES_FUNCTION_CALL 
        std::cout << "Name : " << getName() << std::endl;
        std::cout << "Age  : " << getAge() << std::endl;
        std::cout << "Score: " << getScore() << std::endl;
        std::cout << "Home Address: " << homeAddress << std::endl;
    }

    void print(std::ostream& os) const override
    {
        DEBUG_MESSAGES_FUNCTION_CALL_OPERATOR_OVERLOADING
        os << "Name         : " << getName() << std::endl;
        os << "Age          : " << getAge() << std::endl;
        os << "Score        : " << getScore() << std::endl;
        os << "Home Address : " << homeAddress << std::endl;
    }
};

#endif