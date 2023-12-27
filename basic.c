#include <stdio.h>

int main()
{

    int a, b, c;

    print("enter the numbers\n");
    scanf("%d %d %d", &a, &b, &c);

    print("entered the numbers are %d %d %d", a, b, c);

    printf("sum of numbers are sum=%d", a + b + c);
    return 0;
}