#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>()); // Sort in descending order
        int n = citations.size();

        // Handle the edge case where there is only one element
        if (n == 1)
        {
            return citations[0] > 0 ? 1 : 0;
        }

        int hIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (citations[i] >= i + 1)
            {
                hIndex = i + 1;
            }
            else
            {
                break;
            }
        }

        return hIndex;
    }
};

int main()
{
    Solution s;
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = s.hIndex(citations);
    cout << "The h-index is: " << result << endl;
    return 0;
}
