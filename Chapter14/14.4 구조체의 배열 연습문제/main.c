
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NM_MAX 50
#define NM_TITLE 50
#define MAX 3

char* s_gets()
{
    char buffer[NM_MAX];
    char* fin = fgets(buffer, NM_MAX, stdin);
    if (strchr(fin, '\n'))
    {

    }
    while (getchar() != '\n')
        continue;
}
struct Book
{
    char title[NM_TITLE];
    char author[NM_MAX];
    float price;
};

int main()
{
    char title[NM_TITLE];
    char author[NM_MAX];
    float price = 0.0f;
    struct Book book[MAX];
    int count = 0;
    printf("Input a book title or press [Enter] to stop.\n");
    printf(">>");
    
    //if (scanf("%s", title) == 1 || )
    while (scanf("%s", title) == 1 && title != "\n")
    {
        while (getchar() != '\n')
            continue;
        strcpy(book[0].title, title);
        printf("Input the author\n");
        printf(">>");
        scanf("%s", author);
        strcpy(book[0].author, author);
        printf("Input the price.\n");
        printf(">>");
        scanf("%f", &price);
        book[0].price = price;
    }

    
    for (unsigned int i = 0; i < MAX; ++i)
    {
        printf("\"%s\" written by %s: %f", book[i].title, book[i].author, book[i].price);
    }
    //for (int i = 0; i < 3; ++i)
    //{
    //    printf("Input a book title or press [Enter] to stop.\n");
    //    printf(">>");

    //}
    

    return 0;
}
