
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
    unsigned char i = to_decimal("01000110");
    unsigned char mask = to_decimal("00000101");

    print_binary(i);
    print_binary(mask);
    print_binary(i & mask);
    
    /*
        Decimal to binary

        2^7 : (01000110 & 10000000) != 10000000     print 0

    */
    return 0;
}


unsigned char to_decimal(const char bi[])
{
    unsigned char result = 0;
    size_t n = strlen(bi);
    //printf("%d\n", n);
    for (size_t i = 0; i < n; ++i)
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

void print_binary(const unsigned char num)
{
    printf("Decimal %d\t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    //printf("%d", bits);
    for (size_t i = 0; i < bits; ++i)
    {
        const unsigned char mask =
            (unsigned char)pow((double)2, (double)(bits - 1 - i));

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");

    /*for (int i = 0; i < 8; ++i)
    {
        if (num & (128 >> i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");*/

    /*printf("Decimal %d\t== Binary ", num);
    for (int i = 0; i < 8; ++i)
    {
        if (num & (128 >> i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");*/

    //printf("Decimal %d\t== Binary ", num);
    //for (int i = 7; i >= 0; --i)
    //{
    //    printf("%d", (num >> i) & 1);
    //}
    //printf("\n");


    /*for (int i = 8; i > 0; i--)
    {
        if (num & 1)
        {
            printf("1");
        }
    }*/
    
    /*int n = 8;
    while (n)
    if ((num = (num >> 1)) & 1)
    {
        printf("1");
        n--;
    }*/
    //printf("%d\n", num);
    //printf("%d\n", num >> 1);
    //printf("%d\n", num >> 2);

}