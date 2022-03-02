// exception.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-31
#include <iostream>
#include <exception>
using namespace std;

class E : public exception {
    const char * msg;
    E();
public:
    E(const char * s) throw() : msg(s) {}
    const char * what() const throw() { return msg; }
};

void broken() {
    cout << "this is a broken function" << endl;
    throw exception();
}

int main() {
    cout << "let's have an emergency!" << endl;
    broken();
    return 0;
}
