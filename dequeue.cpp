#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
class dqueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
    dqueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }
    void push_front(int data)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
        size++;
    }
    void push_back(int data)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
        size++;
    }
    void pop_front()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        size--;
    }
    void pop_back()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }
        size--;
    }

    int get_front()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int get_back()
    {
        if (isempty() || rear < 0)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    bool isempty()
    {
        return (front == -1);
    }
    bool isfull()
    {
        return ((front == 0 && rear == capacity - 1) || (front == rear + 1));
    }
    int getsize()
    {
        return size;
    }
};

void print(dqueue &dq)
{
    while (!dq.isempty())
    {
        cout << dq.get_front() << " ";
        dq.pop_front();
    }
}
int main()
{

    dqueue dq(5);
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);
    dq.pop_back();

    print(dq);

    return 0;
}
