#include <stdio.h>

int main()
{

    int a[3],b[3],c[3];
int i;
 int sum;   
for(i=0;i<3;i++)
{scanf("%d",&a[i]);
}
printf("enter second array values ");
for(i=0;i<3;i++)
{scanf("%d",&b[i]);
}

for(i=0;i<3;i++)
{
sum=(a[i]+b[i]);
(c[i])=sum;

printf(" the sum of two array is %d\n",c[i]);
}

    
    return 0;
}