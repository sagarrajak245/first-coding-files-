#include <iostream>

using namespace std;

class stack
{
public:
    int top;
    int *arr;
    int size;

    // constructor
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stackoverflow";
        }
    }

    void pop()
    {
        if (top >= 0)
        {

            arr[top--];
        }
        else
        {
            cout << "stack underflow";
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty";
        }
        return -1;
    }

    bool isempty()
    {

        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
void print(stack s1)
{
    while (!s1.isempty())
    {
        cout << s1.peek() << " ";
        s1.pop();
    }
}

void delmid(stack &s1, int count, int size)
{

    if (count == size / 2)
    {
        s1.pop();
        return;
    }

    int num = s1.peek(); // stored kiya and then pop kiya to wo stack se hat gaya temporarily
    s1.pop();
    count++;
    delmid(s1, count, size); // new stack generATE KARli and then usme push kardiya
    s1.push(num);            // ye return hone ke bad push kardiya
}

int main()
{
    int count = 0;
    stack s1(7);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    cout << s1.peek() << endl;
    print(s1);
    delmid(s1, 0, 7);
    cout << endl;
    print(s1);

    return 0;
}