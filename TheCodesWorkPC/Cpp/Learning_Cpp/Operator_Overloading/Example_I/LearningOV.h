#pragma warning(disable:4996)

/*
	* In this program, operator overloading features of C++ was used for learning purposes.
	* Additionally, Constructors, destructors, copy and move semantics features of C++ were used.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

class LearningCpp
{
public:
	static unsigned int ctrConstructor;
	static unsigned int ctrCopyConstructor;
	static unsigned int ctrCopyAssignment;
	static unsigned int ctrMoveConstructor;
	static unsigned int ctrMoveAssignment;


	//Constructor
	LearningCpp(const char* tempA = "NoName", int tempX = 0, double tempY = 0.0) : a{nullptr}, x { tempX }, y{ tempY }
	{
		std::cout << "Constructor was called. A new object came to life at the address of : " << this << std::endl;
		if (tempA)
		{
			a = new char[std::strlen(tempA) + 1];
			std::strcpy(a, tempA);
		}

		++ctrConstructor;
	}
	//Deconstructor
	~LearningCpp()
	{
		std::cout << "Deconstructor was called. The life of the object at the address of : " << this << " has ended." << std::endl;
		delete[] a;
		a = nullptr;
	}
	//Copy Constructor
	LearningCpp(const LearningCpp& src)
	{
		std::cout << "Copy constructor was called. A new object came to life at the address of : " << this << " using the object at the " << &src << std::endl;
		this->a = new char[std::strlen(src.a) + 1];
		std::strcpy(this->a, src.a);

		this->x = src.x;
		this->y = src.y;

		++ctrCopyConstructor;
	}
	//Copy Assignment
	LearningCpp& operator = (const LearningCpp& src)
	{
		std::cout << "The operator \"=\" was overloaded to assign the object at the " << this << " using the object at the " << &src << std::endl;
		if (this == &src)
		{
			return *this;
		}
		delete[] this->a;
		this->a = new char[std::strlen(src.a) + 1];
		std::strcpy(this->a, src.a);

		this->x = src.x;
		this->y = src.y;

		++ctrCopyAssignment;

		return *this;
	}
	//Move Constructor
	LearningCpp(LearningCpp&& src) noexcept
	{
		std::cout << "Move Constructor was called. From " << &src << " to " << this << std::endl;
		this->a = std::move(src.a);
		src.a = nullptr;

		src.x = 0;
		src.y = 0.;

		this->x = src.x;
		this->y = src.y;

		++ctrMoveConstructor;
	}
	//Move Assingment
	LearningCpp& operator = (LearningCpp&& src) noexcept
	{
		std::cout << "The operator \"=\" was overloaded to move the object from " << &src << " to " << this << std::endl;
		if (&src == this)
		{
			return *this;
		}

		delete[] this->a;

		this->a = std::move(src.a);
		src.a = nullptr;

		this->x = src.x;
		src.x = 0;

		this->y = src.y;
		src.y = 0.;

		++ctrMoveAssignment;

		return *this;
	}

	//Overloading operator<<
	friend std::ostream& operator<< (std::ostream& output, const LearningCpp& src)
	{
		output << "char*  a => " << src.a << std::endl << "int    x => " << src.x << std::endl << "double y => " << src.y << std::endl;
		return output;
	}

	//Overloading operator>>
	friend std::istream& operator>> (std::istream& input, LearningCpp& src)
	{
		std::cout << "Please, enter an integer : ";
		input >> src.x;
		std::cout << "Please, enter a double   : ";
		input >> src.y;
		std::cout << "Please, enter a string   : ";
		src.a = new char[20];
		input >> src.a;
		return input;
	}
    //Overloading operator==
    bool operator==(const LearningCpp& rhs)const
    {
        return !std::strcmp(this->a, rhs.a) && this->x == rhs.x && this->y == rhs.y;       
    }

    //Overloading operator+
    LearningCpp operator+(const LearningCpp& rhs)
    {
        char* buff = new char[std::strlen(this->a) + std::strlen(rhs.a) + 1];

        std::strcpy(buff, this->a);
        std::strcat(buff, rhs.a);

        LearningCpp tempObj{buff};
        delete[] buff;

        tempObj.x = this->x + rhs.x;
        tempObj.y = this->y + rhs.y;
        
        return tempObj;
    }

    //Overloading operator-
    LearningCpp operator-()const
    {
        char* buff = new char[std::strlen(this->a) + 1];

        std::strcpy(buff, this->a);

        for (size_t i = 0; i < buff[i] != '\0'; i++)
        {
            buff[i] = std::tolower(buff[i]);
        }

        int tempX = -(this->x);
        double tempY = -(this->y);

        LearningCpp tempObj{this->a, tempX, tempY};

        return tempObj;
    }

	void showInfo();
private:
	char* a;
	int x;
	double y;
};

std::vector<LearningCpp>& CreateAccount(std::vector<LearningCpp>& myLessons);
void ShowAccount(const std::vector<LearningCpp>& myLessons);