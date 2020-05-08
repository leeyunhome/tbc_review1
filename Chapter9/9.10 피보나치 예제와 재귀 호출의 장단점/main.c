
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Fibonacci sequence
    1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
    ex)
*/
int fibonacci(int number);

int main()
{
    for (int count = 1; count < 13; ++count)
        printf("%d ", fibonacci(count));

    return 0;
}
//메모리를 많이 쓰고 계산의 중복이 생긴다.
int fibonacci(int number)
{
    printf("fibonacci with %d\n", number);

    if (number > 2)
    {
        return fibonacci(number - 1) + fibonacci(number - 2); // double recursion
    }
    else
    {
        return 1;
    }
}
// Note: memo