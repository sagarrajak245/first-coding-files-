

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mini = prices[0];
        int maxP = 0;
        for (int i = 1; i < n; i++)
        {
            if (mini < prices[i])
                maxP += prices[i] - mini;
            mini = prices[i];
        }
        return maxP;
    }
};

int main()
{
    Solution s;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << s.maxProfit(prices) << endl;

    return 0;
}