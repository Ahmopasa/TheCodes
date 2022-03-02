// class.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// a very simple class
class C1 {
    int i = 0;
public:
    void setvalue( int value ) { i = value; }
    int getvalue() { return i; }
};

int main() {
    int i = 47;
    C1 o1;
    
    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());
    return 0;
}
