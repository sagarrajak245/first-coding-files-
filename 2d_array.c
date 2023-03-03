#include <stdio.h>

int main()
{

int a[2][3];
int i,j;
 int sum=0;
 printf("enter the values");   

for(i=0;i<2;i++){
for(j=0;j<3;j++){
    scanf("%d",&a[i][j]);
sum=sum+a[i][j];}
}
printf("the matrix of students is\n");

for(i=0;i<2;i++){
for(j=0;j<3;j++){
    printf("%d\t",a[i][j]);
}
printf("\n");
}

printf("the sum is %d",sum);
    return 0;

}