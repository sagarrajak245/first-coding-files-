#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        int min_rot = INT_MAX;

        for (int num = 1; num <= 6; num++)
        {
            bool possible = true;
            int top_rot = 0, bottom_rot = 0;

            for (int i = 0; i < n; i++)
            {
                if (tops[i] != num && bottoms[i] != num)
                {
                    possible = false;
                    break;
                }
                if (tops[i] != num)
                    top_rot++;
                if (bottoms[i] != num)
                    bottom_rot++;
            }

            if (possible)
                min_rot = min(min_rot, min(top_rot, bottom_rot));
        }

        return min_rot == INT_MAX ? -1 : min_rot;
    }
};

int main()
{
    Solution sol;
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    int result = sol.minDominoRotations(tops, bottoms);
    cout << "Minimum number of rotations: " << result << endl;
    return 0;
}
