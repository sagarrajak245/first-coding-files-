#include <stdio.h>
#include <stdlib.h>

// dynamic allocated queue
// linear queue

struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};

int isempty(struct queue *q)
{

    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct queue *q, int val)
{

    if ((q->rear + 1) % q->size == q->front)
    {
        printf("queue is full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

int pop(struct queue *q)
{
    int data;
    if (q->front == q->rear)
    {
        printf("queue is underflow");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        data = q->arr[q->front];
    }
    return data;
}

int main()
{

    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 5;
    q.arr = (int *)malloc(q.size * sizeof(int));

    push(&q, 12);
    push(&q, 13);
    push(&q, 14);
    push(&q, 15);
    push(&q, 16);

    while (!isempty(&q))
    {
        printf("%d\n", pop(&q));
    }

    return 0;
}