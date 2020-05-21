
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Unions And Structures
*/

struct personal_owner {
    char rrn1[7];       // Resident Registration Number
    char rrn2[8];       // ex: 830422-1185600
};

struct company_owner {
    char crn1[4];       // Company Registration Number
    char crn2[3];       // ex: 111-22-33333
    char crn3[6];
};

union data {
    struct personal_owner po;
    struct company_owner  co;
};

struct car_data {
    char model[15];
    int status; /* 0 = personal, 1 = company */
    union data ownerinfo;
};

void print_car(struct car_data car)
{
    printf("----------------------------\n");
    printf("Car model : %s\n", car.model);

    if (car.status == 0) /* 0 = personal, 1 = company */
        printf("Personal owner : %s-%s\n",
            car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
    else
        printf("Company onwer : %s-%s-%s\n",
            car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
    printf("---------------------------\n");
}

int main()
{
    struct car_data my_car = { .model = "Avante", .status = 0, .ownerinfo.po = {"830422", "1185600"} };
    struct car_data company_car = { .model = "Sonata", .status = 1, .ownerinfo.co = {"111", "22", "33333"} };
    
    print_car(my_car);
    print_car(company_car);

    return 0;
}
