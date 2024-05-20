#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int rptchar(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int max = 0, res = -1;
    for (auto i : mp)
    {
        if (max < i.second)
        {
            res = i.first;
            max = i.second;
        }
    }

    return res;
}

int main()
{

    int arr[] = {5, 5, 5, 4, 4, 2, 2, 2, 2, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = rptchar(arr, n);

    cout << "the most repeated number is : \n"
         << ans << endl;

    return 0;
}
