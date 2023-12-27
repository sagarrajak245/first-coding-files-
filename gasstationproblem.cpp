
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int len = gas.size() - 1;
        int start = 0;
        int def = 0;
        int bal = 0;
        // cout << len << endl;
        for (int i = 0; i <= len; i++)
        {

            bal += gas[i] - cost[i];
            if (bal < 0)
            {
                def += bal;
                start = i + 1;
                bal = 0;
            }
        }

        if (def + bal >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> gas = {3, 1, 1};

    vector<int> cost = {1, 2, 2};

    Solution s;
    cout << "The ans is " << s.canCompleteCircuit(gas, cost);

    return 0;
}