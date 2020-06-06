#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_AUTHOR 50
#define MAX_TITLE 50
#define MAX 3   /* maximum number of books */

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);  // vs. scanf()
    if (ret_val)
    {
        find = strchr(st, '\n');    // if the address is not NULL
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
struct Book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main()
{
    struct Book book[MAX] = { {"Empty", "Empty", 0.0f}, };
    int count = 0;

    while (1)
    {
        printf("Input a book title or press [Enter] to stop.\n");
        printf(">>");
        if (s_gets(book[count].title, MAX_TITLE) == NULL) break;
        if (book[count].title[0] == '\0')
            break;

        printf("Input the author\n");
        printf(">>");
        s_gets(book[count].author, MAX_AUTHOR);
        printf("Input the price.\n");
        printf(">>");
        int flag = scanf("%f", &book[count].price);
        while (getchar() != '\n')
            continue;   /* clear input line */

        count++;
        
        if (count == MAX)
        {
            printf("No more books.\n");
            break;
        }
    }

    if (count > 0)
    {
        printf("\nThe list of books:\n");
        for (unsigned int i = 0; i < count; ++i)
        {
            printf("\"%s\" written by %s: %.1f",
                book[i].title, book[i].author, book[i].price);
        }
    }
    else
    {
        printf("No books to show.\n");
    }



    return 0;
}
