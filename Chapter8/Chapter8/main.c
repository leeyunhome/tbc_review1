
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int count = 0;

    while (1)
    {
        printf("Current count is %d. Continue? (y/n)\n", count);

        
        if (getchar() == 'n')
            break;

        //while (getchar() != '\n')
        //    continue;

        count++;
    }

    return 0;
}
