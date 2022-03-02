// errno.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-31
#include <cstdio>
#include <cstring>
#include <cerrno>

int main() {
    printf("errno is: %d\n", errno);
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    perror("Cannot erase file");
    return 0;
}
