#include <stdio.h>
#include <limits.h>

#define MAX 100

// denotes where the last item in priority queue is
// initialized to -1 since no item is in queue
int idx = -1;//rear

// pqVal holds data for each index item
// pqPriority holds priority for each index item
int pqVal[MAX];
int pqPriority[MAX];

int isEmpty()
{
    return idx == -1;
}

int isFull()
{
    return idx == MAX - 1;
}

// enqueue just adds item to the end of the priority queue | O(1)
void push(int data, int priority)
{
    if (!isFull())
    {

        // Increase the index
        idx++;

        // Insert the element in priority queue
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}

// returns item with highest priority
// NOTE: Max Priority Queue High priority number means higher priority | O(N)
int peek()
{
    // Note : Max Priority, so assigned min value as initial value
    int maxPriority = INT_MIN;
    int indexPos = -1;  

    // Linear search for highest priority
    for (int i = 0; i <= idx; i++)
    {
        // If two items have same priority choose the one with
        // higher data value
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i])
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }

        // note: using MAX Priority so higher priority number
        // means higher priority
        else if (maxPriority < pqPriority[i])
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }

    // Return index of the element where
    return indexPos;
}

// This removes the element with highest priority
// from the priority queue | O(N)
void pop()
{
    if (!isEmpty())
    {
        // Get element with highest priority
        int indexPos = peek();

        // reduce size of priority queue by first
        // shifting all elements one position left
        // from index where the highest priority item was found
        for (int i = indexPos; i < idx; i++)
        {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }

        // reduce size of priority queue by 1
        idx--;
    }
}

void display()
{
    for (int i = 0; i <= idx; i++)
    {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

// Driver Code
int main()
{
    // To enqueue items as per priority
    push(5, 1);
    push(10, 3);
    push(15, 4);
    push(20, 5);
    push(500, 2);

    printf("Before Dequeue : \n");
    display();

    // Dequeue the top element
    pop(); // 20 dequeued
    pop(); // 15 dequeued

    printf("\nAfter Dequeue : \n");
    display();

    return 0;
}