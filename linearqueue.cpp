#include <iostream>
using namespace std;

class queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    queue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[n];
    }

    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = val;
        if (front == -1)
        {
            front++;
        }
    }

    int pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        return x;
    }

    void print()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    queue q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();

    return 0;
}