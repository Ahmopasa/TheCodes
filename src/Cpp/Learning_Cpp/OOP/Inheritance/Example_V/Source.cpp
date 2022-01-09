#include <iostream>
#include <string>

class Animal
{
public:
	Animal() : m_Eyes(2), m_Feet(4), m_Ear(2) { printf("All animals have born with following features: %d Eyes, %d Feet, %d Ear\n", m_Eyes, m_Feet, m_Ear); }; // Default Construct
	~Animal() { printf("All animals were dead now.\n"); };

	int getEyes();
	int getFeet();
	int getEar();

private:
	int m_Eyes;
	int m_Feet;
	int m_Ear;

};

int Animal::getEyes()
{
	return m_Eyes;
}

int Animal::getFeet()
{
	return m_Feet;
}

int Animal::getEar()
{
	return m_Ear;
}


class Cat : public Animal
{
public:
	void setCatFeatures(std::string, int);
	std::string getCatFeatherType();
	int getCatNoseSensitivity();
	void showCatFeatures(const Cat&); 

	Cat();
	~Cat();

private:
	std::string featherType;
	int noseSensitivity;

};

Cat::Cat()
{
	featherType = "Featherless";
	noseSensitivity = 2;

	std::cout << "A newborn cat has born with following features: " << featherType << " feather type and nose sensitivity is " << noseSensitivity << std::endl;
}

Cat::~Cat()
{
	printf("All cats were dead now.\n"); 
}

void Cat::setCatFeatures(std::string tempString, int tempValue)
{
	featherType = tempString;
	noseSensitivity = tempValue;
}

std::string Cat::getCatFeatherType()
{
	return featherType;
}

int Cat::getCatNoseSensitivity()
{
	return noseSensitivity;
}

void Cat::showCatFeatures(const Cat& tempClass)
{
	printf("Cat has following features at the moment;\n");
	std::cout << "- Feather Type: " << featherType << std::endl;
	printf("- Nose Sensitivity: %d \n", noseSensitivity);
	printf("- Eyes: %d\n", Animal::getEyes());
	printf("- Feet: %d\n", Animal::getFeet());
	printf("- Ear: %d\n", Animal::getEar());

}


int main()
{
	puts("*****************");
	Animal animal_1;
	puts("*****************");
	Cat cats_1;
	puts("*****************");
	return 0;
}


