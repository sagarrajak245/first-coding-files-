#include <iostream>
using namespace std;

bool ispossible(int n, int m, int k)
{
    // base case
    if (n > m)
    {
        return 0;
    }

    else if (n <= m - k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    bool ans = ispossible(N, M, K);
    if (ans)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}