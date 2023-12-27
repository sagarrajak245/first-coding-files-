#include <iostream>
#include <bits/stdc++.h>

using namespace std;
stack<int> solve(stack<int> s, int x) // code is correct but not working
{
    if (s.empty())
    { // base case
        s.push(x);
    }
    else
    {
        int topval = s.top(); // top value of stack stored
        s.pop();              // pop the top value

        // recursive call

        solve(s, x);
        // push the top value again (after recursive call)
        s.push(topval);
        cout << s.top();
    }
    return s;
}

void insertatbottom(stack<int> s, int val)
{
    solve(s, val);

    // Print the stack S
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void print(stack<int> s)
{

    while (!s.empty())
    {

        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "the stack before insertion is " << endl;
    print(s);
    cout << endl;

    cout << "the stack after insertion is " << endl;

    insertatbottom(s, 6);

    return 0;
}