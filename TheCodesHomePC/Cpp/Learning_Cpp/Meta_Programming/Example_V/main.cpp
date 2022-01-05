#include <iostream>
#include <string>
#include <memory>
#include <type_traits>

// class ATM
// {
// private:
//     int m_age{};
//     double m_score{};
//     std::string m_identifier{};
// public:
//     void showMembers(void) const
//     {
//         std::cout << "Identify => " << m_identifier << std::endl;
//         std::cout << "Score    => " << m_score << std::endl;
//         std::cout << "Age      => " << m_age << std::endl;
//     }
// };
// class ATM_Program
// {
// private:
//     int m_totalATMAmount{};
//     ATM m_ATMMachine{};
// public:
//     void showMembers(void) const
//     {
//         std::cout << "Total ATM => " << m_totalATMAmount << std::endl;
//         std::cout << "An ATM consists of following members;" << std::endl;
//         m_ATMMachine.showMembers();
//     }
// };
// template<class T>
// void showTemplateFunction(const T& tempClassRef)
// {
//     tempClassRef.showMembers();
// }
// template<class T>
// void showMetaFunction(const T& tempClassRef)
// {
//     if (std::is_same<T, ATM>::value)
//     {
//         std::cout << "Type is of ATM" << std::endl; 
//         tempClassRef.showMembers();
//     }
//     else if (std::is_same<T,ATM_Program>::value)
//     {
//         std::cout << "Type is of ATM_Program" << std::endl; 
//         tempClassRef.showMembers();
//     }
//     else    
//         std::cout << "Type is not SUPPORTED, YET." << std::endl;
// }
// template<class T>
// void showTemplateFunction(const std::unique_ptr<T> tempClass)
// {
//     tempClass->showMembers();
// }
// template<class T>
// void showMetaFunction(const std::unique_ptr<T> tempClass)
// {
//     if (std::is_same<T, ATM>::value)
//     {
//         std::cout << "Type is of ATM" << std::endl;
//         tempClass->showMembers();
//     }
//     else if (std::is_same<T,ATM_Program>::value)
//     {
//         std::cout << "Type is of ATM_Program" << std::endl; 
//         tempClass->showMembers();
//     }
//     else    
//         std::cout << "Type is not SUPPORTED, YET." << std::endl;
// }


void ValidateChar(const char& tempChar)
{
	std::cout << "ValidateChar() was called. The Variable : " << tempChar << std::endl;
}

void ValidateInt(const int& tempInt)
{
	std::cout << "ValidateInt() was called. The Variable : " << tempInt << std::endl;
}

void ValidateString(const std::string& tempString)
{
	std::cout << "ValidateString() was called. The Variable : " << tempString << std::endl;
}



template<typename T>
void ValidateData(T& variable)
{
	std::cout << "Data Validation Started...\n" << std::endl;

	if constexpr (std::is_same<T, char>::value) 
	{
		std::cout << "It is a char.\nRelated function will be called..." << std::endl;
		ValidateChar(variable);
	}

	if constexpr (std::is_same<T, int>::value) 
	{
		std::cout << "It is a int.\nRelated function will be called..." << std::endl;
		ValidateInt(variable);
	}

	if constexpr (std::is_same<T, std::string>::value) 
	{
		std::cout << "It is a std::string.\nRelated function will be called..." << std::endl;
		ValidateString(variable);
	}

	std::cout << "Data Validation Ended...\n" << std::endl;
}


// class ATM
// {
// private:
//     std::string m_identifier{};
//     int m_CashAmount{};
// public:
//     void showMembers(void)
//     {
//         std::cout << "Identifier => " << m_identifier << std::endl; 
//         std::cout << "CashAmount => " << m_CashAmount << std::endl;
//     }
//     void setIdentifier(const std::string& tempIdentifier)
//     {
//         this->m_identifier = tempIdentifier;
//     }
//     void setIntValue(const int& cashAmount)
//     {
//         this->m_CashAmount = cashAmount;
//     }
//     std::string& getIdentifier(void)
//     {
//         return this->m_identifier;
//     }
//     int& getCashAmount(void)
//     {
//         return this->m_CashAmount;
//     }
// };
// class ATM_Program
// {
// private:
//     int m_totalATMAmount{};
//     ATM m_ATMMachine{};
// public:
//     void showMembers(void)
//     {
//         std::cout << "Total ATM Amount => " << m_totalATMAmount << std::endl;
//         std::cout << "ATM Identifier;" << std::endl;
//         m_ATMMachine.showMembers();        
//     }
//     void setIdentifier(const ATM& tempATMObj)
//     {
//         this->m_ATMMachine = tempATMObj;
//     }
//     void setIntValue(const int& tempATMAmount)
//     {
//         this->m_totalATMAmount = tempATMAmount;
//     }
//     ATM& getIdentifier(void)
//     {
//         return this->m_ATMMachine;
//     }
//     int& getCashAmount(void)
//     {
//         return this->m_totalATMAmount;
//     }
// };

// template<class T>
// void showMembers(T& tempClassRef)
// {
//     tempClassRef.showMembers();
// }

// template<class T>
// void changeIntValues(T& tempClassRef)
// {
//     if(std::is_same<T, ATM>::value)
//     {
//         tempClassRef.setIntValue(2'000'000);
//     }
//     else if(std::is_same<T, ATM_Program>::value)    
//     {
//         tempClassRef.setIntValue(5);
//     }
//     else
//     {
//         std::cout << "THE TYPE IS NOT SUPPORTED, YET" << std::endl;
//     }
// }


int main()
{
    // std::cout << "--------------------\n";
    // ATM machine_1{};
    // machine_1.showMembers();
    // std::cout << "--------------------\n";
    // ATM_Program main_program{};
    // main_program.showMembers();
    // std::cout << "--------USING TEMPLATE FUNCTIONS WITH CONST REFERENCE------------\n";
    // showTemplateFunction(machine_1);
    // std::cout << "--------------------\n";
    // showTemplateFunction(main_program);
    // std::cout << "--------USING TEMPLATE FUNCTIONS WITH SMART POINTER------------\n";
    // std::unique_ptr<ATM> machine_1_PTR = std::make_unique<ATM>();
    // showTemplateFunction(std::move(machine_1_PTR));
    // std::cout << "--------------------\n";
    // std::unique_ptr<ATM_Program> main_program_PTR = std::make_unique<ATM_Program>();
    // showTemplateFunction(std::move(main_program_PTR));
    // std::cout << "--------USING META FUNCTIONS WITH CONST REFERENCE------------\n";
    // ATM machine_2{};
    // showMetaFunction(machine_2);
    // std::cout << "--------------------\n";
    // ATM_Program sub_program{};
    // showMetaFunction(sub_program);
    // std::cout << "--------USING META FUNCTIONS WITH SMART POINTER------------\n";
    // std::unique_ptr<ATM> machine_2_PTR = std::make_unique<ATM>();
    // showMetaFunction(std::move(machine_2_PTR));
    // std::cout << "--------------------\n";
    // std::unique_ptr<ATM_Program> sub_program_PTR = std::make_unique<ATM_Program>();
    // showMetaFunction(std::move(sub_program_PTR));
    // std::cout << "--------------------\n";


    // std::cout << "--------------------------------\n";
    // ATM machine_1{};
    // machine_1.showMembers();
    // std::string tempName = "ISTANBUL";
    // machine_1.setIdentifier(tempName);
    // std::cout << "New Name => " << machine_1.getIdentifier() << std::endl;
    // machine_1.setIntValue(1'000'000);
    // std::cout << "New Cash => " << machine_1.getCashAmount() << std::endl;
    // std::cout << "--------------------------------\n";
    // ATM_Program main_program{};
    // main_program.showMembers();
    // main_program.setIdentifier(machine_1);
    // main_program.setIntValue(1);
    // main_program.showMembers();
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // showMembers(machine_1);
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // showMembers(main_program);
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // changeIntValues(machine_1);
    // showMembers(machine_1);
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // changeIntValues(main_program);
    // showMembers(main_program);
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";
    // std::cout << "--------------------------------\n";   

	char tempChar = 'a';
	int tempInt = 32;
	std::string tempString = "Ahmet";
	
	ValidateData(tempChar);
	ValidateData(tempInt);
	ValidateData(tempString);

    return 0;
}