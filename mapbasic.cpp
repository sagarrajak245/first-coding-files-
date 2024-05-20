#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    string s = "sagar";
    map<int, int> q;

    for (int i = 0; i < s.length(); i++)
    {

        q[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {

        if (q[s[i]] == 1)
        {
            cout << i;
            break;
        }
    }
    for ()

        return 0;
}