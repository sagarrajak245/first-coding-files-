#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

// C++ program for the above approach
using namespace std;

queue<int> revq(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    return q;
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "que is " << endl;
    print(q);
    revq(q);

    cout << "the q after rev is " << endl;
    print(q);

    return 0;
}