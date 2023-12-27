#include <stdio.h>

void swap(int *a,int *b);
int sum(int *a,int *b);

int main()
{int x,y;

printf("enter the value of x \n");
scanf("%d",&x);

printf("enter the value of y \n");
scanf("%d",&y);


printf("The value of x and y before is %d and %d\n",x,y);
swap(&x,&y);
printf("The value of x and y after swap is %d and %d \n", x,y);
printf("the sum of x and y is %d\n",sum(&x,&y));
return 0;
}
//call by reference is  used for utilising actual values of variables that's why we use pointer bcoz 
//it gives us direct acess to variables through their address
void swap(int *a,int *b){
int t;
t=*a;
*a=*b;
*b=t;
}

int sum(int *a,int *b){

int p;
p=*a+*b;
return p;
}