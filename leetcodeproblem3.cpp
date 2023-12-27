#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int x;
    cout << "enter the number";
    cin >> x;

    vector<int> ans;
    while (!x == 0)
    {
        int digit = x % 10;
        x = x / 10;
        ans.push_back(digit);
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}