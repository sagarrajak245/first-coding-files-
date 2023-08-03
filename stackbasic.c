#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

/* Check if the stack is empty */
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
        printf("Could not retrieve data, Stack is empty.\n");
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

/* Main function */
int main()
{
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    push(99);
    push(88);
    push(11);

    printf("Element at top of the stack: %d\n", peek());
    printf("Elements: \n");

    printf("Stack full: %s\n", isfull() ? "true" : "false");

    // print stack data
    while (!isempty())
    {
        int data = pop();
        printf("%d\n", data);
    }

    printf("Stack empty: %s\n", isempty() ? "true" : "false");

    return 0;
}