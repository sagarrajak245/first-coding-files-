#include <stdio.h>




int main()
{int x,y;

printf("enter the value of x \n");
scanf("%d",&x);

printf("enter the value of y \n");
scanf("%d",&y);

int *a;
a=&x;



int *b;
b=&y;

printf(" the value of pointer a %d\n",*a);
printf(" the value of pointer b %d\n",*b);
printf("the address of x is %u\n",a);
printf("the address of y is %u\n",b);



return 0;
}