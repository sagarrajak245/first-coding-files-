#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    // Helper function to calculate the sum of digits of a number
    int sumOfDigits(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n)
    {
        unordered_map<int, int> groups; // Map to store the frequency of each sum of digits

        // Grouping numbers by their digit sum
        for (int i = 1; i <= n; i++)
        {
            int sum = sumOfDigits(i);
            groups[sum]++;
        }

        // Finding the maximum size of any group
        int maxGroupSize = 0;
        for (auto &entry : groups)
        {
            maxGroupSize = max(maxGroupSize, entry.second);
        }

        // Counting how many groups have the largest size
        int result = 0;
        for (auto &entry : groups)
        {
            if (entry.second == maxGroupSize)
            {
                result++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n = 13;
    cout << "Number of groups with largest size: " << sol.countLargestGroup(n) << endl;
    return 0;
}
