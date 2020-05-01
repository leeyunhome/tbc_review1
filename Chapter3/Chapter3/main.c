
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float won = 0.0f;
    float dollar = 0.0f;

    printf("Input won\n");
    scanf("%f", &won);

    dollar = won * 0.00082f;
    printf("Dollar = %f\n", dollar);
    /*int i = 0, j = 0;
    int sum = 0;

    printf("Input two integers\n");

    scanf("%d%d", &i, &j);

    sum = i + j;

    printf("%d plus %d = %d\n", i, j, sum);*/
    //printf("Value is %d\n", i);

    return 0;
}
