#define _CRT_SECURE_NO_WARNINGS
#include "C:\\Users\\AhmetKandemirPEHLIVA\\source\\repos\\Ahmopasa\\StructUsage\\Header\\Database.h"


int main()
{
    srand((unsigned int)time(NULL));
    
    std::vector<NotLearning> myClass;
    fillVector(myClass);
    showVector(myClass);

    sortVectorByDetail(myClass);
    showVector(myClass);  

  
}
