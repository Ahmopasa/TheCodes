#define _CRT_SECURE_NO_WARNINGS
#include "C:\\Users\\AhmetKandemirPEHLIVA\\source\\repos\\Ahmopasa\\StructUsage\\Header\\Database.h"

#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0)) // Return 1 / 0 if the year is leap year or not.

NotLearning::NotLearning()   
{

    ID = rand() % 1001 + 101;
    average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;

    static const std::string nameList[] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
                                    "FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
                                    "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
                                    "FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
    };
    name = nameList[rand() % 80];

    static const std::string surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
                                      "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
                                      "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
                                      "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
                                      "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
    };
    surname = surnameList[rand() % 80];

    static const std::string  cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
                                 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
                                 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
                                 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
                                 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
    };
    city = cityList[rand() % 80];
    
    year = rand() % (2020 - 1989 + 1) + 1989;
    static const int daytabs[][13] = {
                {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };
    static const std::string pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };
    int counter_date = rand() % 12 + 1;
    day = daytabs[check_leap(year)][counter_date];
    month = pmons[counter_date];
}

int NotLearning::getID()const
{
    return ID;
}

int NotLearning::getDay()const
{
    return day;
}

int NotLearning::getYear()const
{
    return year;
}

double NotLearning::getAverage()const
{
    return average;
}

std::string NotLearning::getName()const
{
    return name;
}

std::string NotLearning::getSurname()const
{
    return surname;
}

std::string NotLearning::getCity()const
{
    return city;
}

std::string NotLearning::getMonth()const
{
    return month;
}

void fillVector(std::vector<NotLearning>& newClass)
{
    int total;
    std::cin >> total;

    for (int i = 0; i < total; i++)
    {
        NotLearning newStudent;
        newClass.push_back(newStudent);
    }
}

void showVector(const std::vector<NotLearning>& newClass)
{
    size_t size = newClass.size();
    std::cout << "Total size of vector: " << size << std::endl;
    std::cout << "Total capacity of vector: " << newClass.capacity() << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Student " << i << ": " << std::flush;
        std::cout << newClass[i].getID() << " " << std::flush;
        std::cout << newClass[i].getAverage() << " " << std::flush;
        std::cout << newClass[i].getName() << " " << std::flush;
        std::cout << newClass[i].getSurname() << " " << std::flush;
        std::cout << newClass[i].getCity() << " " << std::flush;
        std::cout << newClass[i].getDay() << " " << std::flush;
        std::cout << newClass[i].getMonth() << " " << std::flush;
        std::cout << newClass[i].getYear() << " " << std::endl;
    }
    std::cout << std::endl;
}

bool cmp_by_id(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return one.getID() < two.getID();
}

bool cmp_by_average(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return (one.getAverage() < two.getAverage());
}

bool cmp_by_name(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return one.getName() < two.getName();
}

bool cmp_by_surname(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return one.getSurname() < two.getSurname();
}

bool cmp_by_city(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return one.getCity() < two.getCity();
}

bool cmp_by_day(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID".
{
    return one.getDay() < two.getDay();
}

bool cmp_by_month(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "month".
{
    return one.getMonth() < two.getMonth();
}

bool cmp_by_year(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "year".
{
    return one.getYear() < two.getYear();
}

bool cmp_by_detail(const NotLearning& one, const NotLearning& two) // compare classes inside the vector by checking the member of "ID", then "average", etc...
{
    
    if (one.getID() != two.getID())
    {
        return one.getID() < two.getID();
    }

    if (one.getAverage() != two.getAverage())
    {
        return one.getAverage() < two.getAverage();
    }

    if (one.getName() != two.getName())
    {
        return one.getName() < two.getName();
    }

    if (one.getSurname() != two.getSurname())
    {
        return one.getSurname() < two.getSurname();
    }

    if (one.getCity() != two.getCity())
    {
        return one.getCity() < two.getCity();
    }

    if (one.getDay() != two.getDay())
    {
        return one.getDay() < two.getDay();
    }

    if (one.getMonth() != two.getMonth())
    {
        return one.getMonth() < two.getMonth();
    }

    if (one.getYear() != two.getYear())
    {
        return one.getYear() < two.getYear();
    }

    return true;
}

void sortVectorByID(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getID() < two.getID(); });
     std::sort(newClass.begin(), newClass.end(), cmp_by_id);
}

void sortVectorByAverage(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getAverage() < two.getAverage(); });
    std::sort(newClass.begin(), newClass.end(),cmp_by_average);
}

void sortVectorByName(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getName() < two.getName(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_name);

}

void sortVectorBySurname(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getSurname() < two.getSurname(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_surname);

}

void sortVectorByCity(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getCity() < two.getCity(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_city);

}

void sortVectorByDay(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getDay() < two.getDay(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_day);

}

void sortVectorByMonth(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getMonth() < two.getMonth(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_month);

}

void sortVectorByYear(std::vector<NotLearning>& newClass)
{
   //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getYear() < two.getYear(); });
     std::sort(newClass.begin(), newClass.end(), cmp_by_year);

}

void sortVectorByDetail(std::vector<NotLearning>& newClass)
{
    //std::sort(newClass.begin(), newClass.end(), [](NotLearning& one, NotLearning& two) { return one.getYear() < two.getYear(); });
    std::sort(newClass.begin(), newClass.end(), cmp_by_detail);
}
