#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names {          // A structure

    char given[LEN];    // first name
    char family[LEN];   // last name
};

struct friend {
    struct names full_name;
    char mobile[LEN];
};

int main(void)
{
    struct friend my_friends[2] = {
        {{"hyerim", "lee"}, "1234-1234"},
        {{"yuri", "Chang"}, "1234-1234"},
    };

    struct friend* girl_friend;

    girl_friend = &my_friends[0];

    printf("%zd\n", sizeof(struct friend));
    printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
    // -> : indirect memeber access operator

    girl_friend++;

    printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
    // . has higher precedence than *

    return 0;
}
