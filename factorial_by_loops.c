#include <stdio.h>

int main()
{
 int  a;
 printf(" enter the value\n");
scanf("%d",&a);

int i=1;

while(i<=a)
{
int fact=1;
fact=fact*i;
printf("the value of factorial of number is %d\n",fact);

    i++;
}


    return 0;
}