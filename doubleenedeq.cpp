#include <iostream>
#include <algorithm>
using namespace std;

class dqueue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    // constructor
    dqueue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = size - 1;
    }

    void push1(int data)
    { // front se push kiya
        if (front < size - 1)
        {
            arr[++front] = data;
        }
        else
        {
            cout << "overflow\n";
        }
    }

    int pop1()
    { // front se pop kiya
        int x = 0;
        if (front == -1)
        {
            cout << "underflow\n";
        }
        else
        {
            x = arr[front--];
        }
        return x;
    }

    void push2(int data)
    { // rear se push kiya
        if (rear >= front + 1)
        {
            arr[rear--] = data;
        }
        else
        {
            cout << "overflow\n";
        }
    }

    int pop2()
    { // rear se pop kiya
        int x = 0;
        if (rear < size - 1)
        {
            x = arr[rear++];
        }
        else
        {
            cout << "underflow\n";
        }
        return x;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    dqueue q(5);
    q.push1(1);
    q.push1(2);
    q.push2(3);
    q.push2(5);

    q.print();

    return 0;
}
