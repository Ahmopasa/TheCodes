#include <iostream>
#include <string>
#include <utility>
#include <memory>

struct MyStruct{
    MyStruct() = default;
    MyStruct(int i,double d,std::string s) : m_i{i}, m_d{d}, m_s{s}
    {
        std::cout << "MyStruct(int i,double d,std::string s) was called.\n";
    }
    MyStruct(const MyStruct& other) : m_i{other.m_i}, m_d{other.m_d}, m_s{other.m_s}
    {
        std::cout << "MyStruct(const MyStruct& other) was called.\n";
    }
    MyStruct(MyStruct&& other) : m_i{other.m_i}, m_d{other.m_d}, m_s{other.m_s}
    {
        other.m_i = 0;
        other.m_d = 0.0;
        other.m_s = "deletedString";
        std::cout << "MyStruct(MyStruct&& other) was called.\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const MyStruct& other)
    {
        os << "# Information Table #\n";
        os << "Age   : " << other.m_i << "\n";
        os << "Score : " << other.m_d << "\n";
        os << "Name  : " << other.m_s << "\n";
        return os;
    }


    private:
    int m_i{};
    double m_d{};
    std::string m_s{};
};

// I.  Decleration of "T create(Args&& ... args)"
// template <typename T, typename ... Args>
// T create(Args&& ... args){
//   return T(std::forward<Args>(args)...);
// }

// II. Decleration of "std::unique_ptr<T> create(Args&& ...args)"
// template <typename T, typename ... Args>
// std::unique_ptr<T> create(Args&& ...args)
// {
//     return std::make_unique<T>(std::forward<Args>(args)...);
// }

int main()
{
    // I.   Usage of "T create(Args&& ... args)"
    // std::cout << "/*================================*/\n";
    // MyStruct objOne{28, 8254.56, "Ahmet Kandemir Pehlivanli"};
    // std::cout << objOne << "\n";
    // std::cout << "/*================================*/\n";
    // MyStruct objTwo = create<MyStruct>(objOne);
    // std::cout << objTwo << "\n";
    // std::cout << "/*================================*/\n";
    // MyStruct objThree = create<MyStruct>(26, 2845.34, "Merve Pehlivanli");
    // std::cout << objThree << "\n";
    // std::cout << "/*================================*/\n";
    // MyStruct objFour = create<MyStruct>(std::move(objOne));
    // std::cout << objOne << "\n";
    // std::cout << "/**********************************/\n";
    // std::cout << objFour << "\n";
    // std::cout << "/*================================*/\n";

    // II.  Usage of "std::unique_ptr<T> create(Args&& ...args)"
    // std::cout << "/*================================*/\n";
    // auto objectOne = create<MyStruct>(26, 2895.2354, "Ulya Yuruk");
    // std::cout << *objectOne << "\n";
    // std::cout << "/*================================*/\n";

}