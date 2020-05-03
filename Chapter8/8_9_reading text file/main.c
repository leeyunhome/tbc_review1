
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit()
int main()
{
    int c;
    FILE* file = NULL;
    char file_name[] = "my_file.txt";// TODO: use scanf(...)

    file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1004);
    }

    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);

    return 0;
}
