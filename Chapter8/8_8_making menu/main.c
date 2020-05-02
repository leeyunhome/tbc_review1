
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMenu();
void count();
int main()
{
    char c;
    /*while (1)
    {
        char c;
        printMenu();
        scanf("%c", &c);
        while (getchar() != '\n')
            continue;
        if (c == 'a')
            printf("Avengers assemble!\n");
        else if (c == 'b')
            printf("\a");
        else if (c == 'c')
            count();

    }*/

    printMenu();
    while ((c = getchar()) != 'q')
    {
        switch (c)
        {
        case 'a':
            printf("Avengers assemble!\n");
            break;
        case 'b':
            printf("\a");
            break;
        case 'c':
            count();
            break;
        }
    }

    return 0;
}
void printMenu()
{
    printf("Enter the letter of your choice:\n");
    printf("a. avengers\tb.beep\n");
    printf("c. count\tq.quit\n");
}
void count()
{
    int a;
    int count;
    printf("Enter an integer to count\n");
    scanf("%d", &a);
    for (count = 0; count < a; ++count)
    {
        printf("%d\n", count + 1);
    }
}