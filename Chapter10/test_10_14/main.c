
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    int* pa = &a;
    int* pb = &b;

    int arr[] = { 0, };
    int arr_of_pointer[][1] = { pa, pb };

    printf("arr: %d", arr);
    putchar('\n');
    printf("&arr: %d", &arr);
    putchar('\n');
    printf("arr_of_pointer: %d", arr_of_pointer);
    putchar('\n');
    printf("&arr_of_pointer: %d", &arr_of_pointer[0]);
    return 0;
}
