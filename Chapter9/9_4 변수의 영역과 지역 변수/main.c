
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int a;// file���� ����

int int_max(int i, int j);

int int_max(int i, int j)
{
     //a = 456;
    int m;//stack frame
    m = i > j ? i : j;
    return m;
}

int main()
{
     //m = 123; // �����Լ������� �� ���� ����.

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
        int a;//�̸��� ������ ����
        a = int_max(4, 5);

        printf("%d\n", a);
        printf("%p\n", &a);

        int b = 123;
    }

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}
