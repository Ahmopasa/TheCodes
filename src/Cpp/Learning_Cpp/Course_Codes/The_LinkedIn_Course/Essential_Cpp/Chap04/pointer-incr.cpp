// pointer-incr.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

void printp(char *p) {
    printf("pointer is %p, value is %d\n", p, *p);
}

int main()
{
    char arr[5] = { 1, 2, 3, 4, 5 };
    char *p = arr;
    printp(p++);
    printp(p++);
    printp(p++);

    return 0;
}
