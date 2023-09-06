#include <stdio.h>
#include <stdlib.h>
#define size 10
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void push(int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void pop()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("queue is underflow");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    printf("queue values are\n");
    display();

    pop();
    printf("after pop\n");
    display();
    return 0;
}
