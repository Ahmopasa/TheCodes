#include <iostream>
#include <string>
#include <cstring>

void GreedUser(void);

class LearningCpp
{
public:
    // Default Constructor
    LearningCpp(int size = 256, int tempAge = 0, double tempScore = 0.0): name{new char[size]}, age{tempAge}, score{tempScore}, homeAddress{" "}
    {
        std::cout << "Constructor of base class, was called. The Address : " << this << std::endl;
        std::memset(name,'\0', size);
    }

    // Copy Constructor
    LearningCpp(const LearningCpp& other)
    {
        std::cout << "Copy Constructor of base class, was called. The Address : " << this << std::endl;

        this->name = new char[std::strlen(other.name) + 1];
        std::memcpy(this->name, other.name, std::strlen(other.name) + 1);

        this->age = other.age;
        this->score = other.score;
        this->homeAddress = other.homeAddress;
    }

    // Copy Assignment
    LearningCpp& operator=(const LearningCpp& other)
    {
		std::cout << "In the base class, the operator (=) was overloaded to assign the object at the " << this << " using the object at the " << &other << std::endl;
		if (this == &other)
		{
			return *this;
		}

		if (this->name)
        {
           delete[] this->name;
        }
         
		this->name = new char[std::strlen(other.name) + 1];
		std::memcpy(name, other.name, std::strlen(other.name) + 1);

        this->age = other.age;
        this->score = other.score;
        this->homeAddress = other.homeAddress;

		return *this;
    }

    // Move Constructor
    LearningCpp(LearningCpp&& other) : name(std::move(other.name)), age(std::move(other.age)), score(std::move(other.score)), homeAddress(std::move(other.homeAddress))
    {
        std::cout << "Move Constructor of base class, was called. The Address : " << this << std::endl;

        // this->name = std::move(other.name);
		other.name = nullptr;

		// this->age = other.age;
		other.age = 0;

		// this->score = other.score;
		other.score = 0.;

		// this->homeAddress = other.homeAddress;
        other.homeAddress = " ";
    }

    // Move Assignment
    LearningCpp& operator=(LearningCpp&& other)
    {
		std::cout << "In the base class, the operator (=) was overloaded to move the object at the " << this << " using the object at the " << &other << std::endl;
		if (&other == this)
		{
			return *this;
		}

		delete[] this->name;

		this->name = std::move(other.name);
		other.name = nullptr;

		this->age = other.age;
		other.age = 0;

		this->score = other.score;
		other.score = 0.;

		this->homeAddress = other.homeAddress;
        other.homeAddress = " ";

		return *this;
    }

    // Public UI Functions
    void ShowDetails(void)
    {
        std::cout << "Name         : " << name << std::endl;
        std::cout << "Age          : " << age << std::endl;
        std::cout << "Score        : " << score << std::endl;
        std::cout << "Home Address : " << homeAddress << std::endl;
    }

    // Setter & Getter Functions for name
    void setName(const char* tempName)
    {
        std::memcpy(name, tempName, std::strlen(tempName));
    }
    const char* getName(void)
    {
        return name;
    }

    // Setter & Getter Functions for age
    void setAge(const int tempAge)
    {
        age = tempAge;
    }
    const int getAge(void)
    {
        return age;
    }

    // Setter & Getter Functions for score
    void setScore(const double tempScore)
    {
        score = tempScore;
    }
    const double getScore(void)
    {
        return score;
    }

    // Setter & Getter Functions for homeAddress
    void setHomeAddress(const std::string& tempHome)
    {
        homeAddress = tempHome;
    }
    std::string& getHomeAddress(void)
    {
        return homeAddress;
    }

    // Destructor
    ~LearningCpp()
    {
        delete[] name;
        name = nullptr;
        age = 0;
        score = 0.0;
    }

protected:
    std::string homeAddress;

private:
    char* name;
    int age;
    double score;
};

class DerivedLearningCpp : public LearningCpp
{
public:
    // Constructor
    DerivedLearningCpp(const char* tempName = "NoNameYet", int tempAge = 18, double tempScore = 0.0, std::string tempAddress = "NoAddressYet") : LearningCpp{}
    {
        std::cout << "Constructor of derived class, was called." << std::endl;

        LearningCpp::setName(tempName);
        LearningCpp::setAge(tempAge);
        LearningCpp::setScore(tempScore);
        homeAddress = tempAddress;

        ++counter;
    }

    // Copy Constructor
    DerivedLearningCpp(const DerivedLearningCpp& other) : LearningCpp{other}
    {
        std::cout << "Copy Constructor of sub class, was called. The Address : " << this << std::endl;

        ++counter;
    }

    // Copy Assignment
    DerivedLearningCpp& operator=(const DerivedLearningCpp& other)
    {
        std::cout << "In the sub class, the operator (=) was overloaded to assign the object at the " << this << " using the object at the " << &other << std::endl;
        if (this == &other)
        {
            return *this;
        }

        LearningCpp::operator=(other);

        return *this;        
    }

    // Move Constructor
    DerivedLearningCpp(DerivedLearningCpp&& other) noexcept : LearningCpp{std::move(other)}
    {
        std::cout << "Move Constructor of sub class, was called. The Address : " << this << std::endl;
        
    }

    // Move Assignment
    DerivedLearningCpp& operator=(DerivedLearningCpp&& other) noexcept
    {
        std::cout << "In the sub class, the operator (=) was overloaded to move the object at the " << this << " from the " << &other << std::endl;

        if (this == & other)
        {
            return *this;
        }
        
        LearningCpp::operator=(std::move(other));
        return *this;
    }

    //Destructor
    ~DerivedLearningCpp()
    {
        std::cout << "Destructor of sub class was called. Total of " << --counter << " amount object is alive." << std::endl;
    }

    void ShowDetails(void)
    {
        LearningCpp::ShowDetails();
        std::cout << "There are " << counter << " amount of DerivedLearningCpp type object." << std::endl;
    }
    
public:
    static int counter;
};