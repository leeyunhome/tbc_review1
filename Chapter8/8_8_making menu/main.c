
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//void printMenu();
char get_choice();
char get_first_char(void);
int get_integer(void);
void count();
int main()
{
    int user_choice;
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

    while ((user_choice = get_choice()) != 'q')
    {
        switch (user_choice)
        {
        case 'a':
            printf("Avengers assemble!\n");
            break;
        case 'b':
            //printf("\a");
            putchar('\a');  // Beep
            break;
        case 'c':
            count();
            break;
        default:
            printf("Error with %d.\n", user_choice);
            exit(1);
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
char get_choice()
{
    int c;
    while (1)
    {
        printf("Enter the letter of your choice:\n");
        printf("a. avengers\tb.beep\n");
        printf("c. count\tq.quit\n");
        
        //c = getchar();
        c = get_first_char();
        //printf("%d\n", c);
        if (c != 'a' && c != 'b' && c != 'c' && c != 'q')
        {
            puts("Please try again");
            //while (getchar() != '\n')
            //    continue;
        }
        //else 
        //{
        //    //while (getchar() != '\n')
        //    //    continue;
        //    break;
        //}
        break;
    }
    
    return c;
}
char get_first_char(void)
{
    char c;
    c = getchar();
    while (getchar() != '\n')
        continue;
    return c;
}
int get_integer(void)
{
    int a;
    int flag;
    while (1)
    {
        if ((flag = scanf("%d", &a)) == 1)
        {
            while (getchar() != '\n')
                continue;
            return a;
        }
        else
        {
            printf("Wrong input. please try again\n");
            while (getchar() != '\n')
                continue;
        }
    }
}

void count()
{
    int a;
    int count;
    printf("Enter an integer to count\n");
    a = get_integer();
    for (count = 0; count < a; ++count)
    {
        printf("%d\n", count + 1);
    }
}