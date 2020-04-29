
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, y, z;

    x = 1;
    y = 4;

    z = x + y;

    printf("%i + %i = %i.", x, y, z);
    printf("\a");
    //printf("\"The truth is ... \nIam Iron man.\n\"");
    //// escape sequence

    return 0;
}
