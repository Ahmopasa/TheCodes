// printf.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-31
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int i = 5;
    long int li = 1234567890;
    const char * s = "This is a string.";
    printf("i is %d, li is %ld, s is %s\n", i, li, s);
    return 0;
}
