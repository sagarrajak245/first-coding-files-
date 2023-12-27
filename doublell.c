#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void createlist(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}
void insertatbegin(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insertatend(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}
void insertatpos(int val, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        int i = 1;
        while (i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }
        newnode->next = ptr->next;
        ptr->next->prev = newnode;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}
void deleteatbegin()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
void deleteatend()
{
    struct node *ptr = head;
    struct node *preptr = head;
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
}
void deleteatpos(int pos)
{
    struct node *ptr = head;
    struct node *preptr = head;
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        int i = 1;
        while (i < pos)
        {
            preptr = ptr;
            ptr = ptr->next;
            i++;
        }
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
    }
}
void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    createlist(2);
    createlist(3);
    createlist(4);
    createlist(5);
    createlist(6);
    printf("list values are\n");
    display();
    printf("\n");
    insertatbegin(1);
    printf("list values after inserting at begin\n");
    display();
    printf("\n");
    insertatend(7);
    printf("list values after inserting at end\n");
    display();
    printf("\n");
    insertatpos(8, 4);
    printf("list values after inserting at position\n");
    display();
    printf("\n");
    deleteatbegin();
    printf("list values after deleting at begin\n");
    display();
    printf("\n");
    deleteatend();
    printf("list values after deleting at end\n");
    display();
    printf("\n");
    deleteatpos(3);
    printf("list values after deleting at position\n");
    display();
    printf("\n");
    return 0;
}
