
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen(), strcmp()
#include <stdlib.h> // malloc(), free()
#define SLEN 81

struct namect {
    char* fname;        // Use malloc()
    char* lname;        // Use malloc()
    int letters;
};

void getinfo(struct namect*);   // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);   // free memory when done
char* s_gets(char* st, int n);

int main()
{
    /*
        Dangerous usage
    */

    //struct namect p = { "Jeong-Mo", "Hong" };
    //printf("%s %s\n", p.fname, p.lname);

    ////int f1 = scanf("%[^\n]%*c", p.lname);
    ////printf("%s %s\n", p.lname, p.fname);

    ///*
    //    Recommended usage
    //*/

    //char buffer[SLEN] = { 0, };
    //int f2 = scanf("%[^\n]%*c", buffer);
    //p.fname = (char*)malloc(strlen(buffer) + 1);
    //if (p.fname != NULL)
    //    strcpy(p.fname, buffer);
    //printf("%s %s\n", p.fname, p.lname);

    /* Problem */
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}

void getinfo(struct namect* nc)
{
    int flag;
    char buffer[SLEN] = { 0, };
    printf("Please enter your first name.\n");
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
    {
        puts("Wrong input");
    }
    else
    {
        nc->fname = (char*)malloc(strlen(buffer) + 1);
        if (nc->fname != NULL)
            strcpy(nc->fname, buffer);
        else
            printf("Malloc() failed");
    }
    
    printf("Please enter your last name.\n");
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
        puts("Wrong input");
    nc->lname = (char*)malloc(strlen(buffer) + 1);
    strcpy(nc->lname, buffer);

}
void makeinfo(struct namect* nc)
{
    nc->letters = strlen(nc->fname) + strlen(nc->lname);
}

void showinfo(const struct namect* nc)
{
    printf("%s %s. your name contains %d letters.\n", 
        nc->fname, nc->lname, nc->letters);
}

void cleanup(struct namect* nc)
{
    free(nc->fname);
    free(nc->lname);
}

