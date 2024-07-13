#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (x[n - 1] == y[m - 1])
    {
        return 1 + lcs(x, y, n - 1, m - 1);
    }
    else
    {
        return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
    }
}

int main()
{

    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.length();
    int m = s2.length();
    cout << "len of longest common subsequence is " << lcs(s1, s2, n, m) << endl;

    return 0;
}
