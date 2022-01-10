#include <iostream>

using std::cout;

template <typename T, T val>
struct IntegralConstant 
{
  constexpr static T value = val;

  using value_type = T;
  using type = IntegralConstant<T, val>;

  constexpr operator value_type() const noexcept 
  {
    return value + 100;
  }

  constexpr value_type operator()() const noexcept 
  {
    return value + 1000;
  }
};

int main()
{  
    auto val0 = IntegralConstant<int, 0>()(); cout << "val0 => " << val0 << "\n";

    //operator()()
    constexpr auto val5 = IntegralConstant<int, 5>()(); cout << "val5 => " << val5 << "\n";
    constexpr auto val6 = IntegralConstant<int, 6>{}(); cout << "val6 => " << val6 << "\n";

    constexpr auto val7 = IntegralConstant<int, 7>().operator()(); cout << "val7 => " << val7 << "\n";
    constexpr auto val8 = IntegralConstant<int, 8>{}.operator()(); cout << "val8 => " << val8 << "\n";

    // operator value_type
    constexpr auto val1 = IntegralConstant<int, 1>().operator int(); cout << "val1 => " << val1 << "\n";
    constexpr auto val2 = IntegralConstant<int, 2>{}.operator int(); cout << "val2 => " << val2 << "\n";
    constexpr int val3 = IntegralConstant<int, 3>{}; cout << "val3 => " << val3 << "\n";
    constexpr int val4 = IntegralConstant<int, 4>(); cout << "val4 => " << val4 << "\n";
}