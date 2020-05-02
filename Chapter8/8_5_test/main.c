#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
    char c;

    int rows, cols;

    while (1)
    {

        scanf_s("%c %d %d", &c, sizeof(c), &rows, &cols);

        while (getchar() != '\n') continue;

        display(c, rows, cols);

        if (c == 'n')
            break;
    }

    return 0;
}

void display(char cr, int lines, int width)
{
    int row, col;

    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');
    }
}