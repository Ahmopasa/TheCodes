// void-type.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

void func ( void ) {
    puts("this is void func ( void )");
}

int main() {
    puts("calling func()");
    func();
    return 0;
}

