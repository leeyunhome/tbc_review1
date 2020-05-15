
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r)
{

}
int main()
{
    register int r;
    r = 123;

    // printf("%p\n", &r);
    //int* ptr = &r;

    return 0;
}
