// while.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    int i = 0;
    
    while(i < 5) {
        printf("element %d is %d\n", i, array[i]);
        ++i;
    }
    
    return 0;
}
