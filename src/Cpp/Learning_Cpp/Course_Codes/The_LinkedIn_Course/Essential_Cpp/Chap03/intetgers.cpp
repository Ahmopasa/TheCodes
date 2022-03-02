// integers.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// a byte is 8 bits
constexpr size_t byte = 8;

int main()
{
    printf("sizeof char is %ld bits\n", sizeof(char) * byte);
    printf("sizeof short int is %ld bits\n", sizeof(short int) * byte);
    printf("sizeof int is %ld bits\n", sizeof(int) * byte);
    printf("sizeof long int is %ld bits\n", sizeof(long int) * byte);
    printf("sizeof long long int is %ld bits\n", sizeof(long long int) * byte);
    return 0;
}
