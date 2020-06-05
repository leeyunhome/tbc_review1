
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
    ABCDEF ...
    Current position 0 and read -> A
    Current position 1 and read -> B
    ...
*/

int main()
{
    int ch;
    long cur;

    FILE* fp = fopen("suzie_qcif.yuv", "r");

    cur = ftell(fp); // 현재 어디서 읽을 준비가 되어있는가
    printf("ftell() = %ld\n", cur);

    fseek(fp, 50L, SEEK_SET); // 시작점으로부터 2바이트 떨어진 곳으로 이동한다. 그리고 읽을 준비를 한다. 
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);

    fseek(fp, -2L, SEEK_CUR); // cur 현재 위치에서 이 숫자만큼 이동함
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* SEEK_END */

    fseek(fp, 0L, SEEK_END);
    ch = fgetc(fp);
    printf("##%d %c\n", ch, ch);

    fseek(fp, -1L, SEEK_END);
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    fseek(fp, -2L, SEEK_CUR); // cur 현재 위치에서 이 숫자만큼 이동함
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* fsetpos(), fgetpos() */

    fpos_t pt;
    pt = 10;
    int flag = fsetpos(fp, &pt);       // returns 0 ok
    printf("%d\n", flag);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    fgetpos(fp, &pt);       // returns 0 ok
    printf("%lld\n", pt);   // NOTE: not meant to be read directly

    return 0;
}
