#include <iostream>

class myFunctor{
    public:

    void operator()(void) const{
        std::cout << "myFunctor.operator()(void) was called.\n";
    }

    void operator()(int x){
        std::cout << "myFunctor.operator()(int x) was called. x : " << x << "\n";
    }

    void operator()(float x){
        std::cout << "myFunctor.operator()(float x) was called. x : " << x << "\n";
    }

    void operator()(double x){
        std::cout << "myFunctor.operator()(double x) was called. x : " << x << "\n";
    }
};

int main()
{
    myFunctor myFunctorObj;

    int a{100};
    myFunctorObj(a);

    float b{100.4f};
    myFunctorObj(b);
    
    double c{200.9};
    myFunctorObj(c);

    return 0;
}