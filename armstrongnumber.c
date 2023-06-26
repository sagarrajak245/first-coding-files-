#include <stdio.h>
#include <math.h>

int main()
{ // armstrongnumber
    int num;

    printf("enter the number\n");
    scanf("%d", &num);
    int count = 0;
    int temp = num;
    int sum = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        sum = sum + pow(rem, 3);
        temp = temp / 10;
    }
    if (sum == num)
    {
        printf("number is armstrong number");
    }
    else
    {
        printf("number is not armstrong number");
    }

    return 0;
}