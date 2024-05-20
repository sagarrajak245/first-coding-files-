
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0; // edge case sagar

        int maxProfit = 0;
        int minPrice = prices[0];

        for (int i = 1; i < n; i++)
        {
            //  minimum price seen so far
            minPrice = min(minPrice, prices[i]);

            // Calculate the profit if we sell at the current price
            // and update the maximum profit if necessary
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

int main()
{
    Solution s;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << s.maxProfit(prices) << endl;

    return 0;
}