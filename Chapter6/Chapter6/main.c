
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int d, sum = 0;

    printf("Enter an integer (q to quit) : ");

    while (scanf("%d", &d))
    {
        sum += d;

        printf("Enter an integer (q to quit) : ");

    }
    printf("Sum = %d\n", sum);

    return 0;
}
