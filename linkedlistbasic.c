#include <Stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode()
{

    struct node *start = (struct node *)malloc(sizeof(struct node));
    return start;
}

void insertnode(int data)
{
    struct node *temp = createnode();

    if (temp != NULL)
    {
        head = temp;
    }

    temp->data = data;
}