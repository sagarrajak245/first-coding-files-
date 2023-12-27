#include <stdio.h>

void wrongswap(int a,int b);


int main()
{int x=3;
int y=4;

printf("The value of x and y is %d and %d\n",x,y);
wrongswap(x,y);
printf("The value of x and y after swap is %d and %d \n", x,y);
return 0;
}

void wrongswap(int a,int b){

int t;
t=a;
a=b;
b=t;

}