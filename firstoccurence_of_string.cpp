#include <iostream>
#include <algorithm>

using namespace std;

int firstocc(string st2, string st1)
{

    int len2 = st2.length();
    int len1 = st1.length();
    int idx = 0;

    for (int i = 0; i < len2; i++)
    {

        if (st2[i] == st1[idx])
        {
            idx++;
        }
        else
        {
            idx = -1;
        }
        if (idx == len1)
        {
            return i - len1 + 1;
        }
    }

    return idx;
}

int main()
{

    string st1 = "sad";
    string st2 = "sadbutsad";

    int ans = firstocc(st2, st1);

    cout << "the index at which string  is present " << ans << endl;

    return 0;
}