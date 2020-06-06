
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    user_name = receive_input();
    user_name = count_characters(user_name);
    show_result(user_name);

    return 0;
}

struct name_count receive_input()
{
    struct name_count user_name;
    int flag;
    printf("Input your first name:\n>> ");
    s_gets(user_name.first, NLEN);
    //flag = scanf("%[^\n]%*c", &user_name.first); // ^ : cap operator
    //if (flag != 1)
    //    printf("Wrong input");

    printf("Input your last name:\n>> ");
    s_gets(user_name.last, NLEN);
    //flag = scanf("%[^\n]%*c", &user_name.last);
    //if (flag != 1)
    //    printf("Wrong input");

    return user_name;
}
struct name_count count_characters(struct name_count user_name)
{
    user_name.num = strlen(user_name.first) + strlen(user_name.last);
    return user_name;
}

void show_result(const struct name_count user_name)
{
    printf("Hi, %s %s. Your name has %d characters.\n",
        user_name.first, user_name.last, user_name.num);
}
//
//void receive_input(struct name_count* user_name)
//{
//    int flag;
//    printf("Input your first name:\n>> ");
//    //s_gets(user_name->first, NLEN);
//    flag = scanf("%[^\n]%*c", user_name->first); // ^ : cap operator
//    if (flag != 1)
//        printf("Wrong input");
//
//    printf("Input your last name:\n>> ");
//    //s_gets(user_name->last, NLEN);
//    flag = scanf("%[^\n]%*c", user_name->last);
//    if (flag != 1)
//        printf("Wrong input");
//}
//void count_characters(struct name_count* user_name)
//{
//    size_t count = 0;
//    count = strlen(user_name->first) + strlen(user_name->last);
//    user_name->num = (int)count;
//}
//
//void show_result(const struct name_count* user_name)
//{
//    printf("Hi, %s %s. Your name has %d characters.\n",
//        user_name->first, user_name->last, user_name->num);
//}
char* s_gets(char* st, int n)
{
    char* ret_value;
    char* find;

    ret_value = fgets(st, n, stdin);// vs. scanf()
    if (ret_value)
    {
        find = strchr(st, '\n');    // look for newline
        if (find)                   // if the address is not NULL
            *find = '\0';           // place a null character there
        else
            while (getchar() != '\n')
                continue;           // dispose of rest of line
    }

    return ret_value;
}