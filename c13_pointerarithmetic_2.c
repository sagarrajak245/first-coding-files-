#include <stdio.h>

int main()
{
int d=9;
    int a = 5;
    int *c=&d;
int *b;
b=&a;

    printf("the value of a is %d \n", a);

   // printf("the address of a is %u \n", b);
    //b++;
    printf("the new address of a is %u \n", b); 

    printf("the sum of a+d is %d \n", *c+*b);







    return 0;
}