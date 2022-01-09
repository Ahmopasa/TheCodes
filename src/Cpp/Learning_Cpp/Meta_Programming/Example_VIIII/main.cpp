// https://riptutorial.com/cplusplus/example/19276/variadic-template-data-structures

#include <iostream>

// (4) The reason we can't define the required functionality directly in DataStructure's get is because (as we will shortly see)...
// ...we would need to specialise on idx - but it isn't possible to specialise a template member function without specialising the containing class template: 
template<size_t idx, typename T>
struct GetHelper;

// (1) Start with the general (empty) definition, which also serves as the base-case for recrusion termination in the later specialisation:
template<typename ... T>
struct DataStructure
{
};

// (2) Next comes the recursive case specialisation...
// ...This is now sufficient for us to create arbitrary data structures, like "DataStructure<int, float, std::string> data(1, 2.1, "hello")" :
template<typename T, typename ... Args>
struct DataStructure<T, Args ...>
{
    DataStructure(const T& first, const Args& ... args)
        : first(first)
        , args(args...)
    {
        std::cout << "DataStructure::DataStructure(const T& first, const Args& ... args) was called. => ";
        std::cout << "First : " << first << "\n";
    }
    
    T first;
    DataStructure<Args ... > args;
    
    // (3) Now we have the data structure, but its not terribly useful yet as we cannot easily access the individual data elements...
    // ...(for example to access the last member of DataStructure<int, float, std::string> data we would have to use data.rest.rest.first, which is not exactly user-friendly)...
    // ...So we add a get method to it (only needed in the specialisation as the base-case structure has no data to get):
    template<size_t idx>
    auto get()
    {
        return GetHelper<idx, DataStructure<T,Args...>>::get(*this);
    }
};

// (5) Now the base-case (when idx==0). In this case we just return the first member:
template<typename T, typename ... Args>
struct GetHelper<0, DataStructure<T, Args ... >>
{
    static T get(DataStructure<T, Args...>& data)
    {
        return data.first;
    }
};

// (6) In the recursive case, we decrement idx and invoke the GetHelper for the rest member:
template<size_t idx, typename T, typename ... Args>
struct GetHelper<idx, DataStructure<T, Args ... >>
{
    static auto get(DataStructure<T, Args...>& data)
    {
        return GetHelper<idx-1, DataStructure<Args ...>>::get(data.args);
    }
};

int main()
{
    // std::cout << "The case of [ DataStructure<int> data{100}; ]\n";
    // DataStructure<int> data{100};
    // std::cout << "The usage of [ data.get<0>() ] => ";
    // std::cout << data.get<0>() << "\n";
    // std::cout << "The usage of [ data.first ] => ";
    // std::cout << data.first << "\n";
    // std::cout << "The end of  [ DataStructure<int> data{100}; ]\n";
    std::cout << "*********************************************\n";
    std::cout << "The case of [ DataStructure<char, int, float, double> dataFour{'a', 32, 456.98f, 234.90}; ]\n";
    DataStructure<char, int, float, double> dataFour{'a', 32, 456.98f, 234.90};
    std::cout << "The usage of [ data.get<0>() ] => ";
    std::cout << dataFour.get<0>() << "\n";
    std::cout << "The usage of [ data.get<1>() ] => ";
    std::cout << dataFour.get<1>() << "\n";
    std::cout << "The usage of [ data.get<2>() ] => ";
    std::cout << dataFour.get<2>() << "\n";
    std::cout << "The usage of [ data.get<3>() ] => ";
    std::cout << dataFour.get<3>() << "\n";
    std::cout << "The end of  [ DataStructure<char, int, float, double> dataFour{'a', 32, 456.98f, 234.90}; ]\n";
    std::cout << "*********************************************\n";
    std::cout << "[ " << dataFour.first << " , " << dataFour.args.first << " , " << dataFour.args.args.first << " , " << dataFour.args.args.args.first << " ]\n";
    return 0;
}