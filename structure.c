#include <stdio.h>

struct visa
{

    char name[100];
    char dob[100];
    char countryname[100];
    int passportnum;
    char dateofissue[100];
    char dateofexp[100];
    char add[200];
};

int main()
{

    struct visa visa1;

    printf("enter the visa details\n");

    printf("enter the applicants name\n");
    gets(visa1.name);

    printf("enter the dob\n");
    gets(visa1.dob);

    printf("enter the country name\n");
    gets(visa1.countryname);

    printf("enter the passport num\n");
    gets(visa1.passportnum);

    printf("enter the date of issued\n");
    gets(visa1.dateofissue);

    printf("enter the date of exp\n");
    gets(visa1.dateofexp);

    printf("enter the address\n");
    gets(visa1.add);

    printf("the details are here;\n\n");

    printf("name of applicant is\n");
    puts(visa1.name);

    printf("applicants dob is\n");
    puts(visa1.dob);

    printf("applicants country name is\n");
    puts(visa1.countryname);

    printf("applicants  assport num is\n");
    puts(visa1.passportnum);

    printf("applicants passport issue date is\n");
    puts(visa1.dateofissue);

    printf("applicants passport exp date\n");
    puts(visa1.dateofexp);

    printf("applicants address \n");
    puts(visa1.add);

    return 0;
}