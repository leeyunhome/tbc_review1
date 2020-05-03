
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_min(int, int);
int main()
{
    int i1, i2;

    while (1)
    {
        printf("Input two integers : ");

        if (scanf("%d %d", &i1, &i2) != 2) break;

        int lesser = int_min(i1, i2);
        //int lesser = min;
        printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

        //printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
    }

    printf("End. \n");
    return 0;
}
int int_min(int x, int y)
{
    //int min;// local variable

    //if (x < y)
    //    min = x;
    //else
    //    min = y;

    //return min;

    //return (x > y) ? y : x;

    //return (float)min;

    //if (x < y)
    //    return x;
    //else
    //    return y;

    //printf("Who am I?");
    //exit(1);

    return;   // return with no value
}