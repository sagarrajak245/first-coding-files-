#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
// this basically a head pointer but here we are calling it as top

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);
    pop();

    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }

    return 0;
}