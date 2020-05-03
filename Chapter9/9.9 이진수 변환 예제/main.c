
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    10
    10 / 2 = 5, remainder = 0
    5 / 2 = 2, remainder = 1
    2 / 2 = 1, remainder = 0
    1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
    unsigned long num = 10;

    print_binary_loop(num);
    print_binary(num);

    printf("\n");

    return 0;
}

void print_binary(unsigned long num)
{
    int remainder = num % 2;

    if (num >= 2)
        print_binary(num / 2);

    printf("%d", remainder);

    return;
}

//void print_binary(unsigned long num)
//{
//    if (num > 0)
//    {
//        print_binary(num / 2);
//        printf("%d", num % 2);
//    }
//
//}
void print_binary_loop(unsigned long num)
{
    int arr[5] = { 0, };
    int count = 0;
    while (1)
    {
        int quotient = num / 2;
        int remainder = num % 2;

        //printf("%d", remainder);    // remainder is 0 or 1
        arr[count] = remainder;
        num = quotient;

        if (num == 0) break;
        count++;
    }
    for (int i = 0; i <= count; ++i)
    {
        printf("%d", arr[count - i]);
    }
    printf("\n");
}
//
//void print_binary_loop(unsigned long n)
//{
//    for (int i = n; i > 0; i = i / 2)
//    {
//        printf("%d", i % 2);
//    }
//}