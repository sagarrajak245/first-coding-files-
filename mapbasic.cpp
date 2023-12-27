#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    string s = "sagar";
    queue<char> q;

    for (int i = 0; i < s.length(); i++)
    {
        q.push(s[i]);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}