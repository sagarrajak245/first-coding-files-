#include <stdio.h>
#include <stdlib.h>
#define max 10

char stack[max];
int top = -1;
int ismatch(char ch, char popped);

void push(char x)
{
    if (top == max - 1)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

char pop()
{
    char x;
    if (top == -1)
    {
        printf("stack underflow\n");
        exit(1);
    }
    else
    {
        x = stack[top];
        top = top - 1;
    }
    return x;
}

int balance(char postfix[])
{
    int i = 0;
    char ch;
    char popped;
    while ((ch = postfix[i]) != '\0')
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                return 0; // single parenthesis match
            }
            else
            {
                popped = pop();
                if (!ismatch(ch, popped))
                {
                    return 0; // exception case
                }
            }
        }

        i++;
    }

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ismatch(char ch, char popped)
{
    if (ch == ')' && popped == '(')
    {
        return 1;
    }
    else if (ch == '}' && popped == '{')
    {
        return 1;
    }
    else if (ch == ']' && popped == '[')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char postfix[20];
    printf("enter the postfix expression\n");
    gets(postfix);
    puts(postfix);
    if (balance(postfix))
    {
        printf("expression is balanced\n");
    }
    else
    {
        printf("expression is not balanced\n");
    }

    return 0;
}