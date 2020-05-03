
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH     25
#define NAME      "Jeong-Mo Hong"
#define ADDRESS   "Seoul, Korea"

void print_multiple_chars(char c, int length, bool print_newline);
void print_centered_str(char* c);

int main()
{
    print_multiple_chars('*', WIDTH, true);

    print_centered_str(NAME);
    print_centered_str(ADDRESS);
    print_centered_str("I love you");

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

void print_multiple_chars(char c, int length, bool print_newline)
{
    /*if (c == '*')
    {
        for (int i = 0; i < length; ++i)
            putchar(c);
        putchar('\n');
    }
    else if (c == ' ')
    {
        for (int i = 0; i < length; ++i)
            putchar(' ');
    }*/
    for (int i = 0; i < length; ++i)
        printf("%c", c);    // putchar(c)

    if (print_newline)
        printf("\n");
}

void print_centered_str(char* c)
{
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(c)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", c);
    /*for (int i = 0; i < strlen(c); ++i)
        putchar(c[i]);
    putchar('\n');*/
}
