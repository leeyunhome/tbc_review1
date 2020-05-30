
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MASK_SWORD   (1 << 0)
#define MASK_SHIELD  (1 << 1)
#define MASK_POTION  (1 << 2)
#define MASK_GUNTLET (1 << 3)
#define MASK_HAMMER  (1 << 4)
#define MASK_KEY     (1 << 5)
#define MASK_RING    (1 << 6)
#define MASK_AMULET  (1 << 7)    // 2^7  10000000 0x80  0200

void char_binary(const char num);
void int_binary(const int num);

/*
    flag 
*/
int main()
{
    /*
    bool has_sword = false;
    bool has_shield = false;
    bool has_potion = false;
    bool has_guntlet = false;
    bool has_hammer = false;
    bool has_key = false;
    bool has_ring = false;
    bool has_amulet = false;
    */

    char flags = 0; // MASK flags
    char_binary(flags);

    printf("\nTurning Bits On (Setting Bits)\n");

    flags = flags | MASK_SWORD; // flag |= MASK_SWORD;
    char_binary(flags);
    flags |= MASK_AMULET;
    char_binary(flags);

    printf("\nTurning Bits Off (Clearing Bits)\n");
    flags = flags | MASK_POTION;
    char_binary(flags);
    flags = flags & ~MASK_POTION;   // flags &= ~MASK_POTION;
    char_binary(flags);

    printf("\nToggling Bits\n");

    flags = flags ^ MASK_HAMMER;
    char_binary(flags);
    
    flags = flags ^ MASK_HAMMER;
    char_binary(flags);
    
    flags = flags ^ MASK_HAMMER;
    char_binary(flags);

    printf("\nChecking the Value of a Bit\n");

    if ((flags & MASK_KEY) == MASK_KEY)
        printf(">> You can enter.\n");
    else
        printf(">> You can not enter.\n");

    flags |= MASK_KEY; // Obtained a key!

    if ((flags & MASK_KEY) == MASK_KEY)
        printf(">> You can enter.\n");
    else
        printf(">> You can not enter.\n");

    printf("\nTrimming\n");

    int int_flag = 0xffffffff;
    // 11111111111111111111111111111111
    int_binary(int_flag);
    int_flag &= 0xff;
    // Trim by 11111111
    int_binary(int_flag);

    return 0;
}

void char_binary(const char num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; ++i)
    {
        const char mask = 1 << (bits - 1 - i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

    printf("\n");
}

void int_binary(const int num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; ++i)
    {
        const int mask = 1 << (bits - 1 - i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

    printf("\n");
}