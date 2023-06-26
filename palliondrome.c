#include <stdio.h>
#include <string.h>

int pallindrome(char s1[], int size)
{
    int i;
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        if (s1[start] != s1[end])
        {
            return 0;
        }
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}

int main()
{

    char s1[100];
    printf("enter string\n");
    gets(s1);
    puts(s1);
    int size = strlen(s1);
    int ans = pallindrome(s1, size);
    if (ans > 0)
    {
        printf("it is pallindrome");
    }
    else
    {

        printf("it is not pallindrome");
    }
    strrev(s1);
    printf("\nafter rev string is\n");
    puts(s1);
    return 0;
}