#include "StudentInfo.h"
#define _SIZE_ 3

int main()
{
	srand((unsigned int)time(NULL));
	_counter my_class[_SIZE_] = { 0 };

	CreateNodes(my_class, _SIZE_);
	ShoWNodes(my_class, _SIZE_);
	SaveNodes(my_class, _SIZE_);

	

}
