
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct movie
{
    char title[MAX];
    float rating;
};

int input_int();
void print_menu(int* ptr_n);
void print_all_items(struct movie *m1, int size);

int main()
{
    int n;
    int choice;
    printf("Please input filename to read and press Enter.\n>> ");
    int flag;
    char title[MAX];
    const char* movie_title = "movies.txt";
    flag = scanf("%[^\n]%*c", title);
    if (flag != 1)
    {
        puts("Cannot open file");
        exit(EXIT_FAILURE);
    }

    if (strcmp(title, "movies.txt"))
    {
        printf("ERROR: Cannot open file.");
        exit(EXIT_FAILURE);
    }

    FILE* fp;
    if ((fp = fopen(movie_title, "a+")) == NULL)
    {
        printf("Cannot open file");
        exit(EXIT_FAILURE);
    }
    
    fscanf(fp, "%d", &n);
    printf("%d items have been read from the file.\n\n", n);

    struct movie m1[6];
    for (int i = 0; i < n; ++i)
    {
        fscanf(fp, "%[^\n]%*c", &m1[i].title);
        fscanf(fp, "%f", &m1[i].rating);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%s, %f\n", m1[i].title, m1[i].rating);
    }
    print_menu(&choice);

    switch (choice)
    {
    case 1:
        //print_all_items(m1, n);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        exit(EXIT_SUCCESS);
    default:
        printf("please try again");
    }

    return 0;
}

int input_int()
{
    int n;
    printf(">> ");
    int flag = scanf("%d", &n);
    if (flag != 1)
    {
        printf("Cannot open file");
        exit(EXIT_FAILURE);
    }
    return n;
}

void print_menu(int* ptr_n)
{
    printf("Please select an option and press enter.\n");
    printf("1. Print all items\t2. Print an item\n");
    printf("3. Edit an item\t4. Add an item\n");
    printf("5. Insert an item\t6. Delete an item\n");
    printf("7. Delete all items\t8. Save file\n");
    printf("9. Search by name\t10. Quit\n");
    *ptr_n = input_int();
}

void print_all_items(struct movie* m1, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d : \"%s\", %f\n", i, m1[i].title, m1[i].rating);
    }
}