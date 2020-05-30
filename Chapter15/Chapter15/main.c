
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>   // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()

unsigned char to_decimal(const char bi[]);

int main()
{
    printf("Binary (string) to Decimal conversion\n");

    printf("%d\n", to_decimal("00000110"));
    printf("%d\n", to_decimal("00010110"));

    // Note: ^ (caret) means power in math.
    // Hint: (int)pow(2, 3) == 8
    printf("%d\n", to_decimal("10010100"));

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    unsigned char result = 0;
    size_t n = strlen(bi);
    //printf("%d\n", n);
    for (size_t i = 0; i < n; ++i )
    {
        if (bi[i] == '1')
        {
            result += (int)pow(2, n - 1 - i);
        }
        else if (bi[i] != '0')
        {
            printf("Wrong character : %c", bi[i]);
            exit(1);
        }
    }


    return result;
    // printf("Binary %s == Decimal %d\n", bi, sum);
}