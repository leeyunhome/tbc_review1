
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    while (getchar() != '\n')
    {
        if (getchar() == 'n')
            break;
    }
    /*if (getchar() == 'n')
        break;*/
    return 0;
}
