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

    int pop()
    {
        int data;
        if (top >= 0)
        {

            data = arr[top];
            top--;
            return data;
        }
        else
        {
            cout << "stack underflow";
        }
        return -1;
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

int main()
{
    stack s1(7);

    s1.push(50);
    s1.push(55);
    s1.push(65);
    s1.push(75);
    s1.push(85);
    s1.push(95);
    s1.push(105);

    cout << "top element " << s1.peek();
    s1.pop();
    s1.pop();
    s1.pop();
    cout << endl
         << "top element after poping 3 elements "
         << s1.peek();
    if (s1.isempty())
    {
        cout << "list is empty";
    }
    else
    {
        cout << endl
             << "list is not empty" << endl;
    }

    cout << "the stack is" << endl;
    print(s1);
    cout << endl;
    cout << "the stack after poping more element " << s1.pop() << " " << s1.pop() << endl;

    return 0;
}