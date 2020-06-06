
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
//struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
    int temp;
    int n = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

    if (!my_books) {
        printf("Malloc failed");
        exit(EXIT_FAILURE);
    }

    my_books[0] = (struct book){ "The Greate Gatsby", "F. Scott Fitzgerald" };
    my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    my_books[2] = (struct book){ "The Odyssey", "Homer" };

    print_books(my_books, n);

    printf("\nWriting to a file.\n");
    write_books("books.dat", my_books, n);
    free(my_books);
    n = 0;
    printf("Done.\n");

    printf("\nPress any key to read data from a file.\n\n");
    temp = _getch();

    //my_books = read_books("books.txt", &n);
    read_books2("books.dat", &my_books, &n);
    print_books(my_books, n);
    free(my_books);
    n = 0;

    return 0;
}

void print_books(const struct book* books, int n)
{
    for (int i = 0; i < n; ++i)
        printf("Book %d : \"%s\" written by \"%s\"\n",
            i + 1, books[i].name, books[i].author);

}
void write_books(const char* filename, const struct book* books, int n)
{
    FILE* fp;
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        printf("Cannot open %s file", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(&n, sizeof(n), 1, fp); // number of books
    fwrite(books, sizeof(struct book), n, fp);
    //fprintf(fp, "%d\n", n);// number of books

    //for (int i = 0; i < n; ++i)
    //{
    //    fprintf(fp, "%s\n%s\n", books[i].name, books[i].author);
    //}

    fclose(fp);
}
struct book* read_books(const char* filename, int* n)
{
    FILE* fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open %s file", filename);
        exit(EXIT_FAILURE);
    }

    int flag;
    flag = fscanf(fp, "%d%*c", n);// Remove last \n
    if (flag != 1)
    {
        printf("File read failed");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n);//Note: calloc()

    if (!books) {
        printf("Malloc() failed.");
        exit(1);
    }

    for (int i = 0; i < *n; ++i)
    {
        flag = fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

        if (flag != 2) {
            printf("File read failed");
            exit(1);
        }
    }

    fclose(fp);

    return books;
}
void read_books2(const char* filename, struct book** books_dptr, int* n)
{
    FILE* fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open %s file", filename);
        exit(EXIT_FAILURE);
    }

    fread(n, sizeof(*n), 1, fp);
    
    struct book* books = (struct book*)calloc(sizeof(struct book), *n);//Note: calloc()

    if (!books) {
        printf("Malloc() failed.");
        exit(1);
    }

    fread(books, sizeof(struct book), *n, fp);
    fclose(fp);

    *books_dptr = books;
}
