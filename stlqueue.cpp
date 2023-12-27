#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

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
    queue<int> q1;

    q1.push(5);
    q1.push(5);
    q1.push(25);
    q1.push(24);
    q1.push(29);
    q1.push(21);
    print(q1);

    int len = q1.size();
    cout << len<<endl;


    return 0;
}
