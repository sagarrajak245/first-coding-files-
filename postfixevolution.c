#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(int val);
int pop();
int top_element();

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

int pop()
{
    int x;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        x = stack[top];
        top = top - 1;
    }
    return x;
}
int top_element()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return stack[top];
    }
}

int evolution(char postfix[])
{
    int i = 0;
    char ch;
    int val;
    int A, B;
    while ((ch = postfix[i]) != '\0')
    {
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();
            switch (ch)
            {
            case '*': // else if ladder converted into switch
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
        i++;
    }
    return pop();
}

int isdigit(char ch)
{
    if (ch >= '0' && ch <= '9')
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
    printf("Enter the postfix expression: ");
    gets(postfix);
    puts(postfix);

    printf("the value of evolution is %d", evolution(postfix));

    return 0;
}