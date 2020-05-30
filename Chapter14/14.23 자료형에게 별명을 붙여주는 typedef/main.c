
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // time()

/*
    "One good way to synthesize declarations is
    in samll steps with typedef, ..."
    - K&R book Chapter 5.12
*/

/* Complicated Function Declarations */

char char3[3] = { 'A', 'B', 'C' };

char(*complicated_function1())[3] // Function Returns Pointer to Char[3]
{
    return &char3;// Returns a pointer to char[3]
}

typedef char(*FRPTC3())[3]; // Function Returns Pointer to Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3* fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */

typedef char c3[3];

c3* complicated_function2()
{
    return &char3;  // Returns a pointer to char[3]
}

int main()
{
    /*
        typedef specifier
        - Give symbolic names (or aliases) to types
        - Does not create new types.
    */

    //typedef unsigned char BYTE; // Note the scope of BYTE

    //BYTE x, y[10] = { 0, }, * z = &x;

    //{
    //    typedef unsigned char byte;// You can use lowercases as well.

    //    /* Portable data types */

    //    size_t s = sizeof(byte);// unsigned int (x86), unsigned long long (x64)
    //    // unsigned int s = sizeof(byte);// x86
    //    // unsigned long long s = sizeof(byte); // x64
    //}

    ////byte b;   // typedef definition has a scope

    ///*
    //    This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp)
    //    in seconds.
    //*/

    //time_t t = time(NULL);

    //printf("%lld\n", t);

    ///*
    //    typedef vs #define
    //*/

    //typedef char* STRING;

    //STRING name = "John Wick", sign = "World";

    ///*
    //    - typedef interpretation is performed by the compiler, not the preprocessor
    //    - More flexible than #define

    //    #define STRING char *

    //    STRING name, sign;
    //    char * name, sign;//Note the type of sign
    //*/

    //typedef struct complex {
    //    float real;
    //    float imag;
    //} COMPLEX;// typedef struct complex COMPLEX

    //typedef struct { double width; double height; } rect;// No tag
    //rect r1 = { 1.1, 2.2 };
    //rect r2 = r1;
    //printf("%f %f\n", r2.width, r2.height);

    char(*ret_val)[3] = fptr1();

    printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

    c3* my_c3 = fptr2();

    printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);

    return 0;
}
