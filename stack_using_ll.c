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
void display(struct node *top)
{

    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isempty(struct node *top)
{
    if (top == NULL)
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
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    printf("stack values are\n");
    display(top);

    pop();
    pop();

    printf("stack values after pop is\n");
    display(top);
    return 0;
}