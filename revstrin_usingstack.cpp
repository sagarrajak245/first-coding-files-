#include <iostream>
#include <bits/stdc++.h>
// #include <stack>
using namespace std;

bool ispallindrome(char arr[], int size)
{

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        if (arr[start] != arr[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }

    return true;
}

int main()
{
    char *arr = new char[10];
    stack<char> s1;
    s1.push('s');
    s1.push('a');
    s1.push('g');
    s1.push('a');
    s1.push('s');
    cout << "the stack top is " << s1.top() << endl;

    for (int i = 0; i < 5; i++)
    {
        if (!s1.empty())
        {
            arr[i] = s1.top();
        }
        s1.pop();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    if (ispallindrome(arr, 5))
    {

        cout << endl
             << "stack is pallindrome";
    }
    else
    {
        cout << "stack is not pallindrome";
    }

    delete[] arr;

    return 0;
}
