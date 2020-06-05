
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>    // SetConsoleOutputCP()

int main()
{
    FILE* fp = fopen("hyerim.txt", "rb");

    unsigned char ch;

    SetConsoleOutputCP(CP_UTF8);    // UTF-8 mode

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)//fread 함수의 반환값은 읽어들인 데이터의 양, 
    {                                                   //읽어들인 양이 0이면 EOF니까 break돼서 나가겠죠
        printf("%hhu %c\n", ch, ch);
    }

    fclose(fp);

    return 0;
}
