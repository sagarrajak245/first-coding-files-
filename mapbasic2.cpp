#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> m;
    m[1] = 2;
    m[2] = 3;
    m[3] = 4;
    m[4] = 5;
    m[5] = 6;
    m[6] = 7;
    m[5] = 7;
    m[4] = 7;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}