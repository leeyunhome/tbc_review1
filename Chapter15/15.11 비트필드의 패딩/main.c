
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void char_to_binary(unsigned char uc)
{
    const int bits = CHAR_BIT * sizeof(unsigned char);
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)    // Note: extended for any sizes
{
    for (int i = 0; i < bytes; ++i)
        char_to_binary(data[bytes - 1 - i]);
    printf("\n");
}

int main()
{
    bool a = true;
    struct {
        bool option1 : 1;
        bool         : 0;
        bool option2 : 1;
        //unsigned long long option3 : 16;
    } bbf;

    memset((char*)&bbf, 0x00, sizeof(bbf));
    print_binary((char*)&bbf, sizeof(bbf));
    //bbf.option1 = 1;
    bbf.option2 = 1;
    //bbf.option3 = 0xffff;
    print_binary((char*)&bbf, sizeof(bbf));

    printf("%zu bytes\n", sizeof(bbf));

    struct {
        unsigned short option1 : 1;
        unsigned short option2 : 1;
        //unsigned short : 0;
        unsigned short option3 : 1;
    };
    return 0;
}
