#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10

int top = -1;

char stack[MAXSIZE];

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

/* Check if the stack is full */
int isfull()
{
    if (top == MAXSIZE - 1)
    {

        return 1;
    }

    else
        return 0;
}

/* Function to return the topmost element in the stack */
int peek()
{

    if (!isempty())
    {
        return stack[top];
    }
    else
    {
        return -1;
    }
}

/* Function to delete from the stack */
int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top--;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty\n");
    }
}

/* Function to insert into the stack */
int push(int data)
{
    if (!isfull())
    {
        top++;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int pre(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '=' || ch == '(' || ch == ')')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '=' || ch == '(' || ch == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));

    int i = 0; // traverse through infix
    int j = 0; // traverse through postfix

    while (infix[i] != '\0')
    {

        if (!isoperator(infix[i]))
        {

            postfix[j++] = infix[i++]; // operand push kiya in postfix
        }
        else
        {

            if (pre(infix[i]) > pre(peek()))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (!isempty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "(a+b)*c/d";

    printf("postfix is %s", infixtopostfix(infix));
    return 0;
}