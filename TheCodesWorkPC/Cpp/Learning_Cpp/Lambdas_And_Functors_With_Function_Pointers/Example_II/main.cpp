#include <iostream>

int main()
{

    auto myLambdaI = [](int x){ std::cout << "[](int x) was called. x : " << x << "\n"; };
    auto myLambdaF = [](float x){ std::cout << "[](float x) was called x : " << x << "\n"; };
    auto myLambdaD = [](double x){ std::cout << "[](double x) was called x : " << x << "\n"; };

    int a{100};
    myLambdaI(a);

    float b{100.4f};
    myLambdaF(b);

    double c{200.9};
    myLambdaD(c);

    unsigned int y = 100'999'888;
    auto myLambdaUI = [&y](unsigned int x){ std::cout << "[&y](unsigned int x) was called. [" << y << "] (" << x << ")\n"; };
    myLambdaUI(31U);

    return 0;
}